/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:42:36 by tpinto-e          #+#    #+#             */
/*   Updated: 2023/03/30 16:38:33 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minitalk.h"

void	sig_handler(int sig, siginfo_t *broker, void *nothing)
{
	static unsigned char	c;
	static int				bit_counter = 8;

	(void)nothing;
	if (sig == SIGUSR1)
		c = 1 | c << 1;
	else if (sig == SIGUSR2)
		c = 0 | c << 1;
	else
	{
		ft_printf("\nError: fuckery is afoot.\nTerminating.");
		exit(1);
	}
	bit_counter--;
	if (bit_counter == 0)
	{
		if (c == '\0')
			kill(broker->si_pid, SIGUSR1);
		else
			write(1, &c, 1);
		bit_counter = 8;
	}
}

void	sig_checker(void)
{
	struct sigaction	handle_sig;

	handle_sig.sa_flags = SA_SIGINFO;
	handle_sig.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &handle_sig, NULL);
	sigaction(SIGUSR2, &handle_sig, NULL);
}

int	main(void)
{
	ft_printf("Ready to rock 🤘\nPID:\t%d\n", (int) getpid());
	sig_checker();
	while (1)
		pause();
	return (0);
}
