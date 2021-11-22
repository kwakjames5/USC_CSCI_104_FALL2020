#include "allCombos.h"

std::vector<std::string> allCombos(const std::vector<char>& letters, int n)
{
	std::vector<std::string> combos;
	allCombosHelper(letters, n, combos, "");
	return combos;
}

void allCombosHelper(const std::vector<char>& letters, int n, std::vector<std::string>& combos, std::string prefix)
{
	if(prefix.size() == n)
	{
		combos.push_back(prefix);
		return;
	}

	for(unsigned int i = 0; i < letters.size(); i++)
	{
		allCombosHelper(letters, n, combos, prefix + letters[i]);
	}
}