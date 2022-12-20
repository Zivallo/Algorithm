#include<iostream>
using namespace std;
long long N, s[3][100010], t[100010], u[4][3001], maxi[4];

void solve() {
	cin >> N;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < N; j++) {
			cin >> s[i][j];
			t[j] += s[i][j];
			u[i][s[i][j]]++;
			if (maxi[i] < s[i][j])maxi[i] = s[i][j];
		}
		for (int j = 0; j < N; j++) {
			int r = 1;
			for (int k = s[i][j] + 1; k <= maxi[i]; k++) {
				r += u[i][k];
			}
			cout << r << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i < N; i++) {
		u[3][t[i]]++;
		if (maxi[3] < t[i])maxi[3] = t[i];
	}
	for (int i = 0; i < N; i++) {
		int r = 1;
		for (int j = t[i] + 1; j <= maxi[3]; j++) {
			r += u[3][j];
		}
		cout << r << " ";
	}
	cout << "\n";
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}