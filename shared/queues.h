#ifndef QUEUES_H
#define QUEUES_H

#include <pthread.h>

// Define the maximum size of the queue
#define QUEUE_SIZE 5

// Queue structure with a mutex and condition variable for synchronization
typedef struct {
    char data[QUEUE_SIZE][1024];  // Queue to store strings (maximum length 1024)
    int front;
    int rear;
    pthread_mutex_t mutex;        // Mutex for thread safety
    pthread_cond_t cond;          // Condition variable for synchronization
} Queue;

// Function declarations
void init_queue(Queue* q);
int is_queue_empty(Queue* q);
int is_queue_full(Queue* q);
void enqueue(Queue* q, const char* item);
void dequeue(Queue* q, char* item);

#endif // QUEUES_H
