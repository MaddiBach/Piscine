int ft_fibonacci(int n)
{
	if (n == 0)
		return (0);
	if (n < 2)
		return (1);
	return (ft_fibonacci(n - 1) + ft_fibonacci(n - 2));
}

int main()
{
	printf("\n %d \n", ft_fibonacci(10));
}

// si n > 0 && < 2 ret = 1
// si n = 0 ret = 0
// ret = fibonacci(n - 1) + fibonacci(n - 2)
