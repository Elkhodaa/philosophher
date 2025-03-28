/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wikhamli <wikhamli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:00:14 by wikhamli          #+#    #+#             */
/*   Updated: 2025/03/28 16:29:17 by wikhamli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void ft_sleepms(long time)
{
    long	curr;
	long	end;

	curr = get_time();
	end = curr + time;
	while (get_time() < end)
		usleep(100);
}

long  get_time()
{
    struct timeval time;

    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void    times(t_philo *philo, char **av)
{
    philo->number_of_philo = ft_atoi(av[1]);
    philo->time_to_die = ft_atoi(av[2]);
    philo->time_to_eat = ft_atoi(av[3]);
    philo->time_to_sleep = ft_atoi(av[4]);
    if (philo->time_to_die <= 0 || philo->time_to_eat <= 0 
            || philo->time_to_sleep <= 0) 
       ft_putstr_fd("Error in The time \n", 2);
    philo->number_of_fork = philo->number_of_philo;
    philo->fixed_time = get_time();
}

void    time_to_sleep(t_philo *philo)
{
    writees(philo, 2);
    philo->fixed_time = get_time();
    ft_sleepms(philo->time_to_sleep);
    writees(philo, 3);
}

