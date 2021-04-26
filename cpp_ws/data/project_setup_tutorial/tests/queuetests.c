#include <criterion/criterion.h>

#include "../src/myqueue.h"

queue *q = NULL;

void suite_setup(void)
{
    q = q_create(1);
}

void suite_teardown(void)
{
    q_destroy(q);
}

TestSuite(QueueTests, .init=suite_setup, .fini=suite_teardown);

Test(QueueTests, CreateQueue)
{
    cr_expect(q != NULL, "q_create should not return NULL.");
}

Test(QueueTests, EnqueueElementsInEmptyQueue)
{
    cr_expect(q_enqueue(q, 1), "Expected q_enqueue to succeed.");  
}

Test(QueueTests, EnqueueElementsInFullQueue)
{
    cr_expect(q_enqueue(q, 1), "Expected q_enqueue to succeed.");
    cr_expect(q_enqueue(q, 2) == false, "Expected q_enqueue to fail."); 
}

Test(QueueTests, DequeueElementsFromEmptyQueue)
{
    cr_expect(q_dequeue(q) != QUEUE_EMPTY, "Expected q_dequeue to fail.");  
}