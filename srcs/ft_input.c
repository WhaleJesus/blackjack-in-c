#include "../blackjack.h"

void	printheader(void)
{
	c_clear();
	printf("BLACKJACK\n*********\n");
}

void	printcontinue()
{
	readline("press any key to continue");
}

void	printplayers(t_player *players)
{
	while (players)
	{
		printf("%s: %i  ", players->name, players->score);
		players = players->next;
	}
	printf("\n");
}

int	ft_readint(char *prompt)
{
	int		i;
	int		ret;
	char	*str;
	int		correct_input;

	correct_input = 0;
	while (correct_input != 1)
	{
		correct_input = 1;
		i = 0;
		str = readline(prompt);
		while (str[i])
		{
			if (!ft_isdigit(str[i]) && str[i] != '-')
				correct_input = 0;
			i++;
		}
		if (correct_input != 1)
			printf("Gayass\n");
	}
	ret = ft_atoi(str);
	return (ret);
}
