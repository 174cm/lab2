func : main.o add_func.o sub_func.o mul_func.o div_func.o 
	gcc -o func main.o add_func.o sub_func.o mul_func.o div_func.o -pg

main.o: main.c
	gcc -c main.c
add_func.o: add_func.c
	gcc -c add_func.c
sub_func.o: sub_func.c
	gcc -c sub_func.c
mul_func.o: mul_func.c
	gcc -c mul_func.c
div_func.o: div_func.c
	gcc -c div_func.c
clean:
	rm -f func main.o add_func.o sub_func.o mul_func.o div_func.o
