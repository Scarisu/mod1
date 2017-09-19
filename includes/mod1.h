/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 16:45:46 by pbernier          #+#    #+#             */
/*   Updated: 2017/09/19 13:29:04 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOD1_H
# define MOD1_H

# include <libft.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

# define CANT_OPEN 1

typedef struct s_mod	t_mod;

struct			s_mod
{
	int			fd;
	char		*map_name;
};

void			usage(t_mod *mod1, int ac, char *av);
int				check_name(t_mod *mod1, char *map_name);
void			open_map(t_mod *mod1);
void			error(t_mod *mod1, int e);

#endif
