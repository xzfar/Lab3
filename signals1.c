#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>

int main(void){

  void sigint_handler(int sigint);
  void sigtstp_handler(int sigtstp);
  void sigquit_handler(int sigquit);
  char s[200];
  
  if (signal(SIGINT, sigint_handler) == SIG_ERR){
     perror("signal");
     exit(1);
  }
  if (signal(SIGTSTP, sigtstp_handler) == SIG_ERR){
     perror("signal");
     exit(1);
  }
  if (signal(SIGQUIT, sigquit_handler) == SIG_ERR){
     perror("signal");
     exit(1);
  }
  
  printf("this program will capture these Signals\n");

  if (fgets(s, 200, stdin) == NULL)
      perror("gets");
  else
      printf("finish \n");
  
  return 0;
}

void sigint_handler(int sigint)
{
  printf(" This is a special signal handler for SIGINT” \n");
}

void sigtstp_handler(int sigtstp)
{
  printf(" This is a special signal handler for SIGTSTP” \n");
}

void sigquit_handler(int sigquit)
{
  printf(" This is a special signal handler for SIGQUIT” \n");
}
