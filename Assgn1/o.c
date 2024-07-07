#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<readline/readline.h>
#include<readline/history.h>
#include<unistd.h>
int main(){
	while(1){
	char c[256];
	char b[2000];
	gethostname(c,256);
	char *username=getlogin();
	char g[2]=":";
    getcwd(b,2000);
    char d[2]="@";
	char f[3]="$ ";
	strcat(c,d);
	strcat(c,username);
	strcat(c,g);
	strcat(c,b);
	strcat(c,f);
    unsigned char *a;
	a=readline(c);
	if(strlen(a)!=0){add_history(a);}
	system(a);
	char *kw[30]={"p"};
	int l=0;
    char *token=strtok(a," ");
	while (token != NULL)
              {
                     kw[l] = token;
                     l++;
                     token = strtok(NULL, " ");
              }
	if(strcmp(*kw,"exit")==0){ printf("EXITING\n");
	break;}
        if(strcmp(*kw,"help")==0){system("bash -c help");}
}
}
