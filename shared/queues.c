#include "queues.h"
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>

// Function to initialize the queue
void init_queue(Queue* q) {
    q->front = -1;
    q->rear = -1;
    pthread_mutex_init(&q->mutex, NULL);  // Initialize the mutex
    pthread_cond_init(&q->cond, NULL);    // Initialize the condition variable
}

// Check if the queue is empty
int is_queue_empty(Queue* q) {
    return q->front == -1;
}

// Check if the queue is full
int is_queue_full(Queue* q) {
    return (q->rear + 1) % QUEUE_SIZE == q->front;
}

// Enqueue an item into the queue
void enqueue(Queue* q, const char* item) {
    pthread_mutex_lock(&q->mutex);

    // Wait if the queue is full
    while (is_queue_full(q)) {
        pthread_cond_wait(&q->cond, &q->mutex);
    }

    // Insert item at the rear of the queue
    if (is_queue_empty(q)) {
        q->front = 0;  // If queue is empty, set the front to 0
    }
    q->rear = (q->rear + 1) % QUEUE_SIZE;
    strcpy(q->data[q->rear], item);

    // Signal that the queue has an item available
    pthread_cond_signal(&q->cond);

    pthread_mutex_unlock(&q->mutex);
}

// Dequeue an item from the queue
void dequeue(Queue* q, char* item) {
    pthread_mutex_lock(&q->mutex);

    // Wait if the queue is empty
    while (is_queue_empty(q)) {
        pthread_cond_wait(&q->cond, &q->mutex);
    }

    //
