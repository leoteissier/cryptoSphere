void substitution_cipher(char text[], char substitution[]) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z')
            text[i] = substitution[text[i] - 'a'];
        else if (text[i] >= 'A' && text[i] <= 'Z')
            text[i] = substitution[text[i] - 'A'] - 'a' + 'A';
    }
}