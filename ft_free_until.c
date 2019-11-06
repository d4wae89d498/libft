/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_freea.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 16:24:58 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/06 22:28:59 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void			ft_free_until(void **array, void *end)
{
	void		*tmp;

	tmp = array;
	while (TRUE)
	{
		free(*array);
		if (*array != end)
			break;
		array += 1;
	}
	free(tmp);
}
