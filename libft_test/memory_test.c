#include <criterion/criterion.h>
#include "libft.h"
#include <string.h>

/* ft_bzero */

Test(ft_bzero, zeros_buffer)
{
  char buff[5] = "hello";

  ft_bzero(buff, 5);
  cr_assert_eq(buff[0], 0);
  cr_assert_eq(buff[1], 0);
  cr_assert_eq(buff[2], 0);
  cr_assert_eq(buff[3], 0);
  cr_assert_eq(buff[4], 0);
}

Test(ft_bzero, partial_zero)
{
  char buff[5] = "hello";

  ft_bzero(buff, 3);
  cr_assert_eq(buff[0], 0);
  cr_assert_eq(buff[1], 0);
  cr_assert_eq(buff[2], 0);
  cr_assert_eq(buff[3], 'l');
  cr_assert_eq(buff[4], 'o');
}

Test(ft_bzero, zero_length)
{
  char buff[5] = "hello";

  ft_bzero(buff, 0);
  cr_assert_eq(buff[0], 'h');
}

/* ft_calloc */

Test(ft_calloc, basic_allocation)
{
  int *arr;

  arr = ft_calloc(5, sizeof(int));
  cr_assert_not_null(arr);
  cr_assert_eq(arr[0], 0);
  cr_assert_eq(arr[1], 0);
  cr_assert_eq(arr[2], 0);
  cr_assert_eq(arr[3], 0);
  cr_assert_eq(arr[4], 0);
  free(arr);
}

Test(ft_calloc, zero_nmemb)
{
    void *ptr = ft_calloc(0, sizeof(int));
    cr_assert_not_null(ptr);
    free(ptr);
}

Test(ft_calloc, zero_size)
{
    void *ptr = ft_calloc(5, 0);
    cr_assert_not_null(ptr);
    free(ptr);
}

Test(ft_calloc, overflow)
{
  cr_assert_null(ft_calloc((size_t)-1, 2));
}

Test(ft_calloc, single_element)
{
  char *c;

  c = ft_calloc(1, sizeof(char));
  cr_assert_not_null(c);
  cr_assert_eq(*c, 0);
  free(c);
}

/* ft_memchr */

Test(ft_memchr, found)
{
  char buff[] = "Hello";
  cr_assert_eq(ft_memchr(buff, 'l', 5), memchr(buff, 'l', 5));
}

Test(ft_memchr, not_found)
{
  char buff[] = "hello";
  cr_assert_null(ft_memchr(buff, 'z', 5));
}

Test(ft_memchr, zero_length)
{
  char buff[] = "Hello";

  cr_assert_null(ft_memchr(buff, 'H', 0));
}

/* ft_memcmp */

Test(ft_memcmp, equal)
{
  cr_assert_eq(ft_memcmp("hello", "hello", 5), 0);
}

Test(ft_memcmp, less_than)
{
  cr_assert(ft_memcmp("abc", "abd", 3) < 0);
}

Test(ft_memcmp, greater_than)
{
  cr_assert(ft_memcmp("abc", "aaa", 3) > 0);
}

Test(ft_memcmp, zero_length)
{
  cr_assert_eq(ft_memcmp("abc", "sije", 0), 0);
}

Test(ft_memcmp, partial)
{
  cr_assert_eq(ft_memcmp("hello", "helXX", 3), 0);
}

/* ft_memcpy */

Test(ft_memcpy, basic)
{
  char dst[6];
  char src[] = "Hello";

  ft_memcpy(dst, src, 5);
  dst[5] = '\0';
  cr_assert_str_eq(dst, "Hello");
}

Test(ft_memcpy, zero_length)
{
  char dst[] = "hello";
  char src[] = "world";

  ft_memcpy(dst, src, 0);
  cr_assert_str_eq(dst, "hello");
}

Test(ft_memcpy, partial)
{
  char dst[] = "hello";

  ft_memcpy(dst, "world", 3);
  cr_assert_str_eq(dst, "worlo");
}

/* ft_memmove */
Test(ft_memmove, basic)
{
  char dst[6];
  char src[] = "hello";

  ft_memmove(dst, src, 5);
  dst[5] = '\0';
  cr_assert_str_eq(dst, "hello");
}

Test(ft_memmove, overlap_forward)
{
  char buff[] = "hello";

  ft_memmove(buff + 1, buff, 4);
  cr_assert_str_eq(buff, "hhell");
}

Test(ft_memmove, overlap_backward)
{
  char buff[] = "Hello";
  ft_memmove(buff, buff+1, 4);
  cr_assert_str_eq(buff, "elloo");
}

Test(ft_memmove, zero_length)
{
  char dst[] = "hello";
  ft_memmove(dst, "world", 0);
  cr_assert_str_eq(dst, "hello");
}

/* ft_memset */
Test(ft_memset, basic)
{
  char buff[6];

  ft_memset(buff, 'a', 5);
  buff[5] = '\0';
  cr_assert_str_eq(buff, "aaaaa");
}

Test(ft_memset, zero_length)
{
  char buff[] = "Hello";

  ft_memset(buff, 'x', 0);
  cr_assert_str_eq(buff, "Hello");

}

Test(ft_memset, partial)
{
  char buff[] = "Hello";

  ft_memset(buff, 'x', 3);
  cr_assert_str_eq(buff, "xxxlo");
}

Test(ft_memset, zero_byte)
{
  char buff[] = "Hello";

  ft_memset(buff, 0,5);
  cr_assert_eq(buff[0], 0);
  cr_assert_eq(buff[4], 0);
}
