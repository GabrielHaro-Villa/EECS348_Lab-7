CC := gcc

football.exe: football_main.c football.c football.h
	$(CC) -o football.exe football_main.c football.c

temperature.exe: temperature_main.c temperature.c temperature.h
	$(CC) -o temperature.exe temperature_main.c temperature.c

.PHONY: clean
clean:
	rm -f *.o
	rm -f football.exe
	rm -f temperature.exe