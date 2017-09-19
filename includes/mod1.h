/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 16:45:46 by pbernier          #+#    #+#             */
/*   Updated: 2017/09/19 20:10:03 by pbernier         ###   ########.fr       */
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

# define RESET "\033[0m"
# define RED "\033[38;5;1m"
# define RED_MINUS "\033[38;5;9m"
# define GREEN_MINUS "\033[38;5;10m"
# define GREY "\033[38;5;8m"

# define CANT_OPEN 1
# define MALLOC 2
# define FD 3
# define INVALID_CHAR 4

# define NO_ERROR mod1->nb_err == 0

typedef struct s_mod	t_mod;
typedef struct s_coor	t_coor;
typedef struct s_map	t_map;

struct			s_coor
{
	long double	x;
	long double	y;
	long double	z;
};

struct			s_map
{
	char		*map_name;
	char		*line;
	char		*map;
	int			pos[2];
	char		buff[2];
};

struct			s_mod
{
	int			fd;
	int			nb_err;
	t_map		map;
	int			nb_points;
	t_coor		*coor;
};

void			usage(t_mod *mod1, int ac, char *av);
int				check_name(t_mod *mod1, char *map_name);
void			set_all(t_mod *mod1);
void			open_map(t_mod *mod1);
void			error(t_mod *mod1, int e);
void			get_points(t_mod *mod1);
int				sp_gnl(t_mod *mod1, char **line);
void			valid_char(t_mod *mod1, char c);

void			clean_all(t_mod *mod1);

#endif
