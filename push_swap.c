#include "push_swap.h"

int main(int argc, char *argv[])
{
    t_list *stack_A;
    t_list *stack_B;
 
    if(argc < 2)
        return 0;
    stack_A = NULL;
    stack_B = NULL;

    if(ft_check_args(&stack_A,argv) == 0 || ft_check_duplicate(stack_A) == 0)
    {
        write(2,"ERROR\n",6);
        return 0;
    }
}