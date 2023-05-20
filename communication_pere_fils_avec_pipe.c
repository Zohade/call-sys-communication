#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MSG_SIZE 255

int main (int argc, char *argv[]){

   pid_t pid_fils;
   int fd[2], ret;
   int fd2[2],retu;
   ret = pipe(fd); // le fils écrit dans le pipe et le père y lit
    retu=pipe(fd2); // le pere ecrit le fils lit
    if(retu<0){
    	printf("Imposiible de creer le pipe \n");
    	exit(2);
    }
   if(ret < 0){
      printf("Impossible de créer le pipe\n");
      exit(2);
   }
   
   pid_fils = fork();
   
   if(pid_fils < 0){
      printf("Impossible de créer le processus fils\n");
      exit(1);
   }
   
   if(pid_fils == 0){
       /*Nous sommes dans le processus fils*/
       //execve("./copie_fichier", argv, NULL);
       close(fd[0]); // le fils écrit
       close(fd2[1]);//le fils lit
       
       
       
       char *msge = (char*)malloc(MSG_SIZE);
       int nread = read(fd2[0], msge, strlen(msge));
       printf("%s", msge);
       
       char *msg = "Donne moi de l'argent très cher PAPA\n";
       int nwrite = write(fd[1], msg, strlen(msg)); 
       
       close(fd[1]);
       close(fd2[0]);
       
       exit(-1);
   }else{
       /* Nous sommes dans le processus parent*/
 
       close(fd[1]);
       close(fd2[0]); // le pere écrit
       char *msge = "J'ai pas l'argent mon fils\n";
       int nwrite = write(fd2[1], msge, strlen(msge)); 
       
       char *msg = (char*)malloc(MSG_SIZE);
       int nread = read(fd[0], msg, MSG_SIZE);
       printf("%s", msg);
       close(fd[0]);
       close(fd2[1]);
       int status;
       wait(&status);
       
       printf("Mon fils a renvoyé le code d'erreur %d\n", status);
       exit(0);   
   }

}
