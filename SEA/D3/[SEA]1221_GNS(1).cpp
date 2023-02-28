#include <iostream>
#include <string>
using namespace std;
string n, idx[10] = { "ZRO","ONE","TWO","THR","FOR","FIV","SIX","SVN","EGT","NIN" };
int N, T;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> n >> N; int c[11] = { 0 };
		for (int i = 0; i < N; i++) {
			cin >> n;
			if (n == "ZRO")c[0]++;
			if (n == "ONE")c[1]++;
			if (n == "TWO")c[2]++;
			if (n == "THR")c[3]++;
			if (n == "FOR")c[4]++;
			if (n == "FIV")c[5]++;
			if (n == "SIX")c[6]++;
			if (n == "SVN")c[7]++;
			if (n == "EGT")c[8]++;
			if (n == "NIN")c[9]++;
		}cout << "#" << t << " ";
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < c[i]; j++) {
				cout << idx[i] << " ";
			}
		}
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