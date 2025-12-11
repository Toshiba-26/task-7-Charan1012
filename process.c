#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
 printf("Before using fork(): %d\n",getpid());
 
 pid_t pid = fork();
 
 if(pid < 0){
  perror("fork() failed");
  return 1;
 }
 if(pid == 0){
  printf("Child PID: %d and Parent PID: %d\n",getpid(),getppid());
 }
 else{
  printf("Parent PID: %d and Child PID: %d\n",getpid(),pid);
  wait(NULL);
 }

return 0;
}
