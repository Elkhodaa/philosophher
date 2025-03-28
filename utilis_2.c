/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wikhamli <wikhamli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 12:43:37 by wikhamli          #+#    #+#             */
/*   Updated: 2025/03/28 15:39:09 by wikhamli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    writees(t_philo *philo, int x)
{
    long current_time;

    pthread_mutex_lock(&philo->time);
    current_time = get_time();
    if (x == 0)
        printf("%ld %d has taken a forks\n",current_time - philo->update_time, philo->id);
    if (x == 1)
        printf("%ld %d is eating\n",current_time - philo->update_time, philo->id);
    if (x == 2)
        printf("%ld %d  is sleeping\n",current_time - philo->update_time, philo->id); 
    if (x == 3)
        printf("%ld %d  is thinking\n",current_time - philo->update_time, philo->id);
    if (x == 4)
        printf("%ld %d  died\n",current_time -philo->update_time, philo->id);
    pthread_mutex_unlock(&philo->time);

}

void fun_eat(t_philo *philo)
{   
    // printf("philo->id |%d| \n philo->fork_left |%d| \n philo->fork_right |%d|\n", philo->id, philo->fork_left,
    //      philo->fork_right);
    pthread_mutex_lock(&philo->forks[philo->fork_left]);
    // writees(philo, 0);
    pthread_mutex_lock(&philo->forks[philo->fork_right]);
    writees(philo, 0);
    // time_to_eat(philo);
    usleep(philo->time_to_eat * 1000);
    pthread_mutex_unlock(&philo->forks[philo->fork_left]);
    pthread_mutex_unlock(&philo->forks[philo->fork_right]);
}
