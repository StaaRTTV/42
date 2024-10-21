/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:18:13 by gpochon           #+#    #+#             */
/*   Updated: 2024/09/05 10:34:33 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_numbers(char a, char b, char d)
{
	ft_putchar(a);
	ft_putchar(b);
	ft_putchar(d);
	if (a != '7' || b != '8' || d != '9')
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	d;

	a = '0';
	while (a <= '7')
	{
		b = a + 1;
		while (b <= '8')
		{
			d = b + 1;
			while (d <= '9')
			{
				ft_print_numbers(a, b, d);
				d++;
			}
			b++;
		}
		a++;
	}
}
/*
int main(void)
{
    ft_print_comb();
    return (0);
}
*/
