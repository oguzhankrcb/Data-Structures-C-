#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
	char harfler[] = "AaBbCcDdEeFfGgĞğHhIıİiJjKkLlMmNnOoPpRrSsŞşTtUuÜüVvYyZz";
	char sayilar[] = "0123456789";
	while (1)
	{
		
		printf("\nBir karakter giriniz : ");
		char karakter;
		scanf("%c", &karakter);
		int opt = 0; // 0 = special character, 1 = character, 2 = number
		if (karakter == -1)
			break;

		int i = 0;
		for (i; i < strlen(harfler); i++)
		{
			if (harfler[i] == karakter)
				opt = 1;
		}
		for (i = 0; i < strlen(sayilar); i++)
		{
			if (sayilar[i] == karakter)
				opt = 2;
		}

		if (opt == 0)
			printf("\nOzel karakter");
		else if (opt == 1)
			printf("\nKarakter");
		else if (opt == 2)
			printf("\nSayi");

	}
	



}