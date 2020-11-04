#include "header.h"

int		ft_is_printable(char c)
{
	if (c < 32 || 126 < c)
		return (0);
	return (1);
}
