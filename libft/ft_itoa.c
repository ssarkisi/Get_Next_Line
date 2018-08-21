/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssarkisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:00:58 by ssarkisi          #+#    #+#             */
/*   Updated: 2017/11/08 16:01:07 by ssarkisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_positiv(long int nbr)
{
	if (nbr < 0)
		return (-nbr);
	else
		return (nbr);
}

static int		ft_len(long int nbr)
{
	int		len;

	len = 0;
	if (nbr <= 0)
		len++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int nbr)
{
	char	*tmp;
	int		len;
	int		sign;

	sign = 1;
	if (nbr < 0)
		sign = -1;
	len = ft_len(nbr);
	if ((tmp = (char *)malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	tmp[len] = '\0';
	len--;
	while (len >= 0)
	{
		tmp[len] = '0' + ft_positiv(nbr % 10);
		nbr = ft_positiv(nbr / 10);
		len--;
	}
	if (sign == -1)
		tmp[0] = '-';
	return (tmp);
}
