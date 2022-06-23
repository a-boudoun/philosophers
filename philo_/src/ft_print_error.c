/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:22:16 by aboudoun          #+#    #+#             */
/*   Updated: 2022/06/22 21:28:40 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	print_err(char *message)
{
	write(2, message, ft_strlen(message));
}
