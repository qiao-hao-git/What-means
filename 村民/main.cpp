int main(){
    while(m--){
        scanf("%d%d",&a,&b);
        memset(head,-1,sizeof(head));
        memset(vis,0,sizeof(vis));
        dijkstra();
        printf("%d\n",dis[b]);
    }

}
