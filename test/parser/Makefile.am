AM_CPPFLAGS= -fPIC \
-I/usr/local/include

AM_LDFLAGS=-lc -lm -lrt -lglog -lpthread

LDADD =		\
			/usr/local/lib/libglog.a	\
			/usr/local/lib/libglog.so	
			
noinst_LIBRARIES=lib_test_parser.a

lib_test_parser_a_SOURCES = \
	sql_parser_test.cpp