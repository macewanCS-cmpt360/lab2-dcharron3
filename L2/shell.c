// Name: Damien Charron		SID:1602918 
// This progam is an implimentation of a simple shell.
// Code has been adapted from shell_example.c given in lab.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(void)
{

	char *cmdline;
	char *token = NULL;
	int i, rc;
	char *args[10];

	while (args[i]==NULL){

		rc = fork();
	
		if (rc < 0){
			fprintf(stderr,"Fork Failure\n");
		} else if (rc == 0){
			cmdline = calloc(1, 1024);
			i = 0;
	
			printf("prompt> ");
			fgets(cmdline, 1024, stdin);
			//fprintf(stderr, "[debug] cmdline = *%s*\n", cmdline);
	
			token = strtok(cmdline, "\n ");
			while (token != NULL) {
				//printf("%s\n", token);
				args[i++] = strdup(token);
				token = strtok(NULL, "\n ");
			}
			
			execvp(args[0],args);
			args[i] = NULL;
		
			free(cmdline);
		} else {
			int rc_wait = wait(NULL);
		}
	}
}
