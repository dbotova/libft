/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 11:24:19 by dbotova           #+#    #+#             */
/*   Updated: 2017/08/08 11:24:20 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "llist.h"

void	ft_del(void *data, size_t size)
{
	ft_memset(data, 0, size);
}