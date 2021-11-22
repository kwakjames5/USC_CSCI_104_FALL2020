#ifndef ALL_COMBOS_H
#define ALL_COMBOS_H
#include <vector>
#include <algorithm>
#include <string>

std::vector<std::string> allCombos(const std::vector<char>& letters, int n);
// Add helper function(s) here
void allCombosHelper(const std::vector<char>& letters, int n, std::vector<std::string>& combos, std::string prefix);

#endif