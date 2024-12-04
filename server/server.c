#include "server.h"
#include "queues.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Declare global variables for queues and counters
Queue charA_queue, charE_queue, charI_queue, charO_queue, charU_queue;
int count[5] = {0}; // To store counts for a, e, i, o, u

// Function to initialize the queues
void initialize_queues() {
    init_queue(&charA_queue);
    init_queue(&charE_queue);
    init_queue(&charI_queue);
    init_queue(&charO_queue);
    init_queue(&charU_queue);
}

// Thread function for processing 'a' and 'A'
void* charA_thread(void* arg) {
    char input[BUFFER_SIZE];
    while (1) {
        // Read data from charA_queue and process it
        pthread_mutex_lock(&charA_queue.mutex);
        while (charA_queue.front == -1) {
            pthread_cond_wait(&charA_queue.cond, &charA_queue.mutex);
        }
        // Process the data
        strcpy(input, charA_queue.data[charA_queue.front]);
        charA_queue.front = (charA_queue.front + 1) % QUEUE_SIZE; // Circular queue update
        pthread_mutex_unlock(&charA_queue.mutex);

        // Count occurrences of 'a' and 'A'
        for (int i = 0; input[i] != '\0'; i++) {
            if (input[i] == 'a' || input[i] == 'A') {
                count[0]++;
            }
        }

        // Push the data to charE_queue for further processing
        pthread_mutex_lock(&charE_queue.mutex);
        charE_queue.rear = (charE_queue.rear + 1) % QUEUE_SIZE;
        strcpy(charE_queue.data[charE_queue.rear], input);
        if (charE_queue.front == -1) {
            charE_queue.front = 0;
        }
        pthread_cond_signal(&charE_queue.cond);
        pthread_mutex_unlock(&charE_queue.mutex);
    }
    return NULL;
}

// Thread function for processing 'e' and 'E'
void* charE_thread(void* arg) {
    char input[BUFFER_SIZE];
    while (1) {
        // Read data from charE_queue and process it
        pthread_mutex_lock(&charE_queue.mutex);
        while (charE_queue.front == -1) {
            pthread_cond_wait(&charE_queue.cond, &charE_queue.mutex);
        }
        strcpy(input, charE_queue.data[charE_queue.front]);
        charE_queue.front = (charE_queue.front + 1) % QUEUE_SIZE;
        pthread_mutex_unlock(&charE_queue.mutex);

        // Count occurrences of 'e' and 'E'
        for (int i = 0; input[i] != '\0'; i++) {
            if (input[i] == 'e' || input[i] == 'E') {
                count[1]++;
            }
        }

        // Push the data to charI_queue for further processing
        pthread_mutex_lock(&charI_queue.mutex);
        charI_queue.rear = (charI_queue.rear + 1) % QUEUE_SIZE;
        strcpy(charI_queue.data[charI_queue.rear], input);
        if (charI_queue.front == -1) {
            charI_queue.front = 0;
        }
        pthread_cond_signal(&charI_queue.cond);
        pthread_mutex_unlock(&charI_queue.mutex);
    }
    return NULL;
}

// Thread function for processing 'i' and 'I'
void* charI_thread(void* arg) {
    char input[BUFFER_SIZE];
    while (1) {
        // Read data from charI_queue and process it
        pthread_mutex_lock(&charI_queue.mutex);
        while (charI_queue.front == -1) {
            pthread_cond_wait(&charI_queue.cond, &charI_queue.mutex);
        }
        strcpy(input, charI_queue.data[charI_queue.front]);
        charI_queue.front = (charI_queue.front + 1) % QUEUE_SIZE;
        pthread_mutex_unlock(&charI_queue.mutex);

        // Count occurrences of 'i' and 'I'
        for (int i = 0; input[i] != '\0'; i++) {
            if (input[i] == 'i' || input[i] == 'I') {
                count[2]++;
            }
        }

        // Push the data to charO_queue for further processing
        pthread_mutex_lock(&charO_queue.mutex);
        charO_queue.rear = (charO_queue.rear + 1) % QUEUE_SIZE;
        strcpy(charO_queue.data[charO_queue.rear], input);
        if (charO_queue.front == -1) {
            charO_queue.front = 0;
        }
        pthread_cond_signal(&charO_queue.cond);
        pthread_mutex_unlock(&charO_queue.mutex);
    }
    return NULL;
}

