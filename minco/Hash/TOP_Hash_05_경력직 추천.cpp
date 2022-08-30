#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int N;
unordered_map<string, vector<string>> um;

void recommand(string ID, string name) {
	um[ID].push_back(name);
	um[name].push_back(ID);
	cout << um[ID].size() << "\n";
}

void print(string ID) {
	if (um.count(ID)) {
		for (auto it = um[ID].begin(); it != um[ID].end(); it++) {
			cout << *it << " ";
		}
		cout << "\n";
	}
	else cout << "none\n";
}

void whois(string name) {
	if (um.count(name)) {
		sort(um[name].begin(), um[name].end());
		for (auto it = um[name].begin(); it != um[name].end(); it++) {
			cout << *it << " ";
		}
		cout << "\n";
	}
	else cout << "none\n";
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string cmd, ID, name;
		cin >> cmd;
		if (cmd == "recommand") {
			cin >> ID >> name;
			recommand(ID, name);
		}
		if (cmd == "print") {
			cin >> ID;
			print(ID);
		}
		if (cmd == "whois") {
			cin >> name;
			whois(name);
		}
	}
	return 0;
}