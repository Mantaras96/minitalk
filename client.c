
#include "libft/libft.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void show_error(int error)
{
    if (error == 1)
    {
        write(1, "Numero de parametro no es correcto", 35);
    } else if (error == 2)
    {
        write(1, "El pid solo acepta caracteres numericos", 40);
    }
}

void send_signal(int pid, char c)
{
    int i;
    
    i = 8;
	while (i--)
    {
		if (c >> i & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
	}
}

void send_data(char *server_pid, char *str){
    int i;
    int pid;
    (void)str;
    pid = ft_atoi(server_pid);
    i = 0;
    while(str[i])
    {
        send_signal(pid, str[i]);
        i++;
    }

}


int main(int argc, char **argv){

    if (argc == 3 && ft_strlen > 0){
        send_data(argv[1], argv[2]);
    } else {
        show_error(1);
    }
    return(0);
}