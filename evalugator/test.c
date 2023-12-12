#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>
#include <stdio.h>
#include <sys/time.h>

#include "mock.h"
#include "../source/headers/assessment.h"

void test_record_reading(void **state) {
    struct reading *read = record_reading(read_sensor() / 100.0);
    assert_float_equal(read->value, 3.14, 0.0);
    assert_string_equal(read->tx_id, "a");
    assert_null(read->next);
}

void test_reading_size(void **state) {
    assert_int_equal(sizeof(struct reading), 80);
}

void test_free_readings(void **state) {
    struct reading *read = record_reading(read_sensor() / 100.0);
    assert_int_equal(free_readings(read), 0);
}

void populate_buffer(int size) {
    int num_of_readings = 0;
    struct reading *first_reading;
    struct reading *last_reading;
    while(num_of_readings < 10) {
        if(num_of_readings < 1) {
            first_reading = record_reading(read_sensor() / 100.0);
            last_reading = first_reading;
        } else {
            last_reading->next = record_reading(read_sensor() / 100.0);
            last_reading = last_reading->next;
        }
        read_to_buffer(last_reading);
        num_of_readings++;
    }
}

void test_push_to_buffer(void **state) {
    populate_buffer(10);
    assert_int_equal(report_buffer_size(), 10);
}

void test_read_from_buffer(void **state) {
    populate_buffer(10);
    int readings = report_buffer_size();
    while(readings > 0) {
        struct reading *read = read_from_buffer();
        readings = report_buffer_size();
    }
    assert_int_equal(readings, 0);
}

int main(int argc, char *argv[]) {
    void *state;
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_record_reading),
        cmocka_unit_test(test_reading_size),
	    cmocka_unit_test(test_free_readings),
        cmocka_unit_test(test_push_to_buffer),
        cmocka_unit_test(test_read_from_buffer)
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
