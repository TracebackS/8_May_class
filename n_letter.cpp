#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

int main()
{
	std::vector<std::string> v;
	std::ifstream ifs("dictionary.txt");
	std::string temp = "";
	while (ifs >> temp)
	{
		v.push_back(temp);
	}
	std::cout << "Input the number of letters of suffix:\n";
	int suffix = 0;
	std::cin >> suffix;
	std::map<std::string, std::vector<std::string> > word_list;
	std::map<std::string, std::vector<std::string> >::iterator it;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].size() < suffix)
		{
			continue;
		}
		std::string suf = v[i].substr(v[i].size() - suffix, v[i].size());
		word_list[suf].push_back(v[i]);
	}	
	it = word_list.begin();
	std::vector<int> number;
	while (it != word_list.end())
	{
		number.push_back(it -> second.size());
		it++;
	}
	std::sort(number.begin(), number.end());
	int top[10];
	for (int i = 0; i < 10; i++)
	{
		top[i] = number[number.size() - 1 - i];
	}
	std::vector<std::string> topsuf;
	for (int i = 0; i < 10; i++)
	{
		it = word_list.begin();
		while (it != word_list.end())
		{
			if (it -> second.size() == top[i])
			{
				topsuf.push_back(it -> first);
				std::cout << topsuf[i] << "   " << top[i] << std::endl;
			}
			it++;
		}
	}
	std::cout << '\n' << "Query a n-letter suffix by inputting the suffix:" << std::endl;
	std::string input_suf;
	std::cin >> input_suf;
	for (int i = 0; i < word_list[input_suf].size(); i++)
	{
		std::cout << word_list[input_suf][i] << std::endl;
	}
	std::cout << word_list[input_suf].size() << std::endl;
	return 0;
}
