/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:24:53 by gpochon           #+#    #+#             */
/*   Updated: 2024/12/30 10:51:33 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

static char	*join_path(const char *dir, const char *cmd)
{
	char	*full_path;
	int		len_dir;
	int		len_cmd;

	len_dir = ft_strlen(dir);
	len_cmd = ft_strlen(cmd);
	full_path = malloc(len_dir + len_cmd + 2);
	if (!full_path)
		return (NULL);
	ft_strlcpy(full_path, dir, len_dir + 1);
	full_path[len_dir] = '/';
	ft_strlcpy(full_path + len_dir + 1, cmd, len_cmd + 1);
	return (full_path);
}

static char	*find_cmd_in_path(char *path, char *cmd)
{
	char	*full_path;

	full_path = join_path(path, cmd);
	if (!full_path)
		return (NULL);
	if (access(full_path, F_OK | X_OK) == 0)
		return (full_path);
	free(full_path);
	return (NULL);
}
char	*ft_path(char *cmd, char **envp)
{
	char	**paths;
	char	*full_path;
	int		i;

	i = 0;
	if (access(cmd, F_OK | X_OK) == 0)
		return (ft_strdup(cmd));
	while (*envp && ft_strncmp("PATH=", *envp, 5) != 0)
		envp++;
	paths = ft_split(*envp + 5, ':');
	while (paths[i])
	{
		full_path = find_cmd_in_path(paths[i], cmd);
		if (full_path)
		{
			free_cmd(paths);
			return (full_path);
		}
		i++;
	}
	free_cmd(paths);
	return (NULL);
}
