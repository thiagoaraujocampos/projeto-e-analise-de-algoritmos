// Thiago Araujo Campos - 769850

#include <iostream>
using namespace std;

int mochilaRec(int capacidade, int W[], int i, int **memo)
{
	if (i < 0)
		return 0;
	if (memo[i][capacidade] != -1)
		return memo[i][capacidade];
	if (W[i] > capacidade)
	{
		memo[i][capacidade] = mochilaRec(capacidade, W, i - 1, memo);
		return memo[i][capacidade];
	}
	else
	{
		memo[i][capacidade] = max(W[i] + mochilaRec(capacidade - W[i], W, i - 1, memo),
		mochilaRec(capacidade, W, i - 1, memo));
		return memo[i][capacidade];
	}
}

int mochila(int capacidade, int W[], int N)
{
	int **memo;
	memo = new int *[N];

	for (int i = 0; i <  N; i++)
		memo[i] = new int[capacidade + 1];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < capacidade + 1; j++)
			memo[i][j] = -1;
	return mochilaRec(capacidade, W, N - 1, memo);
}

int main()
{
	int N, soma = 0;
	scanf("%d", &N);

	int W[N];

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &W[i]);
		soma += W[i];
	}

	int max_valor = mochila((soma / 2), W, N);

	int sol = (soma - max_valor) - max_valor;
	printf("%d", sol);

	return 0;
}