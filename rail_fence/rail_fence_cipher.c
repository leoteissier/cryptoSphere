#include <stdlib.h>
#include <string.h>

void rail_fence_cipher(char text[], char *rails) {
    int rails_int = atoi(rails); // Convert rails to an integer
    const int n = strlen(text);
    const int waveLen = 2 * (rails_int - 1); // Longueur d'une "vague" du zigzag
    int counter = 0;

    char output[n + 1]; // Declare output as a character array
    for (int r = 0; r < rails_int; r++) {
        int index = r;
        int wavePos = r; // Position dans la vague actuelle

        while (index < n) {
            output[counter++] = text[index];
            // Calculer le prochain index
            if (wavePos == 0 || wavePos == rails_int - 1) { // En haut ou en bas de la vague
                index += waveLen;
            } else { // Au milieu de la vague
                index += (2 * (rails_int - wavePos - 1));
                wavePos = rails_int - wavePos - 1;
            }
        }
    }
    output[counter] = '\0'; // Terminer la chaîne de caractères
}