# cpp_parser
sql parser in c++

Install cpp_parser:
1. please read the README file in third_party.
2. ./build.sh init
3. ./configure --prefix=/your/path/to/install
4. make
5. make install

Uninstall cpp_parser:
1. make distclean
2. ./build clean

parse sql:
bison -d sql.ypp
flex sql.l
