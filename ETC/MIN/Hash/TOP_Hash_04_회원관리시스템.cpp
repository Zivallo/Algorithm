#include <iostream>
#include <unordered_map>
using namespace std;

struct INFO {
	string Pass;
	int isLogin;
};
unordered_map<string, INFO> um;
int N, numLogin;

void reg(string ID, string pass) {
	if (!um.count(ID)) {
		um[ID] = { pass,0 };
		cout << "welcome " << um.size() << "\n";
	}
	else cout << "reg fail\n";
}
void login(string ID, string pass) {
	if (um.count(ID)) {
		if (um[ID].Pass == pass && um[ID].isLogin == 0) {
			um[ID].isLogin = 1;
			numLogin++;
			cout << "login " << numLogin << "\n";
		}
		else cout << "login fail\n";
	}
	else cout << "login fail\n";
}

void changePass(string ID, string old, string newPass) {
	if (um.count(ID)) {
		if (um[ID].Pass == old) {
			um[ID].Pass = newPass;
			cout << "success\n";
		}
		else cout << "change fail\n";
	}
	else cout << "change fail\n";
}

void logout(string ID) {
	if (um.count(ID)) {
		if (um[ID].isLogin == 1) {
			um[ID].isLogin = 0;
			numLogin--;
			cout << "logout " << numLogin << "\n";
		}
		else cout << "logout fail\n";;
	}
	else cout << "logout fail\n";
}

void bye(string ID) {
	if (um.count(ID)) {
		if (um[ID].isLogin == 1) {
			numLogin--;
			um.erase(ID);
			cout << "bye " << um.size() << "\n";
		}
		else cout << "bye fail\n";
	}
	else cout << "bye fail\n";
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string cmd, ID, pass, newPass;
		cin >> cmd;
		if (cmd == "reg") {
			cin >> ID >> pass;
			reg(ID, pass);
		}
		if (cmd == "login") {
			cin >> ID >> pass;
			login(ID, pass);
		}
		if (cmd == "change") {
			cin >> ID >> pass >> newPass;
			changePass(ID, pass, newPass);
		}
		if (cmd == "logout") {
			cin >> ID;
			logout(ID);
		}
		if (cmd == "bye") {
			cin >> ID;
			bye(ID);
		}
	}
	return 0;
}