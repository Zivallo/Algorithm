#include<iostream>
using namespace std;
int dig[11][7]={
	{1,1,1,1,1,1,0},
	{0,1,1,0,0,0,0},
	{1,1,0,1,1,0,1},
	{1,1,1,1,0,0,1},
	{0,1,1,0,0,1,1},
	{1,0,1,1,0,1,1},
	{1,0,1,1,1,1,1},
	{1,1,1,0,0,1,0},
	{1,1,1,1,1,1,1},
	{1,1,1,1,0,1,1},
	{0,0,0,0,0,0,0}
},T,A,B;

int getAns(int A,int B){
	int ret=0;
	while(A){
		for(int i=0;i<7;i++){
			(dig[A%10][i]==dig[(B==0?10:B%10)][i]?:ret++);
		}
		A/=10;B/=10;
	}
	return ret;
}
void solve(){
	cin>>T;for(int t=1;t<=T;t++){
		cin>>A>>B;
		int r = getAns((A>B?A:B),(A>B?B:A));
		cout<<r<<"\n";
	}
}
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}