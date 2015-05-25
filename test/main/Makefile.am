AM_CPPFLAGS= -fPIC 

AM_LDFLAGS= -lc -lm -lrt -lxs -lpthread

include_HEADERS = main_test.h
				
bin_PROGRAMS = parser_test 

parser_test_SOURCES = main_test.cpp			

parser_test_LDADD =       \
	 ../parser/lib_test_parser.a	\
	 ../../src/parser/lib_parser.a	\
	 ../../src/astnode/lib_astnode.a
