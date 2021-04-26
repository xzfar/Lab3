#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
#include <unistd.h>

char name[50];

void getname(){
	printf("Enter your name: ");
		gets(name);
		printf("Your name is %s\n", name);
}

int main(void){

for (int i = 4; i >= 1; i--){
	pid_t pid = fork();
		if(pid == 0){			
			getname();
		}
		else{
			
			wait(NULL);			
			exit (0);
		}
}
		
printf("job is done\n");	
return EXIT_SUCCESS;
}
