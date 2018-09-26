// Name: Damien Charron  	SID: 1602918
// This is the c code for question 7
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	int y = fork();
	if(y<0){
		printf("\nfork failed");
		exit(1);
	} else if (y == 0) { 	//child process
		close(STDOUT_FILENO);
		printf("\nHello\n");
	} else { 		//parent process
		printf("\nGoodbye\n");
	}
	return 0;
}
// Answer for Question 7:
// When the child process closes STDOUT_FILENO it has
// no descriptor to write to. Since the parent did not
// close it, it can still write to it.
