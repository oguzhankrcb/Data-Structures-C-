#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
void main()
{
	srand(time(NULL));
	char girilen[256];
	printf("Bir kelime giriniz : ");
	gets(girilen);
	int i = 0;
	int kalan = 0;
	int curlen = 0;
	for (i; i < strlen(girilen); i++)
	{
		if (i + 1 == strlen(girilen))
		{
			int j = 0;
			for (j = curlen; j <= i; j++)
			{
				int random = curlen + (rand() % (i - curlen));
				int random2 = curlen + (rand() % (i - curlen));
				char temp = girilen[random];
				girilen[random] = girilen[random2];
				girilen[random2] = temp;
			}

			break;
		}
		if (girilen[i] == ' ')
		{
			int j = 0;
			for (j = curlen; j < i; j++)
			{
				int random = curlen + (rand() % (i - curlen));
				int random2 = curlen + (rand() % (i - curlen));
				char temp = girilen[random];
				girilen[random] = girilen[random2];
				girilen[random2] = temp;
			}
				curlen = i + 1;
				i = curlen;
		}
	}
	printf("\n%s", girilen);
	getch();
}