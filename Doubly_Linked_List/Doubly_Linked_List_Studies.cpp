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
	
	//Ýlk NULL'sa yani baðlý liste hiç oluþturulmamýþsa aldýðýmýz numberyle head nodemizi oluþturuyoruz.
	if(head==NULL)
	{
		head = nevv;
		return head;
	}
	//Eðer gelen number head nodeden küçükse listenin baþýna ekliyoruz(Push yapýyoruz yani)		
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
			//numberyi sona kadar kontrol ediyoruz. numbermiz nodelerdekinden büyük olduðu sürece bir sonraki nodee geçiyoruz
			if(temp->number < nevv->number)
			{
				ptr = ptr->next;
				temp = temp->next;
			}
			else	break;		//Eðer else olursa yani numbermiz nodelerden birisinden küçükse hemen duruyoruz ve döngüden çýkýyoruz
		}
		//Yukardaki kontrol aþamasýnda döngüden çýkmadan NULL'a kadar geldiyse bu number nodedekilerin hepsinden büyüktür demek ki. O yüznden sona ekliyoruz
		if(temp==NULL)
		{
			ptr->next = nevv;	//Önceki nodein sonrasýný nevv nodele
			nevv->previous = ptr;	//nevv nodein de öncesini öncekiyle baðlýyoruz
			nevv->next = NULL;
		}
		//Eðer numbermiz baðlý listenin arasýnda bir yere denk geliyorsa onu araya baðlýyoruz
		else
		{
			ptr->next = nevv;		//Ýlk olarak önceki nodein iþaret ettiði sonraki adres artýk nevvdir diyoruz
			nevv->previous = ptr;		//nevvnin de öncekini iþaret ettiði adres ptr'dir diyoruz
			nevv->next = temp;	//Ýkinci olarak nevvnin iþaret ettiði sonraki adres tempdir diyoruz. Yukarda kendisinden büyük birine rastlayýnca hemen döngüden çýkmýþtýk. Ýþte o temp adlý node oluyor
			temp->previous = nevv;	//tempnin iþaret ettiði önceki adres de nevvdir deyince 4 tane baðý oluþturmuþ oluyoruz.
		}
		return head;		//Burada ve yukarlarda headi geri döndürmemizin sebebi hep headten baþlayýp ilerlediðimiz için sonrakilerde yaptýðýmýz deðiþiklik otomatikmen kaydedilmiþ oluyor.
	}
}


main()
{
	setlocale(LC_ALL, "Turksih");
	
	FILE *fp1 = fopen("numbers.txt", "r");
	FILE *fp2 = fopen("numbers_reverse.txt", "w");
	
	if(!fp1)
	{
		printf("\n\tnumbers.txt dosyasý açýlamadý!");
		getch();
		return 1;
	}
	if(!fp2)
	{
		printf("\n\tnumbers_reverse.txt dosyasý açýlamadý!");
		getch();
		return 2;
	}
	
	struct node *head = NULL;
	struct node *ptr = NULL;
	struct node *temp = NULL;
	struct node *nevv = NULL;
	
	
	while(!feof(fp1))
	{
		nevv = (struct node*)malloc(sizeof(struct node));		//Gelen numberleri kaydetmek için hafýzada bir node kadar yer açýyoruz
		
		fscanf(fp1, "%d", &nevv->number);		//Dosyadan her gelen numberyi nevv adlý nodee atayýp kontrolleri ona göre yapacaðýz
		
		nevv->next = NULL;
		nevv->previous = NULL;
		
		head = add_in_order(head, nevv);		//Fonksiyonda deðiþiklik yapýlmýþ biçimde geri dönen headi tekrar heade eþitleyerek deðiþikliðin gerçekleþmesini saðlýyoruz
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
	while(temp->next!=NULL)			//Burada en son nodee gidiyoruz. Çünkü son node en büyük olaný
		temp = temp->next;
	
	while(temp!=head->previous)			//Son nodeden head 'in evveli yani öbür taraftaki NULL'a kadar tek tek numberleri diðer dosyaya yazýyoruz
	{									//Böylece tekrar sýralamaya gerek kalmadan büyükten küçüðe sayýlarý yazdýrmýþ oluyoruz.
		fprintf(fp2, "%d\n", temp->number);
		temp = temp->previous;
	}
	
	fclose(fp2);
	fclose(fp1);
	return 0;
}
