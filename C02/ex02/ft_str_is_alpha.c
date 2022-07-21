#define true 1

#define false 0

int	ft_is_alpha(char c)
{
	return((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}



int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_is_alpha(str[i]))
			return (false);
		i++;
	}
	return (true);
}

int main(int ac,char **av )
{
	if (ft_str_is_alpha(av[1]))
		printf("YES\n");
	else
		printf("NO\n");
}