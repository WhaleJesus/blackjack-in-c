#include "../blackjack.h"

void	c_clear(void)
{
	system("clear");
}

void	round_first(t_player **players, t_deck **deck, int num_players)
{
	int		turn;

	turn = 0;
	while (turn < num_players)
	{
		deal_card(*players, *deck, turn, 1);
		deal_card(*players, *deck, turn, 1);
		turn++;
	}
}

int	check_eor(t_player *players)
{
	int	hi_score;

	hi_score = 0;
	while (players)
	{
		if (players->status > 0)
		{
			if (players->score > hi_score)
				hi_score = players->score;
		}
		players = players->next;
	}
	return (hi_score);
}

int	check_all_finished(t_player *players)
{
	while (players)
	{
		if (players->status == 1 && players->stand == 0)
			return (0);
		players = players->next;
	}
	return (1);
}

void	set_winner(t_player *players, int hi_score)
{
	printf("Congratulations!\n\n");
	while (players)
	{
		if (players->score != hi_score)
			players->status = 0;
		else
			printf("%s\n", players->name);
		players = players->next;
	}
	printf("\nwon the round!\n");
}

void	check_winner(t_player **players)
{
	int	hi_score;
	char	*winner;

	hi_score = check_eor(*players);
	printheader();
	printplayers(*players);
	set_winner(*players, hi_score);
	printcontinue();
}

void	reset_score(t_player *players)
{
	while (players)
	{
		players->score = 0;
		players->stand = 0;
		players = players->next;
	}
}

void	start_game(t_player **players, t_deck **deck, int num_players)
{
	int		turn;
	int 	players_active;
	int		eor;
	char	*input;

	players_active = num_players;
	init_deck(deck);
	while (players_active > 1)
	{
		eor = 0;
		round_first(players, deck, num_players);
		printheader();
		printplayers(*players);
		while (players_active > 0 && eor == 0)
		{
			turn = 0;
			while (turn < num_players)
			{
				deal_card(*players, *deck, turn, 0);
				turn++;
			}
			printheader();
			printplayers(*players);
			eor = check_all_finished(*players);
		}
		check_winner(players);
		reset_score(*players);
		players_active = active_players(*players);
	}
	reset_players(*players);
}

void	ft_blackjack(void)
{
	t_player 	*players;
	t_deck		*deck;
	int 		num_players;
	int 		i;
	char		*input;

	players = NULL;
	deck = NULL;
	input = "";
	i = 0;

	srand(time(0));
	num_players = select_players(&players);
	if (num_players < 0)
		return ;
	while (ft_strncmp(input, "q", 5))
	{
		c_clear();
		printf("BLACKJACK\n*********\n1. Start\nq. Exit\n\n");
		input = readline("Your choice: ");
		if (!ft_strncmp(input, "1", 5))
			start_game(&players, &deck, num_players);
	}
}

int	main(void)
{
	ft_blackjack();
}
