#include "compare.h"
#include <string>
#include <map>
#include <queue>
#include <fstream>

int main()
{
	map<string, int> words;
	priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> prior;
	string text;
	getline(ifstream("in.txt"), text, '\0');

	for (int i = 0; i < text.size(); i++)
	{
		if (text[i] >= 'A' && text[i] <= 'Z')
			text[i] = text[i] + 32;
	}

	string delims{ " ,?!." };
	size_t start, pos = 0;
	start = text.find_first_not_of(delims, pos);
	while (start != string::npos) 
	{
		pos = text.find_first_of(delims, start + 1);
		string item(text.substr(start, pos-start));
		if (words.count(item) == 0)
			words[item] = 1;
		else
			words[item]++;
	}

	map<string, int>::iterator it;

	for (it = words.begin(); it != words.end(); it++)
	{
		pair<string, int> item(it->first, it->second);
		prior.push(item);
	}
}