#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>

/**
 *infinite_while-Runs indefinitely with sleep interval of 1
 *
 *Return: 0.
 */

int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}

/**
 * main - Creates five zombie processes.
 *
 * Return: Always 0.
 **/
int main(void)
{
	pid_t pid;
	int flag = 0;

	for (flag = 0; flag < 5; flag++)
	{
		pid = fork();
		if (pid > 0)
		{
			printf("Zombie process created, PID: %d\n", pid);
			sleep(1);
		}
		else
			exit(0);
	}

	infinite_while();

	return (EXIT_SUCCESS);
}
