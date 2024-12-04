#ifndef QUEUES_H
#define QUEUES_H

#include <pthread.h>
#include <stdbool.h>

#define QUEUE_SIZE 5
#define MAX_STRING_LENGTH 256

typedef struct {
    char *data[QUEUE_SIZE];      // Array of strings (pointers to strings)
    int head;                    // Index of the front of the queue
    int tail;                    // Index of the back of the queue
    int count;                   // Number of elements in the queue
    pthread_mutex_t lock;        // Mutex for thread safety
    pthread_cond_t not_empty;    // Condition variable for "queue not empty"
    pthread_cond_t not_full;     // Condition variable for "queue not full"
} Queue;

// Function declarations for queue operations
void initQueue(Queue *queue);
void enqueue(Queue *queue, const char *item);
char *dequeue(Queue *queue);
bool isQueueEmpty(Queue *queue);
bool isQueueFull(Queue *queue);
void destroyQueue(Queue *queue);

#endif
