# Use test/tests.cmake to add tests

macro(ktrl_add_test)
    list(APPEND KTRL_TEST_TARGETS ${ARGV0})
endmacro(ktrl_add_test)

include(tests.cmake)

foreach(KTRL_TEST_TARGET ${KTRL_TEST_TARGETS})
    add_executable(${KTRL_TEST_TARGET} write_to_uinput.cpp)
    target_link_libraries(${KTRL_TEST_TARGET} PRIVATE ktrl)
    add_test(${KTRL_TEST_TARGET}_test ${KTRL_TEST_TARGET})
endforeach()
