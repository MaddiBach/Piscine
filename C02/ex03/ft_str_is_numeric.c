#define true 1
#define false 0

int	ft_is_numeric(char c)
{
	return((c >= '0' && c <= '9'));
}



int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_is_numeric(str[i]))
			return (false);
		i++;
	}
	return (true);
}

int main(int ac,char **av )
{
	if (ft_str_is_numeric(av[1]))
		printf("YES\n");
	else
		printf("NO\n");
}