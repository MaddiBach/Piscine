// int ft_is_prime(int nb)
// {
// 	if (nb * nb)
// }

void copy(void *dest, void *src)
{
	memcpy(dest, src, get_size(src));
}

int get_size(void *ptr)
{
	printf("\n %p \n", *(&ptr + 1) - ptr);
	printf("\n %u \n", *(&ptr + 1) - ptr);
	return (*(&ptr + 1) - ptr);
}

typedef struct s_zebi t_zebi;
struct s_zebi
{
	int a;
	char b;
	int c;
	int d;
};

int main(void)
{
	int *ptr = malloc(100 * sizeof(int));
	char *ptr2 = malloc(100 * sizeof(char));
	t_zebi *ptr3 = malloc(100 * sizeof(t_zebi));

	char *env[] = {"lala", "truc"};

	printf("\n %d \n", *(&ptr + 1) - ptr);
	printf("\n %d \n", sizeof(ptr) / sizeof(ptr[0]));
	printf("\n %d \n", *(&ptr2 + 1) - ptr2);
	printf("\n %d \n", *(&ptr3 + 1) - ptr3);
	printf("\n %d \n", *(&env + 1) - env);

	int numbers[] = {5, 8, 9, 3, 4, 6, 1};
	int length = *(&numbers + 1) - numbers;
	printf("\nlen %d \n", length);

	return (0);
}