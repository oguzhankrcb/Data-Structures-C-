#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
void strkopyala(char* src, char* dest)
{
	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;

	}
	*dest = '\0';
}

char * strcat(char *str1, char*str2)
{
	int len1 = 0;
	int len2 = 0;
	while (*str1 != '\0')
	{
		len1++;
		str1++;
	}
	str1 -= len1;
	while (*str2 != '\0')
	{
		len2++;
		str2++;
	}
	str2 -= len2;
	char * p = (char*)malloc(sizeof(char)* (len1 + len2 + 1));
	if (p)
	{
		*(p + len1 + len2) = '\0';
	}
	int i = 0, j = len1;

	for (i; i< len1; i++)
	{
		p[i] = str1[i];
	}
	i = 0;
	for (j; j < len1 + len2; j++)
	{
		p[j] = str2[i];
		i++;
	}
	return p;
}

int main()
{
	char a1[] = "Karabük";
	char a2[] = "Karabükos";
	//char *w = strcat(a1, a2);
	printf("%d", strcmp(a1, a2));
	//printf("%s", w);



	getch();
	return 0;
}
