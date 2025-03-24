/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wikhamli <wikhamli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 12:43:37 by wikhamli          #+#    #+#             */
/*   Updated: 2025/03/24 13:45:22 by wikhamli         ###   ########.fr       */
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
    philo->time = get_time();
    philo->number_of_fork = philo->number_of_philo;
}
void    writees(t_philo *philo, int x)
{
    if (x == 0)
        printf("id  %d has taken a fork\n", philo->id);
    if (x == 1)
        printf("%ld ms %d is eating\n",(get_time() - philo->time),philo->id);
    if (x == 2)
        printf("%ld ms %d  is sleeping\n",(get_time() - philo->time), philo->id); 
    if (x == 3)
        printf("%ld ms %d  is thinking\n",(get_time() - philo->time), philo->id);
    if (x == 4)
        printf("%ld ms %d  died\n",(get_time() - philo->time), philo->id);
}

void    func_sleep(t_philo *philo)
{
    while((get_time() - philo->time) < philo->time_to_sleep)
        usleep(500);
    writees(philo, 2);
    philo->time = get_time();
}


