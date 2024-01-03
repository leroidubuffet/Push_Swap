# Push_swap
### Because Swap_push isn’t as natural

# Push_swap Project Requirements

## Objective:
- Develop a C program named `push_swap` that sorts numbers using two stacks with the minimum number of operations.

## Program Requirements:
- The program should accept a list of integers as arguments, representing stack `a` with the first argument at the top.
- Outputs the sequence of actions to sort the stack, with each action followed by a newline.

## Stack Operations:
- `sa` (swap a): Swap the first two elements of stack `a`.
- `sb` (swap b): Swap the first two elements of stack `b`.
- `ss`: Execute `sa` and `sb` simultaneously.
- `pa` (push a): Move the top element from stack `b` to stack `a`.
- `pb` (push b): Move the top element from stack `a` to stack `b`.
- `ra` (rotate a): Move the first element of stack `a` to the bottom.
- `rb` (rotate b): Move the first element of stack `b` to the bottom.
- `rr`: Execute `ra` and `rb` simultaneously.
- `rra` (reverse rotate a): Move the last element of stack `a` to the top.
- `rrb` (reverse rotate b): Move the last element of stack `b` to the top.
- `rrr`: Execute `rra` and `rrb` simultaneously.

## Code and Project Constraints:
- Must be implemented in C.
- No global variables.
- Graceful error handling with "Error" message output for any issues.
- No memory leaks; all heap allocated memory must be freed.
- A Makefile with the rules: `$(NAME)`, `all`, `clean`, `fclean`, `re`.
- Bonus parts should be in separate files and must not interfere with the mandatory part.

## Performance:
- The number of operations used for sorting is critical; there's a maximum threshold.
- Zero score for incorrect sorting or if the operation count exceeds the maximum allowed.

## Bonus:
- A `checker` program to validate the instructions from `push_swap` is a bonus task.
- The bonus is only assessed if the mandatory part is flawlessly completed.

## Submission:
- Work must be submitted via the assigned Git repository. Evaluation is based solely on the repository content.

## External Functions Allowed:
- `read`, `write`, `malloc`, `free`, `exit`
- Self-coded `ft_printf` or its equivalent.
- Use of `libft` is permitted.

## Lessons learned
- Start testing earlier. I have lost several days of work because my tests were weak and did not find some major bugs
- git branching. Branch early and branch often has proved as good advice as it seems
- `git bisect`. I did not know git had so many helpful features
- using `static` when developing new functions is great to speed up things
- Makefile can hold rules for your testing workflow as well
- Bash ans zsh do not handle strings in quotes equally. Using ARG in zsh will turn out as invalid input.

## Testing
I have leaned in the works of gemartin99 a fellow student who developed a wonderful [tool](https://github.com/gemartin99/Push-Swap-Tester). I have some randomly generated numbers and the tester in /tests.
Makefile has a test rule that will move the push_swap binary file and run push_swap_test.sh. Both need to be in the root directory of he project.
small_stack_utils.sh generates series of numbers and gives the to push_swap as an argument.

