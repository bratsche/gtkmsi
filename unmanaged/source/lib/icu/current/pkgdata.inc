GENCCODE_ASSEMBLY_TYPE=-a gcc-mingw-x86
SO=dll
SOBJ=dll
A=a
LIBPREFIX=lib
LIB_EXT_ORDER=48.dll
COMPILE=i686-w64-mingw32-gcc  -DU_ATTRIBUTE_DEPRECATED= -O2 -g -pipe -Wall -fexceptions --param=ssp-buffer-size=4 -mms-bitfields -Wall -ansi -pedantic -Wshadow -Wpointer-arith -Wmissing-prototypes -Wwrite-strings -Wno-long-long -c
LIBFLAGS=-I/usr/i686-w64-mingw32/sys-root/mingw/include -DPIC 
GENLIB=i686-w64-mingw32-gcc -O2 -g -pipe -Wall -fexceptions --param=ssp-buffer-size=4 -mms-bitfields -Wall -ansi -pedantic -Wshadow -Wpointer-arith -Wmissing-prototypes -Wwrite-strings -Wno-long-long -Wl,--exclude-libs=libintl.a -Wl,--exclude-libs=libiconv.a -Wl,--no-keep-memory  -shared -Wl,--enable-auto-import -Wl,--out-implib=all.a
LDICUDTFLAGS=
LD_SONAME=
RPATH_FLAGS=
BIR_LDFLAGS=-Wl,-Bsymbolic
AR=/usr/bin/i686-w64-mingw32-ar
ARFLAGS=r
RANLIB=/usr/bin/i686-w64-mingw32-ranlib
INSTALL_CMD=/usr/bin/install -c
