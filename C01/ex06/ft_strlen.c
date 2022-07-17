void ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}
