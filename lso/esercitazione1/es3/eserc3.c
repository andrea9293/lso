#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define sizeOfBuffer 50
int main (){
     int size;
     char stringa [sizeOfBuffer];
     char fineString [6];
     int isFine = 0;
     int fd;
     //int *sizeOfString = malloc(sizeof(int));
     fd = open("./file",O_RDWR | O_CREAT | O_TRUNC, S_IRWXU | S_IRWXG | S_IRWXO);
     while(isFine == 0){
          memset(stringa, 0, sizeOfBuffer);
          size = read(STDIN_FILENO, stringa, sizeOfBuffer);
          //*sizeOfString = size;
          write (fd, stringa, size);
          //write (fd, &size, sizeof(size));
          //non funziona la scruttura della lunghezza

          if  (strcmp(stringa, "fine\n") == 0){
               isFine = 1;
               if(close(fd) < 0){
                    write (STDOUT_FILENO, "non riesco a chiudere il file\n", strlen("non riesco a chiudere il file\n")+1);
               }else{
                    write (STDOUT_FILENO, "file chiuso\n", strlen("file chiuso\n")+1);
               }
          }
     }
}
