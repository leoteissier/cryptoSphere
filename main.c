#include <stdio.h>
#include <string.h>

// Include constants
#include "constants.h"

// Include encryption headers
#include "encryption.h"

// Include verification functions
#include "functions/functions.h"

// Include cipher headers
#include "caesar/caesar.h"
#include "vigenere/vigenere.h"
#include "substitution/substitution.h"
#include "xor/xor.h"
#include "rail_fence/rail_fence.h"
#include "aes/aes.h"

typedef struct {
    const char* name;
    void (*cipher_func)(char *, char *);
    void (*decipher_func)(char *, char *);
} CipherInfo;

CipherInfo cipher_info[] = {
    {"Caesar", caesar_cipher, caesar_decipher},
    {"Vigenere", vigenere_cipher, vigenere_decipher},
    {"Substitution", substitution_cipher, substitution_decipher},
    {"XOR", xor_cipher, xor_cipher},
    {"Rail Fence", rail_fence_cipher, rail_fence_decipher},
};

#define NUM_CIPHER_TYPES (sizeof(cipher_info) / sizeof(CipherInfo))

CipherType ask_cipher_or_decipher() {
    int choice;
    printf("Voulez-vous chiffrer ou déchiffrer ?\n");
    printf("1. Chiffrer\n");
    printf("2. Déchiffrer\n");
    scanf("%d", &choice);
    while (choice < 1 || choice > 2) {
        printf("Erreur : choix invalide. Veuillez entrer 1 pour chiffrer ou 2 pour déchiffrer.\n");
        scanf("%d", &choice);
    }
    return choice == 1 ? CIPHER_TYPE_ENCRYPT : CIPHER_TYPE_DECRYPT;
}

CipherType ask_cipher_type() {
    int choice;

    printf("Choisissez le type de chiffrement :\n");
    for (int i = 0; i < NUM_CIPHER_TYPES; i++) {
        printf("%d. %s\n", i + 1, cipher_info[i].name);
    }
    scanf("%d", &choice);
    while (choice < 1 || choice > NUM_CIPHER_TYPES) {
        printf("Erreur : choix invalide. Veuillez entrer un nombre entre 1 et %lu.\n", NUM_CIPHER_TYPES);
        scanf("%d", &choice);
    }

    switch (choice) {
        case 1:
            return CIPHER_TYPE_CAESAR;
        case 2:
            return CIPHER_TYPE_VIGENERE;
        case 3:
            return CIPHER_TYPE_SUBSTITUTION;
        case 4:
            return CIPHER_TYPE_XOR;
        case 5:
            return CIPHER_TYPE_RAIL_FENCE;
        default:
            fprintf(stderr, "Erreur : Type de chiffrement non reconnu.\n");
            return -1; // Return an invalid value
    }
}

const char* get_key_example(CipherType cipher_type) {
    if (cipher_type >= NUM_CIPHER_TYPES != 0) {
        return "";
    }

    switch (cipher_type) {
        case CIPHER_TYPE_CAESAR:
            return "3"; // Example Caesar key
        case CIPHER_TYPE_VIGENERE:
            return "cle"; // Example Vigenere key
        case CIPHER_TYPE_SUBSTITUTION:
            return "bcdefghijklmnopqrstuvwxyza"; // Example substitution key
        case CIPHER_TYPE_XOR:
            return "a"; // Example XOR key
        case CIPHER_TYPE_RAIL_FENCE:
            return "3"; // Example rail count
        default:
            return "";
    }
}

int ask_user_key(CipherType cipher_type, CipherKey *key) {
    if (cipher_type >= NUM_CIPHER_TYPES != 0) {
        fprintf(stderr, "Erreur : Type de chiffrement non reconnu.\n");
        return 0;
    }

    printf("Entrez la clé pour le chiffrement de %s (par exemple, \"%s\") : ", "déchiffrement", get_key_example(cipher_type));
    scanf(" %[^\n]s", key->key);

    return verify_key(cipher_type, key);
}

int main() {
    CipherKey key;
    int exit_program = 0;

    do {
        // Ask user if they want to cipher or decipher
        int cipher_or_decipher = ask_cipher_or_decipher();

        // Ask user which cipher type they want to use
        int chosen_cipher_type = ask_cipher_type();

        // Ask user for the key
        ask_user_key(chosen_cipher_type, &key);

        // Chiffre or decipher based on type
        char text[MAX_TEXT_LENGTH];

        printf("Entrez le texte à %s : ", cipher_or_decipher == CIPHER_TYPE_ENCRYPT ? "chiffrer" : "déchiffrer");
        scanf(" %[^\n]s", text); // Read input with spaces (stops at newline character

        // Remove trailing newline from text
        int len = strlen(text);
        if (len > 0 && text[len - 1] == '\n') {
            text[len - 1] = '\0';
        }

        if (cipher_or_decipher == CIPHER_TYPE_ENCRYPT) {
            cipher_info[chosen_cipher_type].cipher_func(text, key.key);
            printf("Texte chiffré : %s\n", text);
        } else {
            cipher_info[chosen_cipher_type].decipher_func(text, key.key);
            printf("Texte déchiffré : %s\n", text);
        }

        printf("Voulez-vous continuer ? (1 pour Oui, 0 pour Non) : ");
        scanf("%d", &exit_program);
    } while (exit_program);

    return 0;
}