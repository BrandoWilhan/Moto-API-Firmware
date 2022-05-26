all: simu

simu: main.o moto.o battery.o etb.o
	g++ main.o moto.o battery.o etb.o -o simu

main.o: main.cpp
	g++ main.cpp -c

moto.o: moto.cpp
	g++ moto.cpp -c

battery.o: battery.cpp
	g++ battery.cpp -c

etb.o: etb.cpp
	g++ etb.cpp -c

clean:
	rm -rf *.o simu