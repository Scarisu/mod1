/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 16:59:23 by pbernier          #+#    #+#             */
/*   Updated: 2017/09/23 15:27:47 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mod1.h>

void	print_line(t_mod *mod1)
{
	int		ret = 0;

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
	ft_putstr_fd(GREEN_MINUS"^\n"RESET, 2);
	while (mod1->map.buff[0] != '\n')
	{
		if ((ret = read(mod1->fd, mod1->map.buff, 1)) == -1)
	 		error(mod1, FD);
		if (!ret || mod1->map.buff[0] == 0)
	 		return ;
	}
	return ;
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
	}
	mod1->map.line[size - 1] = '\0';
}

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
		ft_putstr_fd(": "RED_MINUS"error:"RESET GRAS" invalid character '", 2);
		ft_putstr_fd(mod1->map.buff, 2);
		ft_putstr_fd("'\n"RESET, 2);
		error_map(mod1);
	}
	clean_all(mod1, 0);
}
