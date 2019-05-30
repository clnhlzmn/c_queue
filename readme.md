# A simple generic FIFO queue in C

## features

* works with elements of any type
* overhead of only `2 * sizeof(QUEUE_INDEX_T) + sizeof(element_t)`
* no dynamic allocation
* simple api (init, push, pop)
* interrupt safe with the following conditions
  * one producer thread and one consumer thread
  * atomic read and write of `QUEUE_INDEX_T` (default is `volatile uint8_t`)

## example

    #include "queue.h"

    //define a queue called queue_example 
    //with elements of type int and size 8
    QUEUE(example, int, 8);

    //create an instance of queue_example
    struct queue_example queue;

    //analog to digital converter isr
    void adc_isr(void) {
        int value = get_adc_value();
        if (queue_push(&queue, &value) == 0) {
            //push successful, no action required
        } else {
            //not enough room in queue, handle appropriately here
        }
    }

    int main(void) {
        //initialize the instance
        queue_example_init(&queue);
        while (1) {
            int value;
            if (queue_example_pop(&queue, &value) == 0) {
                //one element removed and stored in value
                printf("%d\r\n", value);
            } else {
                //queue empty
                continue;
            }
        }
    }