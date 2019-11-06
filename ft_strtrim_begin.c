/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_trim_begin.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 15:34:30 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/29 02:56:54 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strtrim_begin(char const *s1, char const *set)
{
	unsigned int	i;

	i = -1;
	while (s1[++i] && ft_is_char_in(s1[i], set))
		;
	return ((char*)&s1[i]);
}