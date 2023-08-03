/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:45:46 by vschneid          #+#    #+#             */
/*   Updated: 2023/08/03 15:16:53 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*char	*ft_itoa(int n)
{
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *)malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		str[1] = '\0';
		str = ft_strjoin(str, ft_itoa(-n));
	}
	else if (n >= 10)
		str = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
	else if (n < 10 && n >= 0)
	{
		str[0] = n + '0';
		str[1] = '\0';
	}
	return (str);
}*/

int	helper(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

void	reverse(char *str)
{
	char	temp;
	int		counter;
	int		len;

	counter = -1;
	len = ft_strlen(str);
	while (++counter < len / 2)
	{
		temp = *(str + counter);
		*(str + counter) = *(str + len - 1 - counter);
		*(str + len - 1 - counter) = temp;
	}
}

int	strlen_giver(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		sign;

	i = 0;
	sign = n < 0;
	str = ft_calloc(strlen_giver(n) + (sign) + 1, sizeof(char));
	if (!str)
		return (0);
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[i] = '0' + helper(n % 10);
		n /= 10;
		i++;
	}
	if (sign)
		str[i] = '-';
	reverse(str);
	return (str);
}