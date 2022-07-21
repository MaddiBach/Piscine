#define true 1

#define false 0

int	ft_is_uppercase(char c)
{
	return((c >= 'A' && c <= 'Z'));
}



int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_is_uppercase(str[i]))
			return (false);
		i++;
	}
	return (true);
}
