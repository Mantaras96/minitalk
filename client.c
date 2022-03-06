/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amantara <amantara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 17:39:52 by amantara          #+#    #+#             */
/*   Updated: 2022/03/06 18:13:17 by amantara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int	validar_pid(char *str)
{	
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	show_error(int error)
{
	if (error == 1)
	{
		write(1, "Numero de parametro no es correcto", 35);
	}
	else if (error == 2)
	{
		write(1, "El pid solo acepta caracteres numericos", 40);
	}
}

void	send_char(int pid, char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1')
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		i++;
		usleep(100);
	}
}

// Transform array char to array binari codes 
// (8 digits('0' or '1') for each letter)
static char	*ft_to_bit(char *s, size_t i, size_t j)
{
	char	*ret;
	int		c;
	int		bytes;

	i = ft_strlen(s);
	ret = ft_calloc(i * 8 + 1, sizeof(char));
	if (ret == NULL)
		return (NULL);
	while (i + 1 != 0)
	{
		c = s[i - 1];
		bytes = 8;
		while (bytes > 0)
		{
			if (c % 2 == 1)
				ret[ft_strlen(s) * 8 - j - 1] = '1';
			else
				ret[ft_strlen(s) * 8 - j - 1] = '0';
			c /= 2;
			j++;
			bytes--;
		}
		i--;
	}
	return (ret);
}

//Server pid + message will show server
int	main(int argc, char **argv)
{
	if (argc == 3 && ft_strlen > 0 && validar_pid(argv[1]) == 1)
		send_char(ft_atoi(argv[1]), ft_to_bit(argv[2], 0, 0));
	else
	{
		if (validar_pid(argv[1]) == 1)
			show_error (1);
		else
			show_error (2);
	}
	return (0);
}
