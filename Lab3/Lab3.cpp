#include <math.h>
#include <stdio.h>
#include <Windows.h>
#include <ctime>

char prob(double number)
{
	if (number < 0.1)
		return 3;
	else if (number < 0.3)
		return 2;
	else if (number < 0.6)
		return 1;
	else if (number < 1.0)
		return 0;
	else
		throw;
}

unsigned int random(unsigned int X)
{
	// zwraca wartoœci od 0 do 2^32 - 1
	unsigned const int A = 69069, C = 1, M = INT_MAX;
	return (A*X + C) % M;
}

void zadanie1()
{
	// Losowanie liczb 1-4 z okreœlonymi szansami
	// szansa = 0.5 - 0.n

	unsigned int X = 15, M = INT_MAX, N = 100000;

	int* rozklad = (int*)calloc(4, sizeof(int));
	for (unsigned int i = 0; i <= N; i++)
	{
		X = random(X);
		char indeks = prob(floor(10.0 * (double)X / M)/10.0);
		rozklad[indeks]++;
	}

	printf("Rozklad liczb pseudolosowych w zadaniu 1:\n");
	for (int i = 0; i < 4; i++)
	{
		printf("%d: %d\n", i+1, rozklad[i]);
	}
}

unsigned int fun(double X)
{
	// X - 50, 150
	// ret - 0, 10
	return (unsigned int)floor(10.0 * (X / 100.0 - 0.5));
}

void zadanie2()
{
	// f(x) = x/100 - 0.5
	unsigned int N = 100000, M = INT_MAX, X = 15, indeks;


	int* rozklad = (int*)calloc(10, sizeof(int));
	for (unsigned int i = 0; i < N; i++)
	{
		// Wartoœci 0-2^32 - 1
		X = random(X);
		// Wartoœci 50-150
		// Tê zmienn¹ ma zwracaæ program losuj¹cy
		double Xret = 50.0 + 100.0 * ((double)X / M);

		rozklad[fun(Xret)]++;
	}

	printf("Rozklad liczb pseudolosowych w zadaniu 2:\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d: %d\n", i + 1, rozklad[i]);
	}
}

int main()
{
	zadanie1();
	system("pause");
	zadanie2();
	system("pause");
	return 0;
}