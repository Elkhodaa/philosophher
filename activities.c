/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wikhamli <wikhamli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 12:43:37 by wikhamli          #+#    #+#             */
/*   Updated: 2025/03/24 12:04:26 by wikhamli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long  get_time()
{
    struct timeval time;
    long  timestamp_in_ms;
    
    if (gettimeofday(&time, NULL))
    {
        perror("Error getting time");
        return (0); 
    }
    timestamp_in_ms = (long)time.tv_sec * 1000 + time.tv_usec / 1000;
    return (timestamp_in_ms);
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
void    func_sleep(t_philo *philo)
{
    writees(philo, 2);
    
    while((get_time() - philo->time) < philo->time_to_sleep)
        usleep(500);
    philo->time = get_time();
}

void fun_eat(t_philo *philo)
{   
    printf("left %d => \n", philo->fork_left);
    printf("right %d => \n", philo->fork_right);
    if (philo->id % 2 == 0)
    {
        printf("2 \n");
        pthread_mutex_lock(&philo->forks[philo->fork_left]);
        writees(philo, 0);
        pthread_mutex_lock(&philo->forks[philo->fork_right]);
        writees(philo, 0);
    }
    else
    {
        printf("3 \n");
        pthread_mutex_lock(&philo->forks[philo->fork_right]);
        writees(philo, 0);
        pthread_mutex_lock(&philo->forks[philo->fork_left]);
        writees(philo, 0);
    }
    printf("4 \n");
    writees(philo, 1);
    while ((get_time() - philo->time) < philo->time_to_eat)
         usleep(500);
    philo->time = get_time();
    pthread_mutex_unlock(&philo->forks[philo->fork_left]);
    pthread_mutex_unlock(&philo->forks[philo->fork_right]);
    func_sleep(philo);
    writees(philo, 3);
}
