#include<iostream>
#include<string>
using namespace std;
string s,e;

int getSec(){
	cin>>s>>e;int ret=0;
	int sh = s[0]*10+s[1];
	int sm = s[3]*10+s[4];
	int eh = e[0]*10+e[1];
	int em = e[3]*10+e[4];
	ret+=(eh-sh+(em-sm>=0?0:-1))*60;
	ret+=(em-sm+(em-sm>=0?0:60));
	return ret;
}
void solve(){
	int r=0;
	for(int i=0;i<5;i++){
		r+=getSec();
	}
	cout<<r<<"\n";
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}