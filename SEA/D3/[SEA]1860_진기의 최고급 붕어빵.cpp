#include <iostream>
#include <cstring>
using namespace std;
int T, N, M, K, tt[20000];

bool check(int last,int* tt) {
	for (int t = 0; t <= last; t++) {
		if (t != 0)tt[t] += tt[t - 1];
		if (t != 0 && t % M == 0)tt[t] += K;
		if (tt[t] < 0)return false;
	}
	return true;
}
void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N >> M >> K; int last = 0;
		memset(tt, 0, sizeof(tt));
		for (int i = 0; i < N; i++) {
			int tmp; cin >> tmp;
			if (last < tmp)last = tmp;
			tt[tmp]--;
		}cout << "#" << t << " ";
		if (check(last, tt))cout << "Possible\n";
		else cout << "Impossible\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}