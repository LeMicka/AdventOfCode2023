
#ifndef DAY03_H
#define DAY03_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

typedef struct s_card
{
	std::vector <int> winningNumbers;
	std::vector <int> myNumbers;
}	t_card;

void    populateStruct (std::string cardstr, t_card *card);

#endif


