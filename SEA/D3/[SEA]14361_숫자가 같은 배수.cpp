#include <iostream>
#include <string>
using namespace std;
int T, f, n1;
string N;

void dfs(int l, int c[10], string s) {
	if (l == N.length()) {
		int n2 = stoi(s);
		if (n2 / n1 > 1 && n2 % n1 == 0)f = 1;
		return;
	}
	for (int i = 9; i >= 0; i--) {
		if (l == 0 && i == 0) continue;
		if (c[i] == 0)continue;
		c[i]--;
		dfs(l + 1, c, s + to_string(i));
		c[i]++;
		if (f == 1)break;
	}
}
void solve() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N; int c[10] = { 0 };
		f = 0; n1 = stoi(N);
		for (int i = 0; i < N.length(); i++) c[N[i] - '0']++;
		dfs(0, c, "");
		if (f)cout << "#" << t << " possible\n";
		else cout << "#" << t << " impossible\n";
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