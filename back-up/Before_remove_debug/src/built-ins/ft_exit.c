/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjimen & isainz-r <danjimen & isainz-    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:40:06 by danjimen &        #+#    #+#             */
/*   Updated: 2024/10/24 13:57:14 by danjimen &       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	check_lloverflow(const char *str, unsigned long long *value,
				int *negative)
{
	int	digit;

	if (*str == '-')
	{
		*negative = 1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!isdigit(*str))
			return (ERR);
		digit = *str - '0';
		if (*value > LLONG_MAX / 10
			|| (*value == LLONG_MAX / 10 && digit > LLONG_MAX % 10 + *negative))
			return (ERR);
		*value = *value * 10 + digit;
		str++;
	}
	return (OK);
}

int	is_valid_number(const char *str, long long int *result)
{
	int					negative;
	unsigned long long	value;

	negative = 0;
	value = 0;
	if (check_lloverflow(str, &value, &negative) == ERR)
		return (ERR);
	if (negative)
	{
		if (value > (unsigned long long)LLONG_MAX + 1)
			return (ERR);
		*result = -(long long)value;
	}
	else
	{
		if (value > LLONG_MAX)
			return (ERR);
		*result = (long long)value;
	}
	return (OK);
}

static int	its_only_numbers(char *str)
{
	int			i;
	long long	num_not_valid;

	i = 0;
	if (*str == '\0')
		return (ERR);
	while (str[i] != '\0')
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			i++;
		if (!ft_isdigit(str[i]))
			return (ERR);
		i++;
	}
	if (is_valid_number(str, &num_not_valid) == ERR)
		return (ERR);
	return (OK);
}

static int	multiple_args(char **exit_args, int argc)
{
	long long	nbr_atoll;
	int			modulus;
	char		*arg_trimed;

	arg_trimed = ft_strtrim(exit_args[1], " \f\r\n\t\v");
	if (its_only_numbers(arg_trimed) == ERR)
	{
		printf("exit\n");
		ft_dprintf(2, "minishell: exit: %s: numeric argument required\n",
			exit_args[1]);
		return (free (arg_trimed), 2);
	}
	else if (its_only_numbers(arg_trimed) == OK && argc == 2)
	{
		is_valid_number(arg_trimed, &nbr_atoll);
		modulus = (nbr_atoll % 256);
		return (free (arg_trimed), modulus);
	}
	else if (its_only_numbers(arg_trimed) == OK && argc > 2)
	{
		printf("exit\n");
		ft_dprintf(2, "minishell: exit: too many arguments\n");
		return (free (arg_trimed), -1);
	}
	return (0);
}

int	ft_built_exit(t_args *args, char **exit_args)
{
	int	argc;
	int	exit_status;

	(void)args;
	argc = 0;
	exit_status = 0;
	while (exit_args[argc])
		argc++;
	printf("DB: exit argc = %i\n", argc);
	if (argc == 1)
		return (0);
	if (argc >= 2)
		exit_status = multiple_args(exit_args, argc);
	return (exit_status);
}
