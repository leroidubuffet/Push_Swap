#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	int	stack_a[argc - 1];

	if (ft_parse_args(argc, argv, stack_a) != 0)
		return 1;  // If ft_parse_args fails, return an exit status of 1
	return 0;  // If ft_parse_args succeeds, return an exit status of 0
}
