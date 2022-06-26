/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_or_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:25:40 by aboudoun          #+#    #+#             */
/*   Updated: 2022/06/26 18:48:06 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	start_left(t_philo *ph)
{
	while (!ph->data->finish)
	{
		take_left_fork(ph);
		take_right_fork(ph);
		eat(ph);
		pthread_mutex_unlock(&(ph->left_fork));
		pthread_mutex_unlock(ph->right_fork);
		ft_sleep(ph);
		ft_print("is thinking", ph->nbr + 1, ph->data);
		usleep(50);
	}
}

void	start_right(t_philo *ph)
{
	while (!ph->data->finish)
	{
		take_right_fork(ph);
		take_left_fork(ph);
		eat(ph);
		pthread_mutex_unlock(ph->right_fork);
		pthread_mutex_unlock(&(ph->left_fork));
		ft_sleep(ph);
		ft_print("is thinking", ph->nbr + 1, ph->data);
		usleep(50);
	}
}
