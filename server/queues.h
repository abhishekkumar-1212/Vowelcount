#ifndef QUEUES_H
#define QUEUES_H

#include <pthread.h>

#define QUEUE_SIZE 5
#define BUFFER_SIZE 1024

// Structure to define a queue
typedef struct {
    char data[QUEUE_SIZE][BUFFER_SIZE];  // Array to hold data items
    int front, rear;                     // Indices for front and rear of the queue
    pthread_mutex_t mutex;               // Mutex for thread-safe access
    pthread_cond_t cond;                 // Condition variable for synchronization
} Queue;

// Function prototypes for queue operations
void init_queue(Queue *q);                // Initialize the queue
int is_empty(Queue *q);                   // Check if the queue is empty
int is_full(Queue *q);                    // Check if the queue is full
void enqueue(Queue *q, const char *data); // Add data to the queue
void dequeue(Queue *q, char *data);      // Remove data from the queue

#endif // QUEUES_H
