#include <iostream>
#include <string>
using namespace std;
string map[55];
int N, M, result;
string num[10] = { "0001101","0011001","0010011","0111101","0100011","0110001","0101111","0111011","0110111","0001011" };
void input() {
	cin >> N >> M;
	for (int y = 0; y < N; y++) cin >> map[y];
}
int getNum(string tar) {
	for (int i = 0; i < 10; i++) {
		if (tar == num[i])return i;
	}
	return 0;
}
void getAns(string tar) {
	int valid = 0;
	int sum = 0;
	for (int i = 0; i < 8; i++) {
		string slice = tar.substr(i * 7, 7);
		int num = getNum(slice);
		if (i % 2 == 0) valid += 3 * num;
		else valid += num;
		sum += num;
	}
	if (valid % 10 == 0) result = sum;
	else result = 0;
}
void solution() {
	int flag = 0;
	for (int y = 0; y < N; y++) {
		for (int x = M - 1; x >= 56; x--) {
			if (map[y][x] == '0') continue;
			string tar = map[y].substr(x - 55, 56);
			getAns(tar);
			flag = 1;
			break;
		}
		if (flag) break;
	}
}
void solve() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		input();
		solution();
		cout << "#" << t << " " << result << "\n";
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