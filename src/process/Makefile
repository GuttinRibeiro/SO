make:
	gcc lib/lib_so.c -c
	mv lib_so.o lib/
	mkdir bin
	gcc lib/lib_so.o file_generator.c -Wall -o bin/file_generator
	gcc lib/lib_so.o bubble_sort.c -Wall -o bin/bubble_sort
	gcc lib/lib_so.o selection_sort.c -Wall -o bin/selection_sort
	gcc lib/lib_so.o control.c -Wall -o bin/control
run:
	./bin/control
