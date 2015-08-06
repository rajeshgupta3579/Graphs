#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
int visited[1000]={0},indegree[1000]={0};
using namespace std;
void topologicalsort(vector<vector<pair<int,int> > > g,int V)
{
    queue<int> q;
    int counter=0;
    for(int i=0;i<V;i++)
    {
        if(indegree[i]==0)
            q.push(i);
    }
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        cout<<v<<endl;
        counter++;
        for(int j=0;j<g[v].size();j++)
        {
            indegree[g[v][j].first]--;
            if(indegree[g[v][j].first]==0)
                q.push(g[v][j].first);

        }
    }
    if(counter!=V)
        cout<<"Graph has cycles\n";

}
void shortestPath(vector<vector<pair < int , int > > > g,int v,int s){
    pair<int,int> dist[v+1];
    queue<int> q;
    int i;
    for(i=0;i<v;i++){
        dist[i].first = -1;
    }
    dist[s].first = 0;
    dist[s].second = s;
    q.push(s);
    int node;
    while(!q.empty()){
        node = q.front();
        q.pop();
        for(i=0;i<g[node].size();i++){
            if(dist[g[node][i].first].first==-1){
                dist[g[node][i].first].first=dist[node].first+1;
                dist[g[node][i].first].second = node;
                q.push(g[node][i].first);
            }
        }
    }
    printf("Shortest Path=\n");
    for(i=0;i<v;i++){
        printf("%d %d\n",dist[i].first,dist[i].second);
    }
}

void dfs( vector<vector<pair<int,int> > > g ,int v)
{
    visited[v]=1;
    cout<<v<<endl;
    for(int i=0;i<g[v].size();i++)
    {
        if(visited[g[v][i].first]==0)
        {
            dfs(g,g[v][i].first);
        }
    }
}
void bfs(vector<vector<pair<int,int> > > g ,int v)
{
    queue<int> q;
    q.push(v);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        cout<<x<<endl;
        visited[x]=1;
        for(int i=0;i<g[v].size();i++)
        {
            if(visited[g[v][i].first]==0)
            {
                q.push(g[v][i].first);
            }
        }
    }
}
int main()
{
    int i,j;
    pair<int,int> temp;
    int n,v,dest,wt,src;
    cout<<"enter no of vertices\n";
    cin>>v;
    cout<<"enter no of edges\n";
    cin>>n;
    vector<vector<pair<int,int> > > graph(v+1);
    for(int i=0;i<n;i++)
    {
        cout<<"enter src and dest and weight";
        cin>>src>>dest>>wt;
        temp.first=dest;
        temp.second=wt;
        graph[src].push_back(temp);
        indegree[dest]++;
    }
    for(i=0;i<graph.size();i++)
    {
        for(j=0;j<graph[i].size();j++)
        {
            cout<< graph[i][j].first <<" "<<graph[i][j].second <<"\n";
        }
    }

    for(i=0;i<v;i++)
        visited[i]=0;
    for(i=0;i<v;i++)
    {
        if(visited[i]==0)
            dfs(graph,i);
    }
    for(i=0;i<v;i++)
        visited[i]=0;
    for(i=0;i<v;i++)
    {
        if(visited[i]==0)
            bfs(graph,i);
    }
    cout<<endl<<endl;
    topologicalsort(graph,v);
    shortestPath(graph,v,1);
    return 0;
}
