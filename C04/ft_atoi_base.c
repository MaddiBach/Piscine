#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

int		ft_strlen(char *str)
{
	char	*tmp;

	tmp = str;
	while(*str)
		str++;
	return (str - tmp);
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
		puts("??");
		while (*(base + i++))
			if (*base == *(base + i))
				return (0);
		base++;
	}
	return (1);
}


int	ft_atoi_base(char *str, char *base)
{
	int sign;
	int res;
 	int baselen;

	if (base == NULL || !ft_valid_base(base))
	{
		write(2, "putnbr_base : invalid base\n", 27);
		return (1);
	}
	baselen = ft_strlen(base);
	res = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n'|| *str == '\v'
		|| *str == '\f'|| *str == '\r'|| *str == ' ')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = (res * baselen) + (*str) - '0' ;
		str++;
	}
	return (res * sign);
}

int main(int ac, char **av)
{
	printf("result = %d\n", ft_atoi_base(av[1], av[2]));
}