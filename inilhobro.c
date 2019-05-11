#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>
#include <sys/sysmacros.h>

#include<pthread.h>

#define MAXCHAR 1000

char perintah1[100],perintah2[100],perintah3[100],perintah4[100],perintah5[100],perintah6[100],perintah7[100],perintah8[100];
pthread_t tid1, tid2;

void* tulis(void *arg)
{  
   if (fork()==0)
       {
           
       char *argv[4] = {perintah6,perintah7,perintah8, NULL};
       execv(perintah6, argv);
       }
}

void crontime(char min[],char hor[],char tgl[],char mon[],char day[],char p1[],char p2[],char p3[]){

time_t rawtime;
  struct tm * timeinfo;
//int menit = min-48;

int menit=atoi(min);
int jam = atoi(hor);
int tanggal = atoi(tgl);
int bulan = atoi(mon);
int hari = atoi(day);

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
//     printf("%s %s %s %s %s \n",min,hor,tgl,mon,day);
//     printf("%d %d %d %d %d",timeinfo->tm_min,timeinfo->tm_hour,timeinfo->tm_mday,timeinfo->tm_mon,timeinfo->tm_wday);
//  //   printf("%d",(int)day);
  if (hari == timeinfo->tm_wday || day[0] == '*'){
    // printf("\nHari Sama \n");
    
      if (bulan == timeinfo->tm_mon + 1 || mon[0] == '*')
      {
        /* code */
        // printf("Bulan Sama \n");
          if (tanggal == timeinfo->tm_mday || tgl[0] == '*')
          {
            // printf("Tanggal sama \n");

            if (jam == timeinfo->tm_hour || hor[0] == '*')
            {
              // printf("Jam sama \n");
                if (menit == timeinfo->tm_min || min[0] == '*')
                {

                 if(timeinfo->tm_sec == 0){

    pthread_create(&(tid1), NULL, tulis, NULL);
                   
       }
                  
                }
                
            }
            
          }
    }  
        
  }

//printf("%d",timeinfo->tm_wday);



  //printf ( "Current local time and date: %s\n %d", asctime (timeinfo),timeinfo->tm_ );





  //return 0;


}
int main() {
  pid_t pid, sid;

  pid = fork();

  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  umask(0);

  sid = setsid();

  if (sid < 0) {
    exit(EXIT_FAILURE);
  }

  if ((chdir("/home/zahrul/FP")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);
  int ctr=1;
  while(1) {
   
    FILE *fp;
    char str[MAXCHAR];
    char* filename = "/home/zahrul/FP/crontab.data";
    int count=0;
    char a;
    fp = fopen(filename, "r");
    int ke=0,j=0,k=0,l=0,m=0,n=0,o=0,p=0,q=0;
    char p1,p2,p3,p4,p5;


    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }
    while (fgets(str, MAXCHAR, fp) != NULL){
      
        int len = (int) strlen(str);
        for(int i=0;i<len;i++){
            
            if (str[i] == ' ')
            {   
                ke++;    
            }
            else{
                if(ke==0){
                     perintah1[i]=str[i];
                
                 if(str[i+1]==' ' || str[i+1] == '\0')
                             perintah1[i+1]='\0';
                             }
                
                else if(ke==1){

                    perintah2[j]=str[i];
                    j++;
                        if(str[i+1]==' ' || str[i+1] == '\0')
                        perintah2[j]='\0';
            
                        }
                else if(ke==2){

                    perintah3[k]=str[i];
                    k++;
                        if(str[i+1]==' ' || str[i+1] == '\0')
                        perintah3[k]='\0';
            
                        }
                else if(ke==3){

                    perintah4[l]=str[i];
                    l++;
                        if(str[i+1]==' ' || str[i+1] == '\0')
                        perintah4[l]='\0';
            
                        }
                 else if(ke==4){

                    perintah5[m]=str[i];
                    m++;
                        if(str[i+1]==' ' || str[i+1] == '\0')
                        perintah5[m]='\0';
            
                        }
                else if(ke==5){

                    perintah6[n]=str[i];
                    n++;
                        if(str[i+1]==' ' || str[i+1] == '\0')
                        perintah6[n]='\0';
            
                        }
                else if(ke==6){

                    perintah7[o]=str[i];
                    o++;
                        if(str[i+1]==' ' || str[i+1] == '\0')
                        perintah7[o]='\0';
            
                        }
                else if(ke==7){

                    perintah8[p]=str[i];
                    p++;
                        if(str[i+1]==' ' || str[i+1] == '\0')
                        perintah8[p]='\0';
            
                        }
            
            }        
        }


        ke=0;j=0;k=0;l=0;m=0;n=0;o=0;p=0;
        int akhir = strlen(perintah8);
       
       perintah8[akhir-1]='\0';
       p1 = perintah1[0];
   
        crontime(perintah1,perintah2,perintah3,perintah4,perintah5,perintah6,perintah7,perintah8);
   
        perintah1[0]='\0';
        perintah2[0]='\0';
        perintah3[0]='\0';
        perintah4[0]='\0';
        perintah5[0]='\0';
        perintah6[0]='\0';
        perintah7[0]='\0';
        perintah8[0]='\0';
        
        
        
        count++;
        
        
        
    
        
        
        
        
        
        }
    fclose(fp);
//return 0;
  }
  exit(EXIT_SUCCESS);
}
