#include <semaphore.h>
#include <sys/semaphore.h>
#include <unistd.h>

int	main(void)
{
	int		pid;
	sem_t	*semaphore;

	pid = fork();
	if (pid < 0)
		return (1);
	dup2(2, 1);
	semaphore = sem_open("/semaphore", 1);
	if (pid == 0)
	{
		while (1)
		{
			sem_wait(semaphore);
			write(1, "hello ", 6);
			sem_post(semaphore);
			sleep(1);
		}
	}
	else
	{
		sleep(1);
		while (1)
		{
			sem_wait(semaphore);
			write(1, "world\n", 6);
			sem_post(semaphore);
			sleep(1);
		}
	}

}