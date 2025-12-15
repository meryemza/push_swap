#include "push_swap.h"


int	ft_atoi(const char *str)
{
	int				i;
	int				s;
	unsigned long	n;

	i = 0;
	s = 1;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n * s);
}

int ft_check_args(t_list **stack,char *str)
{
    int i ;

    i = 0;

    if(str[i] == '-' || str[i] == '+' )
            i++;
        if(str[i] == '\0')
            return 0;
    while(str[i])
    {
        if(str[i] >= '0' && str[i] <= '9')
            i++;
        else
            return 0;
    }

}
int ft_check_duplicate(t_list **stack)
{

}

