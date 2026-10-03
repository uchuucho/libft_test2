#include <criterion/criterion.h>
#include <string.h>
#include "libft.h"

/* ft_strlen */

Test(ft_strlen, basic)
{
	cr_assert_eq(ft_strlen("hello"), 5);
}

Test(ft_strlen, empty_string)
{
	cr_assert_eq(ft_strlen(""), 0);
}

Test(ft_strlen, single_char)
{
	cr_assert_eq(ft_strlen("a"), 1);
}

/* ft_strchr */

Test(ft_strchr, found)
{
	char	*s;

	s = "hello";
	cr_assert_eq(ft_strchr(s, 'l'), strchr(s, 'l'));
}

Test(ft_strchr, not_found)
{
	cr_assert_null(ft_strchr("hello", 'z'));
}

Test(ft_strchr, find_null_terminator)
{
	char	*s;

	s = "hello";
	cr_assert_eq(ft_strchr(s, '\0'), s + 5);
}

Test(ft_strchr, first_occurrence)
{
	char	*s;

	s = "hello";
	cr_assert_eq(ft_strchr(s, 'l'), s + 2);
}

/* ft_strrchr */

Test(ft_strrchr, found)
{
	char	*s;

	s = "hello";
	cr_assert_eq(ft_strrchr(s, 'l'), strrchr(s, 'l'));
}

Test(ft_strrchr, not_found)
{
	cr_assert_null(ft_strrchr("hello", 'z'));
}

Test(ft_strrchr, last_occurrence)
{
	char	*s;

	s = "hello";
	cr_assert_eq(ft_strrchr(s, 'l'), s + 3);
}

Test(ft_strrchr, find_null_terminator)
{
	char	*s;

	s = "hello";
	cr_assert_eq(ft_strrchr(s, '\0'), s + 5);
}

/* ft_strncmp */

Test(ft_strncmp, equal)
{
	cr_assert_eq(ft_strncmp("hello", "hello", 5), 0);
}

Test(ft_strncmp, less_than)
{
	cr_assert(ft_strncmp("abc", "abd", 3) < 0);
}

Test(ft_strncmp, greater_than)
{
	cr_assert(ft_strncmp("abd", "abc", 3) > 0);
}

Test(ft_strncmp, zero_length)
{
	cr_assert_eq(ft_strncmp("abc", "xyz", 0), 0);
}

Test(ft_strncmp, partial)
{
	cr_assert_eq(ft_strncmp("hello", "helXX", 3), 0);
}

/* ft_strdup */

Test(ft_strdup, basic)
{
	char	*res;

	res = ft_strdup("hello");
	cr_assert_str_eq(res, "hello");
	free(res);
}

Test(ft_strdup, empty_string)
{
	char	*res;

	res = ft_strdup("");
	cr_assert_str_eq(res, "");
	free(res);
}

Test(ft_strdup, independence)
{
	char	*res;
	char	src[] = "hello";

	res = ft_strdup(src);
	src[0] = 'X';
	cr_assert_str_eq(res, "hello");
	free(res);
}

/* ft_strlcpy */

Test(ft_strlcpy, basic)
{
	char	dst[10];
	size_t	ret;

	ret = ft_strlcpy(dst, "hello", 10);
	cr_assert_str_eq(dst, "hello");
	cr_assert_eq(ret, 5);
}

Test(ft_strlcpy, truncation)
{
	char	dst[4];
	size_t	ret;

	ret = ft_strlcpy(dst, "hello", 4);
	cr_assert_str_eq(dst, "hel");
	cr_assert_eq(ret, 5);
}

Test(ft_strlcpy, zero_size)
{
	char	dst[] = "hello";
	size_t	ret;

	ret = ft_strlcpy(dst, "worldddd", 0);
	cr_assert_str_eq(dst, "hello");
	cr_assert_eq(ret, 8);
}

/* ft_strlcat */

Test(ft_strlcat, basic)
{
	char	dst[11] = "hello";
	size_t	ret;

	ret = ft_strlcat(dst, " world", 11);
	cr_assert_str_eq(dst, "hello worl");
	cr_assert_eq(ret, 11);
}

Test(ft_strlcat, no_truncation)
{
	char	dst[12] = "hello";
	size_t	ret;

	ret = ft_strlcat(dst, " world", 12);
	cr_assert_str_eq(dst, "hello world");
	cr_assert_eq(ret, 11);
}

Test(ft_strlcat, zero_size)
{
	char	dst[] = "hello";
	size_t	ret;

	ret = ft_strlcat(dst, "world", 0);
	cr_assert_eq(ret, 5);
}

/* ft_strjoin */

Test(ft_strjoin, basic)
{
	char	*res;

	res = ft_strjoin("hello", " world");
	cr_assert_str_eq(res, "hello world");
	free(res);
}

Test(ft_strjoin, empty_strings)
{
	char	*res;

	res = ft_strjoin("", "");
	cr_assert_str_eq(res, "");
	free(res);
}

Test(ft_strjoin, one_empty)
{
	char	*res;

	res = ft_strjoin("hello", "");
	cr_assert_str_eq(res, "hello");
	free(res);
}

/* ft_substr */

Test(ft_substr, basic)
{
	char	*res;

	res = ft_substr("hello world", 6, 5);
	cr_assert_str_eq(res, "world");
	free(res);
}

Test(ft_substr, start_beyond_length)
{
	char	*res;

	res = ft_substr("hello", 10, 5);
	cr_assert_str_eq(res, "");
	free(res);
}

Test(ft_substr, len_beyond_end)
{
	char	*res;

	res = ft_substr("hello", 3, 100);
	cr_assert_str_eq(res, "lo");
	free(res);
}

Test(ft_substr, zero_len)
{
	char	*res;

	res = ft_substr("hello", 0, 0);
	cr_assert_str_eq(res, "");
	free(res);
}

/* ft_strtrim */

Test(ft_strtrim, basic)
{
	char	*res;

	res = ft_strtrim("  hello  ", " ");
	cr_assert_str_eq(res, "hello");
	free(res);
}

Test(ft_strtrim, no_trim_needed)
{
	char	*res;

	res = ft_strtrim("hello", " ");
	cr_assert_str_eq(res, "hello");
	free(res);
}

Test(ft_strtrim, all_trimmed)
{
	char	*res;

	res = ft_strtrim("   ", " ");
	cr_assert_str_eq(res, "");
	free(res);
}

Test(ft_strtrim, multiple_chars_in_set)
{
	char	*res;

	res = ft_strtrim("xyheloxy", "xy");
	cr_assert_str_eq(res, "helo");
	free(res);
}

/* ft_strnstr */

Test(ft_strnstr, found)
{
	cr_assert_str_eq(ft_strnstr("hello world", "world", 11), "world");
}

Test(ft_strnstr, not_found)
{
	cr_assert_null(ft_strnstr("hello", "world", 5));
}

Test(ft_strnstr, needle_beyond_len)
{
	cr_assert_null(ft_strnstr("hello world", "world", 5));
}

Test(ft_strnstr, empty_needle)
{
	cr_assert_str_eq(ft_strnstr("hello", "", 5), "hello");
}

Test(ft_strnstr, zero_len)
{
	cr_assert_null(ft_strnstr("hello", "hello", 0));
}

/* ft_striteri */

static void	add_index(unsigned int i, char *c)
{
	*c += i;
}

Test(ft_striteri, basic)
{
	char	s[] = "aaa";

	ft_striteri(s, add_index);
	cr_assert_eq(s[0], 'a');
	cr_assert_eq(s[1], 'b');
	cr_assert_eq(s[2], 'c');
}

Test(ft_striteri, empty_string)
{
	char	s[] = "";

	ft_striteri(s, add_index);
	cr_assert_str_eq(s, "");
}

/* ft_strmapi */

static char	to_upper_map(unsigned int i, char c)
{
	(void)i;
	return (ft_toupper(c));
}

Test(ft_strmapi, basic)
{
	char	*res;

	res = ft_strmapi("hello", to_upper_map);
	cr_assert_str_eq(res, "HELLO");
	free(res);
}

Test(ft_strmapi, empty_string)
{
	char	*res;

	res = ft_strmapi("", to_upper_map);
	cr_assert_str_eq(res, "");
	free(res);
}

/* ft_split */

Test(ft_split, basic)
{
	char	**res;

	res = ft_split("hello world foo", ' ');
	cr_assert_str_eq(res[0], "hello");
	cr_assert_str_eq(res[1], "world");
	cr_assert_str_eq(res[2], "foo");
	cr_assert_null(res[3]);
	free(res[0]);
	free(res[1]);
	free(res[2]);
	free(res);
}

Test(ft_split, multiple_delimiters)
{
	char	**res;

	res = ft_split("hello   world", ' ');
	cr_assert_str_eq(res[0], "hello");
	cr_assert_str_eq(res[1], "world");
	cr_assert_null(res[2]);
	free(res[0]);
	free(res[1]);
	free(res);
}

Test(ft_split, no_delimiter)
{
	char	**res;

	res = ft_split("hello", ' ');
	cr_assert_str_eq(res[0], "hello");
	cr_assert_null(res[1]);
	free(res[0]);
	free(res);
}

Test(ft_split, empty_string)
{
	char	**res;

	res = ft_split("", ' ');
	cr_assert_not_null(res);
	cr_assert_null(res[0]);
	free(res);
}

Test(ft_split, only_delimiters)
{
	char	**res;

	res = ft_split("   ", ' ');
	cr_assert_not_null(res);
	cr_assert_null(res[0]);
	free(res);
}
