#include <sys/time.h>
#include "../data/sensor.c"

struct reading {
    char tx_id[52];
    float value;
    struct timeval time_now;
    struct reading *next;
};

struct reading *record_reading(float);
unsigned int free_readings(struct reading *);
void read_to_buffer(struct reading *);
struct reading *read_from_buffer(void);

char *__StackLimit = "264000";
char *__bss_end__ = "11";

unsigned int buffer[100];
int value_counter = 0;
int buff_counter = 0;

void stdio_init_all(void) {
   // Nothing
}

int adc_read(void) {
   return 314;
}

void adc_select_input(int value) {
    // Nothing
}

void adc_set_temp_sensor_enabled(bool is_enabled) {
    // Nothing
}

void irq_set_enabled(int proc, bool is_enabled) {
   // Nothing
}

void irq_set_exclusive_handler(int proc, void *pointer) {
   // Nothing
}

void multicore_fifo_push_blocking(unsigned int value) {
    value_counter++;
    buffer[value_counter] = value;
}

intptr_t multicore_fifo_pop_blocking(void) {
   unsigned int current_value = buffer[buff_counter];
   buff_counter++;
   value_counter--;
   return current_value;
}

bool multicore_fifo_rvalid(void) {
   if(value_counter > 0) {
   	return true;
   }
   return false;
}

void multicore_fifo_clear_irq(void) {
   // Nothing
}

void multicore_launch_core1(void *pointer) {
   // Nothing
}

void adc_init() {
    // Nothing
}

void tight_loop_contents(void) {
   // Nothing
}

int report_buffer_size(void) {
    return value_counter;
}

int read_sensor(void) {
    return adc_read();
}
