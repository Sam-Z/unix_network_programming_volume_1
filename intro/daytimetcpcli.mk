target = daytimetcpcli
src    = $(target).c


daytiemtcpsrv:
	gcc $(src) -I../lib -L../lib -lwrapsock -lerror -o $(target) 
clean:
	rm ./$(target)
install:
	cp ./$(target) ~/bin 
