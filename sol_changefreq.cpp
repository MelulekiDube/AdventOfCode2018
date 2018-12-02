#include <cstdlib>
#include <iostream> //for printing answer
#include <fstream>  //this for dealing with the file.
#include <algorithm>
#include <vector>
using namespace std;


int main(void)
{
	ifstream file("day1_input", fstream::in);
	vector<int> occured_frequency;
	vector<int> values;
	int curr_value, frequency =0, sum =0;
	occured_frequency.push_back(0);
	while(file>>curr_value)
	{
		sum += curr_value;
		values.push_back(curr_value);
	}
	cout << "Part 1 answer is: " << sum <<endl << "Part 2 answer is: ";
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



