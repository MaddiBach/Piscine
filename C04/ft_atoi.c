#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define get_value(ref) (*(*ref))
#define set_value(ref, x) (*(*ref) = x)

// #define(char **) reference

int ft_atoi(char *str)
{
	int sign;
	int res;

	res = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' || *str == '\r' ||
		   *str == ' ')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str) - '0';
		str++;
	}
	return (res * sign);
}

bool is_whitespace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == ' ');
}

bool is_sign(char c)
{
	return (c == '+' || c == '-');
}

bool is_number(char c)
{
	return (c >= '0' && c <= '9');
}

int ft_add_digit_to_int(int *src, char toadd)
{
	*src = (*src * 10) + (toadd - '0');
}

char *skipwhitespace(char **str)
{
	while (is_whitespace(get_value(str)))
		(*str)++;
}

bool get_sign_and_skip(char **str)
{
	bool sign = true;
	while (is_sign(get_value(str)))
	{
		if (get_value(str) == '-')
			sign = !sign;
		(*str)++;
	}
	return sign;
}

int ft_atoi(char *str)
{
	bool sign;
	int res;

	res = 0;

	skipwhitespace(&str);
	sign = get_sign_and_skip(&str);

	while (is_number(*str))
	{
		ft_add_digit_to_int(&res, *str);
		str++;
	}

	return (res * ((sign) ? 1 : -1));
}

int main(int ac, char **av)
{
	char *str = strdup(av[1]);
	printf("res = %d\n", ft_atoi(str));
	printf("res = %d\n", atoi(av[1]));
}