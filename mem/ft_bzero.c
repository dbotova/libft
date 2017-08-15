/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 16:43:31 by dbotova           #+#    #+#             */
/*   Updated: 2016/09/26 16:43:33 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

void	ft_bzero(void *ptr, int len)
{
	unsigned char *src;

	src = ptr;
	while (len > 0)
	{
		*src = 0;
		src++;
		len--;
	}
}
