/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 18:39:01 by pbernier          #+#    #+#             */
/*   Updated: 2017/09/25 22:45:20 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mod1.h>

int		check_char(t_mod *mod1, char *line)
{
	size_t	len;
	size_t	limit;

	len = 0;
	limit = ft_strlen(line);
	while (line[len] && len < limit)
	{
		if (!valid_char(line[len]))
		{
			limit = (!mod1->map.invalid[0]) ? len + 50 : limit;
			list_char(&mod1->map.invalid, line[len]);
			NB_COLUMN = (!NB_COLUMN) ? len + 1 : NB_COLUMN;
		}
		++len;
	}
	if (!NB_COLUMN)
		return (1);
	ver_char(mod1);
	return (0);
}

int		valid_char(char c)
{
	char	valid[20];

	ft_memcpy(valid,
		((char[20]){"0123456789,()-+ \n\0"}), sizeof(char[20]));
	if (!ft_strchr(valid, c))
		return (0);
	return (1);
}

void	list_char(char **invalid, char c)
{
	size_t		i;

	i = 0;
	while ((*invalid)[i])
		if ((*invalid)[i++] == c)
			return ;
	if ((*invalid)[0])
		ft_strjoin_clean_char(invalid, ',');
	ft_strjoin_clean_char(invalid, c);
}
