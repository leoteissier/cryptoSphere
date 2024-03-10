void substitution_decipher(char text[], char substitution[]) {
    char reverseSubstitution[26];
    // Créer une table de substitution inversée
    for (int i = 0; i < 26; i++) {
        // Trouver la lettre correspondante dans le tableau de substitution
        for (int j = 0; j < 26; j++) {
            if (substitution[j] == 'a' + i) {
                reverseSubstitution[i] = 'a' + j;
                break;
            }
        }
    }

    // Utiliser la table de substitution inversée pour déchiffrer
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z')
            text[i] = reverseSubstitution[text[i] - 'a'];
        else if (text[i] >= 'A' && text[i] <= 'Z')
            text[i] = reverseSubstitution[text[i] - 'A'] - 'a' + 'A';
    }
}