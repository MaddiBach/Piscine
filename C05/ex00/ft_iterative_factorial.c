int	ft_iterative_factorial(int nb)
{
	int res;

	res = nb;
	while (--nb)
		res = res *nb;
	return (res);
}

int main(int ac, char **av)
{
	printf("%d\n", ft_iterative_factorial(atoi(av[1])));
}