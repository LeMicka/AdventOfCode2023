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

int minPossibleVal (std::string targetWord, std::string line)
{
	int i;
	int val;
	int minVal;

	minVal = 0;
	i = 0;
	while (line[i] != '\0')
	{
		val = 0;
		if (isalpha(line[i]) && line[i - 1] == ' ')
		{
			if (line.substr(i, targetWord.length()) == targetWord)
				val = getVal(line, i - 1);
		}
		if (val > minVal)
			minVal = val;
		i++;
	}
	return (minVal);
}

int main()
{
	std::ifstream	input("puzzleinput.txt");
	std::string	line;
	std::string	colors[]{"red", "green", "blue"};
	int		i;
	int		linePower;
	int		total;
	int		minimumVal;

	total = 0;
	while(std::getline(input, line))
	{	
		minimumVal = 0;
		linePower = 0;
		i = 0;
		while(i < 3)
		{
			minimumVal = minPossibleVal(colors[i], line); 
			if (linePower != 0 && minimumVal != 0)
				linePower = linePower * minimumVal; 
			else				
				linePower = minimumVal; 
			i++;
		}
		total += linePower;
	}
	std::cout << "Total : " << total << '\n';
	return (0);

}
