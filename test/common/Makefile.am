AM_CPPFLAGS= -fPIC \
-I/usr/local/include

AM_LDFLAGS=-lc -lm -lrt -lglog  -lpthread

LDADD =		\
			/usr/local/lib/libglog.a	\
			/usr/local/lib/libglog.so	

noinst_LIBRARIES=lib_test_myglog.a

lib_test_myglog_a_SOURCES = \
	my_glog_test.cpp