#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    int count = 0;
    bool wait = true;
    for(int i = 0; i < n - 1; i++){
        if(s[i] == 'D' && s[i + 1] != 'D' && wait == false){
            wait = true;
            continue;
        }
        if(s[i] == 'D' && wait == true){
            count++;
            wait = false;
        }
    }
    if(wait == true && s[n - 1] == 'D') count++;
    return count;   
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
