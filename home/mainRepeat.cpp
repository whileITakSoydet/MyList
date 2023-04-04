#include <iostream>
#include <map>
#include <fstream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	ifstream f;
	string str;
	map<string, int> mp;
	bool flag = true;

	f.open("text.txt");

	if (f.is_open())
	{
		while (!f.eof())
		{
			str = "";
			f >> str;
			cout << str << " ";
			if (flag)
			{
				mp.insert(make_pair(str, 1));
				flag = false;
			}
			else
			{
				for (auto &val: mp)
				{
					if (val.first == str)
					{
						val.second += 1;
					}
					else
					{
						mp.insert(make_pair(str, 1));
					}
				}
			}
		}
	}
	else
	{
		cout << "file isn't open.\n";
	}

	f.close();

	pair<string, int> max;
	flag = true;

	for (auto& val : mp)
	{
		if (flag)
		{
			max = val;
			flag = false;
		}
		if (val.second>max.second)
		{
			max = val;
		}
		cout << val.first << " " << val.second << endl;
	}

	cout << "\n\n====MAX = " << max.first << " " << max.second << "======\n";

	ofstream fw;
	fw.open("repeat.txt", ios::app);

	fw << "Слово " << max.first << " Встречалось " << max.second << " раз\n";

	for (auto& val : mp)
	{
		fw << val.first << " " << val.second << endl;
	}

	fw.close();

	return 0;
}