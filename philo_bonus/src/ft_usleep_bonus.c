/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 21:21:44 by aboudoun          #+#    #+#             */
/*   Updated: 2022/06/22 23:16:14 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	ft_usleep(unsigned long time, unsigned long start)
{
	usleep(time * 1000 * 0.95);
	while (ft_get_time() - start < time)
		usleep(50);
}
