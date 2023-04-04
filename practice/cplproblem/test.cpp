#include<iostream>
#include<string>
using namespace std;
int main()
{
	
	string n;
	while (1)
	{
		cout << "give me a num please" << endl;
		cin >> n;
		bool hf = 1;
		for (auto& s : n)
		{
			if (s > '9' || s < '0')
			{
				hf = 0;
				break;
			}
		}
		if (hf)break;
	}
	int sr = stoi(n);
	int js=sr;
	double res = 0.0;
	double pre = 1.0, dq = 1.0;
	while (sr--)
	{
		res += dq / pre;
		int ls = dq;
		dq = pre + dq;
		pre = ls;
	}
	cout <<"n="<<js<<",s="<<res;
}
