/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiningTable_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:40:15 by aboudoun          #+#    #+#             */
/*   Updated: 2022/06/26 19:23:35 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	eat(t_philo *ph)
{
	sem_wait(ph->eat);
	ft_print("is eating", ph->nbr + 1, ph);
	ph->should_die = ft_get_time() + ph->data->time_die;
	ph->nbr_eat++;
	if (ph->nbr_eat == ph->data->must_eat)
		sem_post(ph->data->finish);
	sem_post(ph->eat);
	ft_usleep((ph->data->time_eat), ft_get_time());
}

void	ft_sleep(t_philo *ph)
{
	ft_print("is sleeping", ph->nbr + 1, ph);
	ft_usleep((ph->data->time_sleep), ft_get_time());
}

void	take_forks(t_philo *ph)
{
	sem_wait(ph->data->forks);
	ft_print("is taking a fork", ph->nbr + 1, ph);
	sem_wait(ph->data->forks);
	ft_print("is taking a fork", ph->nbr + 1, ph);
	eat(ph);
	sem_post(ph->data->forks);
	sem_post(ph->data->forks);
}

void	ft_actions(t_philo *ph)
{
	pthread_t	check;

	pthread_create(&check, NULL, &end_diner, ph);
	pthread_detach(check);
	while (1)
	{
		take_forks(ph);
		ft_sleep(ph);
		ft_print("is thinking", ph->nbr + 1, ph);
	}
}
