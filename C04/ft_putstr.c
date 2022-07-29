int		ft_strlen(char *str)
{
	char	*tmp;

	tmp = str;
	while(*str)
		str++;
	return (str - tmp);
}

void	ft_putstr(char *str)
{

	write(1, str, ft_strlen(str));
}

#include "stdlib.h"

int	main(void)
{
	ft_putstr(NULL);
	return (0);
}