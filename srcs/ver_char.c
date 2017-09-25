/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ver_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 16:06:59 by pbernier          #+#    #+#             */
/*   Updated: 2017/09/25 22:45:09 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mod1.h>

void	ver_char(t_mod *mod1)
{
	if (++mod1->nb_err > MAX_ERROR)
		return ;
	ver_pos(mod1);
	ft_putstr_fd(GRAS" invalid character", 2);
	print_invalid(mod1, &mod1->map.invalid);
	print_line(mod1, &mod1->map.line);
	print_arrow(mod1, &mod1->map.arrow);
}

void	print_invalid(t_mod *mod1, char **invalid)
{
	(ft_strlen(*invalid) == 1) ?
		ft_putstr_fd(" '", 2) : ft_putstr_fd("s {", 2);
	ft_putstr_fd(*invalid, 2);
	(ft_strlen(*invalid) == 1) ?
		ft_putstr_fd("'\n"RESET, 2) : ft_putstr_fd("}\n"RESET, 2);
	ft_memdel((void **)invalid);
	if (!(*invalid = ft_strnew(0)))
		error(mod1, MALLOC);
}

void	print_line(t_mod *mod1, char **line)
{
	size_t	start;

	start = (NB_COLUMN > 50) ? NB_COLUMN - 50 : 0;
	(NB_COLUMN > 50) ? ft_putstr_fd("  ...", 2) : 0;
	while ((*line)[start] && start <= NB_COLUMN + 50)
	{
		adjust_arrow(&mod1->map.arrow, (*line)[start], start - NB_COLUMN + 1);
		ft_putchar_fd((*line)[start++], 2);
	}
	if (start > NB_COLUMN + 50 && (*line)[start + 1])
		ft_putstr_fd("...", 2);
	ft_putchar_fd('\n', 2);
	ft_memdel((void **)line);
}

void	adjust_arrow(char **arrow, char c, int size)
{
	int	space;

	if (size <= 0 || valid_char(c))
		return ;
	space = size - ft_strlen(*arrow) + 1;
	while (--space > 0)
		ft_strjoin_clean_char(arrow, ' ');
	ft_strjoin_clean_char(arrow, '~');
}

void	print_arrow(t_mod *mod1, char **arrow)
{
	size_t space;

	space = (NB_COLUMN > 50) ? 54 : NB_COLUMN - 1;
	while (space--)
		ft_putchar_fd(' ', 2);
	ft_putstr_fd(GREEN_MINUS, 2);
	ft_putstr_fd(*arrow, 2);
	ft_putstr_fd("\n"RESET, 2);
	ft_memdel((void **)arrow);
	if (!(*arrow = ft_strdup("^")))
		error(mod1, MALLOC);
}
