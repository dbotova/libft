/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enqueue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 14:43:50 by dbotova           #+#    #+#             */
/*   Updated: 2017/08/08 14:43:52 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	ft_enqueue(t_queue *queue, void *content, size_t size)
{
	t_list *new;

	new = ft_lstnew(content, size);
	if (ft_qempty(queue))
	{
		queue->front = new;
		queue->last = new;
	}
	else
	{
		queue->last->next = new;
		queue->last = new;
	}
}