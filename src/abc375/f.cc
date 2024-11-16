#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Max=300+10;
const int inf=0x3f3f3f3f3f3f3f3f;
int n,m,q;
struct E {
	int u;
	int v;
	int w;
} edge[Max*Max];
struct A {
	int opt;
	int x;
	int y;
	int res;
} Q[200010];
bool vis[Max*Max];
int G[Max][Max];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++){
		cin>>edge[i].u>>edge[i].v>>edge[i].w;
	}
	for(int i=1;i<=q;i++){
		cin>>Q[i].opt;
		if(Q[i].opt==1){
			cin>>Q[i].x;
			vis[Q[i].x]=1;
		} else {
			cin>>Q[i].x>>Q[i].y;
		}
	}
	memset(G,0x3f,sizeof G);
	for(int i=1;i<=n;i++){
		G[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		if(vis[i]){
			continue;
		}
		G[edge[i].u][edge[i].v]=edge[i].w;
		G[edge[i].v][edge[i].u]=edge[i].w;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
			}
		}
	}
	for(int i=q;i>=1;i--){
		if(Q[i].opt==1){
			for(int u=1;u<=n;u++){
				for(int v=1;v<=n;v++){
					G[u][v]=min(G[u][v],G[u][edge[Q[i].x].u]+edge[Q[i].x].w+G[edge[Q[i].x].v][v]);
					G[u][v]=min(G[u][v],G[u][edge[Q[i].x].v]+edge[Q[i].x].w+G[edge[Q[i].x].u][v]);
				}
			}
		} else {
			Q[i].res=G[Q[i].x][Q[i].y];
		}
	}
	for(int i=1;i<=q;i++){
		if(Q[i].opt==2){
			if(Q[i].res==inf){
				cout<<-1<<'\n';
				continue;
			}
			cout<<Q[i].res<<'\n';
		}
	}
	return 0;
}

/*
time:
mem:
*/
