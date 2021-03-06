/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 16:45:19 by pbernier          #+#    #+#             */
/*   Updated: 2017/09/25 17:51:30 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mod1.h>

int		main(int ac, char **av)
{
	t_mod	mod1;

	set_all(&mod1);
	usage(&mod1, ac, av[1]);
	open_map(&mod1);
	check_file(&mod1);
	clean_all(&mod1, 1);
	return (0);
}
