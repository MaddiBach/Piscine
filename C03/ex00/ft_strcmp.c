int	ft_strcmp(char *s1, char *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (NULL);

	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}