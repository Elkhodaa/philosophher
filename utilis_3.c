/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wikhamli <wikhamli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:00:14 by wikhamli          #+#    #+#             */
/*   Updated: 2025/03/26 13:02:26 by wikhamli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long  get_time()
{
    struct timeval time;
    long    start_time;
    
    if (gettimeofday(&time, NULL))
        return (0);
    start_time = time.tv_sec * 1000;
    start_time += time.tv_usec / 1000;
    return (start_time);
}

void    times(t_philo *philo, char **av)
{
    philo->number_of_philo = ft_atoi(av[1]);
    philo->time_to_die = ft_atoi(av[2]);
    philo->time_to_eat = ft_atoi(av[3]);
    philo->time_to_sleep = ft_atoi(av[4]);
    if (philo->time_to_die <= 0 || philo->time_to_eat <= 0 || philo->time_to_sleep <= 0) 
       ft_putstr_fd("Error in The time \n", 2);
    philo->number_of_fork = philo->number_of_philo;
    philo->time = get_time();
}

void    time_to_sleep(t_philo *philo)
{
    // philo->time = get_time();
    while(get_time() - philo->time < philo->time_to_sleep)
        usleep(500);
    writees(philo, 2);
    writees(philo, 3);
    // philo->time = get_time();
}
void    time_to_eat(t_philo *philo)
{
    writees(philo, 1);
    // philo->time = get_time();
    while (get_time() - philo->time  < philo->time_to_eat)
        usleep(500);
    // philo->time = get_time();
}
