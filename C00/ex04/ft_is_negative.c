#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_is_negative(int n)
{
	if (n >= 0)
		ft_putchar('P');
	else
		ft_putchar('N');
}

int main(int ac, char **av)
{
	if (ac == 2)
		ft_is_negative(atoi(av[1]));
	else
		return (1);
}