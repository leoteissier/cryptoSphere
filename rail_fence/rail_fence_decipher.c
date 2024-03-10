#include <stdlib.h>
#include <string.h>

void rail_fence_decipher(char cipherText[], char *rails) {
    int rails_int = atoi(rails); // Convert rails to an integer
    const int n = strlen(cipherText);
    const int waveLen = 2 * (rails_int - 1); // Longueur d'une "vague" du zigzag
    int counter = 0;
    char temp[n + 1]; // Tableau temporaire pour stocker les positions des caractères

    for (int r = 0; r < rails_int; r++) {
        int index = r;
        int wavePos = r; // Position dans la vague actuelle

        while (index < n) {
            temp[index] = cipherText[counter++];

            // Calculer le prochain index
            if (wavePos == 0 || wavePos == rails_int - 1) { // En haut ou en bas de la vague
                index += waveLen;
            } else { // Au milieu de la vague
                index += (2 * (rails_int - wavePos - 1));
                wavePos = rails_int - wavePos - 1;
            }
        }
    }

    char output[n + 1]; // Declare output as a character array
    for (int i = 0; i < n; i++) {
        output[i] = temp[i];
    }
    output[n] = '\0'; // Terminer la chaîne de caractères
}