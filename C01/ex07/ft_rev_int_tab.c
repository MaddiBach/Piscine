#include <stdio.h>

void ft_swap(int a, int b)
{
	int tmp;

	tmp = a;
	a = b;
	b = tmp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int start;
	int end;
	int tmp;

	start = 0;
	end = size - 1;
	while (start < size / 2)
	{
		tmp = tab[start];
		tab[start] = tab[end];
		tab[end] = tmp;
		printf("step %d: tmp = %d| start = %d| end = %d\n",start , tmp, tab[start], tab[end] );
		start++;
		end--;
	}
}

void	ft_print_tab(int *tab,int size)
{
	int i = 0;
	printf("[");
	while (i < size)
	{
		printf("%d, ", tab[i]);
		i++;
	}
	puts("]");
}
int main(void)
{
	int tab[6] = {100, 2, 3, 4,5, 6};
	ft_print_tab(tab, 6);
	ft_rev_int_tab(tab, 6);
	ft_print_tab(tab, 6);
}
