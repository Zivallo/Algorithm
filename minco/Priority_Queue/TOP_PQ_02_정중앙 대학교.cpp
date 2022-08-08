#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue < int, vector<int>, greater<int>> minpq;
priority_queue<int> maxpq;
int N, middle = 500;


int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2; j++) {
			int temp;
			cin >> temp;
			if (temp > middle) minpq.push(temp);
			else maxpq.push(temp);
		}
		int gap = maxpq.size() - minpq.size();
		if (gap == 0) {
			cout << middle << "\n";
		}
		else if (gap < 0) {
			for (int k = 0; k > gap / 2; k--) {
				maxpq.push({ middle });
				middle = minpq.top();
				minpq.pop();
			}
			cout << middle << "\n";
		}
		else if (gap > 0) {
			for (int k = 0; k < gap / 2; k++) {
				minpq.push({ middle });
				middle = maxpq.top();
				maxpq.pop();
			}
			cout << middle << "\n";
		}
	}
	return 0;
}