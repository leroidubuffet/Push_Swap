# Push_swap
*Because Swap_push isn’t as natural*

This is my solution to the Push Swap project for 42 Madrid as per version 7 of the subject. My initial approach involved indexing the input for simplicity, but this apparent advantage showed its real face pretty soon and I had to give it up. In search for a simpler approach, and while trying to avoid the commonly used radix algorithm, I came across [ayogun's solution](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) and fell in love with the idea of a simple approach.
## Project Requirements

### Objective
- Develop a C program named `push_swap` that sorts numbers using two stacks with the minimum number of operations

### Program Requirements
- The program should accept a list of integers as arguments, representing stack `a` with the first argument at the top
- Outputs the sequence of actions to sort the stack, with each action followed by a newline

### Stack Operations
- `sa` (swap a): Swap the first two elements of stack `a`
- `sb` (swap b): Swap the first two elements of stack `b`
- `ss`: Execute `sa` and `sb` simultaneously
- `pa` (push a): Move the top element from stack `b` to stack `a`
- `pb` (push b): Move the top element from stack `a` to stack `b`
- `ra` (rotate a): Move the first element of stack `a` to the bottom
- `rb` (rotate b): Move the first element of stack `b` to the bottom
- `rr`: Execute `ra` and `rb` simultaneously
- `rra` (reverse rotate a): Move the last element of stack `a` to the top
- `rrb` (reverse rotate b): Move the last element of stack `b` to the top
- `rrr`: Execute `rra` and `rrb` simultaneously

### Code and Project Constraints
- Must be implemented in C
- No global variables
- Graceful error handling with "Error" message output for any issues
- No memory leaks; all heap allocated memory must be freed
- A Makefile with the rules: `$(NAME)`, `all`, `clean`, `fclean`, `re`

### Performance
- The number of operations used for sorting is critical; there's a maximum threshold
- Zero score for incorrect sorting or if the operation count exceeds the maximum allowed

### External Functions Allowed
- `read`, `write`, `malloc`, `free`, `exit`
- Self-coded `ft_printf` or its equivalent

## Lessons learned
- Do not over-engineer for performance and write your own requirements. This program will be tested with a maximum of 500 elements. Do not optimize for a million elements unless you have a lot of spare time. 
- Start testing earlier. I have lost several days of work because my tests were weak and did not find some major bugs
- git branching. *Branch early and branch often* has proved good advice
- `git bisect`. I did not know git had so many helpful features
- Using `static` when developing new functions is great to speed up things
- Makefile can hold rules for your testing workflow as well
- Bash ans zsh do not handle strings in quotes equally. Using ARG in zsh will turn out as invalid input
- [Rob Pike’s 5 rules of programming](https://doc.cat-v.org/bell_labs/pikestyle). Particularly, rule 5:

    *Rule 5.  Data dominates.  If you've chosen the right data structures and organized things well, the algorithms will almost always be self-evident.  Data structures, not algorithms, are central to programming.*

    This rule is complementary with [Linus Torvald's quote from 2006](https://lwn.net/Articles/193245/) *Bad programmers worry about the code. Good programmers worry about data structures and their relationships.*
    
    This idea became central to solving this project with a simple algorithm and a tailored set of data structures.
- [Conventional commits](https://www.conventionalcommits.org/en/v1.0.0/)
- Document your functions thoroughly

## Testing
I have profited from the works of gemartin99, a fellow student who developed a wonderful [tool](https://github.com/gemartin99/Push-Swap-Tester).

I also have some randomly generated numbers and the tester in `/tests`

`Makefile` has a test rule that will move the push_swap binary file and run `push_swap_test.sh`. Both need to be in the root directory of the project.

`small_stack_utils.sh` generates series of numbers and gives them to push_swap as an argument.

