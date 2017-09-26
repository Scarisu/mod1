/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 15:43:52 by pbernier          #+#    #+#             */
/*   Updated: 2017/09/26 21:40:20 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mod1.h>

void	set_all(t_mod *mod1)
{
	mod1->fd = -1;
	mod1->nb_err = 0;
	mod1->map.line = NULL;
	mod1->map.pos[0] = 0;
	mod1->map.pos[1] = 0;
	mod1->map.buff[0] = 'A';
	mod1->map.buff[1] = '\0';
	if (!(mod1->map.arrow = ft_strdup("^")))
		error(mod1, MALLOC);
	if (!(mod1->map.invalid = ft_strnew(0)))
		error(mod1, MALLOC);
	mod1->map.tmp = NULL;
	if (!(mod1->map.value = (char **)malloc(sizeof(char *) * 1)))
		error(mod1, MALLOC);
	mod1->map.value[0] = NULL;
	mod1->nb_points = 0;
	mod1->coor = NULL;
}

void	clean_all(t_mod *mod1, int end)
{
	int	i;

	i = -1;
	ft_memdel((void **)&mod1->map.line);
	ft_memdel((void **)&mod1->map.arrow);
	ft_memdel((void **)&mod1->map.invalid);
	ft_memdel((void **)&mod1->map.tmp);
	while (mod1->map.value[++i])
		ft_memdel((void **)&mod1->map.value[i]);
	ft_memdel((void **)&mod1->map.value);
	(mod1->fd > 2) ? close(mod1->fd) : 0;
	read(1, NULL, 1);
	if (end)
		return ;
	exit(-1);
}
