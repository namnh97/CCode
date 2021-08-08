#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;

 

int maxint=1e9+7;

int n=12;

int he[12][12];

int a[12];

vector<int> ke[12];

int res,solved;

 

 

void init_edge()

{

    int dk[]= {1,3,6,12};

    for(int i=0; i<12; i++)

    {

        for(int j=i+1; j<12; j++)

        {

            he[i][j]=he[j][i]=maxint;

            bool ok=false;

            int k=0;

            for(k=0; k<4; k++)

                if(abs(i-j)==dk[k])

                {

                    ok=true;

                    break;

                }

            if(!ok) continue;

            int sc=dk[k+1];

            if(floor(i/sc)==floor(j/sc))

            {

                ke[i].push_back(j);

                ke[j].push_back(i);

                he[i][j]=he[j][i]=1;

            }

        }

        he[i][i]=0;

    }

}

 

void init_he()

{

    for(int k=0; k<n; k++)

        for(int i=0; i<n; i++)

            for(int j=0; j<n; j++)

                he[i][j]=min(he[i][j],he[i][k]+he[k][j]);

}

 

inline int DFS(int cur,int pre,int sum_he,int dep)

{

    if(sum_he==0)

    {

        solved=dep;

        return solved;

    }

 

    if(dep+sum_he>res) return dep+sum_he;

    int res2=maxint;

    int save_he=sum_he;

 

    for(int j:ke[cur])

    {

        if(j==pre) continue;

        sum_he-=he[j][a[j]];

        swap(a[cur],a[j]);

        sum_he+=he[cur][a[cur]];

        int tmp=DFS(j,cur,sum_he,dep+1);

        if(solved!=0) return solved;

        sum_he=save_he;

        swap(a[cur],a[j]);

        res2=min(tmp,res2);

    }

    return res2;

}

 

void solve()

{

    int l0;

    for(int i=0; i<12; i++) cin>>a[i],a[i]==0?l0=i:1;

 

    res=0;

    int sum_he=0;

    for(int i=0; i<12; i++) i==l0?1:sum_he+=he[i][a[i]];

    if(sum_he==0)

    {

        cout<<0<<endl;

        return;

    }

 

    solved=0;

    res=sum_he;

    while (solved==0)

    {

        res=DFS(l0,-1,sum_he,0);

    }

    cout<<solved<<endl;

}

 

int main()

{

    init_edge();

    init_he();

    int T;

    cin>>T;

    while(T--) 

		solve();

    return 0;

}