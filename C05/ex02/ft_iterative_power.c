int	ft_iterative_power(int nb, int power)
{
	int tmp;

	tmp = nb;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	while (--power)
		nb *= tmp;
	return (nb);
}

int main(int ac, char **av)
{
	printf("result = %d\n", ft_iterative_power(atoi(av[1]), atoi(av[2])));
}