// Thread function for processing 'o' and 'O'
void* charO_thread(void* arg) {
    char input[BUFFER_SIZE];
    while (1) {
        // Read data from charO_queue and process it
        pthread_mutex_lock(&charO_queue.mutex);
        while (charO_queue.front == -1) {
            pthread_cond_wait(&charO_queue.cond, &charO_queue.mutex);
        }
        strcpy(input, charO_queue.data[charO_queue.front]);
        charO_queue.front = (charO_queue.front + 1) % QUEUE_SIZE;
        pthread_mutex_unlock(&charO_queue.mutex);

        // Count occurrences of 'o' and 'O'
        for (int i = 0; input[i] != '\0'; i++) {
            if (input[i] == 'o' || input[i] == 'O') {
                count[3]++;
            }
        }

        // Push the data to charU_queue for further processing
        pthread_mutex_lock(&charU_queue.mutex);
        charU_queue.rear = (charU_queue.rear + 1) % QUEUE_SIZE;
        strcpy(charU_queue.data[charU_queue.rear], input);
        if (charU_queue.front == -1) {
            charU_queue.front = 0;
        }
        pthread_cond_signal(&charU_queue.cond);
        pthread_mutex_unlock(&charU_queue.mutex);
    }
    return NULL;
}

// Thread function for processing 'u' and 'U'
void* charU_thread(void* arg) {
    char input[BUFFER_SIZE];
    while (1) {
        // Read data from charU_queue and process it
        pthread_mutex_lock(&charU_queue.mutex);
        while (charU_queue.front == -1) {
            pthread_cond_wait(&charU_queue.cond, &charU_queue.mutex);
        }
        strcpy(input, charU_queue.data[charU_queue.front]);
        charU_queue.front = (charU_queue.front + 1) % QUEUE_SIZE;
        pthread_mutex_unlock(&charU_queue.mutex);

        // Count occurrences of 'u' and 'U'
        for (int i = 0; input[i] != '\0'; i++) {
            if (input[i] == 'u' || input[i] == 'U') {
                count[4]++;
            }
        }
    }
    return NULL;
}

// Thread function to collect counts from all threads and write to a file
void* count_thread(void* arg) {
    while (1) {
        sleep(1); // Simulate waiting for threads to update counts

        // Write the counts to the file
        FILE *file = fopen("receivedVowelCount.txt", "w");
        if (file) {
            fprintf(file, "aA: %d\n", count[0]);
            fprintf(file, "eE: %d\n", count[1]);
            fprintf(file, "iI: %d\n", count[2]);
            fprintf(file, "oO: %d\n", count[3]);
            fprintf(file, "uU: %d\n", count[4]);
            fclose(file);
        } else {
            perror("Error opening file to write counts");
        }
    }
    return NULL;
}

// Function to communicate with the helper and send/receive data
void communicate_with_helper(const char *encoded_data, char *decoded_data) {
    // Placeholder for future helper communication, if necessary
}

// Main function to run the server
int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP> <PORT>\n", argv[0]);
        exit(1);
    }

    // Initialize queues and counters
    initialize_queues();

    // Create threads for processing vowels and counts
    pthread_t threads[6];
    pthread_create(&threads[0], NULL, charA_thread, NULL);
    pthread_create(&threads[1], NULL, charE_thread, NULL);
    pthread_create(&threads[2], NULL, charI_thread, NULL);
    pthread_create(&threads[3], NULL, charO_thread, NULL);
    pthread_create(&threads[4], NULL, charU_thread, NULL);
    pthread_create(&threads[5], NULL, count_thread, NULL);

    // Start the server, handle incoming data, and enqueue it (simulated here)
    // In a real scenario, you would receive data from a client and enqueue it
    char test_input[BUFFER_SIZE] = "This is a test sentence with vowels.";
    enqueue(&charA_queue, test_input);  // Simulate putting data into the first queue

    // Wait for threads to finish (in a real server, this would be done differently)
    for (int i = 0; i < 6; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
