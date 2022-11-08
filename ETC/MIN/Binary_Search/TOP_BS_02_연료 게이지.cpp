#include <iostream>
#include <string>
using namespace std;

int N;
string temp;

int getGage(int s, int e) {
	int whereGage = -1;
	while (s <= e) {
		int mid = (s + e) / 2;

		if (temp[mid] == '#') {
			whereGage = mid;
			s = mid + 1;
		}
		else e = mid - 1;
	}
	return whereGage;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		int gage = getGage(0, temp.size() - 1);
		cout << ((gage + 1) * 100) / temp.size() << "%\n";
	}
	return 0;
}