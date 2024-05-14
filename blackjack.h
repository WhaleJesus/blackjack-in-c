#ifndef BLACKJACK_H
# define BLACKJACK_H


# include "srcs/libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <time.h>

typedef struct s_deck
{
	char			*card;
	int				status;
	struct s_deck	*next;
}	t_deck;

typedef struct s_player
{
	char	*name;
	int		score;
	int		status;
	int		stand;
	struct s_player *next;
}	t_player;

void		ft_blackjack(void);
int			ft_readint(char *prompt);
void		c_clear(void);
void	printheader(void);
void	printplayers(t_player *players);
void	printcontinue();

void		ft_playeradd_back(t_player **lst, t_player *new);
t_player	*ft_playerlast(t_player *players);
int			select_players(t_player **players);
int	active_players(t_player *players);
void	reset_players(t_player *players);

int			init_deck(t_deck **deck);
void	deal_card(t_player *players, t_deck *deck, int turn, int first_round);
void	ft_deckclear(t_deck **deck);

void	start_game(t_player **players, t_deck **deck, int num_players);
#endif
