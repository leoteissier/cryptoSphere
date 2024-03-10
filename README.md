# Cipher Program

Ce programme permet de chiffrer et déchiffrer du texte en utilisant une variété de méthodes de chiffrement classiques.

## Fonctionnement

1. Le programme demande à l'utilisateur de choisir entre le chiffrement et le déchiffrement.
2. Il demande ensuite à l'utilisateur de sélectionner le type de chiffrement à utiliser.
3. Le programme prend la texte à chiffrer ou à déchiffrer en entrée.
4. Il applique la méthode de chiffrement choisie avec la clé correspondante.
5. Le programme affiche le texte chiffré ou déchiffré en sortie.

## Chiffrements pris en charge

* Chiffre de César
* Chiffre de Vigenère
* Chiffre de substitution
* Chiffre XOR
* Chiffre de rail fence

## Compilation et exécution

### Requis

* Un compilateur C (comme GCC)

### Instructions

1. Ouvrez un terminal dans le répertoire du projet.
2. Compilez le code avec la commande :

   ```bash
   gcc -o cipher main.c caesar/caesar.c vigenere/vigenere.c substitution/substitution.c xor/xor.c rail_fence/rail_fence.c functions/functions.c
    ```
3. Exécutez le programme avec la commande :

   ```bash
   ./cipher
   ```
4. Suivez les instructions à l'écran pour chiffrer ou déchiffrer du texte.

## Informations complémentaires
Les clés à utiliser pour chaque chiffrement sont précisées au moment de l'exécution.
Le programme utilise la bibliothèque standard C.
Il respecte les bonnes pratiques de codage C.