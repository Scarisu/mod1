/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 16:50:05 by pbernier          #+#    #+#             */
/*   Updated: 2017/09/23 18:52:03 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mod1.h>

int		valid_char(t_mod *mod1, char c, int sw)
{
	int		i;
	char	valid_char[25];

	i = 0;
	if (!sw && c == '\n')
		ft_memcpy(mod1->map.pos,
			((int[2]){++mod1->map.pos[0], 0}), sizeof(int[2]));
	else if (!sw)
		++mod1->map.pos[1];
	ft_memcpy(valid_char,
		((char[25]){"0123456789,() -\t\n\r\v\f\0"}), sizeof(char[25]));
	while (valid_char[i] && valid_char[i] != c)
		++i;
	if (!valid_char[i])
	{
		list_invalid(mod1, c);
		return (0);
	}
	return (1);
}

void	list_invalid(t_mod *mod1, char c)
{
	int		i;

	i = -1;
	while (mod1->map.invalid[++i])
		if (mod1->map.invalid[i] == c)
			return ;
	if (mod1->map.invalid[0])
		ft_strjoin_clean_char(&mod1->map.invalid, ',');
	ft_strjoin_clean_char(&mod1->map.invalid, c);
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
		if (!valid_char(mod1, mod1->map.buff[0], 0))
			error(mod1, INVALID_CHAR);
		++size;
	}
	return (size);
}

void	get_points(t_mod *mod1)
{
	while ((sp_gnl(mod1, &mod1->map.line)))
	{

		ft_memdel((void **)&mod1->map.line);
	}
	ft_memdel((void **)&mod1->map.line);
}
