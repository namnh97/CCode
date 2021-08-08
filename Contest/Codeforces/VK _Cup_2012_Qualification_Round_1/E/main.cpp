#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define FORD(i, a, b) for (int i = (a), _##i = (b); i >= _##i; --i)
#define DEBUG(X) { auto _X = (X); cerr << "L" << __LINE__ << ": " << #X << " = " << (_X) << endl; };

using namespace std;

const int MAX = 4007;
int dp[MAX][MAX], n, k;

struct Node{
	int t, d;
	bool operator<(const Node &a) const {
	  	return t < a.t;
	};
}p[MAX];


int main(void){
    while (cin >> n >> k)
    {
        for ( int i = 0 ; i < n ; i ++ ) {
            scanf ( "%d%d" , &p[i].t , &p[i].d );
        }
        sort ( p , p+n );
        p[n].t = 86401;
        dp[0][1] = 0;
        dp[0][0] = p[0].t+p[0].d-1;
        if ( k == n )
        {
            puts ( "86400" );
            continue;
        }
        for ( int i = 1 ; i < n ; i++ )
        {
            dp[i][0] = max ( p[i].t-1 , dp[i-1][0] ) + p[i].d;  //time start + duration
            for ( int j = 1 ; j <= k && j <= i; j++ )
            {
                int xx = p[i].t-1; //time start at i 
                if ( i-1 >= j ) xx = max ( xx , dp[i-1][j] );
                dp[i][j] = min ( xx + p[i].d, dp[i-1][j-1] );
            }
        }
        int ans = 0;
        for ( int i = 0 ;i < n ; i++ )
            for ( int j = 0 ; j <= k ; j++ )
            {
                int x = min ( n , k-j+i+1 );
                ans = max ( ans , p[x].t-1 - dp[i][j] );
            }
        printf ( "%d\n" , ans );
    }	
    return 0;
}
            	