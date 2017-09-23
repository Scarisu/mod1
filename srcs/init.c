/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 15:43:52 by pbernier          #+#    #+#             */
/*   Updated: 2017/09/23 18:28:24 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mod1.h>

void	set_all(t_mod *mod1)
{
	mod1->fd = -1;
	mod1->nb_err = 0;
	mod1->map.map_name = NULL;
	mod1->map.line = NULL;
	if (!(mod1->map.map = ft_strnew(0)))
		error(mod1, MALLOC);
	mod1->map.pos[0] = 1;
	mod1->map.pos[1] = 0;
	mod1->map.buff[0] = 'A';
	mod1->map.buff[1] = '\0';
	if (!(mod1->map.arrow = ft_strdup("^")))
		error(mod1, MALLOC);
	if (!(mod1->map.invalid = ft_strnew(0)))
		error(mod1, MALLOC);
	mod1->nb_points = 0;
	mod1->coor = NULL;
}

void	clean_all(t_mod *mod1, int end)
{
	ft_memdel((void **)&mod1->map.line);
	ft_memdel((void **)&mod1->map.map);
	ft_memdel((void **)&mod1->map.arrow);
	ft_memdel((void **)&mod1->map.invalid);
	(mod1->fd > 2) ? close(mod1->fd) : 0;
	read(1, NULL, 1);
	if (end)
		return ;
	exit(-1);
}
