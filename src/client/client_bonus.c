/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:42:26 by tpinto-e          #+#    #+#             */
/*   Updated: 2023/03/30 16:40:41 by tpinto-e         ###   ########.fr       */
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

void	sig_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_printf("Server acknowledgement signal\n");
		exit(0);
	}
	else
	{
		ft_printf("Error: fuckery is afoot.\nTerminating.");
		exit(1);
	}
}

void	sig_checker(void)
{
	struct sigaction	handle_sig;

	handle_sig.sa_handler = &sig_handler;
	handle_sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &handle_sig, NULL);
	sigaction(SIGUSR2, &handle_sig, NULL);
}

int	main(int argc, char **argv)
{
	int					i;

	if (argc != 3 || !ft_check_alnum(argv[1]))
	{
		ft_printf("nope, try again\n");
		return (0);
	}
	sig_checker();
	i = 0;
	while (argv[2][i])
		bit_convert(ft_atoi(argv[1]), argv[2][i++]);
	bit_convert(ft_atoi(argv[1]), argv[2][i]);
	pause();
	return (0);
}
