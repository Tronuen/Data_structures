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
struct Node *edit(Node *head);
struct Node *remove(Node *head, int number);
void clear(char array1[20], char array2[30]);
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
			head = edit(head);
			clear(name, surname);
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
				printf("\nPlease enter the number, name and surname of the student you want to add, leaving a space:\n\n\t");
				do
				{
					clear(name, surname);
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
					head = edit(head);
					clear(name, surname);
					i=0;	j=0;	no=0;	space_ct=0;
					
					printf("Added\n \t");
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
						printf("\n\tFirst element not found!\n");
						getch();
						break;
					}
					
					printf("\nEnter the number of the student you want to delete ");
					
					do
					{
						choice_2 = getche();
						if(choice_2>=48 & choice_2<=57)
							number=number*10+choice_2-48;
					}while(choice_2>47 & choice_2<58);
					
					if(choice_2==27)		break;
					
					head = remove(head, number);
					for(i=0;i<10;i++)
						if(number_of_numbers[0][i]==number%10)
							number_of_numbers[1][i]--;
							
					selectionSort(number_of_numbers);
					head = edit(head);
					
					number = 0;
				}while(choice_2!=27);
			
				break;	
			
			case 's':
				system("cls");
				do
				{
					if(head==NULL)
					{
						printf("\n\tFirst element not found!");
						getch();
						break;
					}
					
					printf("\nEnter the number of the student you want to search: ");
					
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
						printf("\n\aThe student you are looking could not be found.\n");
					else
						printf("\nThe student you are looking found at %d step = %d %s %s\n", s, temp->no, temp->name, temp->surname);
					
					s=0;	number=0;
				}while(choice_2!=27);
			
				break;		
			
			case 'w':
				system("cls");
				do
				{
					if(head==NULL)
					{
						printf("\n	The list is empty!\n");
						break;
					}
					
					temp = head;
					
					while(temp!=NULL)
					{
						printf("\n%d.element = %d %s %s", s+1, temp->no, temp->name, temp->surname);
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
	
	
	file = fopen("Students.txt", "w");
	
	if(file==NULL)
	{
		printf("\nCan't open text file!");
		getch();
		return 0;
	}
	
	char my_number[10];
	char *cp;
	
	temp = head;
	do
	{
		for(i=0;i<10;i++)
			my_number[i]=0;
		i = 0;	
		while(temp->no>0)
		{
			my_number[i] = temp->no%10 + 48;
			temp->no /= 10;
			i++;
		}
		i--;
		cp = &my_number[i];
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


struct Node *add(Node *head, int number, char heads[20], char tails[30])
{
	Node *nevv = (struct Node*)malloc(sizeof(struct Node));
	nevv->no = number;
	strcpy(nevv->name, heads);
	strcpy(nevv->surname, tails);
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


struct Node *edit(Node *head)
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


struct Node *remove(Node *head, int number)
{
	Node *temp = head;
	Node *find = NULL;
	int number_var = 0;
	
	
	if(temp->no==number)
	{
		if(head->next==NULL)
		{
			free(head);
			return NULL;
		}
		find = head;
		head = head->next;
		printf("\n\t%6d %s %s deleted", number, find->name, find->surname);
	}
	else
	{
		while(temp->next!=NULL)
		{
			if(temp->next->no==number)
			{
				number_var = 1;
				find = temp->next;
				break;
			}
			temp = temp->next;
		}
	
		if(number_var==1)
		{
			temp->next = temp->next->next;
			printf("\n\t%6d %s %s deleted\n", number, find->name, find->surname);
		}
		else
			printf("\n\t\aThere is no such student!\n");
	}
	
	free(find);
	return head;
}



void clear(char array1[20], char array2[30])
{
	int i;
	for(i=0;i<20;i++)
		array1[i] = 0;
	for(i=0;i<20;i++)
		array2[i] = 0;
}


void selectionSort (int array[2][10])
{
     int i, j, min, temp;
     for (i=0; i<9; i++)
     {
         min = i;
         for (j=i+1; j<10; j++)
            if(array[1][j]<array[1][min])
            	min = j;
         
         temp = array[0][i];
         array[0][i] = array[0][min];
         array[0][min] = temp;
         
         temp = array[1][i];
         array[1][i] = array[1][min];
         array[1][min] = temp;
     }
}
