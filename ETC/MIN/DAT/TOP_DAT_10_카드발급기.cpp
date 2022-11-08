#include <iostream>
using namespace std;

int arr[1000001];
int temp[1000001];

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int num;
		cin >> num;
		for (int j = 1; j <= num; j++) cin >> temp[j];
		for (int j = 1; j <= num; j++) {
			int idx;
			cin >> idx;
			arr[idx] = temp[j];
		}
		int flag = 0;
		for (int j = 1; j < num; j++) {
			if (arr[j] < arr[j + 1]) flag = 1;
		}
		if (flag) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}