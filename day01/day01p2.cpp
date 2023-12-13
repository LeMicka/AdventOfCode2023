#include <iostream>
#include <string>
#include <fstream>

int getWordNumber (std::string line, int startChar, std::string digitWords[])
{
	size_t index = static_cast<size_t>(startChar);

	for (int i = 0; i < 9; i++)
	{
		if (line.substr(index, digitWords[i].length()) == digitWords[i])
			return (i + 1);
	}
	return (-1);
}	

int main()
{
	std::ifstream configfile("configfile.txt");
	std::string wordDigits[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	int i;
	int firstDigit {-1};
	int secondDigit {-1};
	int result {0};
	int lineCode{0};
	int functionResult {-1};
	std::string line;

	while(std::getline(configfile, line))
	{
		lineCode = 0;
		firstDigit = -1;
		secondDigit = -1;
		functionResult = -1;
		i = 0;
		while (line[i] != '\0')
		{
			if (std::isdigit(line[i]))
			{
				if (firstDigit == -1)
					firstDigit = line[i] - '0';
				secondDigit = line[i] - '0';
			}
			else
			{
				functionResult = getWordNumber(line, i, wordDigits);
			}
			if (firstDigit == -1)
				firstDigit = functionResult;
		       	if (secondDigit != functionResult && functionResult != -1)	
				secondDigit = functionResult;
			i++;
		}
		if (secondDigit != -1)
			lineCode = (firstDigit * 10) + secondDigit;
		else	
			lineCode = (firstDigit * 10) + firstDigit;
		result += lineCode;	
	}
	std::cout << "total : " << result << '\n';	
	return (0);	
}
