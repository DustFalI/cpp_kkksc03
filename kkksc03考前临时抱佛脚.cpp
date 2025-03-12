#include <bits/stdc++.h>
using namespace std;
int s[5], t[5][25], mark[5] = {0, 1200, 1200, 1200, 1200}, ans = 0;
void fuc(int left, int right, int n, int step)
{
	if(step == s[n])
	{
		int tmp = max(left, right);
		if(tmp < mark[n]) mark[n] = tmp;
		return;
	}
	step++;
	fuc(left+t[n][step], right, n, step);
	fuc(left, right+t[n][step], n, step);
}
int main()
{
	for(int i = 1; i <= 4; i++) cin >> s[i];
	for(int i = 1; i <= 4; i++)
	{
		for(int j = 1; j <= s[i]; j++)
		{
			cin >> t[i][j];
		}
	}
	for(int i = 1; i <= 4; i++)
	{
		fuc(0,0,i,0);
	}
	for(int i = 0; i <= 4; i++)
	{
		ans += mark[i];
	}
	cout <<ans;
	return 0;
}
