#include <string.h>

void vigenere_cipher(char text[], char key[]) {
    int m = strlen(key); // Length of the key

    for (int i = 0; i < strlen(text); i++) {
        int keyOffset = key[i % m] - 'a'; // Get the key offset for the current character

        if (text[i] >= 'a' && text[i] <= 'z')
            text[i] = (text[i] - 'a' + keyOffset) % 26 + 'a';
        else if (text[i] >= 'A' && text[i] <= 'Z')
            text[i] = (text[i] - 'A' + keyOffset) % 26 + 'A';
    }
}
