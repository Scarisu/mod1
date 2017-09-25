/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 18:01:07 by pbernier          #+#    #+#             */
/*   Updated: 2017/09/25 21:07:32 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mod1.h>

int		get_line(t_mod *mod1, char **line)
{
	int		ret;
	int		size;

	size = 0;
	BUFF = 'A';
	if (!(*line = malloc(sizeof(char) * (size + 1))))
		error(mod1, MALLOC);
	(*line)[size] = '\0';
	while (BUFF != '\n')
	{
		if ((ret = read(mod1->fd, mod1->map.buff, 1)) == -1)
			error(mod1, FD);
		if (!ret || BUFF == 0)
			return (ret);
		if (BUFF >= '\t' && BUFF <= '\f' && BUFF != '\n')
			BUFF = ' ';
		ft_strjoin_clean_char(line, BUFF);
		++size;
	}
	(*line)[size - 1] = '\0';
	return (size);
}
