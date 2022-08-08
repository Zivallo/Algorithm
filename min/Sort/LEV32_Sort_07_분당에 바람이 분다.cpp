#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string map[10][10];
int N;

void clear(int temp) {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < 3; x++) {
			if (map[y][x] == "0") continue;
			int t = stoi(map[y][x]) % 10 - temp;
			if (t <= 0) map[y][x] = to_string(stoi(map[y][x]) / 10);
			else map[y][x] = to_string(stoi(map[y][x]) - temp);
		}
	}
}

int main() {
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < 3; x++) {
			cin >> map[y][x];
		}
	}
	int K;
	cin >> K;
	for (int x = 0; x < K; x++) {
		int temp;
		cin >> temp;
		int l = 0;
		clear(temp);
	}
	int cnt = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < 3; x++) {
			if (stoi(map[y][x]) > 0) {
				cnt += map[y][x].size();
			}
		}
	}
	cout << cnt;

	return 0;
}