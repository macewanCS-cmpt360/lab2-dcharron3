// Name: Damien Charron  	SID: 1602918
// This is the c code for question 3
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	int y = fork();
	if(y<0){
		printf("\nfork failed");
		exit(1);
	} else if (y == 0) { //child process
		printf("\nHello\n");
	} else { //parent process
		sleep(1); //instead of using wait() just sleep()
		printf("\nGoodbye\n");
	}
	return 0;
}
