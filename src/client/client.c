/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:44:46 by tpinto-e          #+#    #+#             */
/*   Updated: 2023/03/22 19:25:26 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minitalk.h"

void	bit_convert(int pid, int c)
{
	int	i;

	i = 8;
	while (--i >= 0)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc != 3 || !ft_check_alnum(argv[1]))
	{
		ft_printf("nope, try again\n");
		return (0);
	}
	i = 0;
	while (argv[2][i])
		bit_convert(ft_atoi(argv[1]), argv[2][i++]);
	return (0);
}
