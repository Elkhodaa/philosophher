/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wikhamli <wikhamli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:57:33 by wikhamli          #+#    #+#             */
/*   Updated: 2025/03/27 12:03:30 by wikhamli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
    exit(1);
}
void	check_empty(char **str)
{
	int	i;
	int j;

	j = 1;
	i = 0;
	while (str[j])
	{
		i = 0;
		while (str[j][i] == 32)
			i++;
		if (str[j][i] == '\0')
			ft_putstr_fd("empty av \n", 2);
		j++;
	}
}

void	check_sgin(char **str, int j, int i)
{
	if (!(str[j][i + 1] >= '0' && str[j][i + 1] <= '9'))
		ft_putstr_fd("Error in sign\n", 2);
	if (i > 0 && str[j][i - 1] != ' ')
		ft_putstr_fd("Error in sign\n", 2);
}

long	ft_atoi(char *str)
{
	long	res;
	long	s;
	long		i;

	i = 0;
	res = 0;
	s = 1;
	while (str[i] && str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * s);
}

void    check_av(char **str, int ac)
{
    int i;
    int j;

	j = 1;
	if (ac == 5)
	{
		check_empty(str);
		while (str[++j])
		{
			i = 0;
			while (str[j][++i])
			{
				if (str[j][i] < '0' || str[j][i] > '9')
				{
					if (str[j][i] != 32 && str[j][i] != '+' && str[j][i] != '-' )
						ft_putstr_fd("It's not a number\n", 2);
				}
				if (str[j][i] == '-' || str[j][i] == '+')
					check_sgin(str, j, i);
			}
		}
	}
	else
		ft_putstr_fd("error of number the ac \n",2);
}
