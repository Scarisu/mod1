/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 21:37:18 by pbernier          #+#    #+#             */
/*   Updated: 2017/09/26 21:50:09 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mod1.h>

int		check_value(t_mod *mod1, char *line)
{
	char			*check;
	size_t			start;
	static size_t	len = 0;

	++mod1->nb_points;
	start = len;
	while (line[len] && line[len] == ' ')
		++len;
	while (line[len] && line[len] != ' ')
		++len;
	realloc_value(mod1, line, start, len);

	len = 0;
	return (1);
}

void	realloc_value(t_mod *mod1, char *line, size_t start, size_t end)
{
	int		i;
	size_t	cpy;
	char	**new;

	i = -1;
	cpy = -1;
	if (!(new = (char **)malloc(sizeof(char *) * (mod1->nb_points + 1))))
		error(mod1, MALLOC);
	while (++i < mod1->nb_points)
	{
		if (!(new[i] = ft_strnew(ft_strlen(mod1->map.value[i]))))
			error(mod1, MALLOC);
		new[i] = ft_strcpy(new[i], mod1->map.value[i]);
		ft_memdel((void **)&mod1->map.value[i]);
	}
	if (!(new[i] = (ft_strnew(len))))
		error(mod1, MALLOC);
	while (++cpy < len)
		new[i][cpy] = line[cpy];
	new[++i] = NULL;

	ft_memdel((void **)&mod1->map.value);
	ft_memdel((void **)&new);

		(void)line;
}

/*void		realloc_value(t_mod *mod1, char *line, size_t len)
{
	int		i;
	size_t	cpy;
	char	**new;

	i = -1;
	cpy = -1;
	if (!(new = (char **)malloc(sizeof(char *) * (mod1->nb_points + 1))))
		error(mod1, MALLOC);
	while (mod1->map.value && mod1->map.value[++i])
	{
		printf("{%d}..\n", i);
		if (!(new[i] = ft_strnew(ft_strlen(mod1->map.value[i]))))
			error(mod1, MALLOC);
		new[i] = ft_strcpy(new[i], mod1->map.value[i]);
		ft_memdel((void **)&mod1->map.value[i]);
	}
	printf("{%zu} {%d}.\n", len, i);
	if (!(new[i] = (ft_strnew(len))))
		error(mod1, MALLOC);
	while (++cpy < len)
	{
		new[i][cpy] = line[cpy];
	}
	new[++i] = NULL;
	ft_memdel((void **)&mod1->map.value);
	mod1->map.value = new;
	(void)line;
}*/
