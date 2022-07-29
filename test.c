#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	if(argc != 2)
		return 0;

	int lim = atoi(argv[1]);
	int i = 0;

	while(i < lim + 1)
	{
		char n[100] ;
		memset(n,0,100);
		sprintf(n, "%d", i);

		char payload[100];
		strcpy(payload,"mkdir ex");
		strcat(payload,n);
		system(payload);

		i++;
	}

	return 0;
}
