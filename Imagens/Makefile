all: arvorequaternaria.o a.o
	gcc arvorequaternaria.o a.o -o oi -lm

arvorequaternaria.o:
	gcc -c arvorequaternaria.c

a.o:
	gcc -c a.c

clean:
	rm *.o oi

run:
	./oi