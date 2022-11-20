#include "ft_printf.h"

size_t	ft_precision_charcount(const double nb, const size_t precision)
{
	size_t		char_count;
	double		nb_cpy;

	char_count = 0;
	if (precision)
		char_count += precision + 1;
	if (nb < 0 || ft_isnegativezero(nb))
	{
		char_count++;
		nb_cpy = -nb;
	}
	else
		nb_cpy = nb;
	if ((long long int)nb_cpy == 0)
		return (++char_count);
	while (nb_cpy >= 1)
	{
		nb_cpy /= 10.0;
		char_count++;
	}
	return (char_count);
}
