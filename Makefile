CC := gcc

football.exe: football_main.c football.c football.h
	$(CC) -o football.exe football_main.c football.c

temperature.exe: # fill in files here
	# fill in commands here

.PHONY: clean
clean:
	rm -f *.o
	rm -f football.exe