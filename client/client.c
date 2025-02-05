#include "client.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

// Function to read the input data from a file
void read_input_file(const char *filename, char *buffer) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening input file");
        exit(1);
    }
    // Read the file into the buffer
    size_t bytesRead = fread(buffer, sizeof(char), BUFFER_SIZE, file);
    if (bytesRead == 0) {
        perror("Error reading input file");
        fclose(file);
        exit(1);
    }
    buffer[bytesRead] = '\0';  // Null terminate the string
    fclose(file);
}

// Function to communicate with the helper for encoding
void communicate_with_helper(const char *input_data, char *encoded_data) {
    // In this function, you would send `input_data` to the helper
    // and receive the encoded data back. This is a placeholder.
    // Assuming the helper encodes the data and returns it in `encoded_data`.
    printf("Communicating with helper to encode data...\n");

    // Example encoding simulation: just copy the input to encoded data for now
    strncpy(encoded_data, input_data, BUFFER_SIZE);
}

// Function to communicate with the server to send encoded data and receive results
void communicate_with_server(const char *encoded_data, char *server_response) {
    // Simulate server communication here. You would need to implement socket
    // communication with the server, send the encoded data, and receive the response.

    printf("Communicating with server...\n");

    // Placeholder: simulate the server response
    // In a real scenario, you would use sockets to send/receive data.
    snprintf(server_response, BUFFER_SIZE, "Received vowel counts: aA=5, eE=3, iI=2, oO=1, uU=4\n");
}

int main() {
    char input_data[BUFFER_SIZE];
    char encoded_data[BUFFER_SIZE];
    char server_response[BUFFER_SIZE];

    // Step 1: Read input file
    read_input_file("input.txt", input_data);

    // Step 2: Communicate with helper for encoding
    communicate_with_helper(input_data, encoded_data);

    // Step 3: Communicate with server to send encoded data and receive the results
    communicate_with_server(encoded_data, server_response);

    // Step 4: Save server response to file
    FILE *output_file = fopen("receivedVowelCount.txt", "w");
    if (output_file) {
        fprintf(output_file, "%s", server_response);
        fclose(output_file);
        printf("Received results saved in receivedVowelCount.txt\n");
    } else {
        perror("Error writing receivedVowelCount.txt");
    }

    return 0;
}
 // completed