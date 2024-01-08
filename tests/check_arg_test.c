/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:52:16 by airyago           #+#    #+#             */
/*   Updated: 2023/08/16 15:18:48 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

#include "../include/push_swap.h"

void	ft_fill_str_with_numbers(char *str, int n)
{
	int		i;
	char	buffer[20];

	i = 0;
	while (n > 0)
	{
		snprintf(buffer, sizeof(buffer), "%d ", i);
		strcat(str, buffer);
		i++;
		n--;
	}
}

char	*ft_create_large_string(int n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	str[n] = '\0';
	return (str);
}

void	test_case(char *args, int expected_exit_status)
{
	char	*command;
	int		exit_status;
	int		actual_exit_status;

	command = malloc(sizeof(char) * (strlen(args) + 10));
	if (!command)
		exit(EXIT_FAILURE);
	sprintf(command, "./a.out %s", args);
	printf("Calling command with %s\n", command);
	exit_status = system(command);
	free(command);
	actual_exit_status = WEXITSTATUS(exit_status);
	if (actual_exit_status == expected_exit_status)
		printf("OK\n");
	else
		printf("KO\n");
}

int	main(int argc, char *argv[])
{
	char	*str;
	int		n;

	if (argc < 2)
	{
		printf("Error: Invalid number of arguments.\n");
		return (1);
	}
	n = atoi(argv[1]);
	str = ft_create_large_string(n);
	printf("Created a string of %i elements\n", n);
	ft_fill_str_with_numbers(str, n);
	if (!str)
	{
		printf("Error: Could not allocate memory.\n");
		return (1);
	}
	printf("String is: %s\n", str);
	// valid inputs
	test_case(str, 0);
	// test_case("1 2 3 4 5", 0);

	// // invalid inputs
	// test_case("999999999999", 1);
	// test_case("a b c", 1);

	free(str);
	printf("Test done\n");
	return (0);
}
