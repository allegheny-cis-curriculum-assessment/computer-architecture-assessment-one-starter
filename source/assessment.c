#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

#ifndef EVALUGATOR
#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "hardware/irq.h"
#endif

#ifdef EVALUGATOR
#include <stdbool.h>
#include "../evalugator/mock.h"
#endif

#include "headers/heap.h"
#include "headers/timing.h"

extern void init_sensor(void);
extern float read_sensor(void);
extern char *assign_id(void);

/*

Introduction: Read This First!

A power company distributes physical meter hardware that monitors and 
calculates statistics about customers' of electricity for a given 
property. However, the particular model chosen exhibits two clear drawbacks:

    - units quit reporting data after a short amount of time and need to be 
      manually reset
    - even when working properly, the calculations that the device provides 
      are slow by an order of magnitude, causing issues in real-time collection

Given the device and code used in the production models, your task is to 
identify and implement fixes which address the two major areas of concern.

You will apply fixes to the code below keeping two tasks in mind:

    - implementing memory management to solve the first problem in
      the problem statement above
    - using the two-core structure to achieve a performant average
      of all readings taken since device start up (run time should last
      for test duration of 6000 readings)

*/

/*
    Part 1

    Instructions:

    - Complete the struct below to create one named "reading":
      - a char called "tx_id" with a potential size of 52 bytes
      - a float called "value"
      - a pointer struct (of reading type) called "next"

*/

/*

    TODO: Implement struct according to guidelines above

*/

/*
    Part 2

    Instructions:

    - Complete a function called "record_reading" which:
      - creates a struct of the appropriate type called "data"
      - accepts a float called "reading" as a parameter, stored in a 
        field called "value"
      - contains a struct pointer to another reading struct called "next"

*/

struct reading *record_reading(float reading) {
    /* 
        TODO: Allocate space for struct on the heap 
    */
    // Set value of tx_id field
    strcpy(data->tx_id, assign_id());
    /*
        TODO: Set values according to guidelines above
    */
    // Return completed data point
    return data;
}

/*
    Part 3

    Instructions:

    - Complete a function called "free_readings" which frees a given 
      struct pointer passed to it as a parameter, assuming that this
      is the head node of a linked list
*/

unsigned int free_readings(struct reading *read) {
    /* 
        TODO: Continuing to use the variable identifier "read", free
              memory enough to allow continuous reads from the data
              set
    */
    return (unsigned int)read;
}

/*
    Part 4

    Instructions:

    - Complete the following function to read from entries on the inter-core
      buffer, casting them using the appropriate struct
*/

struct reading *read_from_buffer(void) {
    /* 
        TODO: Return a (struct reading *) cast pointer taken from the inter-core buffer
    */
}

int core1_interrupt_handler(void){
    // Prepare values
    float total_usage = 0;
    uint total_readings = 0;
    // While data is on the buffer, read, perform operations
    while(multicore_fifo_rvalid()){
        // Get struct from address posted to buffer
        struct reading *data = read_from_buffer();
        // Increment readings count
        total_readings++;
        // Retrieve value from data and increment usage
        total_usage += data->value;
        // Print report
        printf("AVERAGE: %f kWs\n", total_usage / total_readings);
    }
    multicore_fifo_clear_irq();
    return total_usage / total_readings;
}

int core1_main(void) {
    multicore_fifo_clear_irq();
    irq_set_exclusive_handler(SIO_IRQ_PROC1, (void *)core1_interrupt_handler);
    irq_set_enabled(SIO_IRQ_PROC1, true);
    while (true && !is_runtime_complete()) {
        tight_loop_contents();
    }
    return 0;
}

/*
    Part 5

    Instructions:

    - Complete the read_to_buffer function, taking in a single parameter of
      the correct struct and pushing the parameter to the inter-core buffer
*/

void read_to_buffer(struct reading *read) {
    /* 
        TODO: Push a reference to the parameter passed to the function on the
              inter-process buffer; don't forget that the buffer only
              accepts unsigned ints!
    */
}

/*
    Part 7

    Instructions:

    - Finish the function below by passing the correct value to the above
      read_to_buffer_function
    - Use the free_readings function defined above to free memory when
      the available heap is less than the size of 10 readings
*/

int core0_main(void) {
    int stored_readings = 0;

    struct reading *first_reading;
    struct reading *last_reading;

    while(stored_readings < 6000){

        if(stored_readings < 1) {
            first_reading = record_reading(read_sensor());
            last_reading = first_reading;
        } else {
            last_reading->next = record_reading(read_sensor());
            last_reading = last_reading->next;
        }

        stored_readings++;

        /*
            TODO: Pass correct value to read_to_buffer
        */

        /*
            TODO: Create conditional statement to free memory
                  according to the instructions above
        */
    }
    return 0;
}

// Do not edit any of the source code below this line {{{

#ifndef EVALUGATOR
int main(void) {
    // Initialize USB communications
    stdio_init_all();
    // Start data collection channel
    init_sensor();
    // Start program timer for limited run
    gettimeofday(&pstart, NULL);
    // Set up core operations to enable parallel processing
    multicore_launch_core1((void *)core1_main);
    core0_main();

    return 0;
}
#endif

// }}}
