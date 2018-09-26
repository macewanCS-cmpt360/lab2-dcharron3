// Name: Damien Charron  	SID: 1602918
// This is the c code for question 1
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	int x = 100;
	printf("\nVariable before fork call %d",x);
	int y = fork();
	if(y<0){
		printf("\nfork failed");
		exit(1);
	} else if (y == 0) {
		printf("\nChild variable is %d",x);
		x=300;
		printf("\nChild variable set to %d",x);
	} else {
		printf("\nParent variable %d",x);
		x=200;
		printf("\nParent variable set to %d",x);
	}
	printf("\nVariable after fork %d\n",x);
	return 0;
}

// Question 1 answer:
// Since both processes have access to the same variable they can
// both change it. The final value will be that of which ever
// fork finishes last.
	
