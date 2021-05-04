

#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<conio.h>
using namespace std;

int ck;

class Book
{
  public:
	int b_id;
	char bname[30],author[30];
	float price;
	int copy;
};

/*FUNCTIONS DECLARATION  */

void admin();
void user();
void insert();
void disp();
void search();
void update();
void deletefile();
void sort();
void trans();
int empty();
int avlid(int);
int avla(char *);
int avlb(char *);
void searchid();
void searcha();
int ckid(int);
int ckbook(char *);
int cka(char *);
void searchb();

/*    MAIN FUNCTION     */

int main()
{
	int c, emp;
	char p[15];
	while (1)
	{
		cout<<"\n\n\t\t\t\t\t\t\tMY BOOKSHOP\n";
		cout<<"\n\t\t\t\t\t---------Select your choice---------\n";
		cout<<"\n\t\t\t\t\t1. FOR ADMIN";
		cout<<"\n\t\t\t\t\t2. FOR CUSTOMER";
		cout<<"\n\t\t\t\t\t0. EXIT";
		cout<<"\n\n\t\t\t\t\t-----------------------------------\n";
		cout<<"\n\t\t\t\t\tEnter your choice:";
		cin>>c;
		cout<<endl;
		switch (c)
		{
		case 1:
			cout<<"\n\t\t\t\t\tENTER PASSWORD:";
			cin>>p;
			if(strcmp(p,"msubook")==0)
				admin();
			else
				cout<<"\n\t\t\t\t\tInvalid Password!";
			break;
		case 2:
			user();
			break;
		case 0:
			exit(1);
			break;
		default:
			cout<<"\n\t\t\t\t\tYour choice is wrong\nPlease try again...\n";
			break;
		}
	}
	getche();
	return 0;
}

/*     ADMIN FUNCTION    */
/*FUNCTION DEFINATION   */

void admin()
{
	int c, emp;
	while (1)
	{
		cout<<"\n\n\t\t\t\t\t---------Select your choice---------\n";
		cout<<"\n\t\t\t\t\t1. INSERT\n\t\t\t\t\t2. DISPLAY\n\t\t\t\t\t3. SEARCH";
		cout<<"\n\t\t\t\t\t4. DELETE\n\t\t\t\t\t5. UPDATE\n\t\t\t\t\t6. SORT");
		cout<<"\n\t\t\t\t\t7. TRANSACTION DATAILS\n\t\t\t\t\t0. EXIT";
		cout<<"\n\n\t\t\t\t\t------------------------------------\n";
		cout<<"\n\t\t\t\t\tEnter your choice:";
		cin>>c;
		cout<<endl;
		switch (c)
		{
		case 1:
			insert();
			break;
		case 2:
			emp=empty();
			if(emp==0)
				cout<<"\n\t\t\t\t\tThe file is EMPTY\n";
			else
				disp();
			break;
		case 3:
			searchid();
			break;
		case 4:
			deletefile();
			break;
		case 5:
			update();
			break;
		case 6:
			emp=empty();
			if(emp==0)
				cout<<"\n\t\t\t\t\t The file is EMPTY\n";
			else
				sort();
			break;
		case 7:
			trans();
			break;
		case 0:
			exit(1);
			break;
		default:
			cout<<"\n\t\t\t\t\tYour choice is wrong\nPlease try again...\n";
			break;

		}
	}
	getche();
}

/*    USER FUNCTON    */

void user()
{
	int c,emp;
	while(1)
	{
		cout<<"\n\n\t\t\t\t\t--------Select your choice---------\n";
		cout<<"\n\t\t\t\t\t1. SEARCH BY BOOK NAME ";
		cout<<"\n\t\t\t\t\t2. SEARCH BY AUTHOR NAME ";
		cout<<"\n\t\t\t\t\t0. EXIT";
		cout<<"\n\n\t\t\t\t\t-----------------------------------\n";
		cout<<"\n\t\t\t\t\tEnter your choice:";
		cin>>c;
		cout<<endl;
		switch (c)
		{
		case 1:
			searchb();
			break;
		case 2:
			searcha();
			break;
		case 0:
			exit(1);
			break;
		default:
			cout<<"\n\t\t\t\t\tYour choice is wrong\nPlease try again...\n";
			break;

		}
	}
	getche();
}

/* BELOW FUNCTION USE FOR ADMIN  */

int ckid(int tempId)
{
	FILE *fp;
	int c=0;
	fp=fopen("Record.txt","rb");
	while(!feof(fp))
	{
		fread(&data,sizeof(data),1,fp);
		if(tempId==data.b_id )
		{
			fclose(fp);
			return(0);
		}
	}
	fclose(fp);
	return(1);
}

