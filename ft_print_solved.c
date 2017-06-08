#include "libfil.h"

void	ft_print_solved(t_type3 s)
{
	s.nb_tetra = 0;
	while (s.nb_tetra < s.sq_s)
	{
		ft_putstr(s.square[s.nb_tetra]);
		s.nb_tetra++;
	}
}
