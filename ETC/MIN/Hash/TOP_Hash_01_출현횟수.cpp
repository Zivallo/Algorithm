#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int M, N;
unordered_map<int, int > list1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		int temp;
		cin >> temp;
		list1[temp]++;
	}
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		if (list1.count(temp)) {
			cout << list1[temp] << " ";
		}
		else cout << 0 << " ";
	}

	return 0;
}