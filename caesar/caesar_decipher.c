#include <stdlib.h>
#include <string.h>

void caesar_decipher(char text[], char *key) {
    int key_int = atoi(key); // Convert key to an integer
    const int n = strlen(text);

    for (int i = 0; i < n; i++) {
        if (text[i] >= 'a' && text[i] <= 'z')
            text[i] = (text[i] - 'a' - key_int + 26) % 26 + 'a';
        else if (text[i] >= 'A' && text[i] <= 'Z')
            text[i] = (text[i] - 'A' - key_int + 26) % 26 + 'A';
    }
}