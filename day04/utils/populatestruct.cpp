#include "../day4.hpp"

std::string cutString(std::string cardStr)
{
	std::string returnString;
	int i;

	i = 0;
	while (cardStr[i] != ':')
		i++;
	returnString = cardStr.substr(i + 1);
	return (returnString);
}

void	populateStruct (std::string cardStr, t_card *card)
{
	std::string	cleanString;
	std::string	element;
	int		number;
	bool		pipePassed;

	pipePassed = false;
	number = 0;
	cleanString = cutString(cardStr);
	std::istringstream elementStream (cleanString);
	while (elementStream >> element)
	{
		if (element == "|")
			pipePassed = true;
		else
		{
			std::istringstream numberStream (element);
			if (numberStream >> number)
			{
				if (pipePassed)
					card -> myNumbers.push_back(number);
				else
					card -> winningNumbers.push_back(number);
			}
		}
	}
}
