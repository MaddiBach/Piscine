#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include <fcntl.h>
#include <stdbool.h>

#define true 1

#define false 0

#define is_even(n) !(n & 0x1)

typedef struct s_miller_witness t_miller_witness;
struct  s_miller_witness
{
	int s;
	int d;
};

long long	ft_power(long nb, int *deep)
{

	if ((*deep)-- > 0)
		return (ft_power(nb,deep) * nb);
	return 1;
}

bool	is_witness(long long x, int n)
{
	if (x == 1 || x == n - 1)
		return (false);
	return (true);
}

t_miller_witness	ft_resolve_equation(int n)
{
	t_miller_witness	res;

	n = n - 1;
	res.s = 0;
	int i = 0;
	while (is_even(n) && i < 5)
	{
		n = n / 2;
		res.s++;
		i++;
	}
	res.d = n;
	return(res);
}

#define abs(x) ((x>0) ? x:-x)   // if x > 0 (condition is valid), return "key" (left operand is returned),
								// else return "value" (right operand is returned)
								// (condition) ? true : false;

int	ft_rand(int min, int max)
{
	char buff;
	int i;
	int fd = open("/dev/urandom", O_RDONLY);
	int res = 0;

	i = 0;
	while (i < 4)
	{
		read(fd, &buff, 1);
		res += buff;
		res = res << 8;
		i++;
	}
	res = abs(res);
	res = (res % (max - min + 1)) + min;
	return ((res % (max - min + 1)) + min);
}

int	test_witness(long long n, int a)
{
	int square = 2;
	long long x;

	t_miller_witness wit;
	wit = ft_resolve_equation(n);
	x = ft_power(a, &(wit.d)) % n;
	if (!is_witness(x, n))
		return (false);
	while (wit.s > 1)
	{
		square = 2;
		x = ft_power(x, &square) % n;
		if (!is_witness(x, n))
			return (false);
		wit.s--;
	}
	return (true);

}

bool	ft_miller_rabin(int n, int k)
{
	int a;
    if (n < 2)
        return 0;
	if (n == 2)
		return 1;
    if (is_even(n))
        return 0;
	while (k--)
	{
		a = ft_rand(2, n - 1);
		if (test_witness(n, a))
			return (false);
	}
	return (true);
}

int	ft_find_next_prime(int	n)
{
	bool found;

	if (n <= 1)
		return 2;
	found = false;
	while (!found)
	{
		if (ft_miller_rabin(++n, 1))
			found = true;
	}
	return (n);
}

int main(int ac, char **av)
{
	int n = atoi(av[1]);

	printf("\n next p :%d \n", ft_find_next_prime(n));
}