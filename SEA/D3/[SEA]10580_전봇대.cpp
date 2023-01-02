#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int T, N;
vector<pair<int, int>>v;

bool cmp(pair<int, int>t, pair<int, int>v) {
	return t.first < v.first;
}
void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N; v = vector<pair<int, int>>();
		for (int i = 0; i < N; i++) {
			int a, b; cin >> a >> b;
			v.push_back({ a,b });
		}
		sort(v.begin(), v.end(), cmp);
		int r = 0;
		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				if (v[i].second > v[j].second)r++;
			}
		}
		cout << "#" << t << " " << r << "\n";
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