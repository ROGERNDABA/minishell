/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 19:41:08 by rmdaba            #+#    #+#             */
/*   Updated: 2018/07/19 19:41:10 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <fcntl.h>
# include <dirent.h>
# include "libft.h"

char	*ft_get_line(int fd);
void	parse_line(char *line, char *cmd[]);
char	**check_builtins(char *cmd[], char **envp);
void	simple_cmd(char *cmd[], char **envp);
void	siginthandler2(int sig_num);
void	siginthandler(int sig_num);
void	manage_shell(char **envp, int nbr);
int		ft_find(char **envp, char *to_find);
void	ft_cd(char *cmd[], char **envp);
void	ft_printenv(char *cmd, char **envp);
char	**ft_setenv(char *cmd1, char *cmd2, char **envp);
void	ft_unsetenv(char **envp, char *cmd[]);
char	**new_envp(char **envp);
void	subs_var_env(char *cmd[], char **envp);
void	welcome(void);

#endif
