#pragma once

#include <vector>
#include <string>

void process();
std::vector<int> KMPMatcher(std::string sample, std::string pattern, std::vector<int> location, int &loc);
std::vector<int> ComputePrefix(std::string pattern, int m, std::vector<int> prefix);

