#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

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
	std::map<string, int> counter;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].size() < suffix)
		{
			continue;
		}
		std::string suf = v[i].substr(v[i].size()-suffix, v[i].size()-1);
		
	}	
	return 0;
}
