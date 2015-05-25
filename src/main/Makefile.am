AM_CPPFLAGS= -fPIC 

AM_LDFLAGS= -lc -lm -lrt -lxs -lpthread 

#include_HEADERS = m_test.h
				
bin_PROGRAMS = parser 

parser_SOURCES = main.cpp			

parser_LDADD =       \
				../parser/lib_parser.a	 \
				../astnode/lib_astnode.a	
