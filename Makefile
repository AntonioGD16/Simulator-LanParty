build:
		gcc -Wall liste.h player.h liste.c main.c -o lanParty

clean:
		rm -f lanParty