/*      FUNCTION TO INSERT RECORDS TO THE FILE    */
void add()
{
	char ans;
	int avl,tempId;;
	FILE *fp;
	fp=fopen("Record.txt","ab");
	ans='y';
	while(ans=='y')
	{
	/*StartAgain:*/
		cout<<"\n\t\t\t\t\tEnter book id:";
		cin>>tempId);

		if(ckid(tempId)){
			data.b_id=tempId;
			cin>>"\n\t\t\t\t\tEnter the Book Name   :";
			fflush(stdin);
			gets(data.bname);
			cin>>"\n\t\t\t\t\tEnter the Author Name    :";
			fflush(stdin);
			gets(data.author);
			cout<<"\n\t\t\t\t\tEnter the Price of Book   :";
			cin>>data.price;
			cout<<"\n\t\t\t\t\tEnter Copies Of Book   :";
			cin>>data.copy;
			fwrite(&data, sizeof(data),1,fp);
			printf("\n\t\t\t\t\tAdd another record ?(y/n) ");
			fflush(stdin);
			ans=getche();
			fclose(fp);
		}
		else {
			cout<<"\n\t\t\t\t\tEntered id is already exit\n\n";
		}
	}
}

/*     FUNCTION TO DISPLAY RECORD     */

void disp()
{
	FILE *fp1;
	fp1=fopen("Record.txt", "rb+");
	cout<<"------------------------------------------------------------------------------------------------------------------------";
	cout<<"\nBOOK ID\t\tBOOK NAME\t\t\t\tAUTHOR NAME\t\t\t\tPRICE(Rs.)\tCOPIES\n";
	cout<<"------------------------------------------------------------------------------------------------------------------------\n";
	while(fread(&data,sizeof(data),1,fp1))
		cout<<data.b_id<<data.bname<<data.author<<data.price<<data.copy;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	fclose(fp1);
}

/*     FUNCTION TO SEARCH THE GIVEN RECORD     */

void searchid()
{
	FILE *fp2;
	int id, s, avl;
	cout<<"\n\t\t\t\t\tEnter the Book Id you want to search  :";
	cin>>id;
	avl=avlid(id);
	if(avl==0)
		cout<<"\n\t\t\t\t\tBook Id "<< id<<" not available in the record\n";
	else
	{
		fp2=fopen("Record.txt","rb");
		while (fread(&data,sizeof(data),1,fp2))
		{
			s=data.b_id;
			if(s==id)
			{
				cout<<"\n\t\t\t\t\tBOOK ID       = %d", data.b_id);
				cout<<"\n\t\t\t\t\tBOOK NAME     = %s", data.bname);
				cout<<"\n\t\t\t\t\tAUTHOR NAME   = %s", data.author);
				cout<<"\n\t\t\t\t\tBOOK PRICE(Rs)= %f", data.price);
				cout<<"\n\t\t\t\t\tBOOK COPIES   = %d\n", data.copy);
			}
		}
		fclose(fp2);
	}
}

/*     FUNCTION TO DELETE A RECORD     */

void deletefile()
{
	FILE *fpo, *fpt;
	int id, s;
	printf("\n\t\t\t\t\tEnter the Book Id you want to Delete :");
	scanf("%d", &id);
	if (avlid(id) == 0)
		printf("\n\t\t\t\t\tBook Id %d is not available in the file\n", id);
	else
	{
		fpo = fopen("Record.txt", "rb");
		fpt = fopen("Tempfile.txt", "wb");

		while (fread(&data, sizeof(data), 1, fpo))
		{
			s = data.b_id;
			if (s != id)
				fwrite(&data, sizeof(data), 1, fpt);
		}
		fclose(fpo);
		fclose(fpt);
		fpo = fopen("Record.txt", "wb");
		fpt = fopen("Tempfile.txt", "rb");
		while (fread(&data, sizeof(data), 1, fpt))
			fwrite(&data, sizeof(data), 1, fpo);
		printf("\n\t\t\t\t\tRECORD DELETED\n");
		fclose(fpo);
		fclose(fpt);
	}
}

/*     FUNCTION TO UPDATE THE RECORD     */

