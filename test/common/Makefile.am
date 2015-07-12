AM_CPPFLAGS= -fPIC \
-I/usr/local/include

AM_LDFLAGS=-lc -lm -lrt -lglog  -lpthread

LDADD =		\
			/usr/local/lib/libglog.a	\
			/usr/local/lib/libglog.so	

noinst_LIBRARIES=lib_test_logging.a

lib_test_logging_a_SOURCES = \
	logging_test.cpp