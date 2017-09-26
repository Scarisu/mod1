/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 17:44:41 by pbernier          #+#    #+#             */
/*   Updated: 2017/09/26 19:26:05 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mod1.h>

void	check_file(t_mod *mod1)
{
	int		next;

	next = 1;
	while (mod1->nb_err <= MAX_ERROR && get_line(mod1, &mod1->map.line))
	{
		ft_memcpy(mod1->map.pos,
			((size_t[2]){NB_LINE + 1, 0}), sizeof(size_t[2]));
		next = check_char(mod1, mod1->map.line);
		next = (next) ? check_value(mod1, mod1->map.line) : 1;

		ft_memdel((void **)&mod1->map.line);
	}
	(mod1->nb_err > 0) ? error(mod1, VERBOS) : 0;
}
