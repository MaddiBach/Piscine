int	ft_recursive_factorial(int nb)
{
	if (nb)
		return (ft_recursive_factorial(nb - 1) * nb);
	return (1);
}

int main(int ac, char **av)
{
	printf("result = %d", ft_recursive_factorial(atoi(av[1])));
}