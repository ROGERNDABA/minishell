/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 01:44:30 by rmdaba            #+#    #+#             */
/*   Updated: 2018/07/20 01:44:52 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

static void	time_to_fork(char **path, char *cmd[], char **envp)
{
	pid_t	pid;
	int		loop;

	pid = fork();
	if (pid == 0)
	{
		loop = -1;
		if (path != NULL)
			while (path[++loop])
				execve(path[loop], cmd, envp);
		execve(cmd[0], cmd, envp);
		write(2, "Command Failed\n", 15);
		exit(0);
	}
	else
	{
		wait(NULL);
		if (path != NULL)
		{
			loop = -1;
			while (path[++loop])
				free(path[loop]);
			free(path);
		}
	}
}

void		simple_cmd(char *cmd[], char **envp)
{
	int		loop;
	int		var;
	char	*mem;
	char	**path;

	loop = 0;
	if (((var = ft_find(envp, "PATH")) == -1) ||
	(ft_strchr(cmd[0], '/') != NULL))
	{
		time_to_fork(NULL, cmd, envp);
		return ;
	}
	if ((path = ft_strsplit(&envp[var][4 + 1], ':')) == NULL)
		exit(0);
	loop = -1;
	while (path[++loop])
	{
		mem = path[loop];
		if (!(path[loop] = ft_strcjoin(path[loop], cmd[0], '/')))
			exit(0);
		free(mem);
	}
	time_to_fork(path, cmd, envp);
}
