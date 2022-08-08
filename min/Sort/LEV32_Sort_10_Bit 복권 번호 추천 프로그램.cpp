#include <iostream>
#include <algorithm>
using namespace std;

int arr[10][10], bit[10][10], cnt[10];
int idx, list[100];

bool compare(int t, int v) {
	if (cnt[t] != cnt[v]) return cnt[t] > cnt[v];
	else return t < v;
}

int main() {
	int n;
	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> arr[y][x];
		}
	}
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			cin >> bit[y][x];
		}
	}
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (bit[y][x] == 1) {
				cnt[arr[y][x]]++;
				list[idx] = arr[y][x];
				idx++;
			}
		}
	}
	sort(list, list + idx, compare);

	for (int i = 0; i < idx; i++) cout << list[i] << " ";

	return 0;
}