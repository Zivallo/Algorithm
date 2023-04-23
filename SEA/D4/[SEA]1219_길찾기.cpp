#include <iostream>
#include <vector>
using namespace std;
vector<int> v[110];

bool dfs(int idx) {
	if (idx == 99) { return true; }
	bool ret = false;
	
	for (int i = 0; i < v[idx].size(); i++) {
		ret = dfs(v[idx][i]);
		if (ret == true) break;
	}
	return ret;
}
void solve() {
	for (int T = 0; T < 10; T++) {
		int t, n; cin >> t >> n;
		for (int i = 0; i < 100; i++)v[i] = vector<int>();
		for (int i = 0; i < n; i++) {
			int s, d; cin >> s >> d;
			v[s].push_back(d);
		}
		bool res = dfs(0);
		if (res)cout << "#" << t << " 1\n";
		else cout << "#" << t << " 0\n";
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