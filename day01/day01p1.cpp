#include <iostream>
#include <string>
#include <fstream>

int main()
{
	
	std::ifstream configfile("configfile.txt");
	int i;
	int firstDigit {-1};
	char secondDigit;
	int result {0};
	int lineCode{0};
	std::string line;

	while(std::getline(configfile, line))
	{
		lineCode = 0;
		firstDigit = -1;
		secondDigit = '\0';
		i = 0;
		while (line[i] != '\0')
		{
			if (std::isdigit(line[i]))
			{
				if (firstDigit == -1)
					firstDigit = line[i] - '0';
				secondDigit = line[i];
			}
			i++;
		}
		if (secondDigit != '\0')
			lineCode = (firstDigit * 10) + (secondDigit - '0');
		else	
			lineCode = (firstDigit * 10) + (secondDigit - '0');
		result += lineCode;

		std::cout << lineCode << '\n';	
	}
	std::cout << result << '\n';	
	return (0);	
}
