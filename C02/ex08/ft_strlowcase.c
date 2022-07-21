int	ft_is_upcase(char c)
{
	return((c >= 'A' && c <= 'Z'));
}

char	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_is_upcase(str[i]))
			str[i] = str[i] - ('A' - 'a');
		i++;
	}
	return (str);
}

int main(int ac, char **av)
{
	printf("%s\n", ft_strlowcase(av[1]));
}