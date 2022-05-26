/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiningTable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:40:15 by aboudoun          #+#    #+#             */
/*   Updated: 2022/05/26 11:38:25 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

void	eat(t_philo *ph)
{
	ft_print("is eating", ph->nbr + 1, ph->data);
	ph->start_time = ft_get_time();
	ph->nbr_eat++;
	if (ph->nbr_eat == ph->data->must_eat)
		ph->data->philo_have_eaten++;
	usleep((ph->data->time_eat) * 1000);
}

void	ft_sleep(t_philo *ph)
{
	ft_print("is sleeping", ph->nbr + 1, ph->data);
	usleep((ph->data->time_sleep) * 1000);
}

void	take_fork(t_philo *ph)
{
	pthread_mutex_lock(&(ph->left_fork));
	ft_print("taking fork", ph->nbr + 1, ph->data);
	pthread_mutex_lock(ph->right_fork);
	ft_print("taking fork", ph->nbr + 1, ph->data);
	eat(ph);
	pthread_mutex_unlock(&(ph->left_fork));
	pthread_mutex_unlock(ph->right_fork);
}

void	*ft_actions(void *philo)
{
	t_philo	*ph;

	ph = philo;
	if (ph->nbr % 2 == 0)
		usleep(100);
	while (1)
	{
		take_fork(ph);
		ft_sleep(ph);
		ft_print("is thinking", ph->nbr + 1, ph->data);
	}
}
