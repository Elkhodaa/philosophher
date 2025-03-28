/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wikhamli <wikhamli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:00:14 by wikhamli          #+#    #+#             */
/*   Updated: 2025/03/28 15:27:36 by wikhamli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
    philo->update_time = get_time();
}

void    time_to_sleep(t_philo *philo)
{
    writees(philo, 2);
    // philo->update_time = get_time();
    // while(get_time() - philo->update_time < philo->time_to_sleep)
    //      usleep(100);
    usleep(philo->time_to_sleep * 1000);
    writees(philo, 3);
}
void    time_to_eat(t_philo *philo)
{
    writees(philo, 1);
    while ((get_time() - philo->update_time) < philo->time_to_eat)
        usleep(100);
}
