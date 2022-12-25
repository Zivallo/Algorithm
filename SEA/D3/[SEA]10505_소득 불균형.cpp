#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
int T, N;
vector<int>earn;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N; earn = vector<int>(); ll tt = 0;
		for (int i = 0; i < N; i++) {
			int tmp; cin >> tmp;
			earn.push_back(tmp);
			tt += tmp;
		}
		sort(earn.begin(), earn.end());
		ll avg = tt / N; int cnt = 0;
		for (int i = 0; i < earn.size(); i++) {
			if (earn[i] > avg)break;
			cnt++;
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