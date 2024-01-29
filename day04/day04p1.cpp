#include "day4.hpp"


/* Put the input file intu a vector tu use it in the program */
std::vector	<std::string> getInputText (std::string inputName)
{
	std::ifstream			input(inputName);
	std::vector <std::string>	text;
	std::string			line;

	if (!input)
		std::cout << "Could not open the file " << inputName << '\n';	
	while (std::getline(input, line))
	{
		text.push_back(line);
	}
	return (text);
}

int	getCardPoints (t_card	*card)
{
	int	i;
	int	j;
	int	cardPoints;

	cardPoints = 0;
	i = 0;
	while (card -> winningNumbers[i])
	{
		j = 0;
		while (card -> myNumbers[j])
		{
			if (card -> winningNumbers[i] == card -> myNumbers[j])
			{
				if (cardPoints == 0)
					cardPoints++;
				else
					cardPoints = cardPoints * 2;
			}
			j++;
		}
		i++;
	}
	return (cardPoints);
}

int	main(int argc, char *argv[])
{
	std::vector <std::string>	text;
	std::string			inputName;
	int				totalPoints;
	int				cardPoints;
	t_card				*card;
	int 				i;

	totalPoints = 0;
	if (argc == 2 && argv[1] != nullptr)
	{
		inputName.assign(argv[1]); 
		text = getInputText (inputName);
	}
	else
		std::cout << "Enter only one file name." << '\n';
	i = 0;
	while (i < static_cast<int>(text.size()))
	{
		card = new t_card;
		populateStruct (text[i], card);
		cardPoints = getCardPoints (card);
		totalPoints += cardPoints;
		i++;
		delete card;
	}
	std::cout << totalPoints << '\n';
}
