/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiningTable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:40:15 by aboudoun          #+#    #+#             */
/*   Updated: 2022/06/24 14:52:17 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eat(t_philo *ph)
{
	pthread_mutex_lock(&(ph->eat));
	ft_print("is eating", ph->nbr + 1, ph->data);
	ph->last_eat = ft_get_time();
	ph->nbr_eat++;
	if (ph->nbr_eat == ph->data->must_eat)
		ph->data->philo_have_eaten++;
	pthread_mutex_unlock(&(ph->eat));
	ft_usleep((ph->data->time_eat), ft_get_time());
}

void	ft_sleep(t_philo *ph)
{
	ft_print("is sleeping", ph->nbr + 1, ph->data);
	ft_usleep((ph->data->time_sleep), ft_get_time());
}

void	take_left_fork(t_philo *ph)
{
	pthread_mutex_lock(&(ph->left_fork));
	ft_print("is taking a fork", ph->nbr + 1, ph->data);
}

void	take_right_fork(t_philo *ph)
{
	pthread_mutex_lock(ph->right_fork);
	ft_print("is taking a fork", ph->nbr + 1, ph->data);
}

void	*ft_actions(void *philo)
{
	t_philo	*ph;

	ph = philo;
	if (ph->nbr % 2 == 0)
		start_left(ph);
	start_right(ph);
	return (NULL);
}
