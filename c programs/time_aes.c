#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <mbedtls/aes.h>

#define AES_KEY_SIZE  32
#define AES_BLOCK_SIZE 16
#define FLOAT_COUNT 1000
#define KEY_SIZE 256

static const uint8_t key[AES_KEY_SIZE] = {
    0x60, 0x3d, 0xeb, 0x10, 0x15, 0xca, 0x71, 0xbe,
    0x2b, 0x73, 0xae, 0xf0, 0x85, 0x7d, 0x77, 0x81,
    0x1f, 0x35, 0x2c, 0x07, 0x3b, 0x61, 0x08, 0xd7,
    0x2d, 0x98, 0x10, 0xa3, 0x09, 0x14, 0xdf, 0xf4
};

static const uint8_t iv_init[AES_BLOCK_SIZE] = {
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
    if (pad_len > AES_BLOCK_SIZE || pad_len == 0)
        return data_len;
    return data_len - pad_len;
}

int main() {
    float input[FLOAT_COUNT];
    for (int i = 0; i < FLOAT_COUNT; i++)
        input[i] = ((float)rand() / RAND_MAX) * 1000;

    size_t plain_len = FLOAT_COUNT * sizeof(float);
    size_t padded_len = ((plain_len / AES_BLOCK_SIZE) + 1) * AES_BLOCK_SIZE;
    uint8_t *plaintext = calloc(1, padded_len);
    uint8_t *ciphertext = calloc(1, padded_len);
    uint8_t *decrypted = calloc(1, padded_len);

    memcpy(plaintext, input, plain_len);
    padded_len = pkcs7_pad(plaintext, plain_len, AES_BLOCK_SIZE);

    // Encrypt
    uint8_t iv_enc[AES_BLOCK_SIZE];
    memcpy(iv_enc, iv_init, AES_BLOCK_SIZE);
    mbedtls_aes_context aes_enc;
    mbedtls_aes_init(&aes_enc);
    mbedtls_aes_setkey_enc(&aes_enc, key, KEY_SIZE);

    clock_t enc_start = clock();
    mbedtls_aes_crypt_cbc(&aes_enc, MBEDTLS_AES_ENCRYPT, padded_len, iv_enc, plaintext, ciphertext);
    clock_t enc_end = clock();
    mbedtls_aes_free(&aes_enc);
    printf("Encrypted Bytes:\n");
    for (size_t i = 0; i < padded_len; i++) {
        printf("%02x ", ciphertext[i]);
        if ((i + 1) % 16 == 0) printf("\n");
    }


    // Decrypt
    uint8_t iv_dec[AES_BLOCK_SIZE];
    memcpy(iv_dec, iv_init, AES_BLOCK_SIZE);
    mbedtls_aes_context aes_dec;
    mbedtls_aes_init(&aes_dec);
    mbedtls_aes_setkey_dec(&aes_dec, key, KEY_SIZE);

    clock_t dec_start = clock();
    mbedtls_aes_crypt_cbc(&aes_dec, MBEDTLS_AES_DECRYPT, padded_len, iv_dec, ciphertext, decrypted);
    clock_t dec_end = clock();
    mbedtls_aes_free(&aes_dec);

    size_t dec_len = pkcs7_unpad(decrypted, padded_len);
    float *output = (float *)decrypted;

    // Print timing
    double enc_time = (double)(enc_end - enc_start) / CLOCKS_PER_SEC;
    double dec_time = (double)(dec_end - dec_start) / CLOCKS_PER_SEC;

    printf("✅ Encrypted %d floats in %.6f sec\n", FLOAT_COUNT, enc_time);
    printf("✅ Decrypted in %.6f sec\n", dec_time);

    // Optional: verify first few values
    for (int i = 0; i < 20; i++) {
        printf("Original: %.3f\tDecrypted: %.3f\n", input[i], output[i]);
    }

    free(plaintext);
    free(ciphertext);
    free(decrypted);
    return 0;
}
