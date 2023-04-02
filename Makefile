all: simu

simu: Main.o Motorcycle.o Battery.o ChangeBatteryStation.o
	g++ Main.o Motorcycle.o Battery.o ChangeBatteryStation.o -o simu

Main.o: Main.cpp
	g++ Main.cpp -c

Motorcycle.o: Motorcycle.cpp
	g++ Motorcycle.cpp -c

Battery.o: Battery.cpp
	g++ Battery.cpp -c

ChangeBatteryStation.o: ChangeBatteryStation.cpp
	g++ ChangeBatteryStation.cpp -c

clean:
	rm -rf *.o simu