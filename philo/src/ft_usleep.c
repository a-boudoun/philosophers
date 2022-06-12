/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 21:21:44 by aboudoun          #+#    #+#             */
/*   Updated: 2022/06/12 21:23:19 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

void	ft_usleep(unsigned long time, unsigned long start)
{
	usleep(time * 1000 * 0.95);
	while (ft_get_time() - start < time)
		usleep(50);
}
