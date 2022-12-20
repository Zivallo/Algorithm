#include<iostream>
using namespace std;
int arr[11][2000], work[2000][11];
int H, K, R;

void mkarr() {
	arr[1][1] = 2; arr[1][2] = 1;
	for (int i = 2; i <= H; i++) {
		if (i % 2 == 1) {
			for (int j = (1 << H); j > 0; j -= 2) {
				arr[i][j] = arr[i - 1][j / 2];
				arr[i][j - 1] = arr[i][j] + (1 << (i - 1));
			}
		}
		else {
			for (int j = 1; j <= (1 << H); j += 2) {
				arr[i][j] = arr[i - 1][(j + 1) / 2];
				arr[i][j + 1] = arr[i][j] + (1 << (i - 1));
			}
		}
	}
}
void solve() {
	cin >> H >> K >> R;
	mkarr();
	for (int i = 1; i <= (1 << H); i++) {
		for (int j = 1; j <= K; j++) {
			cin >> work[i][j];
		}
	}
	if (R < H + 1) {
		cout << "0\n";
		return;
	}
	long long result = 0, cnt = H + 1;
	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= (1 << H); j++) {
			if (cnt > R)break;
			result += work[arr[H][j]][i];
			cnt++;
		}
		if (cnt > R)break;
	}
	cout << result << "\n";
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}