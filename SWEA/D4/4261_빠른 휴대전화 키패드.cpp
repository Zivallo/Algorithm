#include <iostream>
#include <string>
using namespace std;
string str = "22233344455566677778889999";
string tar, lst[1100];
int N;

void input() {
	cin >> tar >> N;
	for (int i = 0; i < N; i++) cin >> lst[i];
}
int cmp(int idx) {
	for (int i = 0; i < tar.length(); i++) {
		if (tar[i] != str[lst[idx][i] - 'a']) return 0;
	}
	return 1;
}
void solve() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		input();
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			if (tar.length() != lst[i].length()) continue;
			cnt += cmp(i);
		}
		cout << "#" << t << " " << cnt << "\n";
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