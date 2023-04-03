#include <iostream>	
#include <stack>
#include <vector>
#define or ||

using namespace std;

int main()
{
	stack<char> st;

	//string str = "({ x - y - z }*[x + 2y] - (z + 4x))";
	string str = "([x - y - z}*[x + 2y) - {z + 4x)]";
	vector<char> end;

	for (int i = 0; i < str.size() - 1; ++i)
	{
		if (str[i] == '(' or str[i] == '{' or str[i] == '[')
		{
			st.push(str[i]);
			end.push_back(str[i]);
		}
		if (str[i] == ')' or str[i] == '}' or str[i] == ']')
		{
			if (str[i] == end[end.size() - 1])
			{
				st.pop();
				end.pop_back();
			}
		}
	}

	if (st.empty())
	{
		cout << "Line is correct.\n";
	}
	else
	{
		cout << "Line isn't correct.\n";
	}

	return 0;
}