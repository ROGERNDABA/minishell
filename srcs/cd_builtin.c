/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 01:44:27 by rmdaba            #+#    #+#             */
/*   Updated: 2018/07/25 10:55:28 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

static void	pwd2(char *cd)
{
	int	loop;

	loop = -1;
	while (cd[++loop])
		while ((ft_strncmp(&cd[loop], "/.", 2)) == 0)
			ft_strcpy(&cd[loop], &cd[loop + 2]);
	loop--;
	while (cd[loop] == '/' && loop != 0)
		cd[loop--] = '\0';
}

static void	do_pwd(char *cd)
{
	int loop;
	int mem;

	loop = -1;
	while (cd[++loop])
		while ((ft_strncmp(&cd[loop], "//", 2)) == 0)
			ft_strcpy(&cd[loop], &cd[loop + 1]);
	loop = -1;
	while (cd[++loop])
		while (cd[loop] && (ft_strncmp(&cd[loop], "/..", 3)) == 0)
		{
			if (loop == 0)
				ft_strcpy(&cd[loop], "/");
			else
			{
				mem = loop + 3;
				while (--loop > 0 && cd[loop] != '/')
					cd[loop] = '\0';
				if (loop != 0)
					ft_strcpy(&cd[loop], &cd[mem]);
			}
		}
	pwd2(cd);
}

static void	cd2(char *cd, char *cmd[], char **envp)
{
	int	var;
	DIR	*dir;

	if ((dir = opendir(cd)))
	{
		chdir(cd);
		do_pwd(cd);
		if ((var = ft_find(envp, "PWD")) != -1)
			ft_setenv("OLDPWD", &envp[var][4], envp);
		else
			ft_setenv("OLDPWD", cd, envp);
		ft_setenv("PWD", cd, envp);
		free(cd);
		closedir(dir);
	}
	else
	{
		write(2, "cd: No such file or directory: ", 31);
		ft_putendl_fd(cmd[0], 2);
		free(cd);
	}
}

void		ft_cd(char *cmd[], char **envp)
{
	char	*cd;
	int		var;

	if (cmd[0] == NULL && ((var = ft_find(envp, "HOME")) == -1))
		return ;
	else if (cmd[0] == NULL && ((var = ft_find(envp, "HOME")) > -1))
		cd = ft_strdup(&envp[var][5]);
	else if (cmd[0] && cmd[0][0] == '/')
		cd = ft_strdup(cmd[0]);
	else if (cmd[0] && cmd[0][0] == '~')
	{
		var = ft_find(envp, "HOME");
		cd = ft_strcjoin(&envp[var][4 + 1], &cmd[0][1], '/');
	}
	else if (cmd[0] && ft_strcmp(cmd[0], "-") == 0)
	{
		var = ft_find(envp, "OLDPWD");
		cd = ft_strdup(&envp[var][6 + 1]);
	}
	else
	{
		var = ft_find(envp, "PWD");
		cd = ft_strcjoin(&envp[var][3 + 1], cmd[0], '/');
	}
	cd2(cd, cmd, envp);
}
