#include<stdio.h>//Use for standard I/O Operation
 #include<conio.h>//Use for delay(),getchar(),gotoxy(),etc.  
 #include<string.h>//Use for strcmp(),strcpy(),strlen(),etc
 #include<stdlib.h>

//FUNCTION DECLERATION
void WelcomeScreen(void);//WelcomeScreen function decleration
void Title(void);//Title function decleration
void Enter(void);//Enter function decleration
void Add_rec(void);//Add_rec function declaration
void List_rec(void);//function to list of the studentss details 
//Search_rec function declaration
void LoginScreen(void);//LoginScreen function decleration
void ex_it(void);//exit function declaration

struct student//list of global variable
{
  int age;
  char Gender;
  char First_Name[20];
  char Last_Name[20]; 
  char Contact_no[15];
  char Address[30];
  char Email[30];
};
struct student p;

void main()
{
  
    WelcomeScreen();//Use to call WelcomeScreen function
  Title();//Use to call Title function
  Enter();//Use to call Menu function
}

void WelcomeScreen(void) //function for welcome screen
{
  
  printf("\n\n\n\n\n\n\n\t\t\t\t#########################################");
  printf("\n\t\t\t\t\t\t WELCOME TO\t\t");
  printf("\n\t\t\t\t   VISHNU INSTITUTE OF TECHNOLOGY  OF BHIMAVARAM    ");
  printf("\n\t\t\t\t#########################################"); 
}

/* ************************************************* Title Screen ********************************************* */

void Title(void)//function for title screen
{
  printf("\n\n\t\t----------------------------------------------------------");
  printf("\n\t\t\t\t       ONLINE OUTING        ");
  printf("\n\t\t------------------------------------------------------------");
}

/* ************************************************* Main Menu ********************************************* */
void Enter(void)//function decleration
{
  int choose;
  Title();// call Title function
  printf("\n\n\n\n\n\t\t\t\t1. Add Student\n");
  printf("\n\t\t\t\t2. List Students Record\n");
  printf("\n\t\t\t\t3. Student login\n");
  printf("\n\t\t\t\t4. Exit\n");
  printf("\n\n\n \n\t\t\t\tChoose from 1 to 4:");
  scanf("%i", &choose);
switch(choose)//switch to differeht case
  {
  
  case 1:
  Add_rec();//Add_rec function is called
      break;
    case 2:
  List_rec();
    break;
  case 3:
    LoginScreen;//Edit_rec function is call
    break;
  case 4:
    ex_it();//ex_it function is call
      break;

  default:
    printf("\t\t\tInvalid entry. Please enter right option :)");
    getchar();//holds screen
  }//end of switch
  return 0;  }
  void Add_rec(void)
{
  Title();// call Title function
clrscr();
  char ans;
  FILE*ek;//file pointer
  ek=fopen("Record2.dat","a");//open file in write mode
  printf("\n\n\t\t\t!!!!!!!!!!!!!! Add Student Record !!!!!!!!!!!!!\n");
  
  /* **************************First Name*********************************** */
  printf("\n\t\t\tFirst Name: ");
  scanf("%s",p.First_Name);
  if(strlen(p.First_Name)>20||strlen(p.First_Name)<2)
  {
    printf("\n\t Invalid :( \t The max range for first name is 20 and min range is 2 :)");
  }
  else
  {
    
    printf("\n");
  }
  
  /* ********************************************** Last name ************************************************ */
  printf("\n\t\t\tLast Name: ");
    scanf("%s",p.Last_Name);
    if(strlen(p.Last_Name)>20||strlen(p.Last_Name)<2)
  {
    printf("\n\t Invalid :( \t The max range for last name is 20 and min range is 2 :)");
    
  }
  else
  {
    
    printf("\n");
  }
  
/* ******************************************* Gender ************************************************************** */     
      printf("\n\t\t\tGender[F/M]: ");
    scanf(" %c",&p.Gender);
    if((p.Gender)=='M') 
    {
      printf("\nMale");
    }
   
if((p.Gender)=='F') 
    {
      printf("\nFemale");
    }
else
  {
    
    printf("\n");
  }
/* ***************************************** Age ********************************************************************** */  
    printf("\n\t\t\tAge:");
    scanf(" %i",&p.age);
/* **************************************** Address ******************************************************************* */    

    printf("\n\t\t\tAddress: ");
    scanf("%s",p.Address);
    if(strlen(p.Address)>40||strlen(p.Address)<4)
  {
    printf("\n\t Invalid :( \t The max range for address is 40 and min range is 4 :)");
   
  }
  
else
  {
    
    printf("\n");
  }
/* ******************************************* Contact no. ***************************************** */

    printf("\n\t\t\tContact no: ");
    scanf("%s",p.Contact_no);
    if(strlen(p.Contact_no)>10||strlen(p.Contact_no)!=10)
  {
    printf("\n\t Sorry :( Invalid. Contact no. must contain 10 numbers. Enter again :)");
    
  }
  else
  {
    
    printf("\n");
  }
/* ************************************************** Email ******************************************** */
do
{
    printf("\n\t\t\tEmail: ");
    scanf("%s",p.Email);
    if (strlen(p.Email)>30||strlen(p.Email)<8)
    {
       printf("\n\t Invalid :( \t The max range for email is 30 and min range is 8 :)");  
  }
}while(strlen(p.Email)>30||strlen(p.Email)<8);

  
    fprintf(ek," %s %s %c %i %s %s %s \n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no, p.Email);
    printf("\n\n\t\t\t.... Information Record Successful ...");
    fclose(ek);//ek file is closed
    getchar();
     Enter();
}
    void List_rec()
{
  int row;
  clrscr();
  Title();
  FILE *ek;
  ek=fopen("Record2.dat","r");
  printf("\n\n\t\t\t!!!!!!!!!!!!!! List Students Record !!!!!!!!!!!!!\n");
    printf("Full Name");
    printf("\tGender");
    printf("\tAge");
    printf("\tAddress");
    printf("\tContact No.");
    printf("\tEmail");
    printf("======================================================");
      printf("%s %s",p.First_Name, p.Last_Name);
      printf("\t%c",p.Gender);
      printf("\t%i",p.age);
      printf("\t%s",p.Address);
      printf("\t%s",p.Contact_no);
      printf("\t%s",p.Email);
    fclose(ek);
    getchar();
    Enter();
}
void Search_rec(void)
{
  clrscr();
  char name[20];
 FILE *ek;
  ek=fopen("Record2.dat","r");
  printf("\n\n\t\t\t!!!!!!!!!!!!!! Search Student Record !!!!!!!!!!!!!\n");
  printf("\n Enter Student Name to be viewed:"); 
 scanf("%c,&name");
if((strcmp(p.First_Name,name)==0) || (strcmp(p.First_Name,name)==0))
    {
      printf("Full Name");
      printf("\tGender");
      printf("\tAge");
      printf("\tAddress");
      printf("\tContact No.");
      printf("\tEmail");
("=================================================================================================================");
      printf("%s %s",p.First_Name, p.Last_Name);
      printf("\t%c",p.Gender);
      printf("\t%i",p.age);
      printf("\t%s",p.Address);
      printf("\t%s",p.Contact_no);
      printf("\t%s",p.Email);
      
    }
     
     if((strcmp(p.First_Name,name)!=0) || (strcmp(p.First_Name,name)!=0))
     {
    printf("Record not found!");
    getchar();
   }

}

void LoginScreen(void)//function for login screen
{
//list of variables  
int e=0  ;
char Username[20];
char Password[20];
char original_Username[20];
  original_Username ==p.First_Name; 
char original_Password[20];
  original_Password==p.Last_Name;
do
{
  printf("\n\n\n\n\t\t\t\tEnter your Username and Password :)");
  printf("\n\n\n\t\t\t\t\tUSERNAME:");
  scanf("%s",Username);
  
  printf("\n\n\t\t\t\t\tPASSWORD:");
  scanf("%s",Password);
  
  if (strcmp(Username,original_Username)==0 && strcmp(Password,original_Password)==0)
  {
    printf("\n\n\n\t\t\t\t\t...Login Successfull...");
    
    
    getchar();
    break;
  }
  else
  {
    printf("\n\t\t\tPassword in incorrect:( Try Again :)");
    e++;
    getchar();
  }

}
while(e<=2);
  if(e>2)
  {
  printf("You have cross the limit. You cannot login. :( :(");
  getchar();
    ex_it();
  }
 

void ex_it(void);
{
  Title();// call Title function
  printf("\n\n\n\n\n\t\t\tTHANK YOU FOR VISITING :)");
  getchar();//holds screens
}

}
