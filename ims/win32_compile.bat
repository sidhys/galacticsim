g++ -D imsexport -c ims.cpp
g++ -shared -o ims.dll ims.o -Wl,--out-implib,libshared_dll.lib