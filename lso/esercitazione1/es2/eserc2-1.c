#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#define sizeOfBuffer 50
int main (){
     int size;
     char stringa [sizeOfBuffer];
     char relativeDirectory [3];
     char tmp [sizeOfBuffer];
     int fd;
     const void *buff;
     char *directory;
     off_t fileLength;
     strcpy(relativeDirectory, "./");
     size = strlen(relativeDirectory);
     while(1){
          memset(stringa, 0, sizeOfBuffer);
          memset(tmp, 0, sizeOfBuffer);
          //free(directory);
          memset(&directory, 0, sizeof(&directory));
          size += read(STDIN_FILENO, stringa, sizeOfBuffer);
          strncpy(tmp, stringa, strlen(stringa)-1);
          directory = malloc(size);
          strcpy(directory, relativeDirectory);
          fd = open(strcat(directory, tmp), O_RDONLY);

          if (fd<0)
          write (STDOUT_FILENO, "file non trovato\n", strlen("file non trovato\n"));
          else{
               fileLength = lseek(fd, 0, SEEK_END);
               lseek(fd, 0, SEEK_SET);
               int readReturn = read (fd, &buff, fileLength);

               if (readReturn < 0)
               write (STDOUT_FILENO, "errore\n", strlen("errore\n")+1);
               else
               write (STDOUT_FILENO, &buff, readReturn);

               if(close(fd) < 0)
               write (STDOUT_FILENO, "non riesco a chiudere il file\n", strlen("non riesco a chiudere il file\n"));
               else
               write (STDOUT_FILENO, "file chiuso\n", strlen("file chiuso\n"));
          }
     }

     //aggiungere la free per directory
}
