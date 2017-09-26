/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 16:45:46 by pbernier          #+#    #+#             */
/*   Updated: 2017/09/26 21:49:52 by pbernier         ###   ########.fr       */
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
# define GRAS "\033[1m"
# define DLONG_MAX 9223372036854775807
# define DLONG_MIN -9223372036854775807

# define MAX_ERROR 10
# define NB_LINE mod1->map.pos[0]
# define NB_COLUMN mod1->map.pos[1]
# define TMP mod1->map.tmp
# define BUFF mod1->map.buff[0]

# define CANT_OPEN 1
# define MALLOC 2
# define FD 3
# define VERBOS 4

# define INVALID_CHAR 1
# define START_BRACES 2

typedef struct s_mod	t_mod;
typedef struct s_coor	t_coor;
typedef struct s_map	t_map;

struct			s_coor
{
	int			name;
	long double	x;
	long double	y;
	long double	z;
};

struct			s_map
{
	char		*map_name;
	char		*line;
	size_t		pos[2];
	char		buff[2];
	char		*arrow;
	char		*invalid;
	char		*tmp;
	char		**value;
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
int				get_line(t_mod *mod1, char **line);
void			check_file(t_mod *mod1);
int				check_char(t_mod *mod1, char *line);
int				check_value(t_mod *mod1, char *line);
int				valid_char(char c);
void			list_char(char **invalid, char c);
void			ver_char(t_mod *mod1);
void			ver_pos(t_mod *mod1);
void			clean_all(t_mod *mod1, int end);
void			print_invalid(t_mod *mod1, char **invalid);
void			print_line(t_mod *mod1, char **line);
void			adjust_arrow(char **arrow, char c, int size);
void			print_arrow(t_mod *mod1, char **arrow);
void			ver_value(t_mod *mod1, int e);
void			realloc_value(t_mod *mod1, char *line, size_t start, size_t end);

#endif
