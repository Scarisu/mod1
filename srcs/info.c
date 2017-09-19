/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 16:50:05 by pbernier          #+#    #+#             */
/*   Updated: 2017/09/19 20:13:51 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mod1.h>

void	valid_char(t_mod *mod1, char c)
{
	int		i;
	char	valid_char[18];

	i = 0;
	if (c == '\n')
		ft_memcpy(mod1->map.pos,
			((int[2]){++mod1->map.pos[0], 0}), sizeof(int[2]));
	else
		++mod1->map.pos[1];
	ft_memcpy(valid_char, ((char[18]){"0123456789,() \n\0"}), sizeof(char[18]));
	while (valid_char[i] && valid_char[i] != c)
		++i;
	(!valid_char[i]) ? error(mod1, INVALID_CHAR) : 0;
}

int		sp_gnl(t_mod *mod1, char **line)
{
	int		ret;
	int		size;

	size = 0;
	mod1->map.buff[0] = 'A';
	if (!(*line = malloc(sizeof(char) * (size + 1))))
		error(mod1, MALLOC);
	(*line)[size] = '\0';
	while (mod1->map.buff[0] != '\n')
	{
		if ((ret = read(mod1->fd, mod1->map.buff, 1)) == -1)
			error(mod1, FD);
		if (!ret || mod1->map.buff[0] == 0)
			return (ret);
		ft_strjoin_clean_char(line, mod1->map.buff[0]);
		valid_char(mod1, mod1->map.buff[0]);
		++size;
	}
	//(*line)[size - 1] = '\0';
	return (size);
}

void	get_points(t_mod *mod1)
{
	while ((sp_gnl(mod1, &mod1->map.line)))
	{
		// if (NO_ERROR)
		// 	ft_strjoin_clean(&mod1->map.map, &mod1->map.line);
		ft_memdel((void **)&mod1->map.line);
	}
	ft_memdel((void **)&mod1->map.line);
}
