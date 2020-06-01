#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
void main()
{
	char str[256];
	char * p = str;
	printf("bir string giriniz : ");
	gets(str);

	int i = 1;
	int j = 0;
	
	for (i; i <= strlen(str); i++)
	{
		int k = 0;
		int top = 0;
		for (k; k < i; k++)
		{
			top += k;
		}
		if (top >= strlen(str))
		{
			break;
		}
		for (j = 0; j < i; j++)
		{
			if (p[0] == '\0')
			{
				printf("\n");
				break;
			}
			printf("%c", p[0]);
			p++;	
		}
		printf("\n");
	}

	getch();
}