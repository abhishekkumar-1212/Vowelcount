#ifndef SERVER_UTILS_H
#define SERVER_UTILS_H

// Function to start the server
void start_server(const char* ip, int port);

// Function to handle a client connection
void handle_client_connection(int client_socket);

#endif // SERVER_UTILS_H
