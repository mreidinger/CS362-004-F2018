CFLAGS= -Wall -fpic -coverage -lm

testAll: testme.c
	gcc -o testme testme.c -g $(CFLAGS)
	./testme

clean:
	-rm -f *.gcda *.gcno testme