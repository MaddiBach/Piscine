#include <stdio.h>
const int N = 3;

void print(int arr[][N], int m)
{
	int i, j;
	for (i = 0; i < m; i++)
	for (j = 0; j < N; j++)
		printf("%d ", arr[i][j]);
}

int main()
{
	unsigned int x = 2;
	unsigned int y = 4;
	unsigned int res = x - y;
	printf("\n %u \n", res);
	return 0;
}
