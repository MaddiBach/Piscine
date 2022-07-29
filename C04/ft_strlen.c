int		ft_strlen(char *str)
{
	char	*tmp;

	tmp = str;
	while(*str)
		str++;
	return (str - tmp);
}

int main(int ac, char **av)
{
	printf("%d\n", ft_strlen(av[1]));
}