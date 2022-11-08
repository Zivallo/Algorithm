#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

unordered_map<string, int> um;
int main() {
	int N;
	cin >> N;
	int maxi = -1;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		int tempSize = temp.size();
		sort(temp.begin(), temp.end());
		um[temp]++;
		maxi = max(maxi, um[temp]);
	}
	cout << maxi;

	return 0;
}