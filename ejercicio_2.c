#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMA 5


int main(){
	char *buff;
	char *V[TAMA];

	buff = (char *) malloc(100*sizeof(char));

	for (int i = 0; i < TAMA; i++)
	{	
		printf("Digite el nombre de la persona %d: ",i+1);
		gets(buff);
		V[i] = (char *) malloc((strlen(buff)+1)*sizeof(char));
		strcpy(V[i],buff);
	}
	
	for (int i = 0; i < TAMA; i++)
	{
		printf("\nEl nombre %d es: %s",i+1, V[i]);
		free(V[i]);
	}

	free(buff);

	return 0;

}