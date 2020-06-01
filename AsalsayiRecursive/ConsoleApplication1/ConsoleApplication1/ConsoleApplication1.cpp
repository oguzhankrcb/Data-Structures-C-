#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


void findprimenumbers(int n)
{
	if (n == 1)
		return;

	int i = 2;
	int asalmi = 1;
	for (i; i < n;i++)
	{
		if (n % i == 0)
		{
			asalmi = 0;
		}
		
	}
	if (asalmi)
		printf("%d ", n);

	return findprimenumbers(n - 1);
}


void main()
{
	findprimenumbers(100);

	getch();
}