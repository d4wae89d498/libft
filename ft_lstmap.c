/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mfaussur <mfaussur@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/28 15:24:22 by mfaussur     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/17 15:19:25 by mfaussur    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "ft_list.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*bckp;
	t_list		*out;
	t_list		*it;

	if (!lst)
		return (lst);
	if (!(out = ft_lstnew(f(lst->content))))
		return (NULL);
	it = lst;
	bckp = out;
	while (1)
	{
		if (!(out->next = ft_lstnew(f(it->content))))
		{
			ft_lstclear(&bckp, del);
			return (NULL);
		}
		it = it->next;
		out = out->next;
		if (!it || !out)
			break ;
	}
	return (bckp);
}
