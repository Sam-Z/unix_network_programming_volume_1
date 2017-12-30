
libwrapsock.so:
	gcc wrapsock.c -shared -fPIC -o libwrapsock.so
clean:
	rm libwrapsock.so
install:
	cp ./libwrapsock.so ~/lib
