#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <mbedtls/aes.h>

#define AES_KEY_SIZE    32  // AES-256 = 32 bytes key
#define AES_BLOCK_SIZE  16
#define KEY_SIZE_BITS   256

static const uint8_t key[AES_KEY_SIZE] = {
    0x60, 0x3d, 0xeb, 0x10, 0x15, 0xca, 0x71, 0xbe,
    0x2b, 0x73, 0xae, 0xf0, 0x85, 0x7d, 0x77, 0x81,
    0x1f, 0x35, 0x2c, 0x07, 0x3b, 0x61, 0x08, 0xd7,
    0x2d, 0x98, 0x10, 0xa3, 0x09, 0x14, 0xdf, 0xf4
};

static uint8_t iv[AES_BLOCK_SIZE] = {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
    0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f
};

size_t pkcs7_pad(uint8_t *data, size_t data_len, size_t block_size) {
    size_t pad_len = block_size - (data_len % block_size);
    for (size_t i = 0; i < pad_len; i++) {
        data[data_len + i] = (uint8_t)pad_len;
    }
    return data_len + pad_len;
}

size_t pkcs7_unpad(uint8_t *data, size_t data_len) {
    uint8_t pad_len = data[data_len - 1];
    if (pad_len == 0 || pad_len > AES_BLOCK_SIZE)
        return data_len;
    return data_len - pad_len;
}

int aes_encrypt(const uint8_t *input, size_t input_len, uint8_t *output, size_t *output_len) {
    mbedtls_aes_context aes;
    uint8_t iv_enc[AES_BLOCK_SIZE];
    memcpy(iv_enc, iv, AES_BLOCK_SIZE);

    uint8_t padded[128] = {0};  // Adjust size as needed
    memcpy(padded, input, input_len);
    *output_len = pkcs7_pad(padded, input_len, AES_BLOCK_SIZE);

    mbedtls_aes_init(&aes);
    mbedtls_aes_setkey_enc(&aes, key, KEY_SIZE_BITS);

    int ret = mbedtls_aes_crypt_cbc(&aes, MBEDTLS_AES_ENCRYPT, *output_len, iv_enc, padded, output);
    mbedtls_aes_free(&aes);
    return ret;
}

int aes_decrypt(const uint8_t *input, size_t input_len, uint8_t *output, size_t *output_len) {
    mbedtls_aes_context aes;
    uint8_t iv_dec[AES_BLOCK_SIZE];
    memcpy(iv_dec, iv, AES_BLOCK_SIZE);

    mbedtls_aes_init(&aes);
    mbedtls_aes_setkey_dec(&aes, key, KEY_SIZE_BITS);

    int ret = mbedtls_aes_crypt_cbc(&aes, MBEDTLS_AES_DECRYPT, input_len, iv_dec, input, output);
    mbedtls_aes_free(&aes);

    *output_len = pkcs7_unpad(output, input_len);
    return ret;
}

int main() {
    uint8_t plaintext[] = "Hello, AES-256-CBC!";
    uint8_t encrypted[128] = {0};
    uint8_t decrypted[128] = {0};
    size_t enc_len = 0, dec_len = 0;

    printf("🔓 Plaintext: %s\n", plaintext);

    if (aes_encrypt(plaintext, strlen((char *)plaintext), encrypted, &enc_len) != 0) {
        printf("❌ Encryption failed!\n");
        return -1;
    }

    printf("🔐 Encrypted (hex): ");
    for (size_t i = 0; i < enc_len; i++)
        printf("%02x", encrypted[i]);
    printf("\n");

    if (aes_decrypt(encrypted, enc_len, decrypted, &dec_len) != 0) {
        printf("❌ Decryption failed!\n");
        return -1;
    }

    decrypted[dec_len] = '\0';
    printf("🔓 Decrypted: %s\n", decrypted);

    return 0;
}
