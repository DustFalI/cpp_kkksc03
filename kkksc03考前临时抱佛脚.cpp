#include <bits/stdc++.h>
using namespace std;
int s[5], t[5][25], mark[5] = {0, 1200, 1200, 1200, 1200}, ans = 0;//要有每颗的题数，每题的时间，用于寻找最小值的擂台
void fuc(int left, int right, int n, int step)//递入左脑右脑的状态，科目，已经装入的题（时间）
{
	if(step == s[n])//如果装入的题数量等于该科题数，就代表所有的题都已经遍历完毕
	{
		int tmp = max(left, right);//因为同时运行，所以二者较大的值就是所花费的时间
		if(tmp < mark[n]) mark[n] = tmp;//打擂台，如果该方案比较小，就把当前方案替换原方案的时间
		return;
	}
	step++;//加一代表装入一道题（时间）
	fuc(left+t[n][step], right, n, step);//先往左脑装，直到最后，归后就是装入最后一道题的前一刻
	fuc(left, right+t[n][step], n, step);//开始往右脑装
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
	for(int i = 1; i <= 4; i++)//寻找四科的最佳方案
	{
		fuc(0,0,i,0);
	}
	for(int i = 0; i <= 4; i++)//遍历累加得到的每科最佳方案
	{
		ans += mark[i];
	}
	cout <<ans;
	return 0;
}
