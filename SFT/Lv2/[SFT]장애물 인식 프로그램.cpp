#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int map[30][30];
int u[30][30];
int N,c;
int drY[4]={1,-1,0,0};
int drX[4]={0,0,-1,1};

void input(){
	cin>>N;char c;
	for(int y=0;y<N;y++)for(int x=0;x<N;x++){
		cin>>c;
		map[y][x]=c-'0';
	}
}
void search(int y,int x){
	u[y][x]=1;
	c++;
	for(int i=0;i<4;i++){
		int ny=y+drY[i];
		int nx=x+drX[i];
		if(ny<0||nx<0||ny>=N||nx>=N)continue;
		if(map[ny][nx]==0)continue;
		if(u[ny][nx]==1)continue;
		search(ny,nx);
	}
}
void solve(){
	input();vector<int>ans;
	for(int y=0;y<N;y++){
		for(int x=0;x<N;x++){
			if(map[y][x]==1&&u[y][x]==0){
				c=0;
				search(y,x);
				ans.push_back(c);
			}
		}
	}
	cout<<ans.size()<<"\n";
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<"\n";
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