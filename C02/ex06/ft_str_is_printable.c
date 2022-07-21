#define true 1

#define false 0

int	ft_is_printable(char c)
{
	return((c >= 0 && c <= 126));
}

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_is_printable(str[i]))
			return (false);
		i++;
	}
	return (true);
}
