#include<iostream>
#include<cstdio>
using namespace std;
int n, m;
int able[25][80];
int ha[80];
long long ans = 0;
long long poww(int x)
{
	long long answ=1;
	for (int i = 0; i < x; i++)
	{
		answ *= 2;
	}
	return answ;
}
void dfs(int k)
{
	if (k > n)
	{
		long long temp = 0;
		for (int i = 1; i <= m; i++)
		{
			if (ha[i] % 2 == 0)
			{
				continue;
			}
			else
			{
				temp += (long long)poww(m - i);
			}
		}
		if (temp > ans)
		{
			ans = temp;
		}
		return;
	}
	for (int i = 0; i < able[k][0]; i++)
	{
		ha[able[k][i + 1]]++;
	}
	dfs(k + 1);
	for (int i = 0; i < able[k][0]; i++)
	{
		ha[able[k][i + 1]]--;
	}
	dfs(k + 1);
	return;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> able[i][0];
		for (int j = 0; j < able[i][0]; j++)
		{
			cin >> able[i][j + 1];
		}
	}
	dfs(0);
	cout << ans << endl;
	return 0;
}