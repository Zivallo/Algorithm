#include <iostream>
using namespace std;

int H, W, table[1001][1001] = { 0, }, cnt[10000001] = { 0, };

int main() {
	cin >> H >> W;
	for (int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			cin >> table[y][x];
			cnt[table[y][x]]++;
		}
	}
	int max = -1, maxidx = 0;
	for (int i = 0; i < 10000001; i++) {
		if (cnt[i] > max) {
			max = cnt[i];
			maxidx = i;
		}
	}
	cout << maxidx;

	return 0;
}