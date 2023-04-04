#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

class Min
{
public:
	void operator()(int a)
	{
		if (flag)
		{
			minimum = a;
			flag = false;
		}
		else
		{
			if (a < minimum)
			{
				minimum = a;
			}
		}
	}

	int getMin()
	{
		return minimum;
	}
private:
	int minimum;
	bool flag = true;
};

int main()
{
	srand(time(0));

	Min M;
	vector<int> arr;
	for (int i = 0; i < 10; i++)
	{
		arr.push_back(rand() % 100);
		cout << arr[i] << " ";
	}

	for (auto val : arr)
	{
		M(val);
	}

	cout << "\nMinimum = " << M.getMin() << endl;

	return 0;
}