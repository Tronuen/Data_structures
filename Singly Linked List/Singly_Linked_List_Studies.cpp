#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>


struct	Node *head2 = NULL;
int number_of_numbers[2][10];


struct Node
{
	int no;
	char name[20];
	char surname[30];
	struct Node *next;
};



struct Node *add(Node *head, int number, char heads[20], char sons[30]);
struct Node *duzenle(Node *head);
struct Node *sil(Node *head, int number);
void bosalt(char array1[20], char array2[30]);
void selectionSort(int array[2][10]);



main()
{
	Node *head = NULL;
	Node *temp;
	int i=0, j=0, number=0, s=0, no=0, space_ct=0;
	char letter, choice, choice_2=48;
	char name[20], surname[30];
	
	for(i=0;i<10;i++)
	{
		number_of_numbers[0][i] = i;
		number_of_numbers[1][i] = 0;
	}
	
	FILE *file;
	
	file = fopen("Students.txt", "r");
	
	if(file==NULL)
	{
		printf("\nCan't open text file!");
		getch();
		return 0;
	}
	
	while(!feof(file))
	{
		letter = fgetc(file);
		
		if(letter=='\n' || feof(file))
		{
			head = add(head, no, name, surname);
			for(i=0;i<10;i++)
				if(number_of_numbers[0][i]==no%10)
					number_of_numbers[1][i]++;
					
			selectionSort(number_of_numbers);
			head = duzenle(head);
			bosalt(name, surname);
			i=0;	j=0;	no=0;	space_ct=0;
		}
		else
		{
			if(letter>='0' && letter<='9')
			{
				no = no*10 + (letter-48);
			}
			else if(letter==' ')	space_ct++;
			else
			{
				if(space_ct==1)
				{
					name[i] = letter;
					i++;
				}
				else if(space_ct==2)
				{
					surname[j] = letter;
					j++;
				}
			}
		}
	}
	
	fclose(file);
	
	
	
	while(choice!=27)
	{
		system("cls");
		printf("\n\tMENU");
		printf("\n\n a)---->Add");
		printf("\n d)---->Delete");
		printf("\n s)---->Search");
		printf("\n w)---->Show\n");
		printf("\n ESC)---->Exit\n");
		
		choice=getch();
		
		switch(choice)
		{
			case 'a':
				system("cls");
				printf("\nSýrasýyla, addmek istediðiniz talebenin numarasýný nameýný ve surnameýný boþluk býrakarak giriniz:\n\n\t");
				do
				{
					bosalt(name,surname);
					i=0;	j=0;	no=0;	space_ct=0;
					do
					{
						choice_2 = getche();
						if(choice_2==27)		break;
						else if(choice_2>=48 & choice_2<=57)
							number = number*10 + choice_2-48;
						else if(choice_2==' ')		space_ct++;
						else
						{
							if(space_ct==1)
							{
								name[i] = choice_2;
								i++;
							}
							else if(space_ct==2)
							{
								surname[j] = choice_2;
								j++;
							}
						}
					}while(choice_2!=13);
					
					if(choice_2==27)		break;
					
					head = add(head, number, name, surname);
					for(i=0;i<10;i++)
						if(number_of_numbers[0][i]==number%10)
							number_of_numbers[1][i]++;
							
					selectionSort(number_of_numbers);
					head = duzenle(head);
					bosalt(name, surname);
					i=0;	j=0;	no=0;	space_ct=0;
					
					printf("addndi\n \t");
					temp = head;
					
					number = 0;
				}while(choice_2!=27);
				
				break;
			
			case 'd':
				system("cls");
				do
				{
					if(head==NULL)
					{
						printf("\n\tÝlk eleman bulunamnameý!\n");
						getch();
						break;
					}
					
					printf("\nSilmek istediðiniz talebenin numarasýný giriniz: ");
					
					do
					{
						choice_2 = getche();
						if(choice_2>=48 & choice_2<=57)
							number=number*10+choice_2-48;
					}while(choice_2>47 & choice_2<58);
					
					if(choice_2==27)		break;
					
					head = sil(head, number);
					for(i=0;i<10;i++)
						if(number_of_numbers[0][i]==number%10)
							number_of_numbers[1][i]--;
							
					selectionSort(number_of_numbers);
					head = duzenle(head);
					
					number = 0;
				}while(choice_2!=27);
			
				break;	
			
			case 's':
				system("cls");
				do
				{
					if(head==NULL)
					{
						printf("\n\tÝlk eleman bulunamnameý!");
						getch();
						break;
					}
					
					printf("\nAramak istediðiniz talebenin numarasýný giriniz: ");
					
					do
					{
						choice_2 = getche();
						if(choice_2>=48 & choice_2<=57)
							number=number*10+choice_2-48;
					}while(choice_2>47 & choice_2<58);	
					
					if(choice_2==27)		break;
					
					temp = head;
					
					while(temp!=NULL)
					{
						s++;
						if(temp->no==number)		break;
						temp = temp->next;
					}
					if(temp==NULL)
						printf("\n\aArnameýðýnýz talebe bulunamnameý\n");
					else
						printf("\nArnameýðýnýz talebe %d nameýmda bulundu = %d %s %s\n", s, temp->no, temp->name, temp->surname);
					
					s=0;	number=0;
				}while(choice_2!=27);
			
				break;		
			
			case 'w':
				system("cls");
				do
				{
					if(head==NULL)
					{
						printf("\n	Liste boþ!\n");
						break;
					}
					
					temp = head;
					
					while(temp!=NULL)
					{
						printf("\n%d.eleman= %d %s %s", s+1, temp->no, temp->name, temp->surname);
						s++;
						temp = temp->next;
					}
					
					choice_2 = getch();
					
					s = 0;
				}while(choice_2!=27);
			
				break;
					
			default: break;
		}
	}
	
	
	file = fopen("Ödev-1.txt","w");
	
	if(file==NULL)
	{
		printf("\ntext filesý açýlamnameý!");
		getch();
		return 0;
	}
	
	char numbermiz[10];
	char *cp;
	
	temp = head;
	do
	{
		for(i=0;i<10;i++)
			numbermiz[i]=0;
		i = 0;	
		while(temp->no>0)
		{
			numbermiz[i] = temp->no%10 + 48;
			temp->no /= 10;
			i++;
		}
		i--;
		cp = &numbermiz[i];
  		while(*cp)
  		{
    		fputc(*cp, file);
			cp--;
  		}
		fprintf(file, " ");
  		cp = temp->name;
  		while(*cp)
  		{
    		fputc(*cp, file);
			cp++;
  		}
		fprintf(file, " ");
  		cp = temp->surname;
  		while(*cp)
  		{
    		fputc(*cp, file);
			cp++;
  		}
  		if(temp->next!=NULL)
			fprintf(file, "\n");
		temp = temp->next;
	}while(temp!=NULL);
	
	fclose(file);
	return 0;
}


//**********************************************************************************************************************************************************
//**********************************************************************************************************************************************************


struct Node *add(Node *head, int number, char heads[20], char sons[30])
{
	Node *nevv = (struct Node*)malloc(sizeof(struct Node));
	nevv->no = number;
	strcpy(nevv->name, heads);
	strcpy(nevv->surname, sons);
	nevv->next = NULL;
	
	
	if(head==NULL)
	{
		head = nevv;
		return head;
	}
	else
	{
		Node *temp = head;
		
		while(temp->next!=NULL)
			temp = temp->next;
		temp->next = nevv;
		return head;
	}
	

}


struct Node *duzenle(Node *head)
{
	int i;
	Node *temp = head;
	Node *head2 = NULL;
	
	
		for(i=9;i>=0;i--)
		{
			temp = head;
			do
			{
				if(temp->no%10==number_of_numbers[0][i])
					head2 = add(head2, temp->no, temp->name, temp->surname);
				temp = temp->next;
			}while(temp!=NULL);
		}
		
		return head2;
	
	
}


struct Node *sil(Node *head, int number)
{
	Node *temp = head;
	Node *bul = NULL;
	int number_var = 0;
	
	
	if(temp->no==number)
	{
		if(head->next==NULL)
		{
			free(head);
			return NULL;
		}
		bul = head;
		head = head->next;
		printf("\n\t%6d %s %s silindi", number, bul->name, bul->surname);
	}
	else
	{
		while(temp->next!=NULL)
		{
			if(temp->next->no==number)
			{
				number_var = 1;
				bul = temp->next;
				break;
			}
			temp = temp->next;
		}
	
		if(number_var==1)
		{
			temp->next = temp->next->next;
			printf("\n\t%6d %s %s silindi\n", number, bul->name, bul->surname);
		}
		else
			printf("\n\t\aBöyle bir talebe yok!\n");
	}
	
	free(bul);
	return head;
}



void bosalt(char array1[20], char array2[30])
{
	int i;
	for(i=0;i<20;i++)
		array1[i] = 0;
	for(i=0;i<20;i++)
		array2[i] = 0;
}


void selectionSort (int array[2][10])
{
     int i, j, enKucuk, temp;
     for (i=0; i<9; i++)
     {
         enKucuk = i;
         for (j=i+1; j<10; j++)
            if(array[1][j]<array[1][enKucuk])
            	enKucuk = j;
         
         temp = array[0][i];
         array[0][i] = array[0][enKucuk];
         array[0][enKucuk] = temp;
         
         temp = array[1][i];
         array[1][i] = array[1][enKucuk];
         array[1][enKucuk] = temp;
     }
}
