// MPWI_LAB2.cpp : Defines the entry point for the console application.
//

#include "pch.h"
#include <math.h>
#include <stdio.h>
#include <Windows.h>
#include <ctime>

extern "C" unsigned int rand_asm(char p, char q, time_t seed, unsigned int invoc);

void zadanie1() {
	unsigned int N = 100000, A = 69069, X_0 = 15, C = 1, M = INT_MAX;
	unsigned int X = X_0;

	int* rozklad = (int*)calloc(10, sizeof(int));
	for (unsigned int i = 0; i <= N; i++)
	{
		X = (A*X + C) % M;
		char indeks = (char)floor(10 * (double)X / M);
		rozklad[indeks]++;
	}

	printf("Rozklad liczb pseudolosowych w zadaniu 1:\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d: %d\n", i, rozklad[i]);
	}
}

void zadanie2() {
	// b_i = b_i-p xor b_i-q
	// Z jakiegoś powodu po kilku iteracjach wartość X się zeruje???
	const char p = 7;
	const char q = 3;

	unsigned int N = 100000, X, M = UINT_MAX;
	time_t seed;
	time(&seed);

	int* rozklad = (int*)calloc(10, sizeof(int));
	for (unsigned int i = 0; i < N; i++)
	{
		X = rand_asm(p, q, seed, i);

		char indeks = (char)floor(10 * (double)X / M);
		rozklad[indeks]++;
	}

	printf("Rozklad liczb pseudolosowych w zadaniu 2:\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d: %d\n", i, rozklad[i]);
	}
}

int main() {
	/*
	zadanie1();
	system("pause");
	*/
	zadanie2();
	system("pause");
	return 0;
}
