#include <stdio.h>
#include <stdlib.h>
int r_line;
int line;
int r_k;
int getExp(int line);
int drawTri(int i, int j, char **star);
void copyTri(int k, char **star);
int main()
{
	int i, j, k, tmp;
	char **star;

	scanf("%d", &r_line);
	line = r_line * 2 - 1;
	r_k = getExp(r_line);
	star = (char **)malloc(sizeof(char *)*r_line);
	for (i = 0; i<r_line; i++)
		star[i] = (char *)malloc(sizeof(char)*line);
	for (i = 0; i < r_line; i++)
		for (j = 0; j < line; j++)
			star[i][j] = ' ';
	i = 0;
	j = line / 2;
	k = 0;
	tmp = drawTri(i, j, star);
	copyTri(k, star);
	for (i = 0; i < r_line; i++) {
		for (j = 0; j < line; j++) {
			printf("%c", star[i][j]);
		}
		printf("\n");
	}
	scanf("%d", &i);
	return 0;
}
int getExp(int line)
{
	int tmp;
	tmp = 0;
	line = line / 3;
	while (line != 1)
	{
		line /= 2;
		tmp++;
	}
	return tmp;
}
int exp(int num)
{
	int i, tmp;
	tmp = 1;
	for (i = 0; i < num; i++)
	{
		tmp *= 2;
	}
	return tmp;
}
int drawTri(int i, int j, char **star)
{
	int tmp_i, tmp_j;
	tmp_i = i;
	tmp_j = j;
	while (1)
	{
		star[i][j] = '*';
		i++;
		j--;
		if ((i == tmp_i + 2) && (j == tmp_j - 2))
			break;
	}
	tmp_i = i;
	tmp_j = j;
	while (1)
	{
		star[i][j] = '*';
		j++;
		if (j == tmp_j + 4)
			break;
	}
	tmp_i = i;
	tmp_j = j;
	while (1)
	{
		star[i][j] = '*';
		i--;
		j--;
		if ((i == tmp_i - 2) && (j == tmp_j - 2))
			break;
	}
	return 0;
}
void copyTri(int k, char **star)
{
	int i, j;
	if (k == r_k)
		return;
	for (i = 0; i < r_line; i++)
	{
		for (j = 0; j < line; j++)
		{
			if (star[i][j] == '*')
			{
				star[i + 3 * exp(k)][j - 3 * exp(k)] = '#';
				star[i + 3 * exp(k)][j + 3 * exp(k)] = '#';
			}
		}
	}
	for (i = 0; i < r_line; i++)
	{
		for (j = 0; j < line; j++)
		{
			if (star[i][j] == '#')
			{
				star[i][j] = '*';
			}
		}
	}
	k++;
	copyTri(k, star);
}