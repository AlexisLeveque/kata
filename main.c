/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <aleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 17:01:04 by aleveque          #+#    #+#             */
/*   Updated: 2017/06/26 17:32:38 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char		**ft_strsplit(char const *s, char c);


int main(int argc, char **argv)
{
	int answ;
	int	nb_match;
	char **quest;
	char **info;
	int curr;
	int count;
	int i;
	int x;

	curr = 2;
	answ = 0;
	nb_match = 0;
	if (argc < 2)
	{
		printf("Error: no question\n");
		return (0);
	}
	quest = ft_strsplit(argv[1], ' ');
	while (curr < argc)
	{
		i = 0;
		count = 0;
		info = ft_strsplit(argv[curr], ' ');
		while (quest[i] != NULL)
		{
			x = 0;
			while (info[x] != NULL)
			{
				if (strcmp(quest[i], info[x]) == 0)
					count++;
				x++;
			}
			i++;
		}
		if (count > nb_match)
		{
			answ = curr;
			nb_match = count;
		}
		curr++;
	}
	if (answ == 0)
		printf("No answer found\n");
	else
		printf("The answer is: %s\n", argv[answ]);
	return (0);

}
