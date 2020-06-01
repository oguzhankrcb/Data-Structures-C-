#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct stack{
	int dizi[10];
	int top;
}Stack;


void main()
{
	Stack.top = -1;
	int dizi[10] = { 1, 15, 23, 36, -2, -15, 56, -44, 9, -21 };
	int i = 0;
	for (i; i < sizeof(dizi) / sizeof(int); i++)
	{
		if (dizi[i] < 0)
		{
			Stack.top++;
			Stack.dizi[Stack.top] = dizi[i];
		}
	}
	for(i = Stack.top; i >= 0; i--)
	{
		printf("Stack %d : %d\n", i + 1, Stack.dizi[i]);
	}
	getch();
}