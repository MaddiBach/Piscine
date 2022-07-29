#include <stddef.h>
#include <stdio.h>


//modified to not compare the NULL terminating character.
int	ft_strcmp(char *s1, char *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (NULL);

	while (*(s1 + 1) && *(s2 + 1) && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	printf("haystack last char = %s\nneedle last char = %s\n", s1, s2);
	return (*s1 - *s2);
}

char	*ft_strstr(char *haystack, char *needle)
{
	if (haystack == NULL || needle == NULL)
		return (NULL);
	while (*haystack != *needle)
		haystack++;
	if (*haystack == NULL)
		return (NULL);
	if (!ft_strcmp(haystack, needle))
		return (haystack);
	else
		return (NULL);
}

int main(int ac, char **av)
{
	char *toprint = ft_strstr(av[1], av[2]);
	puts("!!!");
	printf("%p\n", toprint);
}