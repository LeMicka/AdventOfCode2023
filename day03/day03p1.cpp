#include <iostream>
#include <string>
#include <fstream>
#include <vector>

std::vector <std::string> getInputText (std::string inputName)
{
	std::ifstream			input(inputName);
	std::vector <std::string>	text;
	std::string			line;

	while (std::getline(input, line))
	{
		text.push_back(line);
	}
	return (text);
}

int	getNumber(std::string line, int firstChar)
{
	int	i;
	int	number;

	i = firstChar;
	number = 0;
	while (isdigit(line[i]))
	{
		number += line[i] - '0';
		if (isdigit(line[i + 1]))
			number = number * 10;
		i++;
	}
	return (number);
}

bool	partNumberChecker(std::vector <std::string> text, int lineIndex, int firstChar, int lastChar)
{
	int	i;
	int	j;
	int 	k;
	int	length;

	length = text.size();
	if (lineIndex == 0)
		i = lineIndex;
	else
		i = lineIndex - 1;
	j = firstChar;
	k = lastChar;
	while (i <= lineIndex + 1 && i < length)
	{
		j = firstChar;
		while (j <= k)
		{
			if (!isdigit(text[i][j]) && text[i][j] != '.' && text[i][j] != '\0')
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

int	getLineSum (std::vector <std::string> text, int lineIndex)
{
	int	i;
	int	firstChar;
	int	lastChar;
	int	number;
	int	total;

	i = 0;
	total = 0;
	while  (text[lineIndex][i])
	{
		if (isdigit(text[lineIndex][i]) && !isdigit(text[lineIndex][i - 1]))
		{
			firstChar = i - 1;
			number = getNumber(text[lineIndex], i);
		}
		if (isdigit(text[lineIndex][i]) && !isdigit(text[lineIndex][i + 1]))
		{
			lastChar = i + 1;
			if (partNumberChecker(text, lineIndex, firstChar, lastChar))
			{
				total += number;
			}
		}
		i++;
	}
	return (total);
}

int	main()
{
	std::string			input("puzzleinput.txt");
	std::vector <std::string>	text;
	int				lineSum;
	int				total;
	int				i;

	i = 0;
	total = 0;
	text = getInputText(input);
	while (i < static_cast<int>(text.size()))
	{
		lineSum = getLineSum(text, i);
		total += lineSum;
		i++;
	}
	std::cout << "total : " << total << '\n';
}



