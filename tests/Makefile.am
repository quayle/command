AUTOMAKE_OPTIONS = subdir-objects

TESTS = \
	descriptive_holds_data.test \
	callable_invokes_provided_function.test \
	parameter_is_descriptive.test \
	argument_handles_string_value.test

noinst_PROGRAMS = $(TESTS)

AM_CXXFLAGS = -O3 -I$(top_srcdir)/include -std=c++11

descriptive_holds_data_test_SOURCES  = descriptive/holds_data.cpp
callable_invokes_provided_function_test_SOURCES  = callable/invokes_provided_function.cpp
parameter_is_descriptive_test_SOURCES  = parameter/is_descriptive.cpp
argument_handles_string_value_test_SOURCES  = argument/handles_string_value.cpp
