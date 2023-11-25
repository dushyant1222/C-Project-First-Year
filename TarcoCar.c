#include<stdio.h>
#include<windows.h>//gotoxy()
#include<conio.h> //for getch()
#include<ctype.h>//use for toupper(), tolower()
#include<string.h>//use for strcmp()
#include<stdlib.h>

char ans=0;
int ok;
int b, valid=0;

//FUNCTION DECLERATION
void welcomeScreen(); //WelcomeScreen Function Deceleration
void Title();       //Title Function Deceleration
void MainMenu();     //MainMenu function deceleration
void add_car();     //add_car function deceleration
void display_car();  //display_car function deceleration
void search_car();   //search_car function deceleration
void update_car(); //update_car function deceleration
void delete_car(); //delete_car function deceleration
void ex_it();      //exit function deceleration
void gotoxy(short x, short y)
{
    COORD Pos ={x,y}; //sets co-ordinates in (x,y)
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
}
//List of Global Variable
struct car
{
    char car_name[25];
    char car_model[50];
    int year;
    char car_color[10];
    double car_price;
    int available; //1 for available , 0 for sold
}s;
struct car c ,temp_c;
int main()
{
    welcomeScreen(); //use to call the welcomeScreen function
    Title();  //use to call the title function
    MainMenu();
    
}
/* ************************************************Welcome Screen************************************** */
void welcomeScreen() //Function for welcome screen
{
    printf("\n\n\n\n\n\n\n\t\t\t\t#########################################");
    printf("\n\n\t\t\t\t\t WELCOME TO");
    printf("\n\t\t\t\tTARCO CAR SHOWROOM INFORMATION CENTRE");
    printf("\n\n\t\t\t\t#########################################");
    printf("\n\n\n\n\npress any key to continue.....\n\n");
    getch();
    system("cls"); //use to clear the screen

}
/* ***************************************Title Screen************************************************* */
void Title() //function for title
{
    printf("--------------------------------------------------------------------------------------------------------------");
    printf("\n\t\t\t\t\tTARCO CAR SHOWROOM\n\n");
    printf("--------------------------------------------------------------------------------------------------------------");
}
/* ************************************Main Menu********************************************* */
void MainMenu()//function deceleration
{
    system("cls");
    int choose;
    Title(); //Call Title Function
    printf("\n\t\t\t\t\t\t1. Add Car Information\n");
    printf("\t\t\t\t\t\t2. Display Car Information\n");
    printf("\t\t\t\t\t\t3. Search Car Information\n");
    printf("\t\t\t\t\t\t4. Update Car Information\n");
    printf("\t\t\t\t\t\t5. Delete Car Information\n");
    printf("\t\t\t\t\t\t6. Exit\n");
    scanf("%d",&choose);
    switch(choose)
    {
        case 1:
           add_car();
           break;
        case 2:
           display_car();
           break;
        case 3:
           search_car();
           break;
        case 4:
           update_car();
           break;
        case 5:
           delete_car();
           break;
        case 6:
           ex_it();
           break;
        default:
           printf("\n\n\n\nInvalid entry , PLease choose right option\n");
           getch();
           MainMenu();
    }
       
}
/* ************************************Add Car Information *********************************************** */
void add_car()
{
    system("cls"); //Use to clear the screeen
    Title();  // call the title function
    FILE*ek;  //File Pointer
    ek = fopen("Car_Inf.txt","a");  //open file in write mode
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\nAdd Car Information\n\n\n\n\n\n");
  /* *****************************************************Car Name************************************************ */
   A:
   printf("\nCar Name: ");
   scanf("%s",&c.car_name);
   c.car_name[0]=toupper(c.car_name[0]);
   if (strlen(c.car_name)>15 || strlen(c.car_name)<2)
   {
    printf("\nInvalid input :( \t the max range for the car name is 15 and min range is 2 :)");
    goto A;
   }
   else
   {
      for(b=0;b<strlen(c.car_name);b++)
      {
         if(isalpha(c.car_name[b]))
         {
            valid=1;
         }
         else
         {
            valid=0;
            break;
         }
      }
      if(!valid)
      {
         printf("\n\n\n\tCar Name contains invalid Character( Enter again: ");
         goto A;
      }
   }
   /* **********************************Car Model***************************************** */
   do 
   {
      B:
      printf("\n\nCar Model: ");
      scanf("%s",&c.car_model);
      c.car_model[0] = toupper(c.car_model[0]);
      if(strlen(c.car_model)>15 || strlen(c.car_model)<5)
      {
         printf("\n\n\nInvalid Output :( The max limit for model number is 15 and the min limit is 5 :( ");
         goto B;
      }
   }while(!valid);
   /* ****************************************Year****************************************** */
   I:
   printf("\n\nYear: ");
   scanf("%d",&c.year);
   if(c.year>2023 || c.year<1960)
   {
      printf("Invalid Input :(\tThe year should be between 1960 to 2023.");
      goto I;
   }
   /* ****************************************Car Color****************************************** */
   C:
   printf("\n\n Car Color: ");
   scanf("%s",&c.car_color);
   if(strlen(c.car_color)>10 || strlen(c.car_color)<2)
   {
      printf("\n\n\nInvalid Output :(  The max limit for car color is 10 and the min limit is 2 :( ");
      goto C;
   }
   else
   {
      for(b=0;b<strlen(c.car_color);b++)
      {
         if(isalpha(c.car_color[b]))
         {
            valid=1;
         }
         else
         {
            valid=0;
            break;
         }
      }
      if(!valid)
      {
         printf(" Car color contains Invalid Characters :( Enter again");
         goto C;
      }
   }
   /* ********************************************Car Price***************************************************** */
   D:
   printf("\n\nCar Price: ");
   scanf("%lf",&c.car_price);
   if(c.car_price<10000)
   {
      printf("\nInvalid Input:  The minimum limit forr car price is 10000 ");
      goto D;
   }
   /* ****************************************Car Avaliable******************************************* */
   E:
   printf("\n\nCar Avaliable[1/0]: ");
   scanf("%d",&c.available);
   if(c.available!=1 && c.available !=0)
   {
      printf("\nInvalid Input:( Only enter 1 (for avaliable) or 0 (for not avaliable) ");
      goto E;
   }
fprintf(ek, "%s %s %d %s %lf %d", c.car_name, c.car_model, c.year, c.car_color, c.car_price, c.available);
printf("\n\n\tInformation Record Sucessfully...");
fclose(ek);
sd:
getch();
MainMenu();
}

