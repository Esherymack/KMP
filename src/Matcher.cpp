#include "Matcher.h"
#include "Utility.h"

#include <iostream>

#define MAX_ELEMENTS 65537
#define MAX_RUNS 13
#define NUM_AVG 10

int count = 0;

void process()
{
	int n = 16;
	int i = 0;
	int counter[1][MAX_RUNS][1];

	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < MAX_RUNS; j++)
		{
			counter[i][j][0] = 0;
		}
	}

	std::string pattern = "AAAB";

	while ((n <= MAX_ELEMENTS) && (i < MAX_RUNS))
	{

		for (int k = 0; k < NUM_AVG; k++)
		{
			for (int l = 0; l < 1; l++)
			{
				std::string sample = make_string(n);

				count = 0;
				std::vector<int> location;
				int index = 0;
				location = KMPMatcher(sample, pattern, location, index);

				counter[l][i][0] += count++ / NUM_AVG;

			}
		}
		/* for (int i = 0; i < index; i++)
		{
			std::cout << "Pattern found at location: " << location[i] << std::endl;
		} */

		n *= 2;
		i++;
	}

	/* Print average runtimes */
	n = 16;

	std::cout << "n \t long" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;

	for (int j = 0; j < i; j++)
	{
		std::cout << n << "\t";
		for (int k = 0; k < 1; k++)
		{
			if (k == 0)
			{
				std::cout << counter[k][j][0] << std::endl;
			}
			else
			{
				std::cout << counter[k][j][0] << ", " << std::endl;
			}

			if (!writeToCSV("results.csv", n, counter[k][j][0]))
			{
				throw std::runtime_error("File error.");
			}
			std::cout << std::endl;
			n *= 2;
		}
	}

}

std::vector<int> KMPMatcher(std::string sample, std::string pattern, std::vector<int> location, int &loc)
{
	int n, m, i = 0, j = 0;
	count++;

	n = sample.size();
	count++;
	m = pattern.size();
	count++;

	std::vector<int> prefix;
	count++;

	prefix = ComputePrefix(pattern, m, prefix);
	
	while (i < n)
	{
		count++;
		if (sample[i] == pattern[j])
		{
			count++;
			i++;
			j++;
			count++;
			count++;
		}

		if (j == m)
		{
			count++;
			auto it = location.begin() + loc;
			count++;
			location.insert(it, i - j);
			count++;
			loc++;
			count++;

			j = prefix[j - 1];
			count++;
		}

		else if (i < n && pattern[j] != sample[i])
		{
			count++;
			if (j != 0)
			{
				count++;
				j = prefix[j - 1];
				count++;
			}
			else
			{
				count++;
				i++;
				count++;
			}
		}

	}
	count++;
	return location;
}

std::vector<int> ComputePrefix(std::string pattern, int m, std::vector<int> prefix)
{
	int length = 0;
	count++;
	prefix.push_back(0);
	count++;

	for (int i = 1; i < m; i++)
	{
		count++;
		if (pattern[i] == pattern[length])
		{
			count++;
			length++;
			count++;
			prefix.push_back(length);
			count++;
		}
		else
		{
			count++;
			if (length != 0)
			{
				count++;
				length = prefix[length - 1];
				count++;
				i--;
				count++;
			}
			else
			{
				count++;
				prefix.push_back(0);
				count++;
			}
		}
	}
	count++;
	return prefix;
}
