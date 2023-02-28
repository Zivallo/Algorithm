#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
string n, in[10010];
int N, T;
unordered_map<string, int> um;

bool cmp(string t,string v) {
	return um[t] < um[v];
}
void solve() {
	um["ZRO"] = 0, um["ONE"] = 1, um["TWO"] = 2;
	um["THR"] = 3, um["FOR"] = 4, um["FIV"] = 5;
	um["SIX"] = 6, um["SVN"] = 7, um["EGT"] = 8;
	um["NIN"] = 9;
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> n >> N;
		for (int i = 0; i < N; i++)cin >> in[i];
		sort(in, in + N, cmp);
		cout << "#" << t << " ";
		for (int i = 0; i < N; i++)cout << in[i] << " ";
		cout << "\n";
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