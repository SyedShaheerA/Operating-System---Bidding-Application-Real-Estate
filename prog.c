#include <stdio.h>
//#include <process.h>
#include <string.h>
#include <stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<wait.h>
#include<signal.h>
#include<unistd.h>
#define MAXSIZE 27

int registeration_phase(FILE *registeration);
int login_phase(FILE *loginf, char Register[]);
void DispHouse(char Register[]);
void menu(char Register[]);
void admin_login(FILE *loginfo);
void admin();
void userAdds(char Register[]);
void signal_handler(int *kill);
void die(char *str);

struct record_user
{
	char RegisterNumber[100];
	char fname[10];
	char mname[10];
	char lname[10];
	char phoneNumber[20]; 
	char adress[10];
	char password[10];
	char data[10];
	char regno[15];
	char CheckPassword[10];
};




char INPUT_TEXT(char a[])
{
	printf("ENTER TEXT\n");
		char ca;
	int chance = 0;
	int i=0;
	while(chance ==0)
	{
		
		scanf("%c",&ca);
		a[i] = ca;
		//printf("%c",a[i]);
		if(a[i] == '\n')
		{
		chance++;
		}
		i++;
		//a++;
	}
	//printf("TEXT ENTERED");
}




int main()
{
	/*FILE SECTION*/
	FILE *registeration;
	FILE *loginf;
	char Register[15]; 
	
	//char *Register;
	
	//Register=(char*)malloc(10*sizeof(char));
	int option,option1;
system("cls");//code used to clear the previous screen
      printf("Real Estate Property Management\n");
      printf("---------------------------------------\n");
      printf("Please select from the following option\n");
      printf("---------------------------------------\n");
      printf("1:Regestration\n");
      printf("2:Login\n");
      
	printf("Enter Number: ");
	scanf("%d",&option);
	
	
	if(option==1)
	{
		printf("You have chosen option 1: ");
		registeration_phase(registeration);
	}
	if(option==2)
	{
		system("cls");
		printf("You have chosen option 2:\n ");
		 printf("1:Login as Admin\n");
		 printf("2:Login as Client\n");
         printf("\nEnter Number: ");
         scanf("%d",&option1);
        if(option1==2)
		{ 
	      login_phase(loginf, Register);
	    	printf("%s",Register);
			menu(Register);
	    }
	    else
	    {
	    	admin_login(loginf);
	    	admin();
		}
	}


}
void die(char *str) {
	perror(str);
	exit(1);
}
void signal_handler(int *kill){
	 //printf("Received Signal from %d\n",num);
	*kill=1;
}

