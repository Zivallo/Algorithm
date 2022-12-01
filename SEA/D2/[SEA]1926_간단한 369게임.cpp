#include <iostream>
#include <string>
using namespace std;

string print(int n) {
	int tmp = n;
	string s = "";
	while (tmp > 0) {
		if (tmp % 10 != 0 && (tmp % 10) % 3 == 0)s += "-";
		tmp /= 10;
	}
	if (s.length() == 0)return to_string(n);
	else return s;
}
int main() {
	int N; cin >> N;
	for (int i = 1; i <= N; i++)
		cout << print(i) << " ";
	return 0;
}