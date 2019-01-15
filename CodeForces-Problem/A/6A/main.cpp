#include <bits\stdc++.h>

using namespace std;

void sol(){
    int length[4];
    for(int i=0; i<4; i++){
        cin >> length[i];
    }
    sort(length, length + 4);
    if(length[0] + length[1] > length[2] || length[1] + length[2] > length[3]){
        printf("TRIANGLE\n");
    }
    else if(length[0] + length[1] == length[2] || length[1] + length[2] == length[3]){
        printf("SEGMENT\n");
    }
    else printf("IMPOSSIBLE\n");
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif // ONLINE_JUDGE
    sol();
    return 0;
}
