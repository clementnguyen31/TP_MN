all: test_poly perf_poly test_polycreux

GCC_OPT= -Wall

perf_poly: perf_poly.o poly.o
	gcc -o perf_poly perf_poly.o poly.o

perf_poly.o: perf_poly.c poly.h
	gcc $(GCC_OPT) -c perf_poly.c

test_polycreux: test_polycreux.o Poly_Creux.o
	gcc -o test_polycreux test_polycreux.o Poly_Creux.o

test_polycreux.o: test_polycreux.c Poly_Creux.h
	gcc $(GCC_OPT) -c test_polycreux.c

test_poly: test_poly.o poly.o
	gcc -o test_poly test_poly.o poly.o

test_poly.o: test_poly.c poly.h
	gcc $(GCC_OPT) -c test_poly.c

poly.o: poly.c poly.h
	gcc $(GCC_OPT) -c poly.c

Poly_Creux.o: Poly_Creux.c Poly_Creux.h
	gcc $(GCC_OPT) -c Poly_Creux.c

clean:
	rm -f test_poly perf_poly *.o *~
