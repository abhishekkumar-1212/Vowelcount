#ifndef CLIENT_H
#define CLIENT_H

// Function declarations for client-side operations
void send_data_to_server(const char* data, const char* server_ip, int server_port);
void receive_data_from_server(char* buffer, const char* server_ip, int server_port);

#endif // CLIENT_H
