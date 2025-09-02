#include<iostream>
#include<map>
using namespace std;

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	map<string, string>info;
	string id, pw;

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> id >> pw;
		info.insert({id, pw });
	}

	for (int i = 0; i < m; i++)
	{
		cin >> id;
		cout << info[id] << '\n';
	}

	return 0;
}