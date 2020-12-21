#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
struct User
{
  char name[20];
  char mobile[10];
  char username[20];
  char password[20]
}user;

//___________________________________________List of Function__________________________________________________________//
void SendAnnouncements();
void userlogin();
void listofstations();
void reservation();
void transaction(int currentline,int destinationline,int stationnumbernow,int stationnumberdest);
void Register();


//_______________________________________function defintions______________________________________________________________//
void addstation(int menu_choice)
{
  if(menu_choice==1)
  {
     fflush(stdin);
	   char station[200];
	   printf("ENTER THE NEWLY TO BE ADDED STATIONS NAME ");
	   gets(station);
	   FILE *fp;
	   fp = fopen("redline.txt","a");
	   fprintf(fp,"\n%s",station);
	   fclose(fp);
  }
  else if(menu_choice==2)
  {
    fflush(stdin);
    char station[200];
    printf("ENTER THE NEW STATION'S name: ");
    gets(station);
    FILE *fp;
    fp = fopen("blueline.txt","a");
    fprintf(fp,"\n%s",station);
    fclose(fp);
  }
  else
  {
    fflush(stdin);
    char station[200];
    printf("ENTER THE NEWLY TO BE ADDED STATIONS NAME ");
    gets(station);
    FILE *fp;
    fp = fopen("greenline.txt","a");
    fprintf(fp,"\n%s",station);
    fclose(fp);
  }
}
void displaystation(int menu_choice)
{
  if(menu_choice==1)
  {
 	  int i = 0, line = 1;
    char ch[100];
    FILE *fp;
    fp = fopen("redline.txt","a+");
    while(!feof(fp))
	   {
	      char t = fgetc(fp);
	      if(t == 10)
	      {
		      line++;
	      }
	   }
	  char redline[line][100];
    rewind(fp);
    while(i<line)
	  {
    	fgets (ch, 60, fp);
    	strcpy(redline[i],ch);
    	i++;
	  }
    system("cls");
    printf("\t\t\tRED LINE STATIONS\n");
	  for(i=0;i<line;i++)
		printf("\t\t\t%s",redline[i]);
    fclose(fp);
  }
  if(menu_choice==2)
  {
 	  int i = 0, line = 1;
    char ch[100];
    FILE *fp;
    fp = fopen("blueline.txt","a+");
    while(!feof(fp))
	   {
	      char t = fgetc(fp);
	      if(t == 10)
	      {
		      line++;
	      }
	   }
	  char blueline[line][100];
    rewind(fp);
    while(i<line)
	  {
    	fgets (ch, 60, fp);
    	strcpy(blueline[i],ch);
    	i++;
	  }
    system("cls");
    printf("\t\t\tBLUE LINE STATIONS\n");
	  for(i=0;i<line;i++)
		printf("\t\t\t%s",blueline[i]);
    fclose(fp);
  }
  if(menu_choice==3)
  {
 	  int i = 0, line = 1;
    char ch[100];
    FILE *fp;
    fp = fopen("greenline.txt","a+");
    while(!feof(fp))
	   {
	      char t = fgetc(fp);
	      if(t == 10)
	      {
		      line++;
	      }
	   }
	  char greenline[line][100];
    rewind(fp);
    while(i<line)
	  {
    	fgets (ch, 60, fp);
    	strcpy(greenline[i],ch);
    	i++;
	  }
    system("cls");
    printf("\t\t\tGREEN LINE STATIONS\n");
	  for(i=0;i<line;i++)
    {
		  printf("\t\t\t%s",greenline[i]);
    }
    fclose(fp);
  }
}
void SendAnnouncements(void)
{
  char announce[200];
  fflush(stdin);
  printf("Please enter the announcement to be made: ");
  gets(announce);
  system("cls");
  printf("--------------------ATTENTION PASSANGERS!!--------------------------\n");
  puts(announce);
}
void Register()
{
  int i;
	system("cls");
	printf("WELCOME NEW USER!\n");
	printf("PLEASE ENTER YOUR DETAILS GIVEN BELOW");
  char nam[20],mob[10];
	char uname[100];
	char pass[10];
	FILE *fp;
	fp=fopen("users.txt", "a+");
  printf("\nPLEASE ENTER YOUR NAME: ");
  scanf("%s",nam);
  printf("\nPLEASE ENTER YOUR MOBILE NUMBER: ");
  scanf("%s",mob);
	printf("\nENTER YOUR USERNAME ");
	scanf("%s",uname);
	while(fread (&user, sizeof(struct User), 1, fp))
	{
    if(!strcmp(user.username, uname))
		{
      printf ("USERNAME ALREADY EXISTS PLEASE TRY AGAIN");
      getch();
      Register();
    }
  }
	printf("\nENTER YOUR PASSWORD (MAX 10 CHARACTERS) ");
	scanf("%s",pass);
  strcpy(user.name,nam);
  strcpy(user.mobile,mob);
	strcpy(user.username,uname);
  strcpy(user.password,pass);
  fwrite (&user, sizeof(struct User), 1, fp);
  fclose(fp);
  printf("\n\nTAKING YOU TO THE LOGIN SCREEN");
  userlogin();
}
int count=1;
void userlogin(void)
{

  system("cls");
  int answer;
  int i;
  char temp[10],ch;
  char uname[100];
  char pass[10];
  int flag = 0;
  time_t t;
  time(&t);
  printf("\nWELCOME BACK! PLEASE ENTER THE LOGIN CREDENTIALS");
  FILE *fp;
  fp=fopen("users.txt", "r+");
  printf("\nENTER USERNAME: ");
  scanf("%s",uname);
  while (fread (&user, sizeof(struct User), 1, fp))
  {

    if(!strcmp (user.username, uname))
    {
        strcpy(temp,user.password);
        printf("\nENTER PASSWORD: ");
        for(i=0;i<strlen(temp);i++)
        {
          ch = getch();
          pass[i] = ch;
          printf("*");
        }
        pass[i] = '\0';
        if(!strcmp(pass,user.password))
        {
          printf("\n\t\tLOGIN SUCCESSFUL!");
          printf("\n\t\tTIME OF LOGGIN IN %s ",ctime(&t));
          getch();
          break;
        }
      else
      {
        printf("INVALID PASSWORD! PLEASE TRY AGAIN");
        if(count%3==0)
        {
          printf("\nlogin failed 3 times. please try again later");
        }
        count++;
        getch();
        userlogin();
      }
    }
  }
}
void Adminlogin()
{
  int u=0,i=0,a=0;
  char username[32],ch;
  char password[32];
  char user[32]="user";
  char pass[32]="pass";
  do
  {

    printf("\n --------------------------Admin Login-------------------------\n  ");
    printf("\t\t\tplease enter the username :-");
    scanf("%s", username);
    printf("\n\t\t\tplease enter the password:-");
    for(i=0;i<6;i++)
    {
      ch = getch();
      password[i] = ch;
      printf("*");
    }
    password[i] = '\0';
    if(strcmp(username,"Admin")==0 && strcmp(password,"Access")==0)
    {
      printf("\n\t\t\tWelcome Admin");
      printf("\n\t\t\tPress return to continue");
      getch();
      break;
    }
    else
    {
        printf("\n----------------------Login failed!--------------");
        a++;
        getch();
        system("cls");
    }
}
    while(a<=3);
    if (a>3)
    {
        printf("\n\t\t\t Multiple failed login attempts detected, try again later");
        getch();
    }
    else
    {
      system("cls");
    }
}


//_______________________________________Void Reservation____________________________________________________//
void reservation(void)
 {
    cc:

	  printf("\t\t|_______________________________________________|\n");
	  printf("\t\t|                                               |\n");
	  printf("\t\t|         _____________________________         |\n");
	  printf("\t\t|       | Select your current line	   |        |\n");
	  printf("\t\t|       | _____________________________|        |\n");
	  printf("\t\t|       |                              |        |\n");
	  printf("\t\t|     	| 1.Red Line                   |        |\n");
	  printf("\t\t|       | 2.Blue Line                  |        |\n");
	  printf("\t\t|       | 3.Green Line                 |        |\n");
	  printf("\t\t|       |______________________________|        |\n");
	  printf("\t\t|_______________________________________________|\n");
	  printf("\t\t|_______________________________________________|\n\n\n");

   int currentline,stationnumbernow;
   scanf("%d",&currentline);
   if(currentline==1)
   {
     int i = 0, line = 1;
     char ch[100];
     FILE *fp;
     fp = fopen("redline.txt","a+");
     while(!feof(fp))
 	   {
 	      char t = fgetc(fp);
 	      if(t == 10)
 	      {
 		      line++;
 	      }
 	   }
 	  char redline[line][100];
     rewind(fp);
     while(i<line)
 	  {
     	fgets (ch, 60, fp);
     	strcpy(redline[i],ch);
     	i++;
 	  }
     system("cls");
     printf("\t\t\tRED LINE STATIONS\n");
 	  for(i=0;i<line;i++)
 		{
      printf("\t\t\t%d.%s",i+1,redline[i]);
    }
    fclose(fp);
    printf("\n");
 	  scanf("%d",&stationnumbernow);
   }
  else if(currentline==2)
  {
	   printf("Select Station number from the following:");
     int i = 0, line = 1;
     char ch[100];
     FILE *fp;
     fp = fopen("blueline.txt","a+");
     while(!feof(fp))
 	   {
 	      char t = fgetc(fp);
 	      if(t == 10)
 	      {
 		      line++;
 	      }
 	   }
 	  char blueline[line][100];
    rewind(fp);
    while(i<line)
 	  {
     	fgets (ch, 60, fp);
     	strcpy(blueline[i],ch);
     	i++;
 	  }
     system("cls");
     printf("\t\t\tBLUE LINE STATIONS\n");
 	  for(i=0;i<line;i++)
    {
 		   printf("\t\t\t%d.%s",i+1,blueline[i]);
     }
     fclose(fp);
     printf("\n");
	   scanf("%d",&stationnumbernow);
  }
  else if(currentline==3)
  {
	  printf("Select Station number from the following:");
    int i = 0, line = 1;
    char ch[100];
    FILE *fp;
    fp = fopen("greenline.txt","a+");
    while(!feof(fp))
	   {
	      char t = fgetc(fp);
	      if(t == 10)
	      {
		      line++;
	      }
	   }
	  char greenline[line][100];
    rewind(fp);
    while(i<line)
	  {
    	fgets (ch, 60, fp);
    	strcpy(greenline[i],ch);
    	i++;
	  }
    system("cls");
    printf("\t\t\tGREEN LINE STATIONS\n");
	  for(i=0;i<line;i++)
		{
      printf("\t\t\t%d.%s",i+1,greenline[i]);
    }
    fclose(fp);
    printf("\n");
	  scanf("%d",&stationnumbernow);
  }
  system("cls");

	printf("\t\t|_______________________________________________|\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|         _____________________________         |\n");
	printf("\t\t|       | Select your destination Line |     	  |\n");
	printf("\t\t|       | _____________________________|        |\n");
	printf("\t\t|       |                              |        |\n");
	printf("\t\t|     	|      1.Red Line              |        |\n");
	printf("\t\t|       |      2.Blue Line             |        |\n");
	printf("\t\t|       |      3.Green Line            |        |\n");
	printf("\t\t|       |______________________________|        |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|_______________________________________________|\n\n\n");

  int destinationline;
  int stationnumberdest;
  scanf("%d",&destinationline);
  if(destinationline==1)
  {

	  printf("Select Station number from the following: \n\n");
    int i = 0, line = 1;
    char ch[100];
    FILE *fp;
    fp = fopen("redline.txt","a+");
    while(!feof(fp))
	   {
	      char t = fgetc(fp);
	      if(t == 10)
	      {
		      line++;
	      }
	   }
	  char redline[line][100];
    rewind(fp);
    while(i<line)
	  {
    	fgets (ch, 60, fp);
    	strcpy(redline[i],ch);
    	i++;
	  }
    system("cls");
    printf("\t\t\tRED LINE STATIONS\n");
	  for(i=0;i<line;i++)
		{
      printf("\t\t\t%d.%s",i+1,redline[i]);
    }
    fclose(fp);
    printf("\n");
	  scanf("%d",&stationnumberdest);
  }
  else if(destinationline==2)
  {

	  printf("Select Station number from the following:\n\n");
    int i = 0, line = 1;
    char ch[100];
    FILE *fp;
    fp = fopen("blueline.txt","a+");
    while(!feof(fp))
	   {
	      char t = fgetc(fp);
	      if(t == 10)
	      {
		      line++;
	      }
	   }
	  char blueline[line][100];
    rewind(fp);
    while(i<line)
	  {
    	fgets (ch, 60, fp);
    	strcpy(blueline[i],ch);
    	i++;
	  }
    system("cls");
    printf("\t\t\tBLUE LINE STATIONS\n");
	  for(i=0;i<line;i++)
		{
      printf("\t\t\t%d.%s",i+1,blueline[i]);
    }
    printf("\n");
    scanf("%d",&stationnumberdest);
    fclose(fp);
  }

  else if(destinationline==3)
  {

    printf("Select Station number from the following:");
    int i = 0, line = 1;
    char ch[100];
    FILE *fp;
    fp = fopen("greenline.txt","a+");
    while(!feof(fp))
     {
        char t = fgetc(fp);
        if(t == 10)
        {
          line++;
        }
     }
    char greenline[line][100];
    rewind(fp);
    while(i<line)
    {
      fgets (ch, 60, fp);
      strcpy(greenline[i],ch);
      i++;
    }
    system("cls");
    printf("\t\t\tGREEN LINE STATIONS\n");
    for(i=0;i<line;i++)
    {
      printf("\t\t\t%d.%s",i+1,greenline[i]);
    }
    fclose(fp);
    printf("\n");
	  scanf("%d",&stationnumberdest);
  }
    transaction(currentline, destinationline, stationnumbernow, stationnumberdest);
}
//_______________________________________________________________________main Function__________________________________________________________

int main()
{
  char number[10];
	system("cls");
  struct tm* ptr;
  time_t lt;
  time(&lt);
  ptr = localtime(&lt);
	printf("\t\t\t\t|_______________________________________________|\n");
	printf("\t\t\t\t|                                               |\n");
	printf("\t\t\t\t|        _____________________________          |\n");
	printf("\t\t\t\t|        							                           \n");
	printf("\t\t\t\t|       |  L&T Metro Ticket System    |         |\n");
	printf("\t\t\t\t|        _____________________________          |\n");
	printf("\t\t\t\t|                                               |\n");
	printf("\t\t\t\t|                                               |\n");
	printf("\t\t\t\t|                                               |\n");
	printf("\t\t\t\t|                                               |\n");
	printf("\t\t\t\t             %s                          \n",asctime(ptr));
	printf("\t\t\t\t|                                               |\n");
	printf("\t\t\t\t|_______________________________________________|\n\n\n");


	getch();
  system("cls");
  printf("1.login as User\n2.Login as Admin\n");
  int menu_choice;
  scanf("%d",&menu_choice);
  if (menu_choice==1)
  {
    printf("\n1.Register\n2.Login");
    printf("\n");
    scanf("%d",&menu_choice);
    if(menu_choice==1)
    {
      Register();
      userlogin();
    }
    else
    {
      userlogin();
    }
    int choicereturn,menuchoice1;
  	start:
  	system("cls");
  	printf("\n\t\t|______________________________|\n");
  	printf("\t\t|           Welcome User         | \n");
  	printf("\n\t\t|______________________________|");
  	printf("\n\t\t1>> Reserve A Ticket");
  	printf("\n\t\t|______________________________|");
  	printf("\n\t\t2>> View the list of stations");
  	printf("\n\t\t|______________________________|");
  	printf("\n\t\t3>> Book for a friend");
  	printf("\n\t\t|______________________________|");
  	printf("\n\t\t4>> Exit");
  	printf("\n\t\t|______________________________|");
  	printf("\n\n\t\t-->");
  	scanf("%d",&menu_choice);
  	switch(menu_choice)
  	{
  		case 1: reservation();
  			      break;
  		case 2: printf("1.Red Line\n2.Blue line\n3.Green line\n");
              scanf("%d",&menu_choice);
              displaystation(menu_choice);
              getch();
              goto start;
  		case 3: printf("enter your friend's phone number: ");
              scanf("%s",&number);
              reservation();
              printf("\nThe OTP will be shared to %s",number);
              break;

  		case 4: return 0;
  		default:
  			printf("\nInvalid choice");
        goto start;
  	}
  }
  else
  {
    Adminlogin();
    system("cls");
    adst:
  	printf("\n\t\t|______________________________|");
  	printf("\n\t\t|      Welcome Admin      | ");
  	printf("\n\t\t|______________________________|");
  	printf("\n\t\t1>> Send announcements");
    printf("\n\t\t2>> Add new Stations");
    printf("\n\t\t3>> exit");
  	printf("\n\t\t|______________________________|");
  	printf("\n\n-->");
  	scanf("%d",&menu_choice);
    switch (menu_choice)
     {
       case 1: SendAnnouncements();
               getch();
               goto adst;
       case 2: printf("1.Red Line\n2.Blue line\n3.Green line\n");
               scanf("%d",&menu_choice);
               addstation(menu_choice);
               goto adst;
       case 3: printf("Shutting down...");
               break;
       default: printf("option invalid");
                goto adst;

    }
  }
}
void transaction(int currentline,int destinationline,int stationnumbernow,int stationnumberdest)
{
  srand(time(0));
  int hex= rand();
  int fare=0,f1=0;
  if((currentline == 1) && (destinationline ==1))
  {
    while(fare!= abs(stationnumbernow-stationnumberdest))
    {
      fare++;
    }
    printf("\n\t\tYour Ticket price is %d\n\t\tYour OTP is %x",fare*5,hex);
  }
  else if((currentline==1) && (destinationline==3))
  {
    while(fare != abs(stationnumbernow-20))
    {
      fare++;
    }
    while(f1 !=abs(stationnumberdest-10))
    {
      f1++;
    }
    printf("\n\t\tChange train at MG Bus Station");
    printf("\n\t\tYour ticket price is %d\n\t\tYour OTP is %x",(fare+f1)*5,hex);
  }
  else if(currentline==1 && destinationline==2)
  {
    while(fare !=abs(stationnumbernow-11))
    {
      fare++;
    }
    while(f1 !=abs(stationnumberdest-14))
    {
      f1++;
    }
    printf("\n\t\tchange train at Ameerpet\n");
    printf("\n\t\tYour Ticket price is %d\n\t\tYour OTP is %x",(fare+f1)*5,hex);
  }
  else if(currentline==3 && destinationline==1)
  {
    while(fare !=abs(stationnumbernow-10))
    {
      fare++;
    }
    while(f1!=abs(stationnumberdest-20))
    {
      f1++;
    }
    printf("\n\t\tChange train at MG bus station\n");
    printf("\n\t\tYour Ticket price is %d\n\t\tYour OTP is %x",(fare+f1)*5,hex);
  }
  else if(currentline==3 && destinationline ==3)
  {
    while(fare!= abs(stationnumbernow-stationnumberdest))
    {
      fare++;
    }
    printf("\n\t\tYour ticket price is %d\n\t\tYour OTP is %x",(fare)*5,hex);
  }
  else if(currentline==3 && destinationline==2)
  {
    while(fare!=abs(stationnumbernow-2))
    {
      fare++;
    }
    while(f1!=abs(stationnumberdest-9))
    {
      f1++;
    }
    printf("\n\t\tchange train at Parade grounds\n");
    printf("\n\t\tYour Ticket price is %d\n\t\tYour OTP is %x",(fare+f1)*5,hex);
  }
  else if( currentline==2 && destinationline==1)
  {
    while(fare!=abs(stationnumbernow-14))
    {
      fare++;
    }
    while(f1!=abs(stationnumberdest-11))
    {
      f1++;
    }
    printf("\n\t\tChange train at Ameerpet station\n");
    printf("\n\t\tYour Ticket price is %d\n\t\tYour OTP is %x",(fare+f1)*5,hex);
  }
  else if(currentline==2 && destinationline ==3)
  {
    while(fare!= abs(stationnumbernow-9))
    {
      fare++;
    }
    while(f1!=abs(stationnumberdest-2))
    {
      f1++;
    }
    printf("\n\t\tChange train at Parade grounds");
    printf("\n\t\tYour ticket price is %d\n\t\tYour OTP is %x",(fare)*5,hex);
  }
  else if(currentline==2 && destinationline==2)
  {
    while(fare!=abs(stationnumbernow-stationnumberdest))
    {
      fare++;
    }
    printf("\n\t\tYour Ticket price is %d\n\t\tYour OTP is %x",(fare)*5,hex);
  }
}
