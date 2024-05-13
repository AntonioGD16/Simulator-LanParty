build:
	gcc -Wall struct.h liste.h liste.c main.c -o lanParty -lm

clean:
	rm -f lanParty