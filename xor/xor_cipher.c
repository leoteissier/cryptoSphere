#include <string.h>

void xor_cipher(char text[], char key[]) {
    int keyLength = strlen(key);

    for (int i = 0; text[i] != '\0'; i++) {
        text[i] ^= key[i % keyLength];
    }
}