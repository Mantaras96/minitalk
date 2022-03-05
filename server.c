
#include "libft/libft.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>


void		print_pid(void)
{
    char *tmp_pid;

    tmp_pid = ft_itoa(getpid());
    write(1, "pid: ", 5);
    write(1, tmp_pid, ft_strlen(tmp_pid));
    write(1, "\n", 1);
    free(tmp_pid);
}

void recibir (int sig, siginfo_t *info, void *context){
    (void)sig;
    (void)info;
    (void)context;
    if (sig == SIGUSR1)
        write(1, "1", 1);
    else if (sig == SIGUSR2)
        write(1, "0", 1);
}

int main(void)
{
    struct sigaction	s_sigaction;

    print_pid();
    s_sigaction.sa_sigaction = recibir;
    s_sigaction.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
    while (1)
		pause();
    return(0);
}