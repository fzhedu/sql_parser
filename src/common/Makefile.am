AM_CPPFLAGS= -fPIC \
-I/usr/local/include

AM_LDFLAGS=-lc -lm -lrt -lglog -lgflags -lpthread -ll -ly

LDADD =		\
			/usr/local/lib/libgflags.a	\
			/usr/local/lib/libgflags.so	\
			/usr/local/lib/libglog.a	\
			/usr/local/lib/libglog.so	


noinst_LIBRARIES=lib_logging.a
lib_logging_a_SOURCES = \
	logging.cpp			logging.h 