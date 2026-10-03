#include <criterion/criterion.h>
#include <unistd.h>
#include "libft.h"

/* ft_putchar_fd */

Test(ft_putchar_fd, basic)
{
	int		fd[2];
	char	buf[2];

	pipe(fd);
	ft_putchar_fd('A', fd[1]);
	close(fd[1]);
	read(fd[0], buf, 1);
	buf[1] = '\0';
	close(fd[0]);
	cr_assert_eq(buf[0], 'A');
}

Test(ft_putchar_fd, newline)
{
	int		fd[2];
	char	buf[2];

	pipe(fd);
	ft_putchar_fd('\n', fd[1]);
	close(fd[1]);
	read(fd[0], buf, 1);
	buf[1] = '\0';
	close(fd[0]);
	cr_assert_eq(buf[0], '\n');
}

/* ft_putstr_fd */

Test(ft_putstr_fd, basic)
{
	int		fd[2];
	char	buf[6];

	pipe(fd);
	ft_putstr_fd("hello", fd[1]);
	close(fd[1]);
	read(fd[0], buf, 5);
	buf[5] = '\0';
	close(fd[0]);
	cr_assert_str_eq(buf, "hello");
}

Test(ft_putstr_fd, empty_string)
{
	int		fd[2];
	char	buf[1];

	pipe(fd);
	ft_putstr_fd("", fd[1]);
	close(fd[1]);
	buf[0] = '\0';
	close(fd[0]);
	cr_assert_str_eq(buf, "");
}

/* ft_putendl_fd */

Test(ft_putendl_fd, basic)
{
	int		fd[2];
	char	buf[7];

	pipe(fd);
	ft_putendl_fd("hello", fd[1]);
	close(fd[1]);
	read(fd[0], buf, 6);
	buf[6] = '\0';
	close(fd[0]);
	cr_assert_str_eq(buf, "hello\n");
}

/* ft_putnbr_fd */

Test(ft_putnbr_fd, positive)
{
	int		fd[2];
	char	buf[3];

	pipe(fd);
	ft_putnbr_fd(42, fd[1]);
	close(fd[1]);
	read(fd[0], buf, 2);
	buf[2] = '\0';
	close(fd[0]);
	cr_assert_str_eq(buf, "42");
}

Test(ft_putnbr_fd, negative)
{
	int		fd[2];
	char	buf[4];

	pipe(fd);
	ft_putnbr_fd(-42, fd[1]);
	close(fd[1]);
	read(fd[0], buf, 3);
	buf[3] = '\0';
	close(fd[0]);
	cr_assert_str_eq(buf, "-42");
}

Test(ft_putnbr_fd, zero)
{
	int		fd[2];
	char	buf[2];

	pipe(fd);
	ft_putnbr_fd(0, fd[1]);
	close(fd[1]);
	read(fd[0], buf, 1);
	buf[1] = '\0';
	close(fd[0]);
	cr_assert_str_eq(buf, "0");
}

Test(ft_putnbr_fd, int_min)
{
	int		fd[2];
	char	buf[12];

	pipe(fd);
	ft_putnbr_fd(-2147483648, fd[1]);
	close(fd[1]);
	read(fd[0], buf, 11);
	buf[11] = '\0';
	close(fd[0]);
	cr_assert_str_eq(buf, "-2147483648");
}
