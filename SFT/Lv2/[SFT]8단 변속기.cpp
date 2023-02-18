#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
	int a,b,c,dir;
	cin>>a>>b;
	dir=a-b;
	for(int i=0;i<6;i++){
		cin>>c;
		if(dir!=b-c){dir=0;break;}
		b=c;
	}
	if(dir==-1)cout<<"ascending\n";
	else if(dir==1)cout<<"descending\n";
	else cout<<"mixed\n";
	return 0;
}