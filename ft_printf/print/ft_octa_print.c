/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 17:28:11 by dbotova           #+#    #+#             */
/*   Updated: 2017/01/07 16:31:50 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_putline(char *width, char *prefix, char *c, t_flags *flags)
{
	if (flags->width > 0)
		ft_putstr(width);
	if (flags->is_hash)
		ft_putstr("0\0");
	ft_putstr(prefix);
	if (!(*c == '0' && (flags->is_dot || flags->is_hash || flags->cutoff ||
					flags->width)))
		ft_putstr(c);
	if (flags->width < 0)
		ft_putstr(width);
}

static int	ft_getsize(char *c, char *prefix, char *width, t_flags *flags)
{
	int		size;
	char	*hash;

	size = 0;
	hash = (flags->is_hash) ? "0" : NULL;
	if (*c == '0' && (flags->is_dot || flags->cutoff || flags->is_hash))
		size = (int)ft_strlen(prefix) + (int)ft_strlen(width) +
			(int)ft_strlen(hash);
	else
		size = (int)ft_strlen(c) + (int)ft_strlen(prefix) +
			(int)ft_strlen(width) + ft_strlen(hash);
	ft_putline(width, prefix, c, flags);
	if (prefix)
		SMART_FREE(prefix);
	if (width)
		SMART_FREE(width);
	return (size);
}

static char	*ft_mread(va_list ap, union u_types tp, t_flags *flags)
{
	if (flags->is_l == 1)
	{
		tp.ul = va_arg(ap, unsigned long);
		return (ft_ultoa_base(tp.ul, 8));
	}
	if (flags->is_l == 2 || flags->is_j || flags->is_z)
	{
		tp.ull = va_arg(ap, unsigned long long);
		return (ft_ultoa_base(tp.ull, 8));
	}
	if (flags->is_h == 1)
	{
		tp.us = va_arg(ap, unsigned int);
		return (ft_ltoa_base(tp.us, 8));
	}
	if (flags->is_h == 2)
	{
		tp.uc = va_arg(ap, unsigned int);
		return (ft_ltoa_base(tp.uc, 8));
	}
	tp.u = va_arg(ap, unsigned int);
	return (ft_ltoa_base(tp.u, 8));
}

int			ft_octa_print(va_list ap, union u_types tp, t_flags *flags)
{
	int		size;
	char	*prefix;
	char	*width;

	size = 0;
	width = NULL;
	prefix = NULL;
	flags->target = ft_mread(ap, tp, flags);
	flags->is_o = 1;
	if (flags->is_hash)
	{
		ft_hex_read(flags, &prefix, &width, "0");
		size = ft_getsize(flags->target, prefix, width, flags);
	}
	else
	{
		ft_hex_read(flags, &prefix, &width, NULL);
		size = ft_getsize(flags->target, prefix, width, flags);
	}
	SMART_FREE(flags->target);
	return (size);
}
