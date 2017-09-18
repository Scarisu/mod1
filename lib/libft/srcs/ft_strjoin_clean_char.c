/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_clean_char.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 00:25:53 by pbernier          #+#    #+#             */
/*   Updated: 2017/08/18 13:13:00 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_clean_char(char **s, char c)
{
	char	*tmp;
	char	*head;

	if (!(*s))
		*s = ft_strnew(0);
	head = *s;
	tmp = ft_strjoin_char(*s, c);
	*s = ft_strdup(tmp);
	ft_strdel(&head);
	ft_strdel(&tmp);
	return (*s);
}
