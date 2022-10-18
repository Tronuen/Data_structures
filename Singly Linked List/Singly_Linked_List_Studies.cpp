#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<locale.h>


struct	halka *ilk2=NULL;
int cokluk[2][10];


struct halka
{
	int no;
	char ad[20];
	char soyad[30];
	struct halka *next;
};



struct halka *ekle(halka *ilk, int sayi, char ilks[20], char sons[30]);
struct halka *duzenle(halka *ilk);
struct halka *sil(halka *ilk, int sayi);
void bosalt(char dizi1[20], char dizi2[30]);
void selectionSort(int dizi[2][10]);



main()
{
	setlocale(LC_ALL,"Turkish");
	halka *ilk=NULL;
	halka *gecici;
	int i=0,j=0,sayi=0,s=0,no=0,bosluk_sayac=0;
	char harf,secim,secim_2=48;
	char isim[20], soyisim[30];
	
	for(i=0;i<10;i++)
	{
		cokluk[0][i]=i;
		cokluk[1][i]=0;
	}
	
	FILE *dosya;
	
	dosya=fopen("Ödev-1.txt","r");
	
	if(dosya==NULL)
	{
		printf("\ntext dosyasý açýlamadý!");
		getch();
		return 0;
	}
	
	while(!feof(dosya))
	{
		harf=fgetc(dosya);
		
		if(harf=='\n' || feof(dosya))
		{
			ilk=ekle(ilk,no,isim,soyisim);
			for(i=0;i<10;i++)
				if(cokluk[0][i]==no%10)
					cokluk[1][i]++;
			selectionSort(cokluk);
			ilk=duzenle(ilk);
			bosalt(isim,soyisim);
			i=0;	j=0;	no=0;	bosluk_sayac=0;
		}
		else
		{
			if(harf>='0' && harf<='9')
			{
				no=no*10+(harf-48);
			}
			else if(harf==' ')	bosluk_sayac++;
			else
			{
				if(bosluk_sayac==1)
				{
					isim[i]=harf;
					i++;
				}
				else if(bosluk_sayac==2)
				{
					soyisim[j]=harf;
					j++;
				}
			}
		}
	}
	
	fclose(dosya);
	
	
	
	while(secim!=27)
	{
		system("cls");
		printf("\n\tMENÜ");
		printf("\n\n e)---->Ekle");
		printf("\n s)---->Sil");
		printf("\n a)---->Ara");
		printf("\n l)---->Listele\n");
		printf("\n ESC)---->Çýkýþ\n");
		
		secim=getch();
		
		switch(secim)
		{
			case 'e':
				system("cls");
				printf("\nSýrasýyla, eklemek istediðiniz talebenin numarasýný adýný ve soyadýný boþluk býrakarak giriniz:\n\n\t");
				do
				{
					bosalt(isim,soyisim);
					i=0;	j=0;	no=0;	bosluk_sayac=0;
					do
					{
						secim_2=getche();
						if(secim_2==27)		break;
						else if(secim_2>=48 & secim_2<=57)
							sayi=sayi*10+secim_2-48;
						else if(secim_2==' ')		bosluk_sayac++;
						else
						{
							if(bosluk_sayac==1)
							{
								isim[i]=secim_2;
								i++;
							}
							else if(bosluk_sayac==2)
							{
								soyisim[j]=secim_2;
								j++;
							}
						}
					}while(secim_2!=13);
					
					if(secim_2==27)		break;
					
					ilk=ekle(ilk,sayi,isim,soyisim);
					for(i=0;i<10;i++)
						if(cokluk[0][i]==sayi%10)
							cokluk[1][i]++;
					selectionSort(cokluk);
					ilk=duzenle(ilk);
					bosalt(isim,soyisim);
					i=0;	j=0;	no=0;	bosluk_sayac=0;
					
					printf("eklendi\n \t");
					gecici=ilk;
					
					sayi=0;
				}while(secim_2!=27);
				
				break;
			
			case 's':
				system("cls");
				do
				{
					if(ilk==NULL)
					{
						printf("\n\tÝlk eleman bulunamadý!\n");
						getch();
						break;
					}
					
					printf("\nSilmek istediðiniz talebenin numarasýný giriniz: ");
					
					do
					{
						secim_2=getche();
						if(secim_2>=48 & secim_2<=57)
							sayi=sayi*10+secim_2-48;
					}while(secim_2>47 & secim_2<58);
					
					if(secim_2==27)		break;
					
					ilk=sil(ilk,sayi);
					for(i=0;i<10;i++)
						if(cokluk[0][i]==sayi%10)
							cokluk[1][i]--;
					selectionSort(cokluk);
					ilk=duzenle(ilk);
					
					sayi=0;
				}while(secim_2!=27);
			
				break;	
			
			case 'a':
				system("cls");
				do
				{
					if(ilk==NULL)
					{
						printf("\n\tÝlk eleman bulunamadý!");
						getch();
						break;
					}
					
					printf("\nAramak istediðiniz talebenin numarasýný giriniz: ");
					
					do
					{
						secim_2=getche();
						if(secim_2>=48 & secim_2<=57)
							sayi=sayi*10+secim_2-48;
					}while(secim_2>47 & secim_2<58);	
					
					if(secim_2==27)		break;
					
					gecici=ilk;
					
					while(gecici!=NULL)
					{
						s++;
						if(gecici->no==sayi)		break;
						gecici=gecici->next;
					}
					if(gecici==NULL)
						printf("\n\aAradýðýnýz talebe bulunamadý\n");
					else
						printf("\nAradýðýnýz talebe %d adýmda bulundu = %d %s %s\n",s,gecici->no,gecici->ad,gecici->soyad);
					
					s=0;	sayi=0;
				}while(secim_2!=27);
			
				break;		
			
			case 'l':
				system("cls");
				do
				{
					if(ilk==NULL)
					{
						printf("\n	Liste boþ!\n");
						break;
					}
					
					gecici=ilk;
					
					while(gecici!=NULL)
					{
						printf("\n%d.eleman= %d %s %s",s+1,gecici->no,gecici->ad,gecici->soyad);
						s++;
						gecici=gecici->next;
					}
					
					secim_2=getch();
					
					s=0;
				}while(secim_2!=27);
			
				break;
					
			default: break;
		}
	}
	
	
	dosya=fopen("Ödev-1.txt","w");
	
	if(dosya==NULL)
	{
		printf("\ntext dosyasý açýlamadý!");
		getch();
		return 0;
	}
	
	char sayimiz[10];
	char *cp;
	
	gecici=ilk;
	do
	{
		for(i=0;i<10;i++)
			sayimiz[i]=0;
		i=0;	
		while(gecici->no>0)
		{
			sayimiz[i]=gecici->no%10+48;
			gecici->no/=10;
			i++;
		}
		i--;
		cp=&sayimiz[i];
  		while(*cp)
  		{
    		fputc(*cp,dosya);
			cp--;
  		}
		fprintf(dosya," ");
  		cp=gecici->ad;
  		while(*cp)
  		{
    		fputc(*cp,dosya);
			cp++;
  		}
		fprintf(dosya," ");
  		cp=gecici->soyad;
  		while(*cp)
  		{
    		fputc(*cp,dosya);
			cp++;
  		}
  		if(gecici->next!=NULL)
			fprintf(dosya,"\n");
		gecici=gecici->next;
	}while(gecici!=NULL);
	
	fclose(dosya);
	return 0;
}


//**********************************************************************************************************************************************************
//**********************************************************************************************************************************************************


struct halka *ekle(halka *ilk, int sayi, char ilks[20], char sons[30])
{
	halka *yeni=(struct halka*)malloc(sizeof(struct halka));
	yeni->no=sayi;
	strcpy(yeni->ad,ilks);
	strcpy(yeni->soyad,sons);
	yeni->next=NULL;
	
	
	if(ilk==NULL)
	{
		ilk=yeni;
		return ilk;
	}
	else
	{
		halka *gecici=ilk;
		
		while(gecici->next!=NULL)
			gecici=gecici->next;
		gecici->next=yeni;
		return ilk;
	}
	

}


struct halka *duzenle(halka *ilk)
{
	int i;
	halka *gecici=ilk;
	halka *ilk2=NULL;
	
	
		for(i=9;i>=0;i--)
		{
			gecici=ilk;
			do
			{
				if(gecici->no%10==cokluk[0][i])
					ilk2=ekle(ilk2,gecici->no,gecici->ad,gecici->soyad);
				gecici=gecici->next;
			}while(gecici!=NULL);
		}
		
		return ilk2;
	
	
}


struct halka *sil(halka *ilk, int sayi)
{
	halka *gecici=ilk;
	halka *bul=NULL;
	int sayi_var=0;
	
	
	if(gecici->no==sayi)
	{
		if(ilk->next==NULL)
		{
			free(ilk);
			return NULL;
		}
		bul=ilk;
		ilk=ilk->next;
		printf("\n\t%6d %s %s silindi",sayi,bul->ad,bul->soyad);
	}
	else
	{
		while(gecici->next!=NULL)
		{
			if(gecici->next->no==sayi)
			{
				sayi_var=1;
				bul=gecici->next;
				break;
			}
			gecici=gecici->next;
		}
	
		if(sayi_var==1)
		{
			gecici->next=gecici->next->next;
			printf("\n\t%6d %s %s silindi\n",sayi,bul->ad,bul->soyad);
		}
		else
			printf("\n\t\aBöyle bir talebe yok!\n");
	}
	
	free(bul);
	return ilk;
}



void bosalt(char dizi1[20], char dizi2[30])
{
	int i;
	for(i=0;i<20;i++)
		dizi1[i]=0;
	for(i=0;i<20;i++)
		dizi2[i]=0;
}


void selectionSort (int dizi[2][10])
{
     int i, j, enKucuk, temp;
     for (i=0; i<9; i++)
     {
         enKucuk = i;
         for (j=i+1; j<10; j++)
            if(dizi[1][j]<dizi[1][enKucuk])
            	enKucuk = j;
         
         temp = dizi[0][i];
         dizi[0][i] = dizi[0][enKucuk];
         dizi[0][enKucuk] = temp;
         
         temp = dizi[1][i];
         dizi[1][i] = dizi[1][enKucuk];
         dizi[1][enKucuk] = temp;
     }
}
