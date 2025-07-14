run_main: build ./build/main.exe
	./build/main.exe

./build/main.exe: ./build/main.o ./build/island.o ./build/node.o
	gcc ./build/main.o ./build/island.o ./build/node.o -o ./build/main.exe

./build/main.o: ./main.c
	gcc -Wall -g -c ./main.c -o ./build/main.o

./build/island.o: ./island.c
	gcc -Wall -g -c ./island.c -o ./build/island.o

./build/node.o: ./node.c
	gcc -Wall -g -c ./node.c -o ./build/node.o

build:
	mkdir -p build

clean:
	rm -rf build
