#include<bits/stdc++.h>
using namespace std;
int edge;
int vertex;
int maxxdist[100];
vector<int>adcen[100];
int solv(int dis);
int main()
{
    memset(maxxdist, -1, sizeof(maxxdist));
    maxxdist[1] =0;
    cout<<"enter the number of vertex and then edge>>";
    cin>>vertex>>edge;
    int dist;
    cout<<"which one is your destination  node>>";
    cin>>dist;

    for(int i=0; i<edge; i++)
    {
        int u,v;
        cin>>u>>v;
        adcen[v].push_back(u);
    }
    cout<< solv( dist);
    return 0;
}
int solv(int dis)
{
    if(dis==1)return 0;
    if(maxxdist[dis]!=-1)return maxxdist[dis];
    int ans =0;
    for(auto i:adcen[dis])
    {
        ans = max(ans+1,solv(i)+1);
    }
    maxxdist[dis] = ans;
    return  maxxdist[dis];
}

