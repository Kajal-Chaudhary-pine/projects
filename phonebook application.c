#include <stdio.h> 
#include <stdlib.h>
#include <conio.h>
#include <windows.h> 
#include <string.h>  


void add_rec();
void list_rec();
void modify_rec();
void search_rec();
void delete_rec();
void exit(int);


    FILE *fp, *ft;
    char ano, ch;
 
struct contact
    {
        char name[40]; 
        int age;
        char address[20];
        char email[20];
        char contact_no[20];
        
    };

    struct contact e;

    char input[40];


        void add_rec()
         {   
            system("cls");
            fp = fopen("CONTACT.DAT","rb+");
            if(fp == NULL)
             {
              fp = fopen("CONTACT.DAT","wb+");
              if(fp == NULL)
               {
                 printf("Connot open file");
                 exit(0);
               }
             }
            fseek(fp,0,SEEK_END); 
            
            ano = 'y';
            while(ano == 'y')  
            {
                printf("Enter name: \n");
                scanf("%s",e.name);
                printf("Enter age: \n");
                scanf("%d", &e.age);
                printf("Enter address: \n");
                scanf("%s",e.address);
                printf("Enter email id: \n");
                scanf("%s",e.email);
                printf("Enter contact number:\n");
                scanf("%s",e.contact_no);
                fwrite(&e,sizeof(e),1,fp); 

                printf("\nAdd another record(y/n) ");
                fflush(stdin);
                ano = getche();
            }
                fclose(fp);
          }
        

        void list_rec()
          {
            system("cls");
            fp = fopen("CONTACT.DAT","rb+");
            if(fp == NULL)
             {
              fp = fopen("CONTACT.DAT","wb+");
              if(fp == NULL)
               {
                 printf("Connot open file");
                 exit(0);
               }
             }
            
            rewind(fp); 
            while(fread(&e,sizeof(e),1,fp)==1)  
            {
                printf("\n%s %d %s %s %s",e.name,e.age,e.address,e.email,e.contact_no); 
            }
            getch();
            fclose(fp);
          }

        

        void modify_rec()
          {  
            system("cls");
             fp = fopen("CONTACT.DAT","rb+");
             if(fp == NULL)
             {
              fp = fopen("CONTACT.DAT","wb+");
              if(fp == NULL)
               {
                 printf("Connot open file");
                 exit(0);
               }
             }
            ano = 'y';
            while(ano == 'y')
            {
                printf("Enter the contact to modify: ");
                scanf("%s", input);
                rewind(fp);
                while(fread(&e,sizeof(e),1,fp)==1)  
                {
                    if(strcmp(e.name,input) == 0)  
                    {
                        printf("\nEnter new name,age,address,email,contact no: ");
                        scanf("%s%d%s%s%s",e.name,&e.age,e.address,e.email,e.contact_no);
                        fseek(fp,-sizeof(e),SEEK_CUR); 
                        fwrite(&e,sizeof(e),1,fp); 
                        break;
                    }
                }
                printf("\nModify another record(y/n)");
                fflush(stdin);
                ano = getche();
            }
                fclose(fp);
          }

 
        void search_rec()
          {
            system("cls");
            fp = fopen("CONTACT.DAT","rb+");
             if(fp == NULL)
             {
              fp = fopen("CONTACT.DAT","wb+");
              if(fp == NULL)
               {
                 printf("Connot open file");
                 exit(0);
               }
             }
            ano = 'y';
            while(ano=='y')
            {
             printf("enter the name\n");
             scanf("%s",input);
             fp=fopen("CONTACT.dat","rb");
             rewind(fp);
             while(fread(&e,sizeof(e),1,fp) == 1)
             {
                  if(strcmp(e.name,input)==0)
                  {
                   printf("\n%s %d %s %s %s",e.name,e.age,e.address,e.email,e.contact_no);     
                  }
             }
           
             printf("want to search more record(y/n)");
             fflush(stdin);
             ano = getche();
             }
             fclose(fp);
           }       



       void delete_rec()
         {
            system("cls");
            fp = fopen("CONTACT.DAT","rb+");
             if(fp == NULL)
             {
              fp = fopen("CONTACT.DAT","wb+");
              if(fp == NULL)
               {
                 printf("Connot open file");
                 exit(0);
               }
             }
            ano = 'y';
            while(ano == 'y')
            {
                printf("\nEnter contact to delete: ");
                scanf("%s",input);
                ft = fopen("TEMP.dat","wb");  
                rewind(fp); 
                while(fread(&e,sizeof(e),1,fp) == 1)  
                {
                    if(strcmp(e.name,input) != 0)  
                    {
                        fwrite(&e,sizeof(e),1,ft); 
                    }
                }
                fclose(fp);
                fclose(ft);
                remove("CONTACT.DAT"); 
                rename("TEMP.dat","CONTACT.DAT"); 
                fp = fopen("CONTACT.DAT", "rb+");
                printf("Delete another record(y/n)");
                fflush(stdin);
                ano = getche();
            }
                fclose(fp);
          }
        

int main()
{
    
int ch;
    
  do
    {
        system("cls"); 
        
        printf("1. Add Record\n"); 
        
        printf("2. List Records\n"); 
        
        printf("3. Modify Records\n");

        printf("4. Search Records\n"); 
        
        printf("5. Delete Records\n"); 
        
        printf("6. Exit\n"); 
        
        printf("Enter Your Choice: "); 
        fflush(stdin); 
        ch  = getche(); 
        switch(ch)
        {
        
        case '1':
        add_rec();
        break;
        
        case '2':
        list_rec();
        break;
    
        case '3':
        modify_rec();
        break;
     
        case '4':
        search_rec();
        break;
     
        case '5':
        delete_rec();
        break;

        case '6':
        exit(0);
        break;
       
        default:
        printf("Invalid choice:\n");
        break;
        }
     } 
        while(ch>5);
        return 0;
            
   }
            
        
        
