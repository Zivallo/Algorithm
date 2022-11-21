#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
int T, r;
struct Node { char n, c; };
Node s[10];
unordered_map<string, int> um;

bool cmp(Node t, Node v) {
	return t.n < v.n;
}
void dfs(int l, string ss, string cc,int u[10]) {
	if (l != 0 && l % 3 == 0) {
		if (um[cc] == 1) {
			if ((ss[0] == ss[1] && ss[0] == ss[2]) || um[ss] == 1) {
				if (l == 9) {
					r = 1;
					return;
				}
				else ss = ""; cc = "";
			}
			else return;
		}
		else return;
	}
	for (int i = 0; i < 9; i++) {
		if (u[i] == 1)continue;
		if (l % 3 != 0)if (cc[l % 3 - 1] != s[i].c) continue;
		u[i] = 1;
		dfs(l + 1, ss + s[i].n, cc + s[i].c, u);
		u[i] = 0;
	}
}
void solve() {
	um["RRR"] = 1; um["GGG"] = 1; um["BBB"] = 1;
	um["123"] = 1; um["234"] = 1; um["345"] = 1;
	um["456"] = 1; um["567"] = 1; um["678"] = 1;
	um["789"] = 1;
	cin >> T; for (int t = 1; t <= T; t++) {
		int u[10] = { 0 }; r = 0;
		for (int i = 0; i < 9; i++) cin >> s[i].n;
		for (int i = 0; i < 9; i++) cin >> s[i].c;
		sort(s, s + 9, cmp);
		dfs(0, "", "", u);
		if (r)cout << "#" << t << " Win\n";
		else cout << "#" << t << " Continue\n";
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