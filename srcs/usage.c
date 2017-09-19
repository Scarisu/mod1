/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 18:39:41 by pbernier          #+#    #+#             */
/*   Updated: 2017/09/19 20:12:39 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mod1.h>

void	open_map(t_mod *mod1)
{
	mod1->fd = open(mod1->map.map_name, O_RDONLY);
	(mod1->fd <= 2) ? error(mod1, CANT_OPEN) : 0;
}

int		check_name(t_mod *mod1, char *map_name)
{
	int		len[2];
	char	format[6];

	ft_memcpy(len, ((int[2]){ft_strlen(map_name) - 5, 0}), sizeof(int[2]));
	ft_memcpy(format, ((char[6]){".mod1\0"}), sizeof(char[6]));
	if (len[0] < 0)
		return (0);
	while (map_name[len[0]] && format[len[1]] &&
		map_name[len[0]] == format[len[1]])
		ft_memcpy(len, ((int[2]){++len[0], ++len[1]}), sizeof(int[2]));
	if (map_name[len[0]])
		return (0);
	mod1->map.map_name = map_name;
	return (1);
}

void	usage(t_mod *mod1, int ac, char *av)
{
	if (ac == 2 && check_name(mod1, av))
		return ;
	ft_putstr_fd(RED_MINUS, 2);
	(ac == 2) ? ft_putstr_fd("Bad Format\n", 2) : 0;
	(ac < 2) ? ft_putstr_fd("Missing map\n", 2) : 0;
	(ac > 2) ? ft_putstr_fd("Too many arguments\n", 2) : 0;
	ft_putstr_fd(RESET"usage: ./mod1 {map_name}.mod1\n", 2);
	clean_all(mod1);
}
