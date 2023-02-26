#include <iostream>
#include <string>
using namespace std;
int N, c[110];
string s;

void solve() {
	for (int t = 1; t <= 10; t++) {
		cin >> N >> s; 
		for (int i = 0; i < N; i++) c[i] = 0;
		for (int i = 0; i < N - 1; i++) {
			if (c[i] == 1)continue;
			for (int j = i + 1; j < N; j++) {
				if (c[j] == 1)continue;
				if (s[i] == s[j]) {
					c[i] = 1; c[j] = 1;
					i = -1;
				}
				break;
			}
		}
		cout << "#" << t << " ";
		for (int i = 0; i < N; i++)if (c[i] == 0)cout << s[i];
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