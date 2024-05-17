build:
	gcc -Wall struct.h liste.c cozi.c stive.c arbori.c tasks.c main.c -o lanParty -lm

clean:
	rm -f lanParty