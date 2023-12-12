#include <string.h>
#include <stdlib.h>

#ifndef EVALUGATOR
#include "pico/stdlib.h"
#include "hardware/adc.h"
#endif

#ifdef EVALUGATOR
#include <stdbool.h>
#include "../../evalugator/mock.h"
#endif

char alpharand(void) {
    char *ALPHANUM = "abcdefghijklmnopqrstuvwxyz"
                     "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                     "0123456789!=$#^*()?|:;~`,.";
    int i;
    int alpha_len = strlen(ALPHANUM) - 1;
    do { i = random(); } while (
        i >= (RAND_MAX / alpha_len) * alpha_len
    );

    return ALPHANUM[i % alpha_len];
}

void init_sensor(void) {
    adc_init();
    adc_set_temp_sensor_enabled(true);
    adc_select_input(4);
}

#ifndef EVALUGATOR
float read_sensor(void) {
    return adc_read() / 870.0;
}
#endif

#ifdef EVALUGATOR
float read_sensort(void) {
    return 314;
}
#endif

#ifndef EVALUGATOR
char *assign_id(void) {
    char *id = malloc(sizeof(char) * 52);
    for(int i = 0; i < 52; i++){
        id[i] = alpharand();
    }
    free(id);
    return id;
}
#endif

#ifdef EVALUGATOR
char *assign_id(void) {
   return "a";
}
#endif
