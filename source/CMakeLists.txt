file(GLOB FILES *.c *.h)

if(EVALUGATOR)

  add_library(assessment
    ${FILES}
  )
  target_compile_definitions(assessment PUBLIC -D EVALUGATOR)
  target_link_libraries(assessment evalugator)

else()

    add_executable(assessment
        data/sensor.c
        assessment.c
    )

    target_link_libraries(assessment
        pico_stdlib
        pico_multicore
        pico_cyw43_arch_none
        hardware_adc
    )

    pico_add_extra_outputs(assessment)

    pico_enable_stdio_usb(assessment 1)
    pico_enable_stdio_uart(assessment 1)

endif(EVALUGATOR)
