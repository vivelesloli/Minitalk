#include "minitalk.h"

void	choose_sig(char *str, int i, int j, int pid)
{
	if (str[i] & 128 / ft_power(2, j))
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			ft_putstr("Invalid PID");
			exit(1);
		}
	}
	else
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			ft_putstr("Invalid PID");
			exit(1);
		}
	}
}

void	send_char(int pid, char *str)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	max = ft_strlen(str);
	while (i <= max)
	{
		j = 0;
		while (j < 8)
		{
			choose_sig(str, i, j, pid);
			j++;
			usleep(100);
		}
		i++;
	}
}

void	has_receive(int pid)
{
	(void)pid;
	ft_putstr("The message has been receive by the server");
	exit(0);
}

int	main(int argc, char **argv)
{
	int		pid;
	int		client_pid;
	char	*pid_to_char;

	signal(SIGUSR2, has_receive);
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		send_char(pid, argv[2]);
		client_pid = getpid();
		pid_to_char = ft_itoa(client_pid);
		send_char(pid, pid_to_char);
		free(pid_to_char);
	}
	else
	{
		ft_putstr("Error : Arguments");
		return (1);
	}
	pause();
	return (0);
}
