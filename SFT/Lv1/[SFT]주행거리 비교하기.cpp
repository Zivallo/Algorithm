#include<iostream>
using namespace std;
int A,B;

int main(int argc, char** argv)
{
	cin>>A>>B;
	if(A>B)cout<<"A\n";
	else if(A==B)cout<<"same\n";
	else cout<<"B\n";
	return 0;
}