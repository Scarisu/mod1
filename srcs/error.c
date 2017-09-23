/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 16:59:23 by pbernier          #+#    #+#             */
/*   Updated: 2017/09/23 18:38:43 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mod1.h>

void	error(t_mod *mod1, int e)
{
	char *tmp;

	tmp = NULL;
	if (e == CANT_OPEN)
	{
		ft_putstr_fd(RED_MINUS"Permission denied\n"RESET, 2);
		ft_putstr_fd("Can't open '"GREY, 2);
		ft_putstr_fd(mod1->map.map_name, 2);
		ft_putstr_fd(RESET"\n", 2);

	}
	(e == MALLOC) ? ft_putstr_fd("Malloc error\n", 2) : 0;
	if (e == FD)
	{
		ft_putstr_fd(RED_MINUS"Can't read file"RESET" '"GREY, 2);
		ft_putstr_fd(mod1->map.map_name, 2);
		ft_putstr_fd(RESET"'\nfd: '"GREY, 2);
		tmp = ft_itoa(mod1->fd);
		ft_putstr_fd(tmp, 2);
		ft_memdel((void **)&tmp);
		ft_putstr_fd(RESET"'\n", 2);
	}
	if (e == INVALID_CHAR)
	{
		ft_putstr_fd(GRAS, 2);
		ft_putstr_fd(mod1->map.map_name, 2);
		ft_putstr_fd(":", 2);
		tmp = ft_itoa(mod1->map.pos[0]);
		ft_putstr_fd(tmp, 2);
		ft_memdel((void **)&tmp);
		ft_putstr_fd(":", 2);
		tmp = ft_itoa(mod1->map.pos[1]);
		ft_putstr_fd(tmp, 2);
		ft_memdel((void **)&tmp);
		ft_putstr_fd(": "RED_MINUS"error:"RESET GRAS" invalid character", 2);
		error_map(mod1);
	}
	clean_all(mod1, 0);
}
