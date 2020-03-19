// Seti3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <math.h>
#define BYTE unsigned char 

void to_bin(int came, int *ind, BYTE *arr)
{
	unsigned char bin[8] = { 0 };
	for (int i = 7; i > 0; i--)
	{
		bin[i] = came % 2;
		came = came / 2;
	}
	memcpy(arr + *ind, bin, 8);
	*ind += 8;
}

void Hemming(int len_w, BYTE *came, int len_came)
{
	int counter = 0;
	int power = 0;
	while (power <= len_w)
	{
		counter++;
		power = pow(2, counter);
	}
	printf("%d\n", counter);
}


int main()
{
	BYTE msg[] = { 57, 40, 19, 133, 33, 182, 145, 39, 225, 2, 140, 106, 70, 34, 235, 14, 53, 226, 150,
		10, 105, 2, 37, 40, 10, 166, 98, 78, 52, 97, 47, 56, 97, 22, 130, 99, 2, 235, 235, 2, 238, 105 };
	BYTE *arr = (BYTE*)malloc(sizeof(msg) * 8 * sizeof(BYTE));
	int ind = 0;
	int len = 0;
	for (int i = sizeof(msg), j = 0; i > 0; i--, j++)
	{
		to_bin(msg[j], &ind, arr);
	}
	/*for (int i = sizeof(msg) * 8 * sizeof(BYTE), j = 0; i > 0; i--, j++)
	{
		printf("%u", (unsigned int)arr[j]);
		if ((j + 1) % 8 == 0)
		{
			printf("\n");
		}
	}*/
	Hemming(12, NULL, 0);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
