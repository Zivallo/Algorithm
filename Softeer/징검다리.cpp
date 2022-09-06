#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int N;
int stone[4000];
int memo[4000];

int getAns(int now) {
	if (memo[now] != -1) return memo[now];
	if (now == N) return memo[N] = 1;

	int flag = 1;
	for (int next = now + 1; next <= N; next++) {
		if (stone[now] >= stone[next]) continue;
		int temp = getAns(next);
		memo[now] = max(memo[now], temp + 1);
		flag = 0;
	}
	if (flag) memo[now] = 1;
	return memo[now];
}

int main(int argc, char** argv)
{
	cin >> N;
	memset(memo, -1, sizeof(memo));
	for (int i = 1; i <= N; i++) cin >> stone[i];
	int ans = getAns(0) - 1;
	cout << ans;
	return 0;
}