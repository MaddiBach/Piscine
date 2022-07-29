#include <stddef.h>
#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char *ret;

	if (!dest || !src)
		return (NULL);
	ret = dest;
	while (*dest)
		dest++;
	while (*src && nb--)
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = NULL;
	return (ret);
}

int main()
{
	char *str =  calloc(10, sizeof(char));
	char str2[4] = "0000";
	for(int i = 0; i < 5; i++)
	{
		str[i] = '1';
	}
	printf("str before cat = %s\n", str);
	ft_strcat(str, str2);
	*(str + 6) == NULL;
	printf("str after cat = %s\n", str);
}