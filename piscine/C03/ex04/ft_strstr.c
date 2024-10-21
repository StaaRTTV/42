/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:13:47 by gpochon           #+#    #+#             */
/*   Updated: 2024/09/12 17:26:21 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	i2;

	i = 0;
	i2 = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			while (to_find[i2] != '\0'
				&& to_find[i2] == str[i + i2])
			{
				i2++;
			}
			if (to_find[i2] == '\0')
				return (&str[i]);
		}
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char str[] = "Hello, this is a simple string test.";
	char to_find[] = "simple";
	char *result;

	// Test avec une chaîne à chercher qui existe
	result = ft_strstr(str, to_find);
	if (result != 0)
		printf("Sous-chaîne trouvée : %s\n", result);
	else
		printf("Sous-chaîne non trouvée.\n");

	// Test avec une chaîne à chercher qui n'existe pas
	result = ft_strstr(str, "absent");
	if (result != 0)
		printf("Sous-chaîne trouvée : %s\n", result);
	else
		printf("Sous-chaîne non trouvée.\n");

	// Test avec une chaîne vide à chercher
	result = ft_strstr(str, "");
	if (result != 0)
		printf("Sous-chaîne trouvée (chaîne vide) : %s\n", result);
	else
		printf("Sous-chaîne non trouvée.\n");

	return (0);
}
*/
