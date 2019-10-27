#include "./../../inc/ft.h"
#include "./../../inc/ft_list.h"

void ft_lstdelone(t_list *lst, void (*del)(void*))
{
    if (!lst)
        return ;
    (*del)(lst->content);
    free(lst);
    lst = NULL;
}