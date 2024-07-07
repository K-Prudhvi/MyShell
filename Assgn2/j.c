#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>
#include <fcntl.h>
#include <sys/types.h>
void ls(int);
void lsl(int);
void lsU(int);
void lsm(int);
void lsa(int);
void lsS(int);
void lst(int);
void cp(char *, char *);
void cpn(char *, char *);
void cpv(char *, char *);
void cpi(char *, char *);
void cpf(char *, char *);
void mv(char *, char *);
void mvi(char *, char *);
void mvn(char *, char *);
void mvv(char *, char *);
void mvf(char *,char *);
void grep(char a[],char b[]);
void grepH(char a[],char b[]);
void grepc(char a[],char b[]);
void grepn(char a[],char b[]);
void grepv(char a[],char b[]);


struct student
{
       char *filename;
       double size;
       double time;
};
int main()
{
       while (1)
       {
              char c[256];
              char b[2000];
              gethostname(c, 256);
              char *username = getlogin();
              getcwd(b, 2000);
              char d[2] = "@";
              char f[3]="$ ";
              char g[2]=":";
              strcat(c, d);
              strcat(c, username);
              strcat(c,g);
              strcat(c,b);
              strcat(c,f);
              unsigned char *e;
              e = readline(c);
              if(strlen(e)!=0){add_history(e);}
              char *kw[30]={"p"};
              int l = 0;
              char *token = strtok(e, " ");
              while (token != NULL)
              {
                     kw[l] = token;
                     l++;
                     token = strtok(NULL, " ");
              }
              int q;
              if (strcmp(kw[0], "ls") == 0 && l == 1)
              {
                     ls(q);
              }
              else if (l == 2)
              {
                     if (strcmp(kw[1], "-l") == 0 && strcmp(kw[0], "ls") == 0)
                     {
                            lsl(q);
                     }
                     if (strcmp(kw[1], "-a") == 0 && strcmp(kw[0], "ls") == 0)
                     {
                            lsa(q);
                     }
                     if (strcmp(kw[1], "-m") == 0 && strcmp(kw[0], "ls") == 0)
                     {
                            lsm(q);
                     }
                     if (strcmp(kw[1], "-U") == 0 && strcmp(kw[0], "ls") == 0)
                     {
                            lsU(q);
                     }
                     if (strcmp(kw[1], "-S") == 0 && strcmp(kw[0], "ls") == 0)
                     {
                            lsS(q);
                     }
                     if (strcmp(kw[1], "-t") == 0 && strcmp(kw[0], "ls") == 0)
                     {
                            lst(q);
                     }
              }
              else if (l == 3 && strcmp(kw[0], "cp") == 0)
              {
                     cp(kw[1], kw[2]);
              }
              else if (l == 4 && strcmp(kw[1], "-v") == 0 && strcmp(kw[0], "cp") == 0)
              {
                     cpv(kw[2], kw[3]);
              }
              else if (l == 4 && strcmp(kw[1], "-i") == 0 && strcmp(kw[0], "cp") == 0)
              {
                     cpi(kw[2], kw[3]);
              }
              else if (l == 4 && strcmp(kw[1], "-n") == 0 && strcmp(kw[0], "cp") == 0)
              {
                     cpn(kw[2], kw[3]);
              }
              else if (l == 4 && strcmp(kw[1], "-f") == 0 && strcmp(kw[0], "cp") == 0)
              {
                     cpf(kw[2], kw[3]);
              }
              else if (l == 3 && strcmp(kw[0], "mv") == 0)
              {
                     mv(kw[1], kw[2]);
              }
              else if (l == 4 && strcmp(kw[1], "-i") == 0 && strcmp(kw[0], "mv") == 0)
              {
                     mvi(kw[2], kw[3]);
              }
              else if (l == 4 && strcmp(kw[1], "-n") == 0 && strcmp(kw[0], "mv") == 0)
              {
                     mvn(kw[2], kw[3]);
              }
              else if (l == 4 && strcmp(kw[1], "-v") == 0 && strcmp(kw[0], "mv") == 0)
              {
                     mvv(kw[2], kw[3]);
              }
               else if (l == 4 && strcmp(kw[1], "-f") == 0 && strcmp(kw[0], "mv") == 0)
              {
                     mvf(kw[2], kw[3]);
              }
              else if (l == 3 && strcmp(kw[0], "grep") == 0)
              {
                     grep(kw[1],kw[2]);
              }
              else if (l == 4 && strcmp(kw[1], "-H") == 0 && strcmp(kw[0], "grep") == 0)
              {
                     grepH(kw[2], kw[3]);
              }
              else if (l == 4 && strcmp(kw[1], "-v") == 0 && strcmp(kw[0], "grep") == 0)
              {
                     grepv(kw[2], kw[3]);
              }
              else if (l == 4 && strcmp(kw[1], "-c") == 0 && strcmp(kw[0], "grep") == 0)
              {
                     grepc(kw[2], kw[3]);
              }
              else if (l == 4 && strcmp(kw[1], "-n") == 0 && strcmp(kw[0], "grep") == 0)
              {
                     grepn(kw[2], kw[3]);
              }
              else if(!strcmp(kw[0],"exit")){
              printf("EXITING\n");
              break;
              }
       }
}