void update()
{
	FILE *fpt, *fpo;
	int s, id, ch, avl;
	printf("\n\t\t\t\t\tEnter Book Id number to update:");
	scanf("%d", &id);
	avl = avlid(id);
	if (avl == 0)
	{
		printf("\n\t\t\t\t\tBook Id %d is not Available in the file", id);
	}
	else
	{
		fpo = fopen("Record.txt", "rb");
		fpt = fopen("Tempfile.txt", "wb");
		while (fread(&data, sizeof(data), 1, fpo))
		{
			s = data.b_id;
			if (s != id)
				fwrite(&data, sizeof(data), 1, fpt);
			else
			{
				printf("\n\t\t\t\t\t1. Update Book Name");
				printf("\n\t\t\t\t\t2. Update Author Name");
				printf("\n\t\t\t\t\t3. Update Price");
				printf("\n\t\t\t\t\t4. Update Copies of Book");
				printf("\n\t\t\t\t\t5. Update All");
				printf("\n\t\t\t\t\tEnter your choice:");
				scanf("%d", &ch);
				switch (ch)
				{
				case 1:
					printf("\t\t\t\t\tEnter Book Name: ");
					fflush(stdin);
					gets(data.bname);
					break;
				case 2:
					printf("\t\t\t\t\tEnter Author Name: ");
					fflush(stdin);
					gets(data.author);
					break;
				case 3:
					printf("\t\t\t\t\tEnter Price: ");
					scanf("%f", &data.price);
					break;
				case 4:
					printf("\t\t\t\t\tEnter Copies: ");
					scanf("%d", &data.copy);
					break;
				case 5:
					printf("\t\t\t\t\tEnter Book Name: ");
					fflush(stdin);
					gets(data.bname);
					printf("\t\t\t\t\tEnter Author Name: ");
					fflush(stdin);
					gets(data.author);
					printf("\t\t\t\t\tEnter Price: ");
					scanf("%f", &data.price);
					printf("\t\t\t\t\tEnter Copies: ");
					scanf("%d", &data.copy);
					break;
				default:
					printf("\n\t\t\t\t\tInvalid Selection");
					exit(1);
					break;
				}
				fwrite(&data, sizeof(data), 1, fpt);
			}
		}
		fclose(fpo);
		fclose(fpt);
		fpo = fopen("Record.txt", "wb");
		fpt = fopen("Tempfile.txt", "rb");
		while (fread(&data, sizeof(data), 1, fpt))
		{
			fwrite(&data, sizeof(data), 1, fpo);
		}
		fclose(fpo);
		fclose(fpt);
		printf("\t\t\t\t\tRECORD UPDATED");
	}
}

/*     FUNCTION TO SORT THE RECORD     */

void sort()
{
	int a[20], count = 0, i, j, t, c;
	FILE *fpo, *fpt;
	fpo = fopen("Record.txt", "rb");
	fpt = fopen("Tempfile.txt", "wb");
	while (fread(&data, sizeof(data), 1, fpo))
	{
		a[count] = data.b_id;
		count++;
	}
	c = count;
	for (i = 0; i < count - 1; i++)
	{
		for (j = i + 1; j < count; j++)
		{
			if (a[i] > a[j])
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	printf("------------------------------------------------------------------------------------------------------------------------");
	printf("BOOK ID\t\tBOOK NAME\t\t\t\tAUTHOR NAME\t\t\t\tPRICE(Rs)\tCOPIES\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	count = c;
	for (i = 0; i < count; i++)
	{
		rewind(fpo);
		while (fread(&data, sizeof(data), 1, fpo))
		{
			if (a[i] == data.b_id)
			{
				printf("\n%d\t\t%-30s\t\t%-30s\t\t%.2f\t\t%d", data.b_id, data.bname, data.author, data.price, data.copy);
			}
		}
	}
	fclose(fpo);
	printf("\n");
}




/*     FUNCTION TO CHECK GIVEN BOOK ID IS AVAILABLE OR NOT     */

int avlid(int bid)
{
	FILE *fp;
	int c = 0;
	fp = fopen("Record.txt", "rb");
	while (!feof(fp))
	{
		fread(&data, sizeof(data), 1, fp);
		if (bid == data.b_id)
		{
			fclose(fp);
			ck = 1;
			return 1;
		}
	}
	fclose(fp);
	ck = 1;
	return 0;
}

/*      FUNCTION TO CHECK THE FILE IS EMPTY OR NOT     */

int empty()
{
	int c = 0;
	FILE *fp;
	fp = fopen("Record.txt", "rb");
	while (fread(&data, sizeof(data), 1, fp))
		c = 1;
	fclose(fp);
	return c;
}

/* FUNCTIONS FOR USER  */

/*      CHECK AUTHOR NAME IS AVAILABLE OR NOT    */

int avla(char a[30])
{
	FILE *fp;
	int c[30];
	fp = fopen("Record.txt", "rb");
	while (!feof(fp))
	{
		fread(&data, sizeof(data), 1, fp);
		if (strcmp(a, data.author) == 0)
		{
			fclose(fp);
			return 1;
		}
	}
	fclose(fp);
	return 0;
}

/*      CHECK BOOK NAME IS AVAILABLE OR NOT     */

int avlb(char b[30])
{
	FILE *fp;
	char c[30];
	fp = fopen("Record.txt", "rb");
	while (!feof(fp))
	{
		fread(&data, sizeof(data), 1, fp);
		if (strcmp(b, data.bname) == 0)
		{
			fclose(fp);
			return 1;
		}
	}
	fclose(fp);
	return 0;
}

/*     SEARCH BY AUTHOR NAME    */

void searcha()
{
	FILE *fpo, *fp2, *fpt, *ftr;
	int m=0,cp1,id,n,i,s;
	float total1 = 0;
	char an[30], s2[30], avl;
	printf("\n\t\t\t\t\tHow many book you want to buy ? ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("\n\t\t\t\t\tEnter the Author Name you want to search  :");
		fflush(stdin);
		gets(an);
		avl = avla(an);
		if (avl == NULL)
		{
			printf("\n\t\t\t\t\tAuthor %s is not available\n", an);
			break;
		}
		else
		{
			fpo = fopen("Record.txt", "rb");
			rewind(fpo);
			while (fread(&data, sizeof(data), 1, fpo))
			{
				strcpy(s2, data.author);
				if (strcmp(s2, an) == 0)
				{
					printf("\n\t\t\t\t\tAUTHOR NAME= %s", data.author);
					printf("\n\t\t\t\t\tBOOK NAME  = %s", data.bname);
					printf("\n\t\t\t\t\tBOOK ID    = %d", data.b_id);
					printf("\n\t\t\t\t\tBOOK PRICE = %.2f", data.price);
					printf("\n\t\t\t\t\tBOOK COPIES= %d\n", data.copy);
					printf("\n\t\t\t\t\tEnter No. of Copies you want : ");
					scanf("%d", &cp1);

					m = data.copy - cp1;
					if (m > 0 && cp1 != 0)
					{
						printf("\n\t\t\t\t\tEnter Book id of This Book(FOR CONFIRMATION YOUR ORDER) :");
						scanf("%d", &id);
							total1 = total1 + (float)cp1*data.price;
						printf("\n\n\t\t\t\t\tBill Generated!");
	                   printf("\n\n\n\n\t\t\t\tMSU BOOKSTORE");
	                  printf("\n------------------------------------------------------------------------------------------------------------------------------------");
	                  printf("\nBOOK ID\t\tBOOK NAME\t\t\t\tAUTHOR NAME\t\t\t\tPRICE(Rs.)\tCOPIES  TOTAL\n");
	                  printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
	                  printf("%d\t\t%-30s\t\t%-30s\t\t%.2f\t\t%d\t%.2f\n", data.b_id, data.bname, data.author, data.price, cp1,total1);
	                  printf("\n-------------------------------------------------------------------------------------------------------------------------------------");
						ftr = fopen("Transection.txt", "ab+");
						data.copy = cp1;
						fwrite(&data, sizeof(data), 1, ftr);
						fclose(ftr);
						fp2 = fopen("Record.txt", "rb+");
						fpt = fopen("Tempfile.txt", "wb+");

						while (fread(&data, sizeof(data), 1, fp2))
						{
							s = data.b_id;
							if (s != id)
							{
								fwrite(&data, sizeof(data), 1, fpt);
							}
							else
							{
								data.copy = m;
								fwrite(&data, sizeof(data), 1, fpt);
							}
						}
						fclose(fp2);
						fclose(fpt);
						fp2 = fopen("Record.txt", "wb");
						fpt = fopen("Tempfile.txt", "rb+");
						while (fread(&data, sizeof(data), 1, fpt))
						{
							fwrite(&data, sizeof(data), 1, fp2);
						}
						fclose(fp2);
						fclose(fpt);
						break;
					}
					else if (cp1 == 0)
					{
						printf("\n\t\t\t\t\t==>>Press Enter to Show Another Book of Same Author.\n");
						getche();
					}
					else
						printf("\n\t\t\t\t\tCopies are Not Available");
				}
			}
		}
		fclose(fpo);

	}
}

/*    SEARCH BY BOOK NAME    */

void searchb()
{
	FILE *fp2, *fpo, *fpt, *ftr;
	int cp2, m = 0,i,n, id, s;
	float total2 = 0;
	char bn[30], s2[30], avl;
	printf("\n\t\t\t\t\tHow many do you want to buy ? ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("\n\t\t\t\t\tEnter the Book Name you want to search  :");
		fflush(stdin);
		gets(bn);
		avl = avlb(bn);
		if (avl == NULL)
		{
			printf("\n\t\t\t\t\tBook %s is not available.\n", bn);
			break;
		}
		else
		{
			fpo = fopen("Record.txt", "rb+");
			rewind(fpo);
			while (fread(&data, sizeof(data), 1, fpo))
			{
				strcpy(s2, data.bname);
				if (strcmp(s2, bn) == 0)
				{
					printf("\n\t\t\t\t\tBOOK NAME  = %s", data.bname);
					printf("\n\t\t\t\t\tBOOK ID    = %d", data.b_id);
					printf("\n\t\t\t\t\tAUTHOR NAME= %s", data.author);
					printf("\n\t\t\t\t\tBOOK PRICE = %.2f", data.price);
					printf("\n\t\t\t\t\tBOOK COPIES= %d\n", data.copy);
					printf("\n\t\t\t\t\tEnter No. of Copies you want : ");
					scanf("%d", &cp2);

					m = data.copy - cp2;
					if (m > 0 && cp2 != 0)
					{
					printf("\n\t\t\t\t\tEnter Book Id of This Book(FOR CONFIRMATION YOUR ORDER):");
						scanf("%d", &id);

						total2 = total2 + (float)cp2*data.price;

						printf("\n\n\t\t\t\t\tBill Generated!");
	                  printf("\n\n\n\n\t\t\t\tMSU BOOKSTORE");
	                  printf("\n------------------------------------------------------------------------------------------------------------------------------------");
	                  printf("\nBOOK ID\t\tBOOK NAME\t\t\t\tAUTHOR NAME\t\t\t\tPRICE(Rs.)\tCOPIES  TOTAL\n");
	                  printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
	                  printf("%d\t\t%-30s\t\t%-30s\t\t%.2f\t\t%d    %.2f\n", data.b_id, data.bname, data.author, data.price, cp2,total2);
	                  printf("\n-------------------------------------------------------------------------------------------------------------------------------------");

						ftr = fopen("Transection.txt", "ab+");
						data.copy = cp2;
						fwrite(&data, sizeof(data), 1, ftr);
						fclose(ftr);
						fp2 = fopen("Record.txt", "rb+");
						fpt = fopen("Tempfile.txt", "wb+");
						while (fread(&data, sizeof(data), 1, fp2))
						{
							s = data.b_id;
							if (s != id)
							{
								fwrite(&data, sizeof(data), 1, fpt);
							}
							else
							{
								data.copy = m;
								fwrite(&data, sizeof(data), 1, fpt);
							}
						}
						fclose(fp2);
						fclose(fpt);
						fp2 = fopen("Record.txt", "wb");
						fpt = fopen("Tempfile.txt", "rb+");
						while (fread(&data, sizeof(data), 1, fpt))
						{
							fwrite(&data, sizeof(data), 1, fp2);
						}
						fclose(fp2);
						fclose(fpt);
						break;
					}
					else if (cp2 == 0)
					{
						printf("\n\t\t\t\t\t==>>Press Enter to Show Book of Different Author.\n");
						getche();
					}
					else
						printf("\n\t\t\t\t\tCopies are Not Available");
				}
			}
		}
		fclose(fpo);
	}
}

void trans()
{
	FILE *ftr;
	ftr = fopen("Transection.txt", "rb+");
	if (ftr == NULL)
	{
		ftr = fopen("Transection.txt", "ab+");
		if (ftr == NULL)
		{
			puts("\n\t\t\t\tCannot open file");
			getche();
			exit(0);
		}
	}
	rewind(ftr);
	printf("------------------------------------------------------------------------------------------------------------------------");
	printf("\nBOOK ID\t\tBOOK NAME\t\t\t\tAUTHOR NAME\t\t\t\tPRICE(Rs.)\tCOPIES\n");
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	while (fread(&data, sizeof(data), 1, ftr) == 1)
	{
		printf("%d\t\t%-30s\t\t%-30s\t\t%.2f\t\t%d\n", data.b_id, data.bname, data.author, data.price, data.copy);
	}
	printf("------------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\t\t\t\t\tPress Enter To Exit.");
	fclose(ftr);
	getche();
}
