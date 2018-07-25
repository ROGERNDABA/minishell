/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 01:44:32 by rmdaba            #+#    #+#             */
/*   Updated: 2018/07/25 10:55:43 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

void		ft_unsetenv(char **envp, char *cmd[])
{
	int		loop;
	int		envp_read;
	int		del;

	loop = -1;
	while (cmd[++loop])
	{
		envp_read = -1;
		while (envp[++envp_read])
		{
			if (ft_strncmp(envp[envp_read], cmd[loop],
						ft_strlen(cmd[loop])) == 0)
			{
				del = envp_read;
				free(envp[del]);
				while (envp[del + 1] != NULL)
				{
					envp[del] = envp[del + 1];
					del++;
				}
				envp[del] = NULL;
			}
		}
	}
}

static char	**envp_realloc(char **envp, int new_size)
{
	char	**new;
	int		i;

	new = (char **)malloc(sizeof(char *) * (new_size + 2));
	new[new_size + 1] = NULL;
	i = -1;
	while (envp[++i])
	{
		new[i] = ft_strdup(envp[i]);
		free(envp[i]);
	}
	free(envp);
	return (new);
}

char		**ft_setenv(char *cmd1, char *cmd2, char **envp)
{
	int		loop;
	int		var;
	char	**new_envp;

	if (cmd1 == NULL || cmd2 == NULL)
		return (envp);
	var = ft_find(envp, cmd1);
	if (var != -1)
	{
		free(envp[var]);
		envp[var] = ft_strcjoin(cmd1, cmd2, '=');
	}
	else
	{
		loop = 0;
		while (envp[loop] != NULL)
			loop++;
		new_envp = envp_realloc(envp, loop);
		new_envp[loop] = ft_strcjoin(cmd1, cmd2, '=');
		return (new_envp);
	}
	return (envp);
}

void		ft_printenv(char *cmd, char **envp)
{
	int		var;
	int		k;

	k = -1;
	if (cmd == NULL)
		while (envp[++k] != NULL)
		{
			write(1, envp[k], ft_strlen(envp[k]));
			write(1, "\n", 1);
		}
	else
	{
		var = ft_find(envp, cmd);
		if (var != -1)
			ft_putendl(&envp[var][ft_strlen(cmd) + 1]);
	}
}
