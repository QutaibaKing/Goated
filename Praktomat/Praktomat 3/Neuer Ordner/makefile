build:
	mkdir build

compile_main: build 
	gcc -o build/main src/main.c src/functions.c src/load.c -lm

run_main: compile_main
	./build/main

clean: 
	rmdir build /s /q