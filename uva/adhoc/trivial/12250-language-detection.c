#include <stdio.h>
#include <string.h>

/* 12250 - Language Detection */

int main() {
    
	int counter = 1;
	char word[20];
    
	while(scanf("%s", word) && strcmp(word,"#")) {
				    
		printf("Case %d: ",counter++);
        
		if (!strcmp(word, "HELLO"))
            printf("ENGLISH\n");
		else if (!strcmp(word, "HOLA"))
            printf("SPANISH\n");
		else if (!strcmp(word, "HALLO"))
            printf("GERMAN\n");
		else if (!strcmp(word, "BONJOUR"))
            printf("FRENCH\n");
		else if (!strcmp(word,"CIAO"))
            printf("ITALIAN\n");
		else if (!strcmp(word,"ZDRAVSTVUJTE"))
            printf("RUSSIAN\n");
		else
            printf("UNKNOWN\n");
	}
	return 0;
}