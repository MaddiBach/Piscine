#include <stdio.h>
#include <unistd.h>

#define bool unsigned int

#define true 1

#define false 0

int ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

void ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void ft_print_comb(void)
{
	int i = 2;
	char comb[3] = "012";
	bool set = true;
	int gdb = 0;

	while (comb[0] < '7')
	{
		while (comb[i] <= '9' - 2 + i)
		{
			if (!set)
			{

				while (i < 2)
				{


					i++;
				}
				set = true;
			}
			//printf("gdb = %d\n");
			ft_putstr(comb);
			ft_putstr(", ");
			comb[i]++;
		}
		set = false;
		comb[i - 1] = comb[i - 1] + 1;
		comb[i] = comb[i - 1] + 1;
		i--;
		gdb++;
	}
	ft_putstr(comb);
	puts("");
}

int main()
{
	ft_print_comb();
}