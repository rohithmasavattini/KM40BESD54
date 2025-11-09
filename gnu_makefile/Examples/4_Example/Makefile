all:main

main:main.o add/add.o sub/sub.o
	gcc main.o add/add.o sub/sub.o -o main
main.o:main.c
	gcc -c main.c
add/add.o:
	make -C add
sub/sub.o:
	make -C sub
clean:
	rm *.o main
	make -C add clean
	make -C sub clean
install:
	sudo cp main /usr/bin

