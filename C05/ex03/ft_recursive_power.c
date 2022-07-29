// int	ft_recursive_power(int nb, int power)
// {
// 	if (power < 0)
// 		return (0);
// 	else if (power == 0)
// 		return (1);

// 	if (--power)
// 		return (nb * nb)
// }




int	ft_recursive_power(int nb, int *deep)
{
	if (*deep < 0)
		return (0);
	if ((*deep)--> 0)
		return (ft_recursive_power(nb,deep) * nb);
	return 1;
}

 int	main(void)
{
	int p = 4;
	printf("\nrec %d \n",ft_recursive_power(2,&p));
	return (0);
}