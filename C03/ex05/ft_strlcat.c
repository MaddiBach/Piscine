#include <stddef.h>
#include <stdio.h>
#include <bsd/string.h>

char	*ft_strlcat(char *dest, char *src, unsigned int size)
{
	int		len;

	len = 0;
	while (*dest)
	{
		dest++;
		len++;
	}
	while (*src && size-- && size--)
	{
		*dest = *src;
		src++;
		dest++;
		len++;
	}
	*dest = NULL;
	return (len);
}

int main(int ac, char **av)
{
	char *test = malloc(sizeof(char) * atoi(av[3]));
	printf("myfunc ret = %d\n", ft_strlcat(av[1], av[2], atoi(av[3])));
	printf("myfunc res = %s\n", ft_strlcat(av[1], av[2], atoi(av[3])));
	printf("func ret = %d\n", strlcat(av[1], av[2], atoi(av[3])));
	printf("func res = %s\n", strlcat(av[1], av[2], atoi(av[3])));
}


