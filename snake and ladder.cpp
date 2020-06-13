#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;
class Graph
{
    int V;
    map<int , list<int>>AdjList;
public:
    Graph(int v)
    {   
        V=v;
    }
    void addEdge(int v,int u,bool bidir=true)
    {
        AdjList[v].push_back(u);
        if(bidir)
        {   
           AdjList[u].push_back(v);
        }
    }
    void print()
    {   
        for(auto obj:AdjList)
        {
            cout<<obj.first<<"->";
            for(auto entry:obj.second)
            {
                cout<<entry<<" ";
            }
            cout<<endl;
        }
    }
    int bfs(int source,int destination)
    {
        int dest[50]={0};
        queue<int>q;
        map<int,bool>visited;
        map<int,int>parent;
        q.push(source);
        dest[source]=0;
        visited[source]=true;
        while(!q.empty())
        {
            int node;
            node=q.front();
            //cout<<node<<" "<<endl;
            q.pop();
            for(auto neighbour:AdjList[node])
            {
                if(!visited[neighbour])
                {
                    q.push(neighbour);
                    dest[neighbour]=dest[node]+1;
                    visited[neighbour]=true;
                    parent[neighbour]=node;
                }
            }

        }
        int temp=destination;
        while(temp!=source)
        {
            cout<<temp<<"<--";
            temp=parent[temp];
        }
        cout<<source;
        cout<<endl;
        return dest[destination];


    }
};
int main()
{
    Graph g(37);
    int board[50]={0};
    board[2]=13;
    board[5]=2;
    board[9]=18;
    board[18]=11;
    board[17]=-13;
    board[20]=-14;
    board[24]=-8;
    board[25]=-10;
    board[32]=-2;
    board[34]=-22;
    for(int u=0;u<=36;u++)
    {

        for(int dice=1;dice<=6;dice++)
        {
            int v=u+dice+board[u+dice];
            g.addEdge(u,v);
        }
    }
    int s=g.bfs(0,36);
    cout<<"the shortest path is :"<<s;
    return 0;

}
