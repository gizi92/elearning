#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

#define QUEUE_EMPTY INT_MIN

typedef struct myq queue; // opaque data type

queue* q_create(int max_size);
bool q_empty(queue *q);
bool q_full(queue *q);
void q_destroy(queue *q);
bool q_enqueue(queue *q, int value);
int q_dequeue(queue *q);

#endif