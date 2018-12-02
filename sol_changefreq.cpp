#include <cstdlib>
#include <iostream> //for printing answer
#include <fstream>  //this for dealing with the file.
#include <algorithm>
#include <vector>
using namespace std;

void print(vector<int> v)
{
	for(int i: v)
	{
		cout << i <<", ";
	}
	cout <<endl;
}
int main(void)
{
	ifstream file("data", fstream::in);
	vector<int> occured_frequency;
	vector<int> values;
	int curr_value, frequency =0;
	occured_frequency.push_back(0);
	while(file>>curr_value)
	{
		values.push_back(curr_value);
	}
	while(true)
	{
		for(int curr_value : values)
		{
			frequency += curr_value;
			if(find(occured_frequency.begin(), occured_frequency.end(), frequency) != occured_frequency.end())
			{
				cout << frequency <<endl;
				return 0;
			}
			occured_frequency.push_back(frequency);
		}
	}
	return 0;
}



