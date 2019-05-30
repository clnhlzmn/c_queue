

#include <stdio.h>
#include <assert.h>
#include "queue.h"

#undef QUEUE_INDEX_T
#define QUEUE_INDEX_T int
QUEUE(test, int, 2)

int main() {
    struct queue_test q;
    queue_test_init(&q);
    int i = 42;
    assert(queue_test_pop(&q, &i) != 0);
    assert(i == 42);
    assert(queue_test_push(&q, &i) == 0);
    assert(i == 42);
    i++;
    assert(queue_test_push(&q, &i) != 0);
    assert(i == 43);
    i = 0;
    assert(queue_test_pop(&q, &i) == 0);
    assert(i == 42);
    assert(queue_test_pop(&q, &i) != 0);
    printf("success");
    return 0;
}
