#ifndef SERVER_H
#define SERVER_H

#include "queues.h" // Include queues.h for queue structure

// Declare functions for server operations
void initialize_queues();
void* charA_thread(void* arg);
void* charE_thread(void* arg);
void* charI_thread(void* arg);
void* charO_thread(void* arg);
void* charU_thread(void* arg);
void* count_thread(void* arg);
void communicate_with_helper(const char* encoded_data, char* decoded_data);

#endif // SERVER_H
