/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 17:38:06 by amantara          #+#    #+#             */
/*   Updated: 2022/03/06 17:39:04 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	*ft_append_char( char *str, char c)
{	
	char	*str2;
	int		i;

	i = 0;
	str2 = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!str2)
		return (NULL);
	while (str[i])
	{
		str2[i] = str[i];
		i++;
	}
	str2[i] = c;
	str2[i + 1] = '\0';
	free(str);
	return (str2);
}

void	print_pid(void)
{
	char	*tmp_pid;

	tmp_pid = ft_itoa(getpid());
	write(1, "pid: ", 5);
	write(1, tmp_pid, ft_strlen(tmp_pid));
	write(1, "\n", 1);
	free(tmp_pid);
}

void	binary_to_decimal(char *str)
{
	int				acumulado;
	unsigned char	c;
	size_t			i;

	c = 0;
	i = 0;
	acumulado = 128;
	while (str[i])
	{
		c += acumulado * (str[i] - '0');
		acumulado = acumulado / 2;
		i++;
	}
	write(1, &c, 1);
}

// void recibir (int sig){
// 	static char	*bits;
// 	static int	bitcount;

// 	bitcount++;
// 	if(!bits)
// 	{
// 		bits = ft_strdup("");
// 		bitcount = 1;
// 	}
// 	if (sig == SIGUSR1)
// 		ft_strjoinC(bits, '1');
// 	else if (sig == SIGUSR2)
// 		ft_strjoinC(bits, '0');
// 	if (bitcount == 8)
// 	{

// 		binary_to_decimal(bits);
// 		free(bits);
// 		bits = NULL;
// 	}
// }

// reads every bit and appends it to bits
// if its a 8 bit it prints the char to the console
static void	ft_confirm(int sig)
{
	static char	*bits;
	static int	bitcount;
	int			i;

	bitcount++;
	if (bits == NULL)
	{
		bits = ft_strdup("");
		bitcount = 1;
	}
	if (sig == SIGUSR2)
		bits = ft_append_char(bits, '0');
	else
		bits = ft_append_char(bits, '1');
	if (bitcount == 8)
	{
		i = 0;
		binary_to_decimal(bits);
		free(bits);
		bits = NULL;
	}
}

int	main(void)
{
	print_pid();
	while (1)
	{
		signal(SIGUSR1, ft_confirm);
		signal(SIGUSR2, ft_confirm);
		pause();
	}
	return (0);
}
