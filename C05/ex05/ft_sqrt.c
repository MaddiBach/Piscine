#include <stdio.h>

#define squared(nbr) nbr *nbr

int ft_handle_recursion(int nb, int root)
{
	if (squared(root) < nb)
		return (ft_handle_recursion(nb, root + 1));
	if (squared(root) == nb)
	{
		printf("\ngate  %d \n", root);
		return (root);
	}
	if (squared(root) > nb)
		return (0);
}

int ft_sqrt(int nb)
{
	int root;

	root = 0;
	printf("\nin sqrt %d \n", ft_handle_recursion(nb, root));
	return (ft_handle_recursion(nb, root));
}

int main()
{
	printf("\nroot =  %d \n", ft_sqrt(9));
}