cmake_minimum_required(VERSION 3.26)
project(encryptionAndDecryption C)

set(CMAKE_C_STANDARD 23)

add_executable(encryptionAndDecryption main.c
        caesar/caesar_cipher.c
        caesar/caesar_decipher.c
        vigenere/vigenere_cipher.c
        vigenere/vigenere_decipher.c
        substitution/substitution_cipher.c
        substitution/substitution_decipher.c
        xor/xor_cipher.c
        rail_fence/rail_fence_cipher.c
        rail_fence/rail_fence_decipher.c
        caesar/caesar.h
        rail_fence/rail_fence.h
        substitution/substitution.h
        vigenere/vigenere.h
        xor/xor.h
        functions/functions.c
        encryption.h
        constants.h
        functions/functions.h
        aes/aes_cipher.c
        aes/aes_decipher.c
        aes/aes.h
)
