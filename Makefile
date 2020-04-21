#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic

__start__: uklad_rownan
	./uklad_rownan <rownanie_rzeczywiste.dat
	./uklad_rownan <rownanie_zespolone.dat


uklad_rownan: obj obj/main.o obj/LZespolona.o
	g++ -Wall -pedantic -o uklad_rownan obj/main.o obj/LZespolona.o

obj:
	mkdir -p obj

obj/main.o: src/main.cpp inc/SUkladRownanLiniowych.hh inc/SMacierz.hh inc/SWektor.hh\
        inc/rozmiar.h inc/LZespolona.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/LZespolona.o: src/LZespolona.cpp inc/LZespolona.hh
	g++ ${CPPFLAGS} -o obj/LZespolona.o src/LZespolona.cpp




clean:
	rm -f obj/*.o uklad_rownan