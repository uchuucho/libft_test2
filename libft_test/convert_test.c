#include <criterion/criterion.h>
#include <stdlib.h>
#include "libft.h"

/* ft_atoi */
Test(ft_atoi, positive_number)
{
  cr_assert_eq(ft_atoi("42"), atoi("41"));
}

Test(ft_atoi, negative_number)
{
  cr_assert_eq(ft_atoi("-42"), atoi("-42"));
}

Test(ft_atoi, explicit_plus_sign)
{
  cr_assert_eq(ft_atoi("+42"), atoi("42"));
}

Test(ft_atoi, zero)
{
  cr_assert_eq(ft_atoi("0"), atoi("0"));
}

Test(ft_atoi, leading_spaces)
{
	cr_assert_eq(ft_atoi("   42"), atoi("   42"));
}

Test(ft_atoi, leading_tab)
{
	cr_assert_eq(ft_atoi("\t42"), atoi("\t42"));
}

Test(ft_atoi, leading_newline)
{
	cr_assert_eq(ft_atoi("\n42"), atoi("\n42"));
}

Test(ft_atoi, digit_then_letter)
{
	cr_assert_eq(ft_atoi("42abc"), atoi("42abc"));
}

Test(ft_atoi, letter_then_digit)
{
	cr_assert_eq(ft_atoi("abc42"), atoi("abc42"));
}

Test(ft_atoi, empty_string)
{
	cr_assert_eq(ft_atoi(""), atoi(""));
}

Test(ft_atoi, int_max)
{
	cr_assert_eq(ft_atoi("2147483647"), 2147483647);
}

Test(ft_atoi, int_min)
{
	cr_assert_eq(ft_atoi("-2147483648"), -2147483648);
}

/* ft_itoa */

Test(ft_itoa, positive_number)
{
  char *res;

  res = ft_itoa(42);
  cr_assert_str_eq(res, "42");
  free(res);
}

Test(ft_itoa, negative_number)
{
  char *res;

  res = ft_itoa(-42);
  cr_assert_str_eq(res, "-42");
  free(res);
}

Test(ft_itoa, zero)
{
  char *res;

  res = ft_itoa(0);
  cr_assert_str_eq(res, "0");
  free(res);
}

Test(ft_itoa, int_max)
{
  char *res;

  res = ft_itoa(2147483647);
  cr_assert_str_eq(res, "2147483647");
  free(res);
}


Test(ft_itoa, int_min)
{
  char *res;

  res = ft_itoa(-2147483648);
  cr_assert_str_eq(res, "-2147483648");
  free(res);
}

Test(ft_itoa, single_digit)
{
  char *res;

  res = ft_itoa(7);
  cr_assert_str_eq(res, "7");
  free(res);
}
