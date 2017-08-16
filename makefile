all: run execute clean

run: project1.c
     gcc project1.c -o project1
	 
execute: project1.c
	./project1
	
clean: project1.c
	rm project1