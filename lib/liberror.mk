base = error
target = lib$(base).so
src    = $(base).c


$(target):
	gcc $(src) -shared -fPIC -o $(target)
clean:
	rm $(target)
install:
	cp ./$(target) ~/lib
