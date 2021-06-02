#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

#define QUEUE_EMPTY INT_MIN

typedef struct 
{
    int *values;
    int head, tail, num_entries, size;
} queue;

queue* q_create(int max_size)
{
    queue *q = malloc(sizeof(queue));
    q->size = max_size;
    q->values = malloc(sizeof(int) * q->size);
    q->num_entries = 0;  //we're empty
    q->head = 0;
    q->tail = 0;
    return q;
}

void init_queue(queue *q, int max_size)
{
    q->size = max_size;
    q->values = malloc(sizeof(int) * q->size);
    q->num_entries = 0; // we're empty
    q->head = 0;
    q->tail = 0;
}

bool queue_empty(queue *q)
{
    if (q == NULL)
        return false;
    return (q->num_entries == 0);
}

bool queue_full(queue *q)
{
    if (q == NULL)
        return true;
    return (q->num_entries == q->size);
}

void queue_destroy(queue *q)
{
    free(q->values);
    free(q);
}

bool enqueue(queue *q, int value)
{
    if(queue_full(q))
        return false;
    
    q->values[q->tail] = value;
    q->num_entries++;
    q->tail = (q->tail + 1) % q->size;
    if (q->tail >= q->size)
        q->tail = 0;
    
    return true;
}

int dequeue(queue *q)
{
    int result;
    if(queue_empty(q))
        return QUEUE_EMPTY;

    result = q->values[q->head];
    q->num_entries --;
    q->head = (q->head + 1) % q->size;
    
    return result;
}

int main(void)
{
    queue q;
    init_queue(&q, 5);

    enqueue(&q, 56);
    enqueue(&q, 12);
    enqueue(&q, 78);
    enqueue(&q, 113);
    enqueue(&q, 1263);
    enqueue(&q, 5);

    int t;
    while((t = dequeue(&q)) != QUEUE_EMPTY)
    {
        printf("t = %d\n", t);
    }
}