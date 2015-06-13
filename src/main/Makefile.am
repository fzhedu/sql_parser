AM_CPPFLAGS= -fPIC \
-I/usr/local/include

AM_LDFLAGS= -lc -lm -lrt -lxs  -lglog -lgflags -lpthread 

#include_HEADERS = m_test.h
				
bin_PROGRAMS = parser 

parser_SOURCES = main.cpp			

parser_LDADD =       \
				../parser/lib_parser.a	 \
				../astnode/lib_astnode.a	\
				../common/lib_myglog.a		\
				/usr/local/lib/libgflags.a	\
				/usr/local/lib/libgflags.so	\
				/usr/local/lib/libglog.a	\
				/usr/local/lib/libglog.so	