#include <iostream>
#include <string>
using namespace std;

int main() {
	string s; cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			cout << char(s[i] - 'a' + 'A');
		}
		else cout << s[i];
	}
	return 0;
}