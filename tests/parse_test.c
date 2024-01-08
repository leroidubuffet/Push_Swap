#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

#include "../include/push_swap.h"

void	test_case(char *args, int expected_exit_status)
{
	char	command[100];
	int		exit_status;
	int		actual_exit_status;

	// Prepare the command string
	// sprintf outputs strings in an array
	sprintf(command, "./parser.out %s", args);

	// Run the command
	// system allows us to run arguments in a subshell

	exit_status = system(command);

	/*
	This WEXITSTATUS macro performs a bitwise AND operation with 0xff 
	(which is 11111111 in binary) to get the 8 least significant 
	bits of the status, effectively ignoring the rest of the bits. 
	This is the actual exit status of the process.
	Get the actual exit status
	*/
	actual_exit_status = WEXITSTATUS(exit_status);

    // Check the exit status
	if (actual_exit_status == expected_exit_status)
		printf("Test case passed: %s\n", args);
	else
		printf("Test case failed: %s. Expected %d but got %d.\n",
			args, expected_exit_status, actual_exit_status);
}

int	main() 
{
    // Test valid inputs
	test_case("1 2 3 4 5", 0);
	test_case("-1 -2 -3 -4 -5", 0);
	test_case("2147483647 -2147483648", 0);

	// Test invalid inputs
	test_case("1 2 3 4 5 5", 1);	// duplicate number
	test_case("1 2 3 4 five", 1);	// non-integer
	test_case("2147483648", 1);		// too large to fit in an int
	test_case("-2147483649", 1);	// too small to fit in an int

	return (0);
}
