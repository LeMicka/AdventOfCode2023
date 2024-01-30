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

void	initArray (int *arr, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		arr[i] = 1;
		i++;
	}
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
					cardPoints++;
			j++;
		}
		i++;
	}
	return (cardPoints);
}

void	addCardsToArray(int *arr, int points, int size, int index)
{
	int	i;

	i = index + 1;
	while (i <= index + points && i < size)
	{
		arr[i] += arr[index];
		i++;	
	}
}

int	main(int argc, char *argv[])
{
	std::vector <std::string>	text;
	std::string			inputName;
	int				cardPoints;
	int				totalCards;
	int				nbOfCards;
	t_card				*card;
	int				*arrayOfCards;
	int 				i;
	
	totalCards = 0;
	if (argc == 2 && argv[1] != nullptr)
	{
		inputName.assign(argv[1]); 
		text = getInputText (inputName);
	}
	else
		std::cout << "Enter only one file name." << '\n';
	nbOfCards = static_cast<int>(text.size());
	arrayOfCards = new int[nbOfCards];
	initArray (arrayOfCards, nbOfCards);
	i = 0;
	while (i < nbOfCards)
	{
		card = new t_card;
		populateStruct (text[i], card);
		cardPoints = getCardPoints (card);
		addCardsToArray (arrayOfCards, cardPoints, nbOfCards, i);
		totalCards += arrayOfCards[i];
		i++;
		delete card;
	}
	delete arrayOfCards;

	std::cout << totalCards << '\n';
}
