/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philoUtils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:41:18 by aboudoun          #+#    #+#             */
/*   Updated: 2022/06/23 03:06:53 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers_bonus.h"

void	ft_print(char *messege, int p, t_philo *ph)
{
	int	time;
	sem_wait(ph->data->print);
	time = ft_get_time() - ph->data->start_time;
	if (!ph->dead)
		printf("%dms  %d  %s\n", time, p, messege);
	sem_post(ph->data->print);
}

void	ft_print_dead(char *messege, int p, t_philo *ph)
{
	int	time;
	sem_wait(ph->data->print);
	time = ft_get_time() - ph->data->start_time;
	printf("%dms  %d  %s\n", time, p, messege);
	sem_post(ph->data->print);
}

void	ft_destroy(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
		kill(data->table_id[i], SIGKILL);
	free(data->table_id);
	free(data->philo);
	sem_close(data->forks);
	sem_close(data->print);
	sem_close(data->finish);
}

long long	ft_get_time(void)
{
	struct timeval	current_time;
	long long		time;

	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

int	ft_atoi(char *str)
{
	int	i;
	int	s;
	int	n;

	s = 1;
	i = 0;
	n = 0;
	while (str[i] == ' ' || str[i] == '\t' || str [i] == '\f'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -s;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		n = n * 10 + ((int)str[i] - '0');
		i++;
	}
	return (n * s);
}
