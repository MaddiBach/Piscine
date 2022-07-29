
#include "unistd.h"

int	main(void)
{

	int p1[2];
	int p2[2];
	int p3[2];

	 pipe(p1);

	int pid1 = fork();

	if(pid1 == 0)
	{
		write(p1[1],"lalalalalala",10);
		close(p1[0]);
		close(p1[1]);
		return 0 ;
	}
	write(1,"www\n",4);
	close(p1[0]);
	close(p1[1]);
	pipe(p1);
	int pid2 = fork();
	if(pid2 == 0)
	{
		printf("\n gate \n");
		char buff[100];
		printf("\n gate 1\n");
		printf("\np1[0] %d \n",p1[0]);
		printf("read = %d",read(p1[0],&buff,0));
		printf("\n buff :>%s<\n",buff);
		write(1,buff,5);
		write(1,"lalala",3);
		close(p1[0]);
		close(p1[1]);
		return 0 ;
	}
	write(1,"www\n",4);

	close(p1[0]);
	close(p1[1]);

	return (0);
}