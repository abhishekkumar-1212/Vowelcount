#ifndef SERVER_H
#define SERVER_H

#include "queues.h"  // Include queue header for queue-related operations

// Function to initialize the queues for different vowel characters
void initialize_queues();

// Thread function prototypes for processing each vowel and 'count' thread
void* charA_thread(void* arg);
void* charE_thread(void* arg);
void* charI_thread(void* arg);
void* charO_thread(void* arg);
void* charU_thread(void* arg);
void* count_thread(void* arg);

// Function to communicate with the helper module for data encoding/decoding
void communicate_with_helper(const char *encoded_data, char *decoded_data);

#endif // SERVER_H
