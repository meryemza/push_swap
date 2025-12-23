                                            Push_swap

*This project has been created as part of the 42 curriculum by <mezahir>*

1 - Description Section :

    A- Project Summary :
        *Push_Swap* is a program developed as part of the 42 curriculum.  
        Its goal is to sort a list of integers using a limited set of operations ("sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr").
        The program generates the shortest possible sequence of instructions to sort the stack efficiently.  
        A <bonus> program, *checker*, verifies that the output instructions correctly sort the stack or not ,The program outputs OK if the stack is sorted, KO if it's not sorted or Error in case of any invalid input or instruction.

    B- Project Steps :
        1- Parse input arguments: validate integers, check for duplicates, and split arguments if needed.  
        2- Implement operations: code all the instructions ("sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr").
        3- Fill stack: take the numbers from `argv` and store them in a linked list representing stack A.
        4- Sorting algorithm: implement logic for small (2–5 numbers) and large (100–500 numbers) stacks.
        5- Bonus checker: read instructions from stdin, apply them on the stacks, and output `OK` if stack sorted  or `KO` if not sorted. 

2 - Instructions :

    First, compile the project using the "make" command to generate the push_swap executable.
    To compile the bonus part, run "make bonus", which will generate the checker executable.

    To run push_swap, provide a list of integers as arguments, "./push_swap 2 4 0 9"
    The program will output a sequence of instructions that sorts stack A.

    To run checker, provide the same list of integers as arguments and pass the instructions through standard input' , " ./push_swap 2 4 0 9 | ./checker 2 4 0 9 "

    After executing all instructions, checker prints OK if stack A is sorted and stack B is empty.
    Otherwise, it prints KO.
    If an error occurs (invalid arguments, duplicates, or unknown instructions), the program prints Error.
    
3 - Resources :
    - https://www.scribd.com/document/636999723/Untitled
    - https://en.wikipedia.org/wiki/Sorting_algorithm
    - https://www.geeksforgeeks.org/dsa/lifo-principle-in-stack/
    - https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a
    -   ai was used at the beginning of the project to help organize the work, divide the project into      smaller parts, and clarify the ideas and steps.  
    ai was also used as a learning support to understand concepts . 

4 - Exemples :

./push_swap 3 2 1
sa
ra

./push_swap "3 2 1"
sa
ra

./push_swap 3 2 a
Error

 ./push_swap 3 2 3
Error

./push_swap 2147483648 3 2
Error



