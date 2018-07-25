/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 01:44:23 by rmdaba            #+#    #+#             */
/*   Updated: 2018/07/25 10:57:30 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

void	siginthandler2(int sig_num)
{
	if (sig_num == 2)
	{
		write(1, "\n", 1);
		signal(SIGINT, siginthandler2);
	}
}

void	siginthandler(int sig_num)
{
	if (sig_num == 2)
	{
		write(1, "\n", 1);
		signal(SIGINT, siginthandler);
		write(1, "$> ", 3);
	}
}

void	manage_shell(char **envp, int nbr)
{
	int		loop;
	char	*new_shlvl;

	loop = ft_find(envp, "SHELLRL");
	if (loop >= 0)
	{
		new_shlvl = ft_itoa(ft_atoi(ft_strchr(envp[loop], '=') + 1) + nbr);
		if (new_shlvl == NULL)
			exit(0);
		ft_setenv("SHELLRL", new_shlvl, envp);
		free(new_shlvl);
	}
}
