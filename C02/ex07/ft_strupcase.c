int	ft_is_lowercase(char c)
{
	return((c >= 'a' && c <= 'z'));
}

char	*ft_strupcase(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_is_lowercase(str[i]))
			str[i] = str[i] - ('a' - 'A');
		i++;
	}
	return (str);
}

int main(int ac, char **av)
{
	printf("%s\n", ft_strupcase(av[1]));
}