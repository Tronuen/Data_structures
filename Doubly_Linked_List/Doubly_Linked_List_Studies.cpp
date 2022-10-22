#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>

struct node
{
	int number;
	struct node *previous;
	struct node *next;
};

struct node *add_in_order(struct node *head, struct node *nevv)
{
	struct node *ptr = NULL;
	struct node *temp = NULL;
	
	//�lk NULL'sa yani ba�l� liste hi� olu�turulmam��sa ald���m�z numberyle head nodemizi olu�turuyoruz.
	if(head==NULL)
	{
		head = nevv;
		return head;
	}
	//E�er gelen number head nodeden k���kse listenin ba��na ekliyoruz(Push yap�yoruz yani)		
	else if(nevv->number < head->number)
	{
		nevv->next = head;
		head->previous = nevv;
		head = nevv;
		return head;
	}
	else
	{
		ptr = head;
		temp = head->next;
		
		while(temp!=NULL)
		{
			//numberyi sona kadar kontrol ediyoruz. numbermiz nodelerdekinden b�y�k oldu�u s�rece bir sonraki nodee ge�iyoruz
			if(temp->number < nevv->number)
			{
				ptr = ptr->next;
				temp = temp->next;
			}
			else	break;		//E�er else olursa yani numbermiz nodelerden birisinden k���kse hemen duruyoruz ve d�ng�den ��k�yoruz
		}
		//Yukardaki kontrol a�amas�nda d�ng�den ��kmadan NULL'a kadar geldiyse bu number nodedekilerin hepsinden b�y�kt�r demek ki. O y�znden sona ekliyoruz
		if(temp==NULL)
		{
			ptr->next = nevv;	//�nceki nodein sonras�n� nevv nodele
			nevv->previous = ptr;	//nevv nodein de �ncesini �ncekiyle ba�l�yoruz
			nevv->next = NULL;
		}
		//E�er numbermiz ba�l� listenin aras�nda bir yere denk geliyorsa onu araya ba�l�yoruz
		else
		{
			ptr->next = nevv;		//�lk olarak �nceki nodein i�aret etti�i sonraki adres art�k nevvdir diyoruz
			nevv->previous = ptr;		//nevvnin de �ncekini i�aret etti�i adres ptr'dir diyoruz
			nevv->next = temp;	//�kinci olarak nevvnin i�aret etti�i sonraki adres tempdir diyoruz. Yukarda kendisinden b�y�k birine rastlay�nca hemen d�ng�den ��km��t�k. ��te o temp adl� node oluyor
			temp->previous = nevv;	//tempnin i�aret etti�i �nceki adres de nevvdir deyince 4 tane ba�� olu�turmu� oluyoruz.
		}
		return head;		//Burada ve yukarlarda headi geri d�nd�rmemizin sebebi hep headten ba�lay�p ilerledi�imiz i�in sonrakilerde yapt���m�z de�i�iklik otomatikmen kaydedilmi� oluyor.
	}
}


main()
{
	setlocale(LC_ALL, "Turksih");
	
	FILE *fp1 = fopen("numbers.txt", "r");
	FILE *fp2 = fopen("numbers_reverse.txt", "w");
	
	if(!fp1)
	{
		printf("\n\tnumbers.txt dosyas� a��lamad�!");
		getch();
		return 1;
	}
	if(!fp2)
	{
		printf("\n\tnumbers_reverse.txt dosyas� a��lamad�!");
		getch();
		return 2;
	}
	
	struct node *head = NULL;
	struct node *ptr = NULL;
	struct node *temp = NULL;
	struct node *nevv = NULL;
	
	
	while(!feof(fp1))
	{
		nevv = (struct node*)malloc(sizeof(struct node));		//Gelen numberleri kaydetmek i�in haf�zada bir node kadar yer a��yoruz
		
		fscanf(fp1, "%d", &nevv->number);		//Dosyadan her gelen numberyi nevv adl� nodee atay�p kontrolleri ona g�re yapaca��z
		
		nevv->next = NULL;
		nevv->previous = NULL;
		
		head = add_in_order(head, nevv);		//Fonksiyonda de�i�iklik yap�lm�� bi�imde geri d�nen headi tekrar heade e�itleyerek de�i�ikli�in ger�ekle�mesini sa�l�yoruz
	}
	
	temp = head;
	short i = 0;
	while(temp!=NULL)
	{
		printf("\n%2d. element = %4d	at %d.	Previous pointer: %8d	Next pointer: %8d", i+1, temp->number, temp, temp->previous, temp->next);
		temp = temp->next;
		i++;
	}
	
	temp = head;
	while(temp->next!=NULL)			//Burada en son nodee gidiyoruz. ��nk� son node en b�y�k olan�
		temp = temp->next;
	
	while(temp!=head->previous)			//Son nodeden head 'in evveli yani �b�r taraftaki NULL'a kadar tek tek numberleri di�er dosyaya yaz�yoruz
	{									//B�ylece tekrar s�ralamaya gerek kalmadan b�y�kten k����e say�lar� yazd�rm�� oluyoruz.
		fprintf(fp2, "%d\n", temp->number);
		temp = temp->previous;
	}
	
	fclose(fp2);
	fclose(fp1);
	return 0;
}
