#include "helper.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to encode data (just a placeholder, you can implement actual encoding logic)
void encode_data(const char *input, char *encoded_data) {
    int i = 0, j = 0;
    while (input[i] != '\0') {
        // Simple encoding by shifting ASCII values
        encoded_data[j] = input[i] + 1;
        i++;
        j++;
    }
    encoded_data[j] = '\0'; // Null-terminate the encoded string
}

// Function to decode data (reverse of encoding, simple shifting logic)
void decode_data(const char *encoded_data, char *decoded_data) {
    int i = 0, j = 0;
    while (encoded_data[i] != '\0') {
        // Reverse the encoding by shifting ASCII values back
        decoded_data[j] = encoded_data[i] - 1;
        i++;
        j++;
    }
    decoded_data[j] = '\0'; // Null-terminate the decoded string
}

// Function to validate the input data (example of validation, checking if there are vowels)
int validate_input(const char *input) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (strchr("aeiouAEIOU", input[i])) { // Check if the character is a vowel
            return 1; // Valid if it contains vowels
        }
    }
    return 0; // Invalid if no vowels are found
}
