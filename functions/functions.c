#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "../encryption.h"

int verify_key(CipherType cipher_type, CipherKey *key) {
    switch (cipher_type) {
        case CIPHER_TYPE_CAESAR:
            // For a Caesar cipher, the key should be a single integer
            for (int i = 0; key->key[i] != '\0'; i++) {
                if (!isdigit(key->key[i])) {
                    fprintf(stderr, "Erreur : La clé pour le chiffrement de César doit être un nombre entier.\n");
                    return 0;
                }
            }
            break;

        case CIPHER_TYPE_VIGENERE:
            // For a Vigenere cipher, the key should be a string of alphabetic characters
            for (int i = 0; key->key[i] != '\0'; i++) {
                if (!isalpha(key->key[i])) {
                    fprintf(stderr, "Erreur : La clé pour le chiffrement de Vigenère doit être une chaîne de caractères alphabétiques.\n");
                    return 0;
                }
            }
            break;

        case CIPHER_TYPE_SUBSTITUTION:
            // For a substitution cipher, the key should be a string of 26 unique alphabetic characters
            if (strlen(key->key) != 26) {
                fprintf(stderr, "Erreur : La clé pour le chiffrement par substitution doit être une chaîne de 26 caractères alphabétiques uniques.\n");
                return 0;
            }

            int used[26] = {0};
            for (int i = 0; key->key[i] != '\0'; i++) {
                if (!isalpha(key->key[i])) {
                    fprintf(stderr, "Erreur : La clé pour le chiffrement par substitution doit être une chaîne de 26 caractères alphabétiques uniques.\n");
                    return 0;
                }

                int index = tolower(key->key[i]) - 'a';
                if (used[index]) {
                    fprintf(stderr, "Erreur : La clé pour le chiffrement par substitution doit être une chaîne de 26 caractères alphabétiques uniques.\n");
                    return 0;
                }
                used[index] = 1;
            }
            break;

        case CIPHER_TYPE_XOR:
            // For an XOR cipher, the key should be a single character
            if (strlen(key->key) != 1) {
                fprintf(stderr, "Erreur : La clé pour le chiffrement par XOR doit être un seul caractère.\n");
                return 0;
            }
            break;

        case CIPHER_TYPE_RAIL_FENCE:
            // For a rail fence cipher, the key should be a single integer
            for (int i = 0; key->key[i] != '\0'; i++) {
                if (!isdigit(key->key[i])) {
                    fprintf(stderr, "Erreur : La clé pour le chiffrement par rail-fence doit être un nombre entier.\n");
                    return 0;
                }
            }
            break;

        default:
            fprintf(stderr, "Erreur : Type de chiffrement non reconnu.\n");
            return 0;
    }

    return 1;
}