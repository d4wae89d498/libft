/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoll.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 16:08:46 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/28 18:27:15 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft.h"


long long			ft_atoll(const char *str)
{
	int			sign;
	long long		nbr;
	long long		tmp;

	sign = 1;
	while (ft_isspace(*str) && (str++ || 1))
		;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	nbr = 0;
	str -= 1;
	while (ft_isdigit((int)*++str) && ((tmp = nbr * 10 + *str - '0') || 1))
		if (tmp > 2147483648 && sign == -1)
			return (0);
		else if (tmp > 2147483647 && sign == 1)
			return (-1);
		else
			nbr = tmp;
	return (sign * nbr);
}
