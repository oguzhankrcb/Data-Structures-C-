#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


struct stack{
	int dizi[5];
	int operators[4];
	int top;
	int top2;
}S;

int isEmpty()
{
	if (S.top == -1)
		return 1;
	else
		return 0;
}

int pop()
{
	if (S.top == -1)
	{
		printf("Stack bosken birsey cekemezsin...\n");
		return 0;
	}
	else
	{
		S.dizi[S.top] = NULL;
		S.top = S.top - 1;
	}
	return 0;
}
int push(int element)
{
	if (S.top == 4)
	{
		printf("Stack dolu...");
		return 0;
	}
	else
	{
		S.top = S.top + 1;
		S.dizi[S.top] = element;
	}
	return 0;
}

int getnegfromstack()
{
	int dizi[10] = { 15, -21, -3, 16, 55, -8, -34, 35, -1, -9 };

	int i = 0;

	if (isEmpty())
	{
		for (i; i < sizeof(dizi) / sizeof(int); i++)
		{
			if (dizi[i] < 0)
				push(dizi[i]);
		}
	}
	else
	{
		pop();
		getnegfromstack();
	}
	
	return 0;
}

void display()
{
	int i = S.top;

	for (i; i >= 0; i--)
	{
		printf("\n%d", S.dizi[i]);
	}
}




void asalbul(int n)
{
	if (n == 1)
		return;

	int i = 2;
	for (i; i < n; i++)
	{
		if (n % i == 0){
			return asalbul(n - 1);
		}
	}

	printf("%d ", n);

	return asalbul(n - 1);
}
typedef enum boola{ TRUE, FALSE };

boola fnc()
{

}
// 12.0'ýn adresi 0x0018B6F0
void main()
{
//	asalbul(15);
	getch();

}












/*int ekok(int n1, int n2,int i, int enkuc)
{
	if (i == 1)
		return enkuc;
		if (n1 % i == 0 && n2 % i == 0)
		{
			enkuc = i;
		}
		return ekok(n1, n2, i - 1, enkuc);
}*/


/*void main()
{
	
	int ekokubul = ekok(8,6,6, 0);
	
	printf("%d", ekokubul);

	getch();

}*/