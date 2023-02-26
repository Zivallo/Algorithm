#include <iostream>
#include <vector>
using namespace std;
vector<int> n;

void solve() {
	for (int i = 0; i < 10; i++) {
		int t; cin >> t; n = vector<int>();
		for (int j = 0; j < 8; j++) {
			int tmp; cin >> tmp; n.push_back(tmp);
		}int minus = 1;
		while (n.back()) {
			n[0] -= minus;
			if (n[0] < 0)n[0] = 0;
			n.push_back(n[0]);
			n.erase(n.begin());
			minus++;
			if (minus == 6)minus = 1;
		}
		cout << "#" << t << " ";
		for (int i = 0; i < 8; i++)cout << n[i] << " ";
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