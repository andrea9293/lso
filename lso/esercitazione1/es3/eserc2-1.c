#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#define sizeOfBuffer 50

int main( int argc, char *argv[] )  {
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

     if( argc == 2 ) {
          write (STDOUT_FILENO, "il file da cercare e': ", strlen("il file da cercare e': "));
          write (STDOUT_FILENO, argv[1], strlen(argv[1]));
          write (STDOUT_FILENO, "\n\n", strlen("\n\n"));

          size += sizeof(argv[1]);
          strncpy(tmp, argv[1], strlen(argv[1]));
          directory = malloc(size);
          strcpy(directory, relativeDirectory);

          //write (STDOUT_FILENO, strcat(directory, tmp), strlen(strcat(directory, tmp)));
          write (STDOUT_FILENO, "\n\n", strlen("\n\n"));

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
     else if( argc > 2 ) {
          write (STDOUT_FILENO, "troppi argomenti inseriti", strlen("troppi argomenti inseriti"));
     }
     else {
          write (STDOUT_FILENO, "inserire almeno un argomento", strlen("inserire almeno un argomento"));
     }

     //aggiungere la free per directory
}
