#include <iostream>
using namespace std;
int last[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int main() {
	int T; cin >> T; for (int t = 1; t <= T; t++) {
		int a; cin >> a;
		int y = a / 10000; 
		if (y>10000) cout << "#" << t << " -1\n";
		else {
			a %= 10000;
			int m = a / 100; 
			if(m<1||m>12)cout << "#" << t << " -1\n";
			else {
				int d = a % 100;
				if (d<1 || d>last[m]) cout << "#" << t << " -1\n";
				else {
					cout.fill('0');
					cout << "#" << t << " ";
					cout.width(4);
					cout << y << "/"; 
					cout.width(2);
					cout << m << "/";
					cout.width(2);
					cout << d << "\n";
				}
			}
		}
	}
	return 0;
}