// Seti3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include "stdlib.h"
#include <math.h>
#include <string.h>
#define BYTE unsigned char 
#define TRUE 1
#define FALSE 0

typedef struct pair
{
	BYTE amount;
	short int count;
	BYTE flag;
}pair;

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

void verify_arr(BYTE* came_v, int block_len, int counter, BYTE* arr_out)
{
	int power = 0;
	int flag = TRUE;
	pair *pows = (pair*)calloc(counter, sizeof(pair));
	//BYTE *pows_real = (BYTE*)calloc(counter, sizeof(BYTE));
	for (int j = 0; j < counter; j++)
	{
		power = pow(2, j);
		pows[j].count = power;
		for (int k = power - 1; k < block_len;)
		{
			for (int m = 0; m < power; m++, k++)
			{
				if (came_v[k] == 1)
					pows[j].amount += 1;
			}
			k += power;
		}
	}

	for (int j = 0; j < counter; j++)
	{
		if (came_v[pows[j].count - 1] == (pows[j].amount % 2))
		{
			pows[j].flag = TRUE;
		}
		else
		{
			pows[j].flag = FALSE;
			flag = FALSE;
		}
	}

	if (flag == TRUE)
	{
		for (int i = 0, j = 0, it = 0; i < block_len; i++)
		{
			if (pows[j].count - 1 == i)
			{
				j++;
				continue;
			}
			else
			{
				arr_out[it] = came_v[i];
				it++;
			}
		}
	}
	if (flag == FALSE)
	{
		//here we are doing somthing interesting
	}
	return arr_out;
}

void Hemming(int len_w, BYTE *came, int len_came)
{
	int counter = 0;
	int power = 0;
	int blocks = 0;
	int itter = 0;
	BYTE *arr_t = NULL;
	
	while (power <= len_w)
	{
		counter++;
		power = pow(2, counter);
	}
	printf("%d\n", counter);
	
	int block_len = len_w + counter;
	BYTE *arr_out = (BYTE*)malloc(block_len - counter * sizeof(BYTE));
	if (len_came % block_len == 0)
	{
		blocks = len_came / block_len;
		arr_t = (BYTE*)malloc(block_len * sizeof(BYTE));
	}
	else
	{
		//I don't know
	}
	int counter2 = 0;
	for (int i = 0; i < blocks; i++)
	{
		power = 0;
		//counter2 = 0;
		memcpy(arr_t, came + i, block_len);
		verify_arr(arr_t, block_len, counter, arr_out); //save in new array
	}
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
	Hemming(12, arr, sizeof(msg) * 8 * sizeof(BYTE));
	free(arr);
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