void bidder(char Register[])
{
	int shmid;
	key_t key;
	key_t key2;
	key_t key3;
	key_t key4;
	key_t key5;
	key_t key6;
	key_t key7,keyend;
	int maxL;	
	char *shm, *s;
	int *shm2, *s2;
	int *shm3, *s3;
	int *shm4, *max;
	char *shm5, *s5;
	int *shm6, *s6;
	int *shm7, *s7;
	int option=0 ;
	int amo;
	int tempNUM=0;
	int *shmend,*end;
	int listNUM=0;
	
	printf("%s: \n", Register);
	key = 2211;
	key2= 2222;
	key3= 2233;
	key4= 2244;
	key5= 2255;
	key6= 2266;
	key7= 2277;
	keyend=2288;

	fflush(stdin);
	if((shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666)) < 0)
		die("shmget");
	if((shm = shmat(shmid, NULL, 0)) == (char*) -1)
		die("shmat");

	if((shmid = shmget(key6, MAXSIZE, IPC_CREAT | 0666)) < 0)
		die("shmget");
	if((shm6 = shmat(shmid, NULL, 0)) == (int*) -1)
		die("shmat");

	if((shmid = shmget(key7, MAXSIZE, IPC_CREAT | 0666)) < 0)
		die("shmget");
	if((shm7 = shmat(shmid, NULL, 0)) == (int*) -1)
		die("shmat");	
	
	if((shmid = shmget(key5, MAXSIZE, IPC_CREAT | 0666)) < 0)
		die("shmget");
	if((shm5 = shmat(shmid, NULL, 0)) == (char*) -1)
		die("shmat");

	if((shmid = shmget(key2, MAXSIZE, IPC_CREAT | 0666)) < 0)
		die("shmget");
	if((shm2 = shmat(shmid, NULL, 0)) == (int*) -1)
		die("shmat");
	
	if((shmid = shmget(key3, MAXSIZE, IPC_CREAT | 0666)) < 0)
		die("shmget");
	if((shm3 = shmat(shmid, NULL, 0)) == (int*) -1)
		die("shmat");

	if((shmid = shmget(key4, MAXSIZE, IPC_CREAT | 0666)) < 0)
		die("shmget");
	if((shm4 = shmat(shmid, NULL, 0)) == (int*) -1)
		die("shmat");
	if((shmid = shmget(keyend, MAXSIZE, IPC_CREAT | 0666)) < 0)
		die("shmget");
	if((shmend = shmat(shmid, NULL, 0)) == (int*) -1)
		die("shmat");

	s2=shm2;
	s= shm;
	s3=shm3;
	max=shm4;
	s5= shm5;
	s6= shm6;
	s7= shm7;
	end=shmend;
	*s6=0;
	if(*s6==0)
	{
		listNUM= *s6;
		*s7=0;
	}
	else
	{
		
		*s7= *s7+1;		
		listNUM= *s6+1;
	}
	//*s6=0;
	
	
	
	*s3=0;
	while(option ==0)
	{
				
		//sleep(5);

		
		while(*s3 == 0)
		{
		    sleep(1);
		}
		
		for(s = shm; *s != '\0'; s++)
			putchar(*s);
		
		
		for(int p=0; Register[p] != '\0'; p++)
		{
			s5[p] = Register[p];
		}	

		printf("%s", s5); 

		printf("\nENTER BIDDING AMOUNT: \n");
		if(*end==0)
		{
			scanf("%d", &amo);
		}
		if(*end==1)
		{
			break;
		}
		*s2 = amo;
		if(*max >= amo)
		{
			printf("\nBID IS LESS THAN MAX\n");
		
		}
		else
		{
			*max = amo;
			for(int p=0; Register[p] != '\0'; p++)
			{
				s5[p] = Register[p];
			}	
		}
		
		
		//*s = '*';
		*s3 = 0;
		*s6= *s6+1;
		if(*s6>*s7)
		{
			*s6=0;
		}
	
//	printf("PLEASE PRESS 0 TO CONTINUE\n");
//		scanf("%d", &option);

	}
	printf("\nAuction is over\n");
	if(amo==*max)
	{
	printf("Property sold to:%s",s5);
	
	
	printf("\n For: Rs.%d",*s2);	
	}
	*end=2;
	//printf("\n");
	exit(0);
}



