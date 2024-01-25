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

int	getNumber(std::string line, int charIndex)
{
	int	i;
	int	number;

	i = charIndex;
	number = 0;
	while (isdigit(line[i - 1]))
		i--;
	while (isdigit(line[i]))
	{
		number += line[i] - '0';
		if (isdigit(line[i + 1]))
			number = number * 10;
		i++;
	}
	return (number);
}

int calcRatio (std::vector<std::string> text, int lineIndex, int charIndex)
{
	int	num1;
	int	num2;
	int	total;
	int	i;
	int	j;
	int	elements;

	elements = 0;
	total = 0;
	if (lineIndex == 0)
		i = lineIndex;
	else
		i = lineIndex - 1;
	while (i <= lineIndex + 1 && i <= static_cast<int>(text.size()))
	{
		if (charIndex == 0)
			j = charIndex;
		else
			j = charIndex - 1;
		while (j <= charIndex + 1 && text[i][j] != '\0')
		{
			if (isdigit(text[i][j]) && isdigit(text[i][j + 1]))
			{	
				if(elements == 0)
					num1 = getNumber(text[i], j);
				else
					num2 = getNumber(text[i], j);
				elements++;
				break;
			}
			else if (isdigit(text[i][j]) && !isdigit(text[i][j + 1]))
			{
				if(elements == 0)
					num1 = getNumber(text[i], j);
				else
					num2 = getNumber(text[i], j);
				elements++;
			}
			j++;
		}
		i++;
	}
	if (elements == 2)
		return (num1 * num2);
	return (0);
}

int lineRatioSum (std::vector<std::string> text, int lineIndex)
{
	int	total;
	int	i;

	total = 0;
	i = 0;
	while (text[lineIndex][i] != '\0')
	{
		if (text[lineIndex][i] == '*')
			total += calcRatio(text, lineIndex, i);
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
		lineSum = lineRatioSum(text, i);
		total += lineSum;
		i++;
	}
	std::cout << "total : " << total << '\n';
}



