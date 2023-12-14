#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

int getVal (std::string line, int index)
{
	int val;
	int i;

	val = 0;
	i = index;
	while (std::isdigit(line[i - 1]))
		i--;

	while (std::isdigit(line[i]))
	{
		val += line[i] - '0';
		if (std::isdigit(line[i + 1]))
			val = val * 10;
		i++;
	}
	return (val);
}

bool possible (std::string targetWord, int maxValue, std::string line)
{
	int i;
	int val;

	i = 0;
	while (line[i] != '\0')
	{
		val = 0;
		if (isalpha(line[i]) && line[i - 1] == ' ')
		{
			if (line.substr(i, targetWord.length()) == targetWord)
				val = getVal(line, i - 1);
		}
		if (val > maxValue)
			return (false);
		i++;
	}
	return (true);
}

int main()
{
	std::ifstream	input("puzzleinput.txt");
	std::string	line;
	int		numberOfCubes[]{12, 13, 14};
	std::string	colors[]{"red", "green", "blue"};
       	int		lineNumber;
	int		i;
	int		total;	

	total = 0;
	lineNumber = 1;
	while(std::getline(input, line))
	{
		i = 0;
		while(i < 3)
		{
			if (!possible(colors[i], numberOfCubes[i], line))
				break;
			if (i == 2)
				total += lineNumber;
			i++;
		}		
		lineNumber++;
	}
	std::cout << "Total : " << total << '\n';
	return (0);

}
