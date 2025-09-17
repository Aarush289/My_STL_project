#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <mbedtls/aes.h>

#define AES_KEY_SIZE    32  // 256-bit key
#define AES_BLOCK_SIZE  16

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

int aes_encrypt(const uint8_t *input, size_t input_len, uint8_t *output) {
    mbedtls_aes_context aes;
    uint8_t iv_copy[AES_BLOCK_SIZE];
    memcpy(iv_copy, iv, AES_BLOCK_SIZE);

    if (input_len % AES_BLOCK_SIZE != 0) {
        printf("❌ Input length must be multiple of %d bytes (no padding used)\n", AES_BLOCK_SIZE);
        return -1;
    }

    mbedtls_aes_init(&aes);
    mbedtls_aes_setkey_enc(&aes, key, 256);
    int ret = mbedtls_aes_crypt_cbc(&aes, MBEDTLS_AES_ENCRYPT, input_len, iv_copy, input, output);
    mbedtls_aes_free(&aes);
    return ret;
}

int aes_decrypt(const uint8_t *input, size_t input_len, uint8_t *output) {
    mbedtls_aes_context aes;
    uint8_t iv_copy[AES_BLOCK_SIZE];
    memcpy(iv_copy, iv, AES_BLOCK_SIZE);

    if (input_len % AES_BLOCK_SIZE != 0) {
        printf("❌ Encrypted length must be multiple of %d bytes\n", AES_BLOCK_SIZE);
        return -1;
    }

    mbedtls_aes_init(&aes);
    mbedtls_aes_setkey_dec(&aes, key, 256);
    int ret = mbedtls_aes_crypt_cbc(&aes, MBEDTLS_AES_DECRYPT, input_len, iv_copy, input, output);
    mbedtls_aes_free(&aes);
    return ret;
}

int main() {
    // Plaintext must be exactly multiple of 16 bytes
    uint8_t plaintext[32] = "Hello16ByteBlock!!AES!!____";
    uint8_t encrypted[32] = {0};
    uint8_t decrypted[32] = {0};

    printf("🔓 Plaintext: %s\n", plaintext);

    if (aes_encrypt(plaintext, sizeof(plaintext), encrypted) != 0) {
        printf("❌ Encryption failed\n");
        return 1;
    }

    printf("🔐 Encrypted: ");
    for (int i = 0; i < sizeof(encrypted); i++) {
        printf("%02x", encrypted[i]);
    }
    printf("\n");

    if (aes_decrypt(encrypted, sizeof(encrypted), decrypted) != 0) {
        printf("❌ Decryption failed\n");
        return 1;
    }

    printf("✅ Decrypted: %s\n", decrypted);
    return 0;
}
