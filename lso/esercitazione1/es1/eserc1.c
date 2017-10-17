#include <unistd.h>
#define sizeOfBuffer 50
int main (){
	int size;
	char stringa [sizeOfBuffer];
	char fineString [6];
	strcpy(fineString, "fine\n");
	int isFine = 0;
	while(isFine == 0){
		memset(stringa, 0, sizeOfBuffer);
		size = read(STDIN_FILENO, stringa, sizeOfBuffer);
		write (STDERR_FILENO, stringa, size);
		printf("%d\n", size);

		if  (strcmp(stringa, fineString) == 0){
			isFine = 1;
		}
	}
}


