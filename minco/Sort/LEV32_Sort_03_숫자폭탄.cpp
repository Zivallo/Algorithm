#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, arr[1000] = { 0, };
	cin >> n;
	int idx = 0;
	for (int x = 0; x < n; x++) {
		cin >> arr[idx];
		if (idx > 1) {
			if (arr[idx] == arr[idx - 1] && arr[idx] == arr[idx - 2]) {
				idx = idx - 3;
			}
		}
		idx++;
	}
	sort(arr, arr + idx);
	for (int x = 0; x < idx; x++) cout << arr[x] << " ";

	return 0;
}