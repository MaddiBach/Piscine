void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	int nb = nbr;

	if(nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}

	if(nb)
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
}

int	main()
{
	ft_putnbr(-123456);
}