#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool Greater(string left, string right)
{
	return left > right;
}

string solution(vector<int> numbers) 
{
	vector<string> v;

	for (size_t i = 0; i < numbers.size(); i++)
	{
		v.push_back(to_string(numbers[i]));
	}

	sort(v.begin(),v.end(),Greater);


	string answer = "";
	for (size_t i =0 ; i<numbers.size(); i++)
	{
		answer += v[i];
	}

	return answer;
}

int main(void)
{
	vector<int> temp;
	temp.push_back(3);
	temp.push_back(30);
	temp.push_back(34);
	temp.push_back(5);
	temp.push_back(9);
	printf("%s",solution(temp));

}