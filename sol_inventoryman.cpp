#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

bool found = false;
int count_2s = 0,	 count_3s = 0;

void part1(string s)
{
	char freq_table[256] = {0};
	bool found_3 = false, found_2 = false;
	for(int i=0; i<s.size(); ++i)
	{
		++freq_table[s[i]];
	}
	for(int i=0; i<s.size(); ++i)
	{
		if(freq_table[s[i]] == 2 && !found_2)
		{
			++count_2s;
			found_2 = true;
		}
		if(freq_table[s[i]] == 3 && !found_3)
		{
			++count_3s; 
			found_3 = true;
		}
	}
}

void part2(string s, string s2)
{
	char freq_table[256] = {0};
	char s2_freq[256] = {0};
	int count = 0, index =-1;
	for(int i=0; i<s.size(); ++i)
	{
		if(s[i] != s2[i]){
			++count;
			index = i;
		}
		if(count > 2)
			return;
	}
	if(count == 1)
	{
		for(int i=0; i <s.size(); ++i)
		{
			if(i != index)
				cout << s[i];
		}
	}
}

int main(void)
{
	ifstream file("day2_input", fstream::in);
	string id;
	vector<string> input;
	while(file>>id)
	{
		part1(id);
		input.push_back(id);
	}
	cout << "Part 1 answer is: " << (count_2s*count_3s) << endl << "Part2 answer is: ";
	for(int i=0; i<input.size(); ++i)
	{
		for(int j=i+1; j <input.size(); ++j)
		{
			part2(input[i], input[j]);
			if(found)
				return 0;
		}
	}
	return 0;
}