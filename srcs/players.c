/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 23:07:29 by sklaps            #+#    #+#             */
/*   Updated: 2024/05/12 19:15:53 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../blackjack.h"

t_player	*ft_playerlast(t_player *players)
{
	if (!players)
		return (NULL);
	while (players->next)
		players = players->next;
	return (players);
}

void	ft_playeradd_back(t_player **lst, t_player *new)
{
	t_player	*tmp;

	tmp = ft_playerlast(*lst);
	if (!tmp)
		*lst = new;
	else
		tmp->next = new;
}

int	check_name_dup(t_player *players, char *name)
{
	while (players)
	{
		if (!ft_strncmp(players->name, name, ft_strlen(players->name)))
			return (1);
		players = players->next;
	}
	return (0);
}

int	active_players(t_player *players)
{
	int	i;

	i = 0;
	while (players)
	{
		if (players->status > 0)
			i++;
		players = players->next;
	}
	return (i);
}

void	reset_players(t_player *players)
{
	while (players)
	{
		players->status = 1;
		players->stand = 0;
		players->score = 0;
		players = players->next;
	}
}

int	select_players(t_player **players)
{
	int			i = 0;
	int 		num_players = 0;
	int			dup_name = 1;
	char		*name;
	t_player	*curr_player;
	t_player	*tmp;

	printheader();
	while (num_players < 1)
	{
		num_players = ft_readint("Players: ");
		if (num_players < 1)
			printf("Nigga\n");
	}
	while (i < num_players)
	{
		printheader();
		curr_player = malloc(sizeof(t_player *));
		if (!curr_player)
		{
			return (-1);
		}
		dup_name = 1;
		while (dup_name == 1)
		{
			printf("Player %i ", i + 1);
			name = readline("name: ");
			if (check_name_dup(*players, name) == 0)
				dup_name = 0;
			else
				printf("No duplicate names\n");
		}
		curr_player->name = name;
		curr_player->score = 0;
		curr_player->status = 1;
		curr_player->stand = 0;
		curr_player->next = NULL;
		ft_playeradd_back(players, curr_player);
		i++;
	}
	return (num_players);
}
