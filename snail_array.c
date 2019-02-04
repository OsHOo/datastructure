#include <stdio.h>
#include <stdlib.h>
void snail(int **, int);
void print_snail(int **, int);
int main()
{
	int size, i, j;
	int **board;
	printf("Input N : ");
	scanf("%d", &size);
	board = (int **)malloc(sizeof(int *)*(size+1));
	for(i=0;i<size;i++)
	{
		*(board+i) = (int *)malloc(sizeof(int)*(size+1));
	}
	snail(board, size);
	print_snail(board, size);
	return 0;
}
void print_snail(int **board, int size)
{
	int i, j;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
			printf("%3d ", *(*(board+i)+j));
		printf("\n");
	}
}
void snail(int **board, int size)
{
	int i, j, num, dev, hex;
	dev = size;
	hex = 0;
	num = 1;
	while(num != size*size + 1)
	{
		for(j=hex;j<dev;j++)
		{
			*(*(board+hex)+j) = num;
			num++;
		}
		hex++;
		dev--;
		for(i=hex;i<dev+1;i++)
		{
			*(*(board+i)+dev) = num;
			num++;
		}
		hex--;
		for(j=dev-1;hex-1<j;j--)
		{
			*(*(board+dev)+j) = num;
			num++;
		}
		dev--;
		for(i=dev;hex<i;i--)
		{
			*(*(board+i)+hex) = num;
			num++;
		}
		hex++;
		dev++;
	}
}

