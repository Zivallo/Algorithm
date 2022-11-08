#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string arr[5];
	for (int y = 0; y < 5; y++) cin >> arr[y];
	int idx1, idx2;
	cin >> idx1 >> idx2;

	sort(arr[idx1].begin(), arr[idx1].end());
	sort(arr[idx2].begin(), arr[idx2].end());

	for (int y = 0; y < 5; y++) {
		cout << arr[y][0] << " ";
	}



	return 0;
}