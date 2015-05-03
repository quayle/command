AUTOMAKE_OPTIONS = subdir-objects

TESTS = \
	descriptive_holds_data.test \
	callable_invokes_provided_function.test \
	callable_invokes_void_function.test \
	parameter_is_descriptive.test \
	argument_handles_string_value.test \
	argument_handles_int_value.test \
	argument_handles_negative_int_value.test \
	argument_handles_float_value.test \
	argument_handles_negative_float_value.test \
	argument_handles_boolean_value.test \
	option_handles_string_value.test \
	option_handles_boolean_value.test \
	option_handles_float_value.test

noinst_PROGRAMS = $(TESTS)

AM_CXXFLAGS = -I$(top_srcdir)/include -std=c++11

descriptive_holds_data_test_SOURCES  = descriptive/holds_data.cpp

callable_invokes_provided_function_test_SOURCES  = callable/invokes_provided_function.cpp
callable_invokes_void_function_test_SOURCES  = callable/invokes_void_function.cpp

parameter_is_descriptive_test_SOURCES  = parameter/is_descriptive.cpp

argument_handles_string_value_test_SOURCES  = argument/handles_string_value.cpp
argument_handles_int_value_test_SOURCES  = argument/handles_int_value.cpp
argument_handles_negative_int_value_test_SOURCES  = argument/handles_negative_int_value.cpp
argument_handles_float_value_test_SOURCES  = argument/handles_float_value.cpp
argument_handles_negative_float_value_test_SOURCES  = argument/handles_negative_float_value.cpp
argument_handles_boolean_value_test_SOURCES  = argument/handles_boolean_value.cpp

option_handles_string_value_test_SOURCES  = option/handles_string_value.cpp
option_handles_boolean_value_test_SOURCES  = option/handles_boolean_value.cpp
option_handles_float_value_test_SOURCES  = option/handles_float_value.cpp
