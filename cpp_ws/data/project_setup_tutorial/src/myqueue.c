
#include "myqueue.h"


typedef struct myq
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

bool q_empty(queue *q)
{
    if (q == NULL)
        return false;
    return (q->num_entries == 0);
}

bool q_full(queue *q)
{
    if (q == NULL)
        return true;
    return (q->num_entries == q->size);
}

void q_destroy(queue *q)
{
    free(q->values);
    free(q);
}

bool q_enqueue(queue *q, int value)
{
    if(q_full(q))
        return false;
    
    q->values[q->tail] = value;
    q->num_entries++;
    q->tail = (q->tail + 1) % q->size;
    if (q->tail >= q->size)
        q->tail = 0;
    
    return true;
}

int q_dequeue(queue *q)
{
    int result;
    if(q_empty(q))
        return QUEUE_EMPTY;

    result = q->values[q->head];
    q->num_entries --;
    q->head = (q->head + 1) % q->size;
    
    return result;
}