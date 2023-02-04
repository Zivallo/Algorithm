#include <iostream>
#include <string>
using namespace std;
int T, N;
string X;

unsigned long long trans10(int n, string x) {
	unsigned long long ret = 0;
	for (int i = 0;i<x.length();i++){
		ret += (x[i] - '0');
	}
	return ret;
}
void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> N >> X;
		cout << "#" << t << " " << trans10(N, X) % (N - 1) << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}