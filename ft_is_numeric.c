#include "header.h"

int		ft_is_numeric(char c)
{
	if (c < '0' || '9' < c)
		return (0);
	return (1);
}