/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 16:59:23 by pbernier          #+#    #+#             */
/*   Updated: 2017/09/25 22:56:02 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mod1.h>

void	error(t_mod *mod1, int e)
{
	if (e == CANT_OPEN)
	{
		ft_putstr_fd(RED_MINUS"Permission denied\n"RESET, 2);
		ft_putstr_fd("Can't open '"GREY, 2);
		ft_putstr_fd(mod1->map.map_name, 2);
		ft_putstr_fd(RESET"\n", 2);
	}
	(e == MALLOC) ? ft_putstr_fd(RED_MINUS"Malloc error\n"RESET, 2) : 0;
	if (e == FD)
	{
		ft_putstr_fd(RED_MINUS"Can't read file"RESET" '"GREY, 2);
		ft_putstr_fd(mod1->map.map_name, 2);
		ft_putstr_fd(RESET"'\nfd: '"GREY, 2);
		TMP = ft_itoa(mod1->fd);
		ft_putstr_fd(TMP, 2);
		ft_memdel((void **)&TMP);
		ft_putstr_fd(RESET"'\n", 2);
	}
	if (e == VERBOS)
	{
		if (mod1->nb_err > MAX_ERROR)
		{
			--mod1->nb_err;
			ft_putstr_fd("More than ", 2);
		}
		TMP = ft_itoa(mod1->nb_err);
		ft_putstr_fd(TMP, 2);
		ft_memdel((void **)&TMP);
		ft_putstr_fd(" error", 2);
		(mod1->nb_err != 1) ? ft_putstr_fd("s", 2) : 0;
		ft_putstr_fd(" generated.\n", 2);
	}
	clean_all(mod1, 0);
}

void	ver_pos(t_mod *mod1)
{
	ft_putstr_fd(GRAS, 2);
	ft_putstr_fd(mod1->map.map_name, 2);
	ft_putstr_fd(":", 2);
	TMP = ft_itoa(NB_LINE);
	ft_putstr_fd(TMP, 2);
	ft_memdel((void **)&TMP);
	ft_putstr_fd(":", 2);
	TMP = ft_itoa(NB_COLUMN);
	ft_putstr_fd(TMP, 2);
	ft_memdel((void **)&TMP);
	ft_putstr_fd(": "RED_MINUS"error:"RESET, 2);
}
