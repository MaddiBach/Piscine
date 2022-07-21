#define true 1

#define false 0

int	ft_is_lowercase(char c)
{
	return((c >= 'a' && c <= 'z'));
}

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_is_lowercase(str[i]))
			return (false);
		i++;
	}
	return (true);
}
