#include <stddef.h>
#include <limits.h>
#include <unistd.h>

int		ft_strlen(char *str)
{
	char	*tmp;

	tmp = str;
	while(*str)
		str++;
	return (str - tmp);
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void 	ft_handle_recursion(int nbr, int baselen,char * base)
{
	if(nbr > baselen -1)
		ft_handle_recursion(nbr / baselen, baselen, base);
	ft_putchar(base[nbr % baselen]);
}

int		ft_valid_base(char *base)
{
	int i;

	i = 0;
	if (base == NULL)
		return (0);
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[i++])
		if (base[i] == '-' || base[i] == '+')
			return (0);
	i = 0;
	while (*base)
	{
		while (*(base + i))
			if (*base == *(base + i + 1))
				return (0);
			i++

		base++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int baselen;

	if (base == NULL || !ft_valid_base(base))
	{
		write(2, "putnbr_base : invalid base\n", 27);
		return ;
	}
	baselen = ft_strlen(base);
	if (nbr == INT_MIN)
	{
		ft_putchar('-');
		ft_handle_recursion((nbr / 10) * -1, baselen, base);
		ft_putchar(base[(nbr % baselen) * -1]);
	}
	else if(nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
		ft_handle_recursion(nbr, baselen, base);
	}
	else
		ft_handle_recursion(nbr, baselen, base);
}

int main(int ac, char **av)
{
	// ft_putnbr_base(atoi(av[1]), av[2]);
	int i = 0;
	printf("\ni =  %d \n",i++);
}