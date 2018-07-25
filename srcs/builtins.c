/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 01:44:25 by rmdaba            #+#    #+#             */
/*   Updated: 2018/07/25 10:56:27 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

static void	ft_echo(char *cmd[])
{
	int	k;
	int	no_new_line;

	k = -1;
	no_new_line = 0;
	if (cmd[0] != NULL)
	{
		if ((ft_strcmp(cmd[++k], "-n") == 0))
			no_new_line = 1;
		else
			k--;
		while (cmd[++k] != NULL)
		{
			write(1, cmd[k], ft_strlen(cmd[k]));
			write(1, " ", 1);
		}
	}
	if (no_new_line != 1)
		write(1, "\n", 1);
}

static void	ft_exit(char *cmd[], char **envp)
{
	if (cmd[0] == NULL)
	{
		manage_shell(envp, -1);
		exit(0);
	}
	else if (cmd[1] == NULL)
	{
		manage_shell(envp, -1);
		exit(ft_atoi(cmd[0]));
	}
	else
		write(2, "MyShell: exit: too many arguments\n", 34);
}

char		**check_builtins(char *cmd[], char **envp)
{
	if (!cmd[0])
		return (envp);
	else if (!(ft_strcmp(cmd[0], "exit")))
		ft_exit(cmd + 1, envp);
	else if (!(ft_strcmp(cmd[0], "cd")))
		ft_cd(cmd + 1, envp);
	else if (!(ft_strcmp(cmd[0], "setenv")) && cmd[1] && cmd[2])
		envp = ft_setenv(cmd[1], cmd[2], envp);
	else if (!(ft_strcmp(cmd[0], "unsetenv")))
		ft_unsetenv(envp, cmd + 1);
	else if ((!(ft_strcmp(cmd[0], "env")) && !(cmd[1])) ||
			!(ft_strcmp(cmd[0], "printenv")))
		ft_printenv(cmd[1], envp);
	else if (!(ft_strcmp(cmd[0], "echo")))
		ft_echo(cmd + 1);
	else
		simple_cmd(cmd, envp);
	return (envp);
}
