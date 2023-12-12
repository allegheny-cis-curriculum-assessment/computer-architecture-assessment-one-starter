#include <stdint.h>
#include <stdbool.h>
#include <sys/time.h>

#define SIO_IRQ_PROC1 1

struct reading;
struct timeval;

void stdio_init_all();

void adc_init();
int adc_read();
void adc_select_input(int);
void adc_set_temp_sensor_enabled(bool);

bool multicore_fifo_rvalid();
intptr_t multicore_fifo_pop_blocking();
void multicore_fifo_push_blocking();
void multicore_fifo_clear_irq();
void multicore_launch_core1(void *);

void irq_set_enabled(int, bool);
void irq_set_exclusive_handler(int, void*);
void tight_loop_contents();

int getFreeHeap();
int getTotalHeap();