void auction(char Register[])
{
//	execp("/home/shaheer/Desktop/PROJECT/server.c" );
	char c;
	int shmid;
	int maxL;
	key_t key;
	key_t key2;
	key_t key3;
	key_t key4;	
	key_t key5;
	key_t key6,keyend;		
	char *shm, *s;
	int *shm2, *s2;
	int *shm3, *s3;
	int *shm4, *max;
	char *shm5, *s5;
	int *shm6, *s6;
	int option=0;
	int tempNUM=0;
	int *shmend,*end,temp;
	printf("%s: \n", Register);
	key = 2211;
	key2= 2222;
	key3= 2233;
	key4= 2244;
	key5= 2255;
	key6= 2266;
	keyend=2288;


	if((shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666)) < 0)
		die("shmget");
	if((shm = shmat(shmid, NULL, 0)) == (char*) -1)
		die("shmat");	
	
	if((shmid = shmget(key6, MAXSIZE, IPC_CREAT | 0666)) < 0)
		die("shmget");
	if((shm6 = shmat(shmid, NULL, 0)) == (int*) -1)
		die("shmat");

	if((shmid = shmget(key5, MAXSIZE, IPC_CREAT | 0666)) < 0)
		die("shmget");
	if((shm5 = shmat(shmid, NULL, 0)) == (char*) -1)
		die("shmat");

	if((shmid = shmget(key2, MAXSIZE, IPC_CREAT | 0666)) < 0)
		die("shmget");
	if((shm2 = shmat(shmid, NULL, 0)) == (int*) -1)
		die("shmat");

	if((shmid = shmget(key3, MAXSIZE, IPC_CREAT | 0666)) < 0)
		die("shmget");
	if((shm3 = shmat(shmid, NULL, 0)) == (int*) -1)
		die("shmat");

	if((shmid = shmget(key4, MAXSIZE, IPC_CREAT | 0666)) < 0)
		die("shmget");
	if((shm4 = shmat(shmid, NULL, 0)) == (int*) -1)
		die("shmat");
	if((shmid = shmget(keyend, MAXSIZE, IPC_CREAT | 0666)) < 0)
		die("shmget");
	if((shmend = shmat(shmid, NULL, 0)) == (int*) -1)
		die("shmat");

	
	s2=shm2;
	s3=shm3;
	s = shm;
	max=shm4;
	s6= shm6;
	s5= shm5;
	end=shmend;

	*end=0;




	*s3 =0;

	*s6=0;
	printf("\nENTER MIN AMOUNT: ");
	scanf("%d", &maxL);
	
	*max= maxL;

	while(option==0)
	{

	INPUT_TEXT(s);
	
//	printf("%c", s[0]);
//	for(int i = 0; i <= 12; i++) 
//	{
//		
//		*s++ = c[i];
//	}

	*s3= 1;
	while(*s3 == 1)
		sleep(1);
	*s3=0;
	
	printf("%s",s5);
	
	printf(": ");
		
	printf("%d\n", *s2);	
	printf("\n End auction? (yes=1,no=0)\n");
	scanf("%d",&temp);
	*end=temp;
	if(*end==1)
	{
		*s3=2;
		break;
	}
	for(int i=0; s[i] != '\0'; i++)
	{
		s[i] = '\0';
		//s5[i] = '\0';
	}
	
	for(int i=0; s5[i] != '\0'; i++)
	{
		//s[i] = '\0';
		s5[i] = '\0';
	}
	
		
        
	

	//printf("PLEASE PRESS 0 TO CONTINUE\n");
	//	scanf("%d", &option);
	}
	
	
	printf("Property sold to:%s\nFor: Rs%d\n",s5,*max);
	//printf("\n For: Rs.%d",*max);
	while(*end!=2)
	{
		sleep(1);
	}
	*end=1;
	exit(0);
}

void menu(char Register[])
{
	int i;
	system("cls");
	printf("Account %s \n",Register);
	printf("1) For ading and finding house\n");
//	printf("2) For Deleting your add\n");
	printf("2) For seeing your add\n");
	printf("3) For auctioning your house\n");
	printf("4) For bidding on a house\n");
	printf("\nChose the following option: ");
	scanf("%d",&i);
	if(i==1)
	{
		printf("You have chose option 1");
		DispHouse(Register);
	}
	else if(i==2)
	{
		printf("You have chosen option 2");
		userAdds(Register);
	}
	else if(i==3)
	{
		printf("You chose option 3");
		auction(Register);
	}
	else
	{
		printf("You chose option 3");
		bidder(Register);
	}
}




