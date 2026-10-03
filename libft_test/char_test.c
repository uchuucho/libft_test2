#include <criterion/criterion.h>
#include "libft.h"

/*ft_isalnum*/

Test(ft_isalnum, letter)
{
  cr_assert(ft_isalnum('a'));
  cr_assert(ft_isalnum('z'));
}

Test(ft_isalnum, digit)
{
  cr_assert(ft_isalnum('0'));
  cr_assert(ft_isalnum('9'));
}

Test(ft_isalnum, special_char)
{
  cr_assert_not(ft_isalnum('!'));
  cr_assert_not(ft_isalnum(' '));
}

/*ft_isalpha*/

Test(ft_isalpha, lowercase)
{
  cr_assert(ft_isalpha('a'));
  cr_assert(ft_isalnum('z'));
}

Test(ft_isalpha, uppercase)
{
  cr_assert(ft_isalpha('A'));
  cr_assert(ft_isalpha('Z'));
}

Test(ft_isalpha, digit)
{
  cr_assert_not(ft_isalpha('9'));
}

Test(ft_isalpha, special_char)
{
  cr_assert_not(ft_isalpha('!'));
}

/*ft_isascii*/

Test(ft_isascii, valid)
{
  cr_assert(ft_isascii(0));
  cr_assert(ft_isascii(127));
  cr_assert(ft_isascii('a'));
}

Test(ft_isascii, invalid)
{
  cr_assert_not(ft_isascii(128));
  cr_assert_not(ft_isascii(-1));
}

/*ft_isdigit*/

Test(ft_isdigit, digit)
{
  cr_assert(ft_isdigit('0'));
  cr_assert(ft_isdigit('9'));
}

Test(ft_isdigit, letter)
{
  cr_assert_not(ft_isdigit('a'));
}

Test(ft_isdigit, special_char)
{
  cr_assert_not(ft_isdigit('!'));
}

/*ft_isprint*/

Test(ft_isprint, printable)
{
  cr_assert(ft_isprint(' '));
  cr_assert(ft_isprint('~'));
  cr_assert(ft_isprint('a'));
}

/*ft_tolower*/

Test(ft_tolower, uppercase)
{
  cr_assert_eq(ft_tolower('A'), 'a');
  cr_assert_eq(ft_tolower('Z'), 'z');
}

Test(ft_tolower, already_in_lowercase)
{
  cr_assert_eq(ft_tolower('a'), 'a');
  cr_assert_eq(ft_tolower('z'), 'z');
}

Test(ft_tolower, non_alpha)
{
  cr_assert_eq(ft_tolower('1'), '1');
  cr_assert_eq(ft_tolower(' '), ' ');
  cr_assert_eq(ft_tolower('!'), '!');
}

/*ft_toupper*/

Test(ft_toupper, lowercase)
{
  cr_assert_eq(ft_toupper('a'), 'A');
  cr_assert_eq(ft_toupper('z'), 'Z');
}

Test(ft_toupper, uppercase)
{
  cr_assert_eq(ft_toupper('a'), 'A');
  cr_assert_eq(ft_toupper('z'), 'Z');
}

Test(ft_toupper, already_in_uppercase)
{
  cr_assert_eq(ft_toupper('A'), 'A');
  cr_assert_eq(ft_toupper('Z'), 'Z');
}

Test(ft_toupper, non_alpha)
{
  cr_assert_eq(ft_toupper('1'), '1');
  cr_assert_eq(ft_toupper(' '), ' ');
  cr_assert_eq(ft_toupper('!'), '!');
}
