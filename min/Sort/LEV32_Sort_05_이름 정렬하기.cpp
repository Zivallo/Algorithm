#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Info {
	string name;
	int len;
};

Info info[100];

bool compare(Info t, Info v) {
	if (t.len != v.len) return t.len < v.len;
	else return t.name < v.name;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> info[i].name;
		info[i].len = info[i].name.length();
	}

	sort(info, info + n, compare);

	for (int i = 0; i < n; i++) {
		cout << info[i].name << '\n';
	}

	return 0;
}