/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_analysis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: airyago <airyago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 10:34:06 by airyago           #+#    #+#             */
/*   Updated: 2023/09/01 10:34:30 by airyago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_print_analysis(t_analysis *analysis)
{
	printf("Analysis Results:\n");
	printf("------------------\n");
	printf("Reverse Count: %d\n", analysis->reverse_count);
	if (analysis->start_reverse)
		printf("Start Reverse Position: %d\n", analysis->start_reverse->position);
	else
		printf("Start Reverse Position: NULL\n");
	if (analysis->end_reverse)
		printf("End Reverse Position: %d\n", analysis->end_reverse->position);
	else
		printf("End Reverse Position: NULL\n");
	switch (analysis->action)
	{
		case ROTATE:
			printf("Action: ROTATE\n");
			break;
		case REVERSE_ROTATE:
			printf("Action: REVERSE_ROTATE\n");
			break;
		case UNTOUCHED:
			printf("Action: UNTOUCHED\n");
			break;
		default:
			printf("Action: UNKNOWN\n");
			break;
	}
	
	printf("Rotate to Position: %d\n", analysis->rotate_to_position);
	printf("------------------\n\n");
}