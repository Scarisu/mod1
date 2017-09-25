/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 16:06:59 by pbernier          #+#    #+#             */
/*   Updated: 2017/09/25 16:48:03 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mod1.h>

void	error_map(t_mod *mod1)
{
	char	*tmp;

	++mod1->nb_err;
	get_all_line(mod1);
	print_line(mod1);
	while ((sp_gnl(mod1, &mod1->map.line)))
	{
		ft_memdel((void **)&mod1->map.line);
	}
	tmp = ft_itoa(mod1->nb_err);
	ft_putstr_fd(tmp, 2);
	ft_memdel((void **)&tmp);
	ft_putstr_fd(" error generated.\n", 2);
	clean_all(mod1, 0);
}

void	get_all_line(t_mod *mod1)
{
	int		ret;
	int 	size;

	mod1->map.buff[0] = 'A';
	size = mod1->map.pos[1];
	while (mod1->map.buff[0] != '\n'
		&& size <= mod1->map.pos[1] + 50)
	{
		if ((ret = read(mod1->fd, mod1->map.buff, 1)) == -1)
			error(mod1, FD);
		if (!ret || mod1->map.buff[0] == 0)
			break ;
		ft_strjoin_clean_char(&mod1->map.line, mod1->map.buff[0]);
		size++;
		if (!valid_char(mod1, mod1->map.buff[0], 1))
			adjust_arrow(mod1, &mod1->map.arrow, size);
	}
	(ft_strlen(mod1->map.invalid) == 1) ?
		ft_putstr_fd(" '", 2) : ft_putstr_fd("s {", 2);
	ft_putstr_fd(mod1->map.invalid, 2);
	(ft_strlen(mod1->map.invalid) == 1) ?
		ft_putstr_fd("'\n"RESET, 2) : ft_putstr_fd("}\n"RESET, 2);
	ft_memdel((void **)&mod1->map.invalid);
	(!(mod1->map.invalid = ft_strnew(0))) ? error(mod1, MALLOC) : 0;
	mod1->map.line[size - 1] = '\0';
}


void	adjust_arrow(t_mod *mod1, char **arrow, int size)
{
	int				space;

	space = size - (mod1->map.pos[1]) - ft_strlen(*arrow);
	while (--space > 0)
		ft_strjoin_clean_char(arrow, ' ');
	ft_strjoin_clean_char(arrow, '~');
	(void)mod1;
	(void)arrow;
	(void)size;
}

void	print_line(t_mod *mod1)
{
	int		ret;

	if (mod1->map.pos[1] > 50)
	{
		mod1->map.pos[1] -= 45;
		ft_putstr_fd("  ...", 2);
		ft_putstr_fd(&mod1->map.line[50], 2);
	}
	else
		ft_putstr_fd(mod1->map.line, 2);
	ft_memdel((void **)&mod1->map.line);
	(mod1->map.buff[0] == '\n') ? 0 : ft_putstr_fd("...", 2);
	ft_putstr_fd("\n", 2);
	while (--mod1->map.pos[1])
		ft_putstr_fd(" ", 2);
	++mod1->map.pos[0];
	ft_putstr_fd(GREEN_MINUS, 2);
	ft_putstr_fd(mod1->map.arrow, 2);
	ft_putstr_fd("\n"RESET, 2);
	ft_memdel((void **)&mod1->map.arrow);
	if (!(mod1->map.arrow = ft_strdup("^")))
		error(mod1, MALLOC);
	while (mod1->map.buff[0] != '\n')
	{
		if ((ret = read(mod1->fd, mod1->map.buff, 1)) == -1)
	 		error(mod1, FD);
		if (!ret || mod1->map.buff[0] == 0)
	 		return ;
	}
	return ;
}
