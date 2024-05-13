/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deck.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaps <sklaps@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 08:11:45 by sklaps            #+#    #+#             */
/*   Updated: 2024/05/12 22:35:30 by sklaps           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../blackjack.h"

t_deck	*ft_decklast(t_deck *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_deckadd_back(t_deck **lst, t_deck *new)
{
	t_deck	*tmp;

	tmp = ft_decklast(*lst);
	if (!tmp)
		*lst = new;
	else
		tmp->next = new;
}

int		calc_score(char	*card)
{
	int	score;

	score = 0;
	if (ft_isdigit(card[0]))
		score = ft_atoi(card);
	else if (!ft_strncmp(card, "A", 1))
		score = 11;
	else
		score = 10;
	return (score);
}

void	deal_card(t_player *players, t_deck *deck, int turn, int first_round)
{
	int	i;
	int i_rand;
	int score;
	char	*input;

	input = "";
	srand(time(0));
	i = 0;
	i_rand = rand() % 52;
	while (i++ <= i_rand)
		deck = deck->next;
	score = calc_score(deck->card);
	i = 0;
	while (i++ < turn)
		players = players->next;
	if (players->status == 0 || players->stand == 1)
		return ;
	printheader();
	printf("Turn: %s\nScore: %i\n\n1. Hit\n2. Stand\n", players->name, players->score);
	if (!first_round)
	{
		while (ft_strncmp(input, "1", 1) && ft_strncmp(input, "2", 1))	
		{
			input = readline("Your choice: ");
			if (!ft_strncmp(input, "2", 1))
			{
				players->stand = 1;
				return ;
			}
		}
	}
	players->score += score;
	printheader();
	printf("Turn: %s.\nCard: %s\nScore: %i\n", players->name, deck->card, players->score);
	if (players->score > 21)
	{
		players->status = 0;
		printf("Bust a nut!\n");
	}
	else if (players->score == 21)
		players->stand == 1;
	readline("press any key to continue...");
}

int	init_deck(t_deck **deck)
{
	int	i;
	int	k;
	t_deck	*card;

	i = 0;
	k = 0;
	while (i++ < 40)
	{
		k++;
		card = malloc(sizeof(t_deck));
		if (!card)
			return (-1);
		card->card = ft_itoa(k);
		card->next = NULL;
		ft_deckadd_back(deck, card);
		if (k == 10)
			k = 0;
	}
	i = 0;
	while (i < 16)
	{
		card = malloc(sizeof(t_deck));
		if (!card)
			return (-1);
		if (i < 4)
			card->card = "J";
		else if (i < 8)
			card->card = "Q";
		else if (i < 12)
			card->card = "K";
		else
			card->card = "A";
		card->next = NULL;
		ft_deckadd_back(deck, card);
		i++;
	}
}
