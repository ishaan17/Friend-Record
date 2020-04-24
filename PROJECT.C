#include<stdio.h>
#include<conio.h>
#include<process.h>

struct Friend
{
	char name[20];
	char phone[12];

};

void main (int argc, char *argv[])
{
	struct Friend f;
	FILE *fp;
	int choice,flag;
	char name1[20];
	fp=fopen(argv[1],"rb+");
	if (fp==NULL)
		fp=fopen(argv[1],"wb+");

	while(1)
	{
		clrscr();
		printf("\n 1. ADD FRIEND");
		printf("\n 2. VIEW ALL FRIEND");
		printf("\n 3. SEARCH FRIEND");
		printf("\n 4. MODIFY FRIEND RECORD");
		printf("\n 8. EXIT ");
		printf("\n  enter your choice ");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				printf("\n enter name");
				fflush(stdin);
				gets(f.name);
				printf("\n enter phone");
				fflush(stdin);
				gets(f.phone);

				fseek(fp,0,SEEK_END);
				fwrite(&f,sizeof(f),1,fp);
				break;
			case 2:
				fseek(fp,0,SEEK_SET);
				while(fread(&f,sizeof(f),1,fp)==1)
				{
					printf("\n Name=%s",f.name);
					printf("  Phone=%s",f.phone);
				}
				break;
			case 3:
				printf("\n enter the name to search");
				fflush(stdin);
				gets(name1);
				flag=0;
				fseek (fp,0,SEEK_SET);
				while (fread(&f,sizeof(f),1,fp)==1)
				{
					if(strcmp(name1,f.name)==0)
					{
						printf("\n name=%s",f.name);
						printf("\n phone=%s",f.phone);
						flag=1;
						break;
					}
				}
				if (flag==0)
				   printf("\n name not found");
				break;
			case 4: printf("\n enter the name to modify\n");
				fflush(stdin);
				gets(name1);
				flag=0;
				fseek (fp,0,SEEK_SET);
				while (fread(&f,sizeof(f),1,fp)==1)
				{
					if(strcmp(name1,f.name)==0)
					{
						printf("\n enter modified name");
						fflush(stdin);
						gets(f.name);
						printf("\n enter modified phone");
						fflush(stdin);
						gets(f.phone);
						fseek(fp,-sizeof(f),SEEK_CUR);
						fwrite(&f,sizeof(f),1,fp);
						printf("\nRecord Modified");
						flag=1;
						break;
					}
				}
				if (flag==0)
				   printf("\n name not found");
				break;
			case 8:
				fclose(fp);
				exit(0);

			default:
				printf("\n wrong choice");
			}
			getch();
		}

}








