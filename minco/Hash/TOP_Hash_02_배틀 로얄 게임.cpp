#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;
int N;
unordered_map<string, vector<int>> list1;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string team; int n;
		cin >> team >> n;
		if (list1[team].empty()) {
			list1[team].push_back(0);
			list1[team].push_back(0);
		}
		list1[team][0]++;
		list1[team][1] += n;
	}
	string t1, t2;
	cin >> t1 >> t2;
	cout << list1[t1][0] << " " << list1[t1][1] << "\n";
	cout << list1[t2][0] << " " << list1[t2][1] << "\n";
	if (list1[t1][1] > list1[t2][1]) cout << t1;
	else cout << t2;
	return 0;
}