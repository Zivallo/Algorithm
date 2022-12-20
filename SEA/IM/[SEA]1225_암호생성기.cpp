#include <iostream>
using namespace std;

int list[10];

void swap_list() {
	for (int i = 0; i < 7; i++) {
		swap(list[i], list[i + 1]);
	}
}

int main() {
	/*freopen_s(new FILE*, "input.txt", "r", stdin);*/
	for (int tc = 1; tc <= 10; tc++) {
		int t;
		cin >> t;
		for (int i = 0; i < 8; i++) {
			cin >> list[i];
		}
		int idx = 1;
		while (1) {
			list[0] -= idx;
			if (list[0] <= 0) {
				list[0] = 0;
				swap_list();
				break;
			}
			swap_list();
			idx++;
			if (idx == 6) idx = 1;
		}
		cout << "#" << t << " ";
		for (int i = 0; i < 8; i++) {
			cout << list[i] << " ";
		}
		cout << '\n';
	}
	return 0;
}