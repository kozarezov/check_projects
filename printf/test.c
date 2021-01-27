#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "libftprintf.h"

void	*ft_memset1(void *dest, int c, size_t n)
{
	unsigned char *str;

	str = dest;
	while (n--)
		*str++ = (unsigned char)c;
	return (dest);
}

void	*ft_calloc1(size_t num, size_t size)
{
	void *arr;

	arr = malloc(num * size);
	if (arr == NULL)
		return (NULL);
	else
		ft_memset1(arr, 0, num * size);
	return (arr);
}

size_t	ft_strlen1(const char *str)
{
	int i;

	i = 0;
	while (*str != 0)
	{
		i++;
		str++;
	}
	return (i);
}

size_t	ft_strlcat1(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t len_s;
	size_t len_d;

	i = 0;
	len_d = ft_strlen1(dest);
	len_s = ft_strlen1(src);
	if (size > len_d)
	{
		while (*src != '\0' && ((len_d + i) != (size - 1)))
			dest[len_d + i++] = *src++;
	}
	if (size)
		dest[len_d + i] = '\0';
	return (len_s + (size < len_d ? size : len_d));
}

char	*ft_strjoin1(char const *s1, char const *s2)
{
	char		*str;
	size_t		len_s;

	if (!s1)
		return (0);
	len_s = ft_strlen1(s1) + ft_strlen1(s2);
	if ((str = (char *)ft_calloc1(1, len_s + 1)))
	{
		ft_strlcat1(str, s1, len_s + 1);
		ft_strlcat1(str, s2, len_s + 1);
		return (str);
	}
	return (0);
}

char	*ft_strdup1(char *src)
{
	char	*str;
	size_t	len;
	size_t	str_len;

	if (!(str_len = ft_strlen1(src) + 1))
		return (0);
	if (!(str = (char *)malloc(sizeof(char) * str_len)))
		return (0);
	len = 0;
	while (src[len] != '\0')
	{
		str[len] = src[len];
		len++;
	}
	str[len] = '\0';
	return (str);
}

int main (int argc, char **argv)
{
	int ret, ret2, i, j;

	long long int arr[10] = {0, 97, 120, 10, -120, 2147483647, -2147483648, 9223372036854775807, -9223372036854775807};

	char **spec = (char **)malloc(sizeof(char *) * 10);

	spec[0] = ft_strdup1("c");
	spec[1] = ft_strdup1("d");
	spec[2] = ft_strdup1("i");
	spec[3] = ft_strdup1("u");
	spec[4] = ft_strdup1("x");
	spec[5] = ft_strdup1("X");
	spec[6] = ft_strdup1("p");
	spec[7] = ft_strdup1("%");
	spec[8] = ft_strdup1("s");
	spec[9] = 0;

	char **s = (char **)malloc(sizeof(char *) * 10);

	s[0] = ft_strdup1("abcde");
	s[1] = ft_strdup1("a");
	s[2] = ft_strdup1("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	s[3] = ft_strdup1("");
	s[4] = 0;
	s[5] = ft_strdup1("abcde\0abcde");
	s[6] = ft_strdup1("абвгде");
	s[7] = ft_strdup1("че смотришь?");
	s[8] = ft_strdup1("\n");
	s[9] = ft_strdup1("12");

	char *str[500];
	
	j = 0;
	i = 0;
	while (spec[i] != 0)
	{
		str[j++] = ft_strjoin1("%", spec[i]);
		str[j++] = ft_strjoin1("%2", spec[i]);
		str[j++] = ft_strjoin1("%10", spec[i]);
		str[j++] = ft_strjoin1("%100", spec[i]);
		//
		str[j++] = ft_strjoin1("%.", spec[i]);
		str[j++] = ft_strjoin1("%.2", spec[i]);
		str[j++] = ft_strjoin1("%.10", spec[i]);
		str[j++] = ft_strjoin1("%.100", spec[i]);
		str[j++] = ft_strjoin1("%10.10", spec[i]);
		str[j++] = ft_strjoin1("%10.2", spec[i]);
		str[j++] = ft_strjoin1("%2.10", spec[i]);
		str[j++] = ft_strjoin1("%200.100", spec[i]);
		str[j++] = ft_strjoin1("%200.0", spec[i]);
		//
		str[j++] = ft_strjoin1("%-", spec[i]);
		str[j++] = ft_strjoin1("%-2", spec[i]);
		str[j++] = ft_strjoin1("%-10", spec[i]);
		str[j++] = ft_strjoin1("%-100", spec[i]);
		str[j++] = ft_strjoin1("%-.", spec[i]);
		str[j++] = ft_strjoin1("%-.2", spec[i]);
		str[j++] = ft_strjoin1("%-.10", spec[i]);
		str[j++] = ft_strjoin1("%-.100", spec[i]);
		str[j++] = ft_strjoin1("%-10.10", spec[i]);
		str[j++] = ft_strjoin1("%-10.2", spec[i]);
		str[j++] = ft_strjoin1("%-2.10", spec[i]);
		str[j++] = ft_strjoin1("%-200.100", spec[i]);
		str[j++] = ft_strjoin1("%-200.0", spec[i]);
		//
		str[j++] = ft_strjoin1("%02", spec[i]);
		str[j++] = ft_strjoin1("%010", spec[i]);
		str[j++] = ft_strjoin1("%0100", spec[i]);
		str[j++] = ft_strjoin1("%0.", spec[i]);
		str[j++] = ft_strjoin1("%0.2", spec[i]);
		str[j++] = ft_strjoin1("%0.10", spec[i]);
		str[j++] = ft_strjoin1("%0.100", spec[i]);
		str[j++] = ft_strjoin1("%010.10", spec[i]);
		str[j++] = ft_strjoin1("%010.2", spec[i]);
		str[j++] = ft_strjoin1("%02.10", spec[i]);
		str[j++] = ft_strjoin1("%0200.100", spec[i]);
		str[j++] = ft_strjoin1("%0200.0", spec[i]);
		//
		str[j++] = ft_strjoin1("%0-2", spec[i]);
		str[j++] = ft_strjoin1("%0-10", spec[i]);
		str[j++] = ft_strjoin1("%0-100", spec[i]);
		str[j++] = ft_strjoin1("%0-.", spec[i]);
		str[j++] = ft_strjoin1("%0-.2", spec[i]);
		str[j++] = ft_strjoin1("%0-.10", spec[i]);
		str[j++] = ft_strjoin1("%0-.100", spec[i]);
		str[j++] = ft_strjoin1("%0-10.10", spec[i]);
		str[j++] = ft_strjoin1("%0-10.2", spec[i]);
		str[j++] = ft_strjoin1("%0-2.10", spec[i]);
		str[j++] = ft_strjoin1("%0-200.100", spec[i]);
		str[j++] = ft_strjoin1("%0-200.0", spec[i]);
		i++;
	}
	str[j] = 0;

	i = 0;
	j = 0;
	while (str[i] != 0)
	{
		printf("\x1b[34m[%s]\x1b[m\n", str[i]);
		j = 0;
		while (j < 10)
		{
			if (i <= 49)
			{
				if (j > 2)
					break;
			}
			if (i < 400)
			{
				ret = ft_printf(str[i], arr[j]);
				printf("|[%d]%d\n", ret, i);
				ret2 = printf(str[i] , arr[j]);
				printf("|[%d]%d\n---------------------\n", ret2, i);
                if (ret != ret2)
                {
                    printf("\x1b[1;31m[%s]\x1b[m\n", "ERROR");
                    printf("---------------------\n");
                }
                else
                {
                    printf("\x1b[1;32m[%s]\x1b[m\n", "OK");
                    printf("---------------------\n");
                }
			}
			if (i >= 400)
			{
				ret = ft_printf(str[i], s[j]);
				printf("|[%d]%d\n", ret, i);
				ret2 = printf(str[i], s[j]);
				printf("|[%d]%d\n---------------------\n", ret2, i);
                if (ret != ret2)
                {
                    printf("\x1b[1;31m[%s]\x1b[m\n", "ERROR");
                    printf("---------------------\n");
                }
                else
                {
                    printf("\x1b[1;32m[%s]\x1b[m\n", "OK");
                    printf("---------------------\n");
                }
			}
			j++;
		}
		i++;
		getchar();
	}
	i = -1;
	while (str[++i])
		free(str[i]);
	i = -1;
	while (++i < 10)
	{
		free(spec[i]);
		free(s[i]);
	}
	free(s);
	free(spec);
	return (0);
}
