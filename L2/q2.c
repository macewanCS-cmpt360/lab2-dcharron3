// Name: Damien Charron  	SID: 1602918
// This is the c code for question 2
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	char *filename = "q2.test";
	close(STDOUT_FILENO);
	open(filename, O_WRONLY | O_CREAT | O_TRUNC);
	int y = fork();
	if(y<0){
		printf("\nfork failed");
		exit(1);
	} else if (y == 0) {
		printf("Child writing to file\n");
	} else {
		printf("Parent writing to file\n");
	}

	return 0;
}

// Question 2 answer:
// Both the parent and child can access and print to the same
// file. When both write at the same time (concurrently)
// the scheduler decides which can write first and the second
// IO process will need to wait until the first is finished.
	
