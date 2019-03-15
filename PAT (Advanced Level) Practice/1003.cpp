#include <cstdio>
const int INF=9999999;
const int max=500;
int dis[max];//到每个点距离 
int path[max][max];
int rescue[max];//每点救援队数 
int amount[max];//可以得到的救援队数 
int pathcount[max];//最短距离数 
int city, road, start, dest;
bool book[max];//记录到每点是否最短 

void dijkstra(int a){
    dis[a]=0;
    amount[a]=rescue[a];
    book[a]=1;
    int u=a;
    for(int i=0;i<city;i++){
    	dis[i]=path[a][i];
    	if(dis[i]!=INF&&i!=a){
    		amount[i]=amount[a]+rescue[i];
		}
	}
	for(int i=0;i<city;i++){
		int min=INF;
		for(int j=0;j<city;j++){
			if(book[j]!=1&&dis[j]<min){
				u=j;
				min=dis[j];
			}
		}
		book[u]=1;
		for(int v=0;v<city;v++){
			if(book[v]!=1&&dis[v]>dis[u]+path[u][v]){
				dis[v]=dis[u]+path[u][v];
				amount[v]=amount[u]+rescue[v];
				pathcount[v]=pathcount[u];
			}
			else if(book[v]!=1&&dis[v]==dis[u]+path[u][v]){
				pathcount[v]+=pathcount[u];
				if(amount[v]<rescue[v]+amount[u]){ 
					amount[v]=rescue[v]+amount[u];
				} 
			}
		}
	}
}

int main(){
    scanf("%d%d%d%d",&city,&road,&start,&dest);
    for (int i=0;i<city;i++){
        scanf("%d",&rescue[i]);
    }
    for (int i=0;i<city;i++){//初始化 
        dis[i]=INF;
        pathcount[i]=1;
        book[i]=0;
        for (int j=0;j<city;j++){
            path[i][j]=INF;
        }
    }
    int p1,p2,p3;
    for (int i=0;i<road;i++){/ 
        scanf("%d %d %d",&p1,&p2,&p3);
        path[p1][p2]=p3;
        path[p2][p1]=p3;
    }
    dijkstra(start);
    
    printf("%d %d",pathcount[dest],amount[dest]);
    return 0;
}
