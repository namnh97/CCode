#include<bits/stdc++.h>

using namespace std;

class TurretDefense{
public:
    int firstMiss(vector<int> xs, vector<int> ys, vector<int> times){
        int x = 0;
        int y = 0;
        int t = 0;
        for(int i = 0; i < n; i++){
            int res = t + abs(x - xs[i]) + abs(y - ys[i]);
            if(res > times[i]){
                return i;
            }
            x = xs[i];
            y = ys[i];
            t = times[i];
        }
        return -1;
    }
};