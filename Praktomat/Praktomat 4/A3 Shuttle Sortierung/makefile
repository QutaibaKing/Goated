run_main: build ./build/shuttle_sort
	./build/shuttle_sort

./build/shuttle_sort: ./build/main.o ./build/shuttle.o
	gcc ./build/main.o ./build/shuttle.o -o ./build/shuttle_sort

./build/main.o: ./main.c ./shuttle.h
	gcc -Wall -g -c ./main.c -o ./build/main.o

./build/shuttle.o: ./shuttle.c ./shuttle.h
	gcc -Wall -g -c ./shuttle.c -o ./build/shuttle.o

build:
	mkdir -p build

clean:
	rm -rf build

