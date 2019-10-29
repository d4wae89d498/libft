/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdelone.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 15:29:28 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/28 18:28:47 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft.h"
#include "ft_list.h"

void		ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	(*del)(lst->content);
	free(lst);
	lst = NULL;
}