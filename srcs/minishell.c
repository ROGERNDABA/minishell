/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 01:44:36 by rmdaba            #+#    #+#             */
/*   Updated: 2018/07/25 10:56:08 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"
#include <stdio.h>

void		subs_var_env(char *cmd[], char **envp)
{
	int		loop;
	int		del;
	int		var;

	loop = -1;
	while (cmd[++loop])
	{
		if (cmd[loop][0] == '$')
		{
			if ((var = ft_find(envp, &cmd[loop][1])) != -1)
				cmd[loop] = &envp[var][ft_strlen(cmd[loop])];
			else
			{
				del = loop;
				while (cmd[del + 1] != NULL)
				{
					cmd[del] = cmd[del + 1];
					del++;
				}
				cmd[del] = NULL;
			}
		}
	}
}

void		parse_line(char *line, char *cmd[])
{
	int	loop;

	loop = -1;
	while (*line && *line != '\n' && *line != '#')
	{
		while (*line == ' ' || *line == '\t' || *line == '\'' || *line == '"')
			*(line++) = '\0';
		if (*line && *line != '\n' && *line != '#')
			cmd[++loop] = line;
		while (*line && *line != '\n' && *line != ' ' && *line != '\t' &&
				*line != '\'' && *line != '"')
			line++;
	}
	cmd[++loop] = NULL;
	*line = '\0';
}

char		*malloc_line(char *line, int loop)
{
	char	*new_line;

	if (!(new_line = malloc(sizeof(char) * (loop + 1 + 255 + 1))))
		exit(0);
	if (line != NULL)
		ft_strcpy(new_line, line);
	new_line[loop + 256] = '\0';
	free(line);
	return (new_line);
}

char		*ft_get_line(int fd)
{
	char	*line;
	int		loop;

	loop = 0;
	line = malloc_line(NULL, 0);
	while (loop == 0 || (line[loop - 1] != '\n' && line[loop - 1] != -1))
	{
		if (read(fd, &line[loop++], 1) == 0)
		{
			write(1, "\n", 1);
			free(line);
			return (NULL);
		}
		if (loop % 255 == 0)
			line = malloc_line(line, loop);
	}
	line[loop] = '\0';
	return (line);
}

int			main(int argc, char **argv)
{
	char		*line;
	char		*cmd[256];
	char		**new_enp;
	extern char **environ;

	new_enp = new_envp(environ);
	manage_shell(new_enp, 1);
	welcome();
	if (argc == 1 && argv[1] == NULL)
		while (1)
		{
			signal(SIGINT, siginthandler);
			write(1, "$> ", 3);
			if ((line = ft_get_line(1)) != NULL)
			{
				signal(SIGINT, siginthandler2);
				parse_line(line, cmd);
				subs_var_env(cmd, new_enp);
				new_enp = check_builtins(cmd, new_enp);
				free(line);
			}
		}
	return (0);
}
