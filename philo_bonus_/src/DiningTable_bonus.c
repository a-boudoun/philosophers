/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiningTable_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:40:15 by aboudoun          #+#    #+#             */
/*   Updated: 2022/06/23 02:40:30 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers_bonus.h"

void	*end_diner(void *philo)
{
	t_philo	*ph;
	int	i;

	i = -1;
	ph = philo;
	while (!ph->dead)
	{
		printf("TIME%lld\n%lld\n", ft_get_time(), ph->should_die);
		if (ft_get_time() >= ph->should_die)
		{
			ph->dead = 1;
			ft_print("died", ph->nbr + 1, ph);
			while (++i < ph->data->nb_philo)
				sem_post(ph->data->finish);
		}
		usleep(100);
	}
	return (NULL);
}

void	eat(t_philo *ph)
{
	ft_print("is eating", ph->nbr + 1, ph);
	ph->should_die = ft_get_time() + ph->data->time_die;
	ph->nbr_eat++;
	if (ph->nbr_eat == ph->data->must_eat)
		sem_post(ph->data->finish);
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

	ph->should_die = ph->data->start_time + ph->data->time_die;
	printf("time sould die:%lld\n", ph->should_die);
	printf("time die:%d\n",  ph->data->time_die);
	printf("start time:%d\n", ph->data->start_time);
	pthread_create(&check, NULL, &end_diner, ph);
	pthread_detach(check);
	if (ph->nbr % 2 == 0)
		ft_usleep(100, ft_get_time());
	while (1)
	{
		take_forks(ph);
		ft_sleep(ph);
		ft_print("is thinking", ph->nbr + 1, ph);
		usleep(100);
	}
	//pthread_join(check, NULL);
}
