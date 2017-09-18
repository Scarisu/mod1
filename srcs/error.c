/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 16:59:23 by pbernier          #+#    #+#             */
/*   Updated: 2017/09/18 18:38:26 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mod1.h>

int		check_name(char *map_name)
{
	(void)map_name;
	return (1);
}

void	usage(int ac, char *av)
{
	if (ac == 2)
		return ;
	(ac == 2 && !check_name(av)) ? ft_putstr_fd("Bad Format\n", 2) : 0;
	(ac < 2) ? ft_putstr_fd("Missing map\n", 2) : 0;
	(ac > 2) ? ft_putstr_fd("Too many arguments\n", 2) : 0;
	ft_putstr_fd("usage: ./mod1 {map_name}.mod1\n", 2);
	exit(-1);
}
