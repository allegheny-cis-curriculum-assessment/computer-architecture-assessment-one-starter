file(GLOB FILES *.c *.h)

add_executable(evalugator ${FILES})

target_link_libraries(evalugator PRIVATE cmocka assessment)

set_target_properties(
    evalugator
    PROPERTIES
        OUTPUT_NAME evalugator.assessment.test
        SUFFIX ".bin"
)

#target_compile_options(evalugator PRIVATE -e entry)
