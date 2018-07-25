/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 01:44:34 by rmdaba            #+#    #+#             */
/*   Updated: 2018/07/25 10:55:52 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

void	welcome(void)
{
	ft_printf("\e[34m			_   _      _____       ___\n\e[0m");
	ft_printf("\e[33m			| | | |    |_   _|     / _/\n");
	ft_printf("\e[32m			| 'V' | __   | |   __ | \\__\n\e[0m");
	ft_printf("\e[31m			!_/ \\_! \\/   |_|   \\/  \\__/\n\e[0m");
	ft_printf("\e[31m		__ __ _ __  _ _   __  _  _ ___ _   _\n\e[0m");
	ft_printf("\e[32m		|  V  | |  \\| | |/' _/| || | __| | | |\n\e[0m");
	ft_printf("\e[33m		| \\_/ | | | ' | |`._`.| >< | _|| |_| |_\n\e[0m");
	ft_printf("\e[34m		|_| |_|_|_|\\__|_||___/|_||_|___|___|___|\n\e[0m");
	ft_printf("\n			   \e[33mBy : ROGER NDABA\n\n\e[0m");
}

int		ft_find(char **envp, char *to_find)
{
	int	loop;

	loop = 0;
	while (envp[loop] &&
			((ft_strncmp(envp[loop], to_find, ft_strlen(to_find)) != 0)
			|| &envp[loop][ft_strlen(to_find)] > &envp[loop][0] +
			ft_strlen(envp[loop])
			|| envp[loop][ft_strlen(to_find)] != '='))
		loop++;
	if (envp[loop] == NULL)
		return (-1);
	else
		return (loop);
}

char	**new_envp(char **envp)
{
	char	**new_envp;
	int		i;

	i = 0;
	while (envp[i] != NULL)
		i++;
	new_envp = (char **)malloc(sizeof(char *) * (i + 1));
	new_envp[i] = NULL;
	i = -1;
	while (envp[++i])
		new_envp[i] = ft_strdup(envp[i]);
	return (new_envp);
}
