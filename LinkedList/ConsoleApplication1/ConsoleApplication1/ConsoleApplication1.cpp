#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct ogrenci{
	double vize;
	double final;
	char ogrenciad[30];
	struct ogrenci * before;
	struct ogrenci * next;
};
typedef struct ogrenci node;
void listekle(node * head)
{
	while (head->next != NULL)
	{
		head = head->next;
	}
	head->next = (node*)malloc(sizeof(node));
	node * p = head;
	head = head->next;
	head->before = p;
	head->next = NULL;
}
char* eniyiogrencinotubul(node * middle)
{
	node *p, *p2;
	p = middle;
	p2 = middle;
	double eniyinot = 0;
	char * eniyiogrenci;
	while (p != NULL)
	{
		double ort = ((p->vize * 0, 4) + (p->final * 0, 6));
		if (eniyinot < ort)
		{
			eniyinot = ort;
			eniyiogrenci = p->ogrenciad;
		}

		p = p->next;
	}
	while (p2 != NULL)
	{
		double ort = ((p2->vize * 0, 4) + (p2->final * 0, 6));
		if (eniyinot < ort)
		{
			eniyinot = ort;
			eniyiogrenci = p2->ogrenciad;
		}
		p2 = p2->before;
	}
	return eniyiogrenci;
}
int fib(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;


	return fib(n - 1) + fib(n - 2);
}
int boolean(int k)
{
	if (k != 0)
		return 1;
	else
		return 0;
}
void main()
{
	int bul = 0;
	if (boolean(bul))
		printf("%d", bul);

	getch();


}