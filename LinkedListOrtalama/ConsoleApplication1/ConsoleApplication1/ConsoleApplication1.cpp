#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct dugum{
	int deger;
	struct dugum * next;
};

float ortalamaBul(struct dugum* head)
{
	float toplam = 0;
	float adet = 0;
	while (head != NULL)
	{
		if (head->deger % 15 == 0)
		{
			toplam = toplam + head->deger;
			adet++;
		}
		head = head->next;
	}
	return (toplam / adet);
}

void main()
{
	struct dugum* head = (struct dugum *)malloc(sizeof(struct dugum));
	struct dugum * p = head;
	p->deger = 225;
	p->next = (struct dugum*)malloc(sizeof(struct dugum));
	p = p->next;
	p->deger = 15;
	p->next = (struct dugum*)malloc(sizeof(struct dugum));
	p = p->next;
	p->deger = 150;
	p->next = NULL;

	float ort = ortalamaBul(head);
	printf("%0.2f", ort);

	getch();

}