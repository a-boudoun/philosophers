/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiningTable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:40:15 by aboudoun          #+#    #+#             */
/*   Updated: 2022/06/23 14:41:20 by aboudoun         ###   ########.fr       */
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
	ft_usleep((ph->data->time_eat), ft_get_time());
	pthread_mutex_unlock(&(ph->eat));
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
	eat(ph);
	pthread_mutex_unlock(&(ph->left_fork));
	pthread_mutex_unlock(ph->right_fork);
}

void	*ft_actions(void *philo)
{
	t_philo	*ph;

	ph = philo;
	if (ph->nbr % 2 == 0)
		ft_usleep(100, ft_get_time());
	while (!ph->data->finish)
	{
		take_left_fork(ph);
		if (ph->data->nb_philo == 1)
		{
			ph->data->finish = 1;
			ft_usleep(ph->data->time_die, ft_get_time());
			break ;
		}
		take_right_fork(ph);
		ft_sleep(ph);
		ft_print("is thinking", ph->nbr + 1, ph->data);
		usleep(100);
	}
	return (NULL);
}