void ls(int a)
{
       int k = 0;
       struct dirent *d;
       struct student bro[1000];
       struct student g;
       DIR *dr = opendir(".");
       while ((d = readdir(dr)) != NULL)
       {
              if (d->d_name[0] != '.')
              {
                     k++;
              }
       }
       closedir(dr);
       int i = 0;
       DIR *dir = opendir(".");
       while ((d = readdir(dir)) != NULL)
       {
              if (d->d_name[0] != '.')
              {
                     bro[i].filename = d->d_name;
                     i++;
              }
       }
       for (int i = 0; i < k; i++)
       {
              for (int j = 0; j < k; j++)
              {
                     if (strcmp(bro[i].filename, bro[j].filename) < 0)
                     {
                            g = bro[i];
                            bro[i] = bro[j];
                            bro[j] = g;
                     }
              }
       }
       for (int i = 0; i < k; i++)
       {
              printf("%s ", bro[i].filename);
       }
       puts(" ");
}
void lsl(int a)
{
       struct group *gr;
       struct passwd *pw;
       struct dirent *d;
       struct stat file;
       struct student bro[1000];
       int i=0;
       DIR *dr = opendir(".");
       while ((d = readdir(dr)) != NULL)
       {
              if (d->d_name[0] != '.')
              {
                     if (stat(d->d_name, &file) != -1)
                     {
                            if (S_ISDIR(file.st_mode))
                            {
                                   printf("d");
                            }
                            else
                            {
                                   printf("-");
                            }
                            if (file.st_mode & S_IRUSR)
                            {
                                   printf("r");
                            }
                            else
                            {
                                   printf("-");
                            }
                            if (file.st_mode & S_IWUSR)
                            {
                                   printf("w");
                            }
                            else
                            {
                                   printf("-");
                            }
                            if (file.st_mode & S_IXUSR)
                            {
                                   printf("x");
                            }
                            else
                            {
                                   printf("-");
                            }
                            if (file.st_mode & S_IRGRP)
                            {
                                   printf("r");
                            }
                            else
                            {
                                   printf("-");
                            }
                            if (file.st_mode & S_IWGRP)
                            {
                                   printf("w");
                            }
                            else
                            {
                                   printf("-");
                            }
                            if (file.st_mode & S_IXGRP)
                            {
                                   printf("x");
                            }
                            else
                            {
                                   printf("-");
                            }
                            if (file.st_mode & S_IROTH)
                            {
                                   printf("r");
                            }
                            else
                            {
                                   printf("-");
                            }
                            if (file.st_mode & S_IWOTH)
                            {
                                   printf("w");
                            }
                            else
                            {
                                   printf("-");
                            }
                            if (file.st_mode & S_IXOTH)
                            {
                                   printf("x ");
                            }
                            else
                            {
                                   printf("- ");
                            }
                            printf("%ld ", file.st_nlink);
                            pw = getpwuid(file.st_uid);
                            printf("%s ", pw->pw_name);
                            gr = getgrgid(file.st_gid);
                            printf("%s ", gr->gr_name);
                            printf("%ld ", file.st_size);
                            char date[32];
                            strftime(date, 32, "%b %d", localtime(&file.st_mtime));
                            printf(" %s ", date);
                            char time[32];
                            strftime(time, 32, "%H:%M", localtime(&file.st_mtime));
                            printf("%s ", time);
                            printf("%s",d->d_name);
                            puts(" ");
                     }
              }
       }
}
void lsa(int a)
{
       struct student bro[1000];
       struct student q;
       struct dirent *d;
       int i = 0;
       DIR *dr = opendir(".");
       while ((d = readdir(dr)) != NULL)
       {
              bro[i].filename = d->d_name;
              i++;
       }
       for (int m = 0; m < i; m++)
       {
              for (int n = m + 1; n < i; n++)
              {
                     if (strcmp(bro[m].filename, bro[n].filename) > 0)
                     {
                            q = bro[m];
                            bro[m] = bro[n];
                            bro[n] = q;
                     }
              }
       }
       for (int m = 0; m < i; m++)
       {
              printf("%s ", bro[m].filename);
       }
       puts(" ");
}
void lsm(int a)
{
       struct student bro[1000];
       struct student q;
       int count = 0;
       struct dirent *d;
       DIR *dr = opendir(".");
       while ((d = readdir(dr)) != NULL)
       {
              if (d->d_name[0] != '.')
              {
                     bro[count].filename = d->d_name;
                     count++;
              }
       }
       for (int m = 0; m < count; m++)
       {
              for (int n = m + 1; n < count; n++)
              {
                     if (strcmp(bro[m].filename, bro[n].filename) > 0)
                     {
                            q = bro[m];
                            bro[m] = bro[n];
                            bro[n] = q;
                     }
              }
       }
       closedir(dr);
       for (int m = 0; m < count - 1; m++)
       {
              printf("%s ,", bro[m].filename);
       }
       printf("%s", bro[count - 1].filename);
       puts(" ");
}
void lsU(int a)
{
       struct dirent *d;
       DIR *dr = opendir(".");
       while ((d = readdir(dr)) != NULL)
       {
              if (d->d_name[0] != '.')
              {
                     printf("%s ", d->d_name);
              }
       }
       puts(" ");
}
void lsS(int a)
{
       struct dirent *d;
       struct stat file;
       struct student bro[1000];
       struct student q;
       int i = 0;
       DIR *dr = opendir(".");
       while ((d = readdir(dr)) != NULL)
       {
              if (d->d_name[0] != '.')
              {
                     bro[i].filename = d->d_name;
                     i++;
              }
       }
       closedir(dr);
       int j = 0;
       DIR *dir = opendir(".");
       while ((d = readdir(dir)) != NULL)
       {
              if (d->d_name[0] != '.')
              {
                     if (stat(d->d_name, &file) != -1)
                     {
                            bro[j].size = file.st_size;
                            j++;
                     }
              }
       }
       for (int m = 0; m < i; m++)
       {
              for (int n = m + 1; n < i; n++)
              {
                     if (bro[m].size < bro[n].size)
                     {
                            q = bro[m];
                            bro[m] = bro[n];
                            bro[n] = q;
                     }
              }
       }
       for (int m = 0; m < i; m++)
       {
              printf("%s ", bro[m].filename);
       }
       puts(" ");
}
void lst(int a)
{
       struct dirent *d;
       struct stat file;
       struct student bro[1000];
       struct student q;
       int i = 0;
       DIR *dr = opendir(".");
       while ((d = readdir(dr)) != NULL)
       {
              if (d->d_name[0] != '.')
              {
                     bro[i].filename = d->d_name;
                     i++;
              }
       }
       closedir(dr);
       int j = 0;
       DIR *dir = opendir(".");
       while ((d = readdir(dir)) != NULL)
       {
              if (d->d_name[0] != '.')
              {
                     if (stat(d->d_name, &file) != -1)
                     {
                            bro[j].time = file.st_atime;
                            j++;
                     }
              }
       }
       for (int m = 0; m < i; m++)
       {
              for (int n = m + 1; n < i; n++)
              {
                     if (bro[m].time < bro[n].time)
                     {
                            q = bro[m];
                            bro[m] = bro[n];
                            bro[n] = q;
                     }
              }
       }
       for (int m = 0; m < i; m++)
       {
              printf("%s ", bro[m].filename);
       }
       puts(" ");
}
void cp(char *a, char *b)
{
       struct stat file;
       char buffer[1000];
       int s, d, br, bw;
       s = open(a, O_RDONLY);
       if (s < 0)
       {
              printf("Couldn't open file\n");
       }
       stat(b,&file);
       if (S_ISDIR(file.st_mode)){
              strcat(b,"/");
              strcat(b,a);
              d = open(b, O_WRONLY | O_CREAT | O_TRUNC, 0644);
       if (d < 0)
       {
              printf("Couldn't open destination file\n");
              close(s);
       }
       while ((br = read(s, buffer, 1000)) > 0)
       {
              bw = write(d, buffer, br);
              if (bw != br)
              {
                     printf("Error: Unable to write to destination file.\n");
                     close(s);
                     close(d);
              }
       }
       close(s);
       close(d);
       }
       else{
       d = open(b, O_WRONLY | O_CREAT | O_TRUNC, 0644);
       if (d < 0)
       {
              printf("Couldn't open destination file\n");
              close(s);
       }
       while ((br = read(s, buffer, 1000)) > 0)
       {
              bw = write(d, buffer, br);
              if (bw != br)
              {
                     printf("Error: Unable to write to destination file.\n");
                     close(s);
                     close(d);
              }
       }
       close(s);
       close(d);
}
}
void cpv(char *a, char *b)
{
       int s;
       s=open(a,O_RDONLY);
       if(s<0){
              printf("Coudn't open file\n");
       }
       else{
       cp(a,b);
       printf("'%s' -> '%s'", a, b);
       printf("\n");}
}
void cpi(char *a, char *b)
{
       struct stat file;
       char buffer[1000];
       int s, d, br, bw, k, l = 0;
       char *q;
       s = open(a, O_RDONLY);
       if (s < 0)
       {
              printf("Couldn't open file\n");
       }
       else{
       k = open(b, O_RDONLY);
       if (k < 0)
       {
              cp(a,b);
       }
       if (k > 0)
       {
              stat(b,&file);
              if (S_ISDIR(file.st_mode)){
              strcat(b,"/");
              strcat(b,a);
              printf("cp: overwrite '%s'?", b);
              q = readline(" ");
              if (*q == 'y')
              {
                     cp(a,b);
              }
              }
              else{
              printf("cp: overwrite '%s'?", b);
              q = readline(" ");
              if (*q == 'y')
              {
                     cp(a,b);
              }
}
       }
       }
}

void cpn(char *a, char *b)
{
       struct stat file;
       char buffer[1000];
       int s, d, br, bw, k;
       s = open(a, O_RDONLY);
       if(s<0){
              printf("Coudn't open file\n");
       }
       k = open(b, O_RDONLY);
       stat(b,&file);
       if (S_ISDIR(file.st_mode)){
              strcat(b,"/");
              strcat(b,a);
              cp(a,b);}
       else if (k < 0)
       {
              cp(a,b);
       }
      else if (k > 0)
       {
              return;
       }
}
void cpf(char *a, char *b)
{
       struct stat file;
       char buffer[1000];
       int s, d, br, bw, k;
       s = open(a, O_RDONLY);
       k = open(b, O_RDONLY);
       stat(b,&file);
       if (S_ISDIR(file.st_mode)){
              strcat(b,"/");
              strcat(b,a);
              cp(a,b);}
       if (k < 0)
       {
              cp(a, b);
       }
       if (k > 0)
       {
              remove(b);
              cp(a, b);
       }
}
void mv(char *a, char *b)
{
       struct stat file;
       char buffer[1000];
       int s, d, br, bw;
       stat(b,&file);
       s = open(a, O_RDONLY);
       if(s<0){
              printf("Coudn't open file\n");
       }
       else if (S_ISDIR(file.st_mode)){
              strcat(b,"/");
              strcat(b,a);
              cp(a,b);
              remove(a);}
       else
       {
              cp(a, b);
              remove(a);
       }
}
void mvi(char *a, char *b)
{
       struct stat file;
       char buffer[1000];
        stat(b,&file);
       int s, d, br, bw, k;
       char *q;
       s = open(a, O_RDONLY);
       if(s<0){
              printf("Coudn't open file\n");
       }
       else{
       k = open(b, O_RDONLY);
       if (k < 0)
       {
              cp(a, b);
              remove(a);
       }
       if (k > 0)
       {
              
              if (S_ISDIR(file.st_mode)){
              strcat(b,"/");
              strcat(b,a);
              printf("mv: overwrite '%s'?", b);
              q = readline("");
              if (*q == 'y')
              {
                     cp(a, b);
                     remove(a);
              }
              }
              else{
                     printf("mv: overwrite '%s'?", b);
              q = readline("");
              if (*q == 'y')
              {
                     cp(a, b);
                     remove(a);
              }

              }
       }
       }
}
void mvn(char *a, char *b)
{
       struct stat file;
       char buffer[1000];
       int s, d, br, bw, k;
       s = open(a, O_RDONLY);
       if(s<0){
              printf("Coudn't open file\n");
       }
        stat(b,&file);
       k = open(b, O_RDONLY);
       if (k < 0)
       {
              cp(a, b);
              remove(a);
       }
       if (k > 0)
       {
              if (S_ISDIR(file.st_mode)){
              strcat(b,"/");
              strcat(b,a);
              cp(a,b);
              remove(a);}
              else{
              return;}
       }
}

void mvv(char *a, char *b)
{
       struct stat file;
       char buffer[1000];
       int s, d, br, bw;
       stat(b,&file);
       s = open(a, O_RDONLY);
       if(s<0){
              printf("Coudn't open file");
       }
        else if (S_ISDIR(file.st_mode)){
              strcat(b,"/");
              strcat(b,a);
              cp(a,b);
              remove(a);
              printf("renamed '%s' -> '%s'", a, b);
       }
       else
       {
              cp(a, b);
              remove(a);
              printf("renamed '%s' -> '%s'", a, b);
       }
       puts(" ");
}
void mvf(char *a, char *b)
{
       struct stat file;
       char buffer[1000];
       int s, d, br, bw, k;
       s = open(a, O_RDONLY);
       k = open(b, O_RDONLY);
       stat(b,&file);
       if (S_ISDIR(file.st_mode)){
              strcat(b,"/");
              strcat(b,a);
              cp(a,b);
              remove(a);}
       if (k < 0)
       {
              cp(a, b);
              remove(a);
       }
       if (k > 0)
       {
              remove(b);
              cp(a, b);
              remove(a);
       }
}
void grep(char a[100],char b[100])
{
       FILE* s;
    s=fopen(b,"r");
    char *line;
    size_t size = 0;
    int l=0;
    
    while(getline(&line,&size, s)!=-1){
            l++;
            if (strstr(line,a) != NULL) {
                printf("%s", line);
            }
        }
    

    fclose(s);
}
void grepH(char a[100],char b[100])
{
       FILE* s;
    s=fopen(b,"r");
    char *line;
    size_t size = 0;
    int l=0;
    
    while(getline(&line,&size, s)!=-1){
            l++;
            if (strstr(line,a) != NULL) {
                printf("%s:%s",b,line);
            }
        }
    

    fclose(s);
}
void grepv(char a[100],char b[100])
{
       FILE* s;
    s=fopen(b,"r");
    char *line;
    size_t size = 0;
    int l=0;
    
    while(getline(&line,&size, s)!=-1){
            l++;
            if (strstr(line,a) == NULL) {
                printf("%s",line);
            }
        }
    

    fclose(s);
}
void grepn(char a[100],char b[100])
{
       FILE* s;
    s=fopen(b,"r");
    char *line;
    size_t size = 0;
    int l=0;
    
    while(getline(&line,&size, s)!=-1){
            l++;
            if (strstr(line,a) != NULL) {
                printf("%d:%s",l,line);
            }
        }
    

    fclose(s);
}
void grepc(char a[100],char b[100])
{
       FILE* s;
    s=fopen(b,"r");
    char *line;
    size_t size = 0;
    int l=0;
    
    while(getline(&line,&size, s)!=-1){
            if (strstr(line,a) != NULL) {
              l++;
            }
        }
        printf("%d\n",l);
    fclose(s);
}


