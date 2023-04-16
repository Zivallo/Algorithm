#include <iostream>
#include <string>
using namespace std;

bool validCheck(int arr[4]) {
	if (arr[1] >= 0 && arr[1] <= 9) {
		if (arr[2] != 0 && arr[3] != 0)return false;
		else return true;
	}
	if (arr[1] == 21e8) {
		if (arr[2] == 0 && arr[3] == 0)return false;
		else return true;
	}
	return false;
}
void solve() {
	for (int t = 1; t <= 10; t++) {
		int valid = 1; string f;
		getline(cin, f);
		int n = stoi(f);
		for (int i = 1; i <= n; i++) {
			getline(cin, f);
			int check[4] = { 0 }, idx = 0;
			int xptr = 0, ptr = f.find(' ', xptr);
			while (ptr != -1) {
				string temp = f.substr(xptr, ptr - xptr);
				if (temp == "+" || temp == "-" || temp == "*" || temp == "/")check[idx++] = 21e8;
				else check[idx++] = stoi(temp);
				xptr = ptr + 1;
				ptr = f.find(' ', xptr);
			}
			string temp = f.substr(xptr, f.length() - xptr + 1);
			if (temp == "+" || temp == "-" || temp == "*" || temp == "/")check[idx++] = 21e8;
			else check[idx++] = stoi(temp);
			if (!validCheck(check)) valid = 0;
		}
		cout << "#" << t << " " << valid << "\n";
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