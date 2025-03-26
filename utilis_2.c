/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wikhamli <wikhamli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 12:43:37 by wikhamli          #+#    #+#             */
/*   Updated: 2025/03/26 13:28:37 by wikhamli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    writees(t_philo *philo, int x)
{
    long current_time;

    current_time = get_time() - philo->time;
    if (x == 0)
        printf("%ld ms id  %d has taken a fork\n",current_time ,philo->id);
    if (x == 1)
        printf("%ld ms id %d is eating\n",current_time ,philo->id);
    if (x == 2)
        printf("%ld ms id %d  is sleeping\n",current_time, philo->id); 
    if (x == 3)
        printf("%ld ms id %d  is thinking\n",current_time, philo->id);
    if (x == 4)
        printf("%ld ms id %d  died\n",current_time, philo->id);
}

void fun_eat(t_philo *philo)
{   
    if (philo->id % 2 == 0)
    {
        pthread_mutex_lock(&philo->forks[philo->fork_left]);
        writees(philo, 0);
        pthread_mutex_lock(&philo->forks[philo->fork_right]);
        writees(philo, 0);
    }
    else
    {
        pthread_mutex_lock(&philo->forks[philo->fork_right]);
        writees(philo, 0);
        pthread_mutex_lock(&philo->forks[philo->fork_left]);
        writees(philo, 0);
    }
    // philo->last_meal = get_time();
    time_to_eat(philo);
    pthread_mutex_unlock(&philo->forks[philo->fork_left]);
    pthread_mutex_unlock(&philo->forks[philo->fork_right]);
    time_to_sleep(philo);
}
