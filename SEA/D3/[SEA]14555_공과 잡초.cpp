#include <iostream>
#include <stack>
#include <string>
using namespace std;
int T;
string str;
stack<char> s;

void solve() {
	cin >> T; for (int t = 1; t <= T; t++) {
		cin >> str; s = stack<char>(); int r = 0;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '|') {
				if (!s.empty())
					if (s.top() == '(') {
						r++;
						s = stack<char>();
					}
					else s.push('|');
				else s.push('|');
			}
			if (str[i] == '(')s.push('(');
			if (str[i] == ')') {
				if (s.top() == '|' || s.top() == '(') {
					r++;
					s = stack<char>();
				}
			}
		}
		cout << "#" << t << " " << r << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	solve();
	return 0;
}