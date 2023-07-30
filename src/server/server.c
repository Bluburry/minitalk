/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:52:21 by tpinto-e          #+#    #+#             */
/*   Updated: 2023/03/22 19:53:42 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minitalk.h"

void	sig_handler(int sig)
{
	static unsigned char	c;
	static int				bit_counter = 8;

	if (sig == SIGUSR1)
		c = 1 | c << 1;
	else if (sig == SIGUSR2)
		c = 0 | c << 1;
	else
	{
		ft_printf("Error: fuckery is afoot.\nTerminating.");
		exit(1);
	}
	bit_counter--;
	if (bit_counter == 0)
	{
		write(1, &c, 1);
		bit_counter = 8;
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

int	main(void)
{
	ft_printf("Server started\nPID:\t%d\n", (int) getpid());
	sig_checker();
	while (1)
		pause();
	return (0);
}
