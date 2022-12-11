#include<iostream>
using namespace std;
int N;
long long bus[5100], arr[5100][5100];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> bus[i];
}
void setArr() {
	for (int i = 1; i <= N; i++) {
		for (int j = N - 1; j >= 1; j--) {
			arr[i][j] = arr[i][j + 1] + (i > bus[j + 1] ? 1 : 0);
		}
	}
}
long long getResult() {
	long long sum = 0;
	for (int i = 1; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (bus[i] < bus[j]) sum += arr[bus[i]][j];
		}
	}
	return sum;
}
void solve() {
	input();
	setArr();
	long long result = getResult();
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