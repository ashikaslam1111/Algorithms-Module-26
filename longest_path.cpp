#include<bits/stdc++.h>
using namespace std;
int main()
{
    int edge;
    int vertex;
    int maxxdist[100];
    memset(maxxdist, -1, sizeof(maxxdist));
    maxxdist[1] =0;
    cout<<"enter the number of vertex and then edge>>";
        cin>>vertex>>edge;
    int dist;
    cout<<"which one is your destination  node>>";
        cin>>dist;
    vector<int>adcen[vertex+1];
    for(int i=0; i<edge; i++)
    {
        int u,v;
        cin>>u>>v;
        adcen[u].push_back(v);
    }
    queue<int>q;
    q.push(1);
    while(!q.empty())
    {
        int head = q.front();
        q.pop();
        for(auto i:adcen[head])
        {
            if(maxxdist[head]+1>maxxdist[i])
            {
                maxxdist[i] = maxxdist[head]+1;
            }
            q.push(i);
        }
    }
    cout<<maxxdist[dist];
    return 0;
}
