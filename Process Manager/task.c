#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char pID[100],com[200],sname[100],t,k;

void run_stop()
{
	system("top");
	int c;
	printf("\n1. Run process\n2. Stop process (kill processID)\n");
	scanf("%d",&c);
	k = getchar(); // to take one character
	if(c== 1){
	 printf("Enter the name of the process you want to run : ");	
	        gets(com);
		system(com);

	}else if (c==2){
		strcpy(com,"kill ");
		printf("Enter the process id : ");
		gets(pID);
		strcat(com,pID);
		system(com);
		//system("kill 4");
	}else
	     printf("Enter Correct Choice");
				
}

void send_signal(){
 	// kill -s SIGName PID
	printf("\nThe Running processes \n");
	system("top");
	
	printf("Enter the name of the signal : ");
	gets(sname);
	
	printf("Enter the ID of the process : "); 
	gets(pID);
	
	strcpy(com,"kill -s ");
	strcat(com,sname);
	strcat(com, " ");
	strcat(com,pID);
	system(com);
}




int main(int argc, char *argv[]){

if(argc > 1){
	if(strcmp(argv[1],"--help")==0)
		printf("First option is to List all the process in the system\nSecond option is to List all the process grouped by user\nThird option is to Display the process ID of all the processes \nFourth option i to Run OR stop a specific process\nFifth option is to Send specific signals to specific process\nSixth option is to Exit from the project\n");
}else{ 
	
	while(1){
		printf("1. List all the process in the system \n2. List all the process grouped by user \n3. Display the process ID of all the processes \n4. Run/ stop a specific process \n5. Send specific signals to specific process \n6. Exit\n");
		int choice;
		scanf("%d",&choice);
		t = getchar();
		switch(choice)	{
			// list all the processes in the system
			case 1: system("ps -A"); 
				break;
			
			// list all the processes grouped by a user
			case 2: system("ps -u");
				break;
			
			// Display process id of all the processes
			case 3:system("ps -eo pid");
				break;
			
			// Run/ stop a specific process
			case 4:
				run_stop();
				break;
				
			// send specific signal to specfic process 
			case 5: 
				send_signal();
				break;
			case 6:
				exit(0);
			default:
				printf("Enter Correct Choice\n");
		
		}
	  
	}
}
	return 0;
}
