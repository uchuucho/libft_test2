#include <criterion/criterion.h>
#include "libft.h"

/* ft_lsadd_back */

Test(ft_lstadd_back, empty_list)
{
  t_list  *lst;
  t_list  *node;

  lst = NULL;
  node = ft_lstnew("Hello");
  ft_lstadd_back(&lst, node);
  cr_assert_str_eq(lst->content, "Hello");
  free(lst);
}

Test(ft_lstadd_back, existing_list)
{
	t_list	*lst;
	t_list	*second;

	lst = ft_lstnew("first");
	second = ft_lstnew("second");
	ft_lstadd_back(&lst, second);
	cr_assert_str_eq(lst->next->content, "second");
	free(lst);
	free(second);
}

Test(ft_lstadd_back, null_list)
{
    t_list  *lst = NULL;
    t_list  *node = ft_lstnew("hello");

    ft_lstadd_back(&lst, node);
    cr_assert_eq(lst, node); // normal call, nothing to assert beyond no crash
    free(node);
}


/* ft_lstadd_front */

Test(ft_lstadd_front, empty_list)
{
	t_list	*lst;
	t_list	*node;

	lst = NULL;
	node = ft_lstnew("hello");
	ft_lstadd_front(&lst, node);
	cr_assert_str_eq(lst->content, "hello");
	free(lst);
}

Test(ft_lstadd_front, existing_list)
{
	t_list	*lst;
	t_list	*node;

	lst = ft_lstnew("second");
	node = ft_lstnew("first");
	ft_lstadd_front(&lst, node);
	cr_assert_str_eq(lst->content, "first");
	cr_assert_str_eq(lst->next->content, "second");
	free(node->next);
	free(node);
}

Test(ft_lstadd_front, null_node)
{
    t_list  *lst;

    lst = ft_lstnew("hello");
    ft_lstadd_front(&lst, NULL);
    cr_assert_str_eq(lst->content, "hello");
    free(lst);
}

/* ft_lstclear */

Test(ft_lstclear, basic)
{
	t_list	*lst;

	lst = ft_lstnew(strdup("one"));
	lst->next = ft_lstnew(strdup("two"));
	lst->next->next = ft_lstnew(strdup("three"));
	ft_lstclear(&lst, free);
	cr_assert_null(lst);
}

Test(ft_lstclear, null_list)
{
	ft_lstclear(NULL, free);
}


/* ft_lstdelone */

Test(ft_lstdelone, basic)
{
	t_list	*node;

	node = ft_lstnew(strdup("hello"));
	ft_lstdelone(node, free);
}

Test(ft_lstdelone, null_del)
{
	t_list	*node;

	node = ft_lstnew("hello");
	ft_lstdelone(node, NULL);
}

Test(ft_lstdelone, null_node)
{
    ft_lstdelone(NULL, free);
}


/* ft_lstiter */

static void	upcase(void *content)
{
	char	*s;
	int		i;

	s = (char *)content;
	i = 0;
	while (s[i])
	{
		s[i] = ft_toupper(s[i]);
		i++;
	}
}

Test(ft_lstiter, basic)
{
	t_list	*lst;

	lst = ft_lstnew(strdup("hello"));
	lst->next = ft_lstnew(strdup("world"));
	ft_lstiter(lst, upcase);
	cr_assert_str_eq(lst->content, "HELLO");
	cr_assert_str_eq(lst->next->content, "WORLD");
	ft_lstclear(&lst, free);
}

Test(ft_lstiter, null_list)
{
	ft_lstiter(NULL, upcase);
}

Test(ft_lstiter, null_function)
{
    t_list  *lst;

    lst = ft_lstnew("hello");
    ft_lstiter(lst, NULL);
    free(lst);
}

/* ft_lstmap */

static void *duplicate(void *content)
{
  return (strdup((char *)content));
}

Test(ft_lstmap, basic)
{
  t_list *lst;
  t_list *result;

  lst = ft_lstnew(strdup("Hello"));
  lst->next = ft_lstnew(strdup("world"));
  result = ft_lstmap(lst, duplicate, free);
  cr_assert_not_null(result);
  cr_assert_str_eq(result->content, "Hello");
  cr_assert_str_eq(result->next->content, "world");
  ft_lstclear(&lst, free);
  ft_lstclear(&result,free);
}

Test(ft_lstmap, null_list)
{
  cr_assert_null(ft_lstmap(NULL, duplicate, free));
}

Test(ft_lstmap, null_function)
{
  t_list *lst;

  lst = ft_lstnew(strdup("Hello"));
  cr_assert_null(ft_lstmap(lst, NULL, free));
  ft_lstclear(&lst, free);
}

Test(ft_lstmap, null_del)
{
  t_list *lst;

    lst = ft_lstnew(strdup("Hello"));
    ft_lstmap(lst, duplicate, NULL);
    ft_lstclear(&lst, free);
}

Test(ft_lstmap, null_del_list_untouched)
{
    t_list  *lst;

    lst = ft_lstnew(strdup("Hello"));
    lst->next = ft_lstnew(strdup("world"));
    ft_lstmap(lst, duplicate, NULL);
    cr_assert_str_eq(lst->content, "Hello");
    cr_assert_str_eq(lst->next->content, "world");
    ft_lstclear(&lst, free);
}

/* ft_lstlast */

Test(ft_lstlast, null_list)
{
  cr_assert_null(ft_lstlast(NULL));
}

Test(ft_lstlast, single_node)
{
  t_list *node;

  node = ft_lstnew("hello");
  cr_assert_eq(ft_lstlast(node), node);
  free(node);
}

Test (ft_lstlast, multiple_nodes)
{
  t_list *head;
  t_list *last;

  head = ft_lstnew("first");
  head->next = ft_lstnew("middle");
  last = ft_lstnew("last");
  head->next->next = last;
  cr_assert_eq(ft_lstlast(head), last);
  free(head->next);
  free(head);
  free(last);
}
/* ft_lstnew */

Test(ft_lstnew, basic)
{
  t_list *node;

  node = ft_lstnew("Hello");
  cr_assert_not_null(node);
  cr_assert_str_eq(node->content, "Hello");
  cr_assert_null(node->next);
  free(node);
}

Test(ft_lstnew, null_content)
{
  t_list *node;

  node = ft_lstnew(NULL);
  cr_assert_not_null(node);
  cr_assert_null(node->content);
  cr_assert_null(node->next);
  free(node);
}

Test(ft_lstnew, int_content)
{
  t_list *node;
  int n;

  n = 42;
  node = ft_lstnew(&n);
  cr_assert_not_null(node);
  cr_assert_eq(*(int*)node->content, 42);
  cr_assert_null(node->next);
  free(node);
}


/* ft_lstsize */
Test(ft_lstsize, null_list)
{
  cr_assert_eq(ft_lstsize(NULL), 0);
}

Test(ft_lstsize, single_node)
{
  t_list *node;

  node = ft_lstnew("hello");
  cr_assert_eq(ft_lstsize(node), 1);
  free(node);
}

Test(ft_lstsize, multiple_nodes)
{
  t_list *head;
  t_list *second;
  t_list *third;

  head = ft_lstnew("one");
  second = ft_lstnew("two");
  third = ft_lstnew("three");

  head->next = second;
  second->next = third;

  cr_assert_eq(ft_lstsize(head), 3);
  free(head);
  free(second);
  free(third);
}