int registeration_phase(FILE *registeration)
{
		system("cls");
printf("#--------------------------------------------------------------------------#\n");	
printf("#                  Real Estate Property Management                         #\n");
printf("#                                                                          #\n");
printf("#                    You have chosen to Regester                           #\n");	
printf("#                                                                          #\n");
printf("#                  Please provide us with your details                     #\n");
printf("#--------------------------------------------------------------------------#\n");

//ofstream outfile;//used for file
//outfile.open("RealEstate.txt", ios::app);//will store evetry data we want after it
registeration=fopen("testrun.txt","a");//w means write
struct record_user x;
printf("\n\nEnter your Citizen Number/Passport Number: ");
scanf("%s",&x.data);
//outfile << data << "\t";
fputs(x.data,registeration);
fprintf(registeration,"\t");
//printf("..................................................................\n");

printf("Enter your First Name:");
scanf("%s",&x.fname);
//outfile << fname << "\t";
fputs(x.fname,registeration);
fprintf(registeration,"\t");
//printf("..................................................................\n");

printf("Enter your Middle Name:");
scanf("%s",&x.mname);
//outfile << mname << "\t";
fputs(x.mname,registeration);
fprintf(registeration,"\t");
//printf("..................................................................\n");

printf("Enter your Last name:");
scanf("%s",&x.lname);
//outfile << lname << "\t";
fputs(x.lname,registeration);
fprintf(registeration,"\t");
//printf("..................................................................\n");

printf("Enter your phone number:");
scanf("%s",&x.phoneNumber);
//outfile << phoneNumber << "\t";
fputs(x.phoneNumber,registeration);
fprintf(registeration,"\t");
//printf("..................................................................\n");

printf("Enter your current adress use \"_\"(undescore) instead of space:");
scanf("%s",&x.adress);
//outfile << adress << "\t";
fputs(x.adress,registeration);
fprintf(registeration,"\t");
//printf("..................................................................\n");

printf("Enter your Password:");
scanf("%s",&x.password);
//outfile << Password << "\t\n";
fputs(x.password,registeration);
fprintf(registeration,"\n");

fclose(registeration);
main();
//ofstream reg("UserLogin.txt", ios::app);//will only register information  entered before it 
//reg<<data<<' '<<Password<<endl;// we have clearified the things to be regestered
}






int login_phase(FILE *loginf,char Register[])
{
	struct record_user x;
	char *pos;
	int exist=0,c;
	char tempregno[10];
	char temppass[10];
	int option,z=0;
	//string CheckUser, CheckPassword, u, p; 	
puts("Enter your Citizen/Passport number:");
getchar();
gets(x.regno);
printf("\n");

puts("Enter your Password: ");
gets(x.CheckPassword);
loginf=fopen("testrun.txt","r");
	while(c!=EOF)
	{
		/*fgets(tempregno,10,loginf);
        if ((pos=strchr(tempregno, '\n')) != NULL)
        {
            *pos = '\0';
    	}*/
    	fscanf(loginf,"%s",tempregno);
		c=getc(loginf);
		if(strcmp(tempregno,x.regno)==0)
		{
			exist=1;
			strcpy(Register,x.regno);
			break;
		}
	}
	if(exist==0)
	{
		printf("User not registered.To register press 1 to register or press 2 to exit");
		scanf("%d",&option);
		if(option==1)
		{
			main();
		}
		else
		{
			exit(1);
		}
	}
	c=12;
	exist=0;
	//while(c!=EOF)
	//{
		/*fgets(temppass,3,loginf);
		if ((pos=strchr(temppass, '\t')) != NULL)
        {
            *pos = '\0';
        }*/
        while(z<6)
		{
          fscanf(loginf,"\t%s",temppass);
	      z++;
		}
		//c=getc(loginf);
		if(strcmp(temppass,x.CheckPassword)==0)
		{
			exist=1;
			//break;
		}
	//}
	if(exist==0)
	{
		while(exist!=1)
		{
		    printf("Wrong password. Please try again");
		    //fgets(temppass,3,loginf);
		    gets(x.CheckPassword);
		    if(strcmp(temppass,x.CheckPassword)==0)
		    {
		 	    exist=1;
		 	    printf("Login successful. \n Welcome!\n");
		 	    fclose(loginf);
			    break;
		    }
	    }
	}
	else
	{
		printf("Login successful. \n Welcome!\n");
		printf("Account %s", x.regno);
		//scanf("%s",&x.data);
		fclose(loginf);
		//return(x.regno);
	}
}

void userAdds(char Register[])
{
	system("cls");
	unsigned int houseno;
	unsigned int condition;
	unsigned int room;
	char address[30],findaddr[30];
	double price;
	int c=0,ch1,ch2;
	int checkType;
	int ChekType;
	FILE *cfPtr;
	int option;
	long int min,max;
	int balance_check,pptExist=0;
	struct record_user R;
	printf("\nAccount: %s\n",Register);
	int i;
	
	
	cfPtr= fopen("SellHouse.txt","r");
	 printf( "%-10s%-10s%-10s%-13s%-10s%-10s%-10s\n", "checkType", "ChekType","houseno", "address", "price", "room", "condition" );
	while(i!=EOF)
		    {
			  fscanf( cfPtr, "%s%d%d%d%29s%lf%d%d", &R.regno,&checkType, &ChekType, &houseno, address, &price, &room, &condition );
			  if(strcmp(R.regno,Register)==0)
			  {
			    printf( "%-10d%-10d%-10d%-13s%-10.2f%-10d%-10d\n", checkType, ChekType, houseno, address, price, room, condition );
                pptExist++;			
			  }
			
				i=fgetc(cfPtr);
			}
	
}


void DispHouse(char Register[])
{
	system("cls");
	unsigned int houseno;
	unsigned int condition;
	unsigned int room;
	char address[30],findaddr[30];
	double price;
	int c=0,ch1,ch2;
	int checkType;
	int ChekType;
	FILE *cfPtr;
	int option;
	long int min,max;
	int balance_check,pptExist=0;
	struct record_user R;
	printf("\nAccount: %s",Register);
	printf("\nEnter the following option: ");
	printf("\nPress 1 to sell || press 2 to find : ");
	scanf("%d",&option);

	if(option==1)
	{
	if((cfPtr=fopen("SellHouse.txt","a"))==NULL)
	{
		puts("File could not be opened");
	}
	else
	{
		puts("Enter the RegestrationNumber ,H[1]|A[2], R[1]|S[2], House_Number, Address, Price, NUMBER OF ROOM, QUALTIY(1-5).");
		puts("Enter EOF to end input.");
		printf("%s","->");

		do{
           scanf("%s%d%d%d%29s%5lf%d%d",&R.regno ,&checkType, &ChekType, &houseno, address, &price, &room, &condition);
           if(strcmp(R.regno,Register)!=0)
           {
           	printf("Enter the correct account number! or check the condition");
		   }
		  }while(strcmp(R.regno,Register)!=0 || condition>5 || condition<1);

			fprintf(cfPtr, "%s %d %d %d %s %.2f %d %d\n", R.regno,checkType, ChekType, houseno, address, price, room, condition);
			printf("%s","-->");
			//c++;
		//	scanf("%d%d%d%29s%5lf", &checkType, &ChekType, &houseno, address, &price);
		fclose(cfPtr);
		
		
	}
}
		if(option==2)
		{
		//	fclose(cfPtr);
	
		FILE *cfPtr;
	if((cfPtr=fopen("SellHouse.txt","r"))==NULL)
	{
		puts("File Could not be opened");
	}
	else
	{
			
		printf("Enter 1 for houses, 2 for apartments:");
		scanf("%d",&ch1);
		printf("Enter 1 for rent, 2 for sale:");
		scanf("%d",&ch2);
		printf("Enter Minimum price:");
		scanf("%d",&min);
		printf("Enter Maximum price:");
		scanf("%d",&max);
		printf("Press 3 to search by address else press 4:");
		scanf("%d",&option);
		if(option==3)
		{
			printf("Enter address");
			scanf("%s",findaddr);
		}
		printf("%-10s%-10s%-10s%-13s%-10s%-10s%s\n", "H[1]|A[2]","R[1]|S[2]","House.N.O", "Address", "price", "Room", "Quality");
			//fscanf( cfPtr, "%d%d%d%29s%lf", &checkType, &ChekType, &houseno, address, &price );
		int i=0;
		if(option==3)
		{
		  while(i!=EOF)
		  {
			fscanf( cfPtr, "%s%d%d%d%29s%lf%d%d", &R.regno,&checkType, &ChekType, &houseno, address, &price, &room, &condition );
			if(ch1==checkType && ch2==ChekType && price>min && price<max && strcmp(findaddr,address)==0)
			{
			 printf( "%-10d%-10d%-10d%-13s%-10.2f%-10d%-10d\n", checkType, ChekType, houseno, address, price, room, condition );
             pptExist++;			
			}
			
			//i++;
			i=fgetc(cfPtr);
			//fscanf( cfPtr, "%d%d%d%29s%lf", &checkType, &ChekType, &houseno, address, &price );
		  }
	    }
	    else
	    {
	    	while(i!=EOF)
		    {
			  fscanf( cfPtr, "%s%d%d%d%29s%lf%d%d", &R.regno,&checkType, &ChekType, &houseno, address, &price, &room, &condition );
			  if(ch1==checkType && ch2==ChekType && price>min && price<max)
			  {
			    printf( "%-10d%-10d%-10d%-13s%-10.2f%-10d%-10d\n", checkType, ChekType, houseno, address, price, room, condition );
                pptExist++;			
			  }
			
			//i++;
			i=fgetc(cfPtr);
			//fscanf( cfPtr, "%d%d%d%29s%lf", &checkType, &ChekType, &houseno, address, &price );
		  }
		}
		if(pptExist==0)
		{
			printf("Not available");
		}
		fclose( cfPtr );
	}
		}
}

void admin_login(FILE *loginfo)
{
	int ID,password,z,tempID,temppassword,IDexist=0,passexist=0;
	loginfo=fopen("admin_info.txt","r");
	printf("Enter ID:");
	scanf("%d",&tempID);
	printf("Enter enter password:");
	scanf("%d",&temppassword);
	while(z!=EOF)
	{
	   fscanf(loginfo,"%d %d",&ID,&password);
	   if(tempID==ID)
	   {
	   	 IDexist=1;
	    if(temppassword==password)
	    {
	   	 if(IDexist==1)
	   	 {
	   	 	printf("Login Successfull!");
	   	 	
	   	 	break;
		 }
		 else
		 {
		 	printf("ID does not exist"); //lagay ga
		 }
	   }
	   else
	   {
	   	 printf("Wrong password! try again");
	   	 scanf("%d",&temppassword);
		 while(1)
	   	 {
	   	 	if(temppassword==password)
	   	 	{
	   	 	   	printf("Login Successfull!");
	   	 	   	
	   	 	   	passexist=1;
	   	 	    break;
			}
			else
			{
				 printf("Wrong password! try again");
				 scanf("%d",&temppassword);
			}
			
		 }
	   }
	   }
	    if(passexist==1)
	    {
	    	break;
		}
	   z=fgetc(loginfo);
    }
    
}



void admin()
{
FILE *userinfo;
printf("\nuser information\n");
userinfo=fopen("testrun.txt","r");
struct record_user x;
int i=0;

printf("%-10s %-15s %-15s %-15s %-15s %-15s %s","ACCOUNT", "First_Name","Middle_Name", "Last_Name", "Phone_Number","Adress","Password");
while(i != EOF)
{
	fscanf(userinfo,"%s %s %s %s %s %s %s", &x.regno, &x.fname, &x.mname, &x.lname, &x.phoneNumber, &x.adress, &x.password);
	printf("\n%-10s %-15s %-15s %-15s %-15s %-15s %-15s",x.regno, x.fname, x.mname, x.lname, x.phoneNumber, x.adress, x.password);
	i=fgetc(userinfo);
}


}
