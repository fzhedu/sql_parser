AM_CPPFLAGS= -fPIC \
-I/usr/local/include

AM_LDFLAGS= -lc -lm -lrt -lxs -lglog  -lpthread

include_HEADERS = main_test.h
				
bin_PROGRAMS = parser_test 

parser_test_SOURCES = main_test.cpp			

parser_test_LDADD =       \
	 ../parser/lib_test_parser.a	\
	 ../../src/parser/lib_parser.a	\
	 ../../src/astnode/lib_astnode.a	\
	 ../../src/common/lib_myglog.a	\
	 /usr/local/lib/libglog.a	\
	 /usr/local/lib/libglog.so	