/* *****************************************************Display Car***************************************** */
void display_car()
{
   int row;
   system("cls");
   Title();
   FILE*ek;
   ek = fopen("Car_Inf.txt","r"); //open file in reading mode to display the cars information
   printf("\n\n\t\t!!!!!!!!!!!!!!!  Display The Car Information !!!!!!!!!!!!!!!\n");
      gotoxy(1,15);
      printf("Car Name");
      gotoxy(20,15);
      printf("car Model");
      gotoxy(33,15);
      printf("Year");
      gotoxy(41,15);
      printf("Car Color");
      gotoxy(60,15);
      printf("Car Price");
      gotoxy(85,15);
      printf("Car Avaliable\n");
      printf("====================================================================================================");
      row=17;
      while(fscanf(ek, "%s %s %d %s %lf %d", &c.car_name, &c.car_model, &c.year, &c.car_color, &c.car_price, &c.available)!=EOF)
      {
         gotoxy(1,row);
         printf("%s",c.car_name);
         gotoxy(20,row);
         printf("%s",c.car_model);
         gotoxy(33,row);
         printf("%d",c.year);
         gotoxy(41,row);
         printf("%s",c.car_color);
         gotoxy(60,row);
         printf("%lf",c.car_price);
         gotoxy(85,row);
         printf("%d",c.available);
         row++;
      }
   fclose(ek);
   getch();
   MainMenu();
}
/* ****************************************Search Car******************************************************** */
void search_car()
{
   
   char name[15];
   system("cls");
   Title();//call the title function
   FILE*ek;
   ek=fopen("Car_Inf.txt","r");
   printf("\n\n\n\t!!!!!!!!!!Search Car Information!!!!!!!!!!\n");
   gotoxy(12,8);
   printf("\nEnter Car Name to View Car Information: ");
   scanf("%s",&name);
   fflush(stdin);
   name[0]=toupper(name[0]);
   while(fscanf(ek, "%s %s %d %s %lf %d", &c.car_name, &c.car_model, &c.year, &c.car_color, &c.car_price, &c.available)!=EOF)
   {
      if(strcmp(c.car_name,name)==0)
      {
         gotoxy(1,15);
         printf("Car Name:");
         gotoxy(20,15);
         printf("Car Model");
         gotoxy(33,15);
         printf("Year");
         gotoxy(41,15);
         printf("Car color");
         gotoxy(60,15);
         printf("Car price");
         gotoxy(85,15);
         printf("Avaliable\n");
         printf("=========================================================================================================");
         gotoxy(1,18);
         printf("%s",c.car_name);
         gotoxy(20,18);
         printf("%s",c.car_model);
         gotoxy(33,18);
         printf("%d",c.year);
         gotoxy(41,18);
         printf("%s",c.car_color);
         gotoxy(60,18);
         printf("%lf",c.car_price);
         gotoxy(85,18);
         printf("%d",c.available);
         printf("\n");
         break;
      }
      
   }
   if(strcmp(c.car_name,name)!=0)
   {
      gotoxy(5,10);
      printf("Record not found!!!");
      getch();
   }
   fclose(ek);
   getch();
   MainMenu();
}
/* **************************************************Update car Information***************************************** */
void update_car()
{
   struct car c;
   FILE*ek,*ft;
   int i,b,valid=0;
   char ch;
   char name[15];
   system("cls");
   Title();
   ft=fopen("temp.txt","w+");
   ek=fopen("Car_Inf.txt","r");
   /*if(ek==NULL)
   {
      printf("\n\n\tCannot open file!! ");
      getch();
      MainMenu();
   }*/
   printf("\n\n!!!!!! Update Car Information !!!!!!\n");
   gotoxy(12,13);
   printf("Enter the car name: ");
   scanf("%s",name);
   fflush(stdin);
   name[0]=toupper(name[0]);
   gotoxy(12,15);
   if(ft=NULL)
   {
      printf("\n\n Can not open file!\n");
      getch();
      MainMenu();
   }
   while(fscanf(ek, "%s %s %d %s %lf %d\n", &c.car_name, &c.car_model, &c.year, &c.car_color, &c.car_price, &c.available)!=EOF)
   {
      if(strcmp(c.car_name,name)==0)
      {
         valid=1;
         gotoxy(25,17);
         printf("*** Existing Record ***");
         gotoxy(10,19);
         printf("%s \t%s \t%d \t%s \t%lf \t%d\n", c.car_name, c.car_model, c.year, c.car_color, c.car_price, c.available);
         gotoxy(12,22);
         printf("Enter the new car name: ");
         scanf("%s",&c.car_name);
         gotoxy(12,28);
         printf("Enter the car model: ");
         scanf("%s",&c.car_model);
         gotoxy(12,30);
         printf("Enter the year: ");
         scanf("%d",&c.year);
         gotoxy(12,34);
         printf("Enter the car color: ");
         scanf("%s",&c.car_color);
         gotoxy(12,38);
         printf("Enter the Car Price: ");
         scanf("%lf",&c.car_price);
         gotoxy(12,42);
         printf("Enter the availability");
         scanf("%d",&c.available);
         printf("\n Press U Character for updating Operation");
         ch=getche();
         if(ch=='u' || ch=='U')
         {
            fprintf(ft,"%s %s %d %s %lf %d\n", c.car_name, c.car_model, c.year, c.car_color, c.car_price, c.available);
            printf("\n\n\n\n\n\tCar Information Updated Sucessfully...");
         }
      }
      else
      {
         fprintf(ft,"%s %s %d %s %lf %d\n", c.car_name, c.car_model, c.year, c.car_color, c.car_price, c.available);
      }
   }
   if(!valid)
   {
      printf("\n\n\nNO Record Found...");
   }
   fclose(ft);
   fclose(ek);
   remove("Car_Inf.txt");
   rename("temp.txt","Car_Inf.txt");
   getch();
   MainMenu();
}
/* ********************************************Delete Car Informataion******************************************** */
void delete_car()
{
   struct car c;
   char name[15];
   int found=0;
   system("cls");
   Title();
   FILE*ek,*ft;
   ft=fopen("temp1.txt","w+");
   ek=fopen("Car_Inf.txt","r");
   printf("\n\n\n\t!!!!!!!!!! Delete Car Information !!!!!!!!!!\n");
   gotoxy(12,8);
   printf("\n Enter Car Name to delete: ");
   fflush(stdin);
   gets(name);
   name[0]=toupper(name[0]);
   while(fscanf(ek,"%s %s %d %s %lf %d\n", &c.car_name, &c.car_model, &c.year, &c.car_color, &c.car_price, &c.available)!=EOF)
   {
      if(strcmp(c.car_name,name)!=0)
      {
         fprintf(ft,"%s %s %d %s %lf %d\n", c.car_name, c.car_model, c.year, c.car_color, c.car_price, c.available);
      }
      else
      {
         printf("%s %s %d %s %lf %d\n", c.car_name, c.car_model, c.year, c.car_color, c.car_price, c.available);
         found=1;
      }
   }//while loop ends
   if(found==0)
   {
      printf("\n\n\t Record not found....");
      getch();
      MainMenu();
   }
   else
   {
      fclose(ek);
      fclose(ft);
      remove("Car_Inf.txt");
      rename("temp1.txt","Car_Inf.txt");
      printf("\n\n\n\t Record Deleted Sucessfully...");
      getch();
      MainMenu();
   }
}
/* ******************************************exit Screen********************************************************* */
void ex_it()//function to exit
{
   system("cls");
   Title();
   printf("\n\n\n\t Thanks For Visiting.....");
   getch();
}

