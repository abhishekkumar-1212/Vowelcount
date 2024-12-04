#ifndef CLIENT_UTILS_H
#define CLIENT_UTILS_H

// Function to read input file into buffer
void read_input_file(const char *filename, char *buffer);

// Function to communicate with the helper for encoding
void communicate_with_helper(const char *input_data, char *encoded_data);

// Function to communicate with the server for results
void communicate_with_server(const char *encoded_data, char *server_response);

#endif // CLIENT_UTILS_H

// completed