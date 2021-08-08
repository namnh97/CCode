#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Block {
    int dimensions[3];
    Block(int x, int y, int z) {
        dimensions[0] = x;
        dimensions[1] = y;
        dimensions[2] = z;
    }

    bool operator < (const Block &other) const {
        for (int i = 0; i < 3; i++) {
            if (dimensions[i] > other.dimensions[i]) {
                return true;
            }
            if (dimensions[i] < other.dimensions[i]) {
                return false;
            }
        }
        return true;
    }

    bool canStack(const Block &other) {
        if (dimensions[0] < other.dimensions[0] && dimensions[1] < other.dimensions[1]) {
            return true;
        }
        return false;
    }

    int getHeight() {
        return dimensions[2];
    }
};

void addBlocks(vector<Block> &blocks, int x, int y, int z) {
    int a[] = {x, y, z};
    sort(a, a + 3);
    do {
        blocks.push_back(Block(a[0], a[1], a[2]));
    } while (next_permutation(a, a + 3));
}

int findLis(vector<Block> &blocks) {
    vector<int> height(blocks.size());
    int res = 0;
    for (int i = 0; i < blocks.size(); i++) {
        height[i] = blocks[i].getHeight();
        for (int j = 0; j < i; j++) {
            if (blocks[i].canStack(blocks[j])) {
                height[i] = max(height[i], height[j] + blocks[i].getHeight());
            }
        }
        res = max(res, height[i]);
    }
    return res;
}

void solve() {
    int n;
    int cases = 1;
    while (cin >> n) {
        if (n == 0) break;
        vector<Block> blocks;
        for (int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            addBlocks(blocks, x, y, z);
        }
        sort(blocks.begin(), blocks.end());
        int res = findLis(blocks);
        cout << "Case " << cases++ << ": maximum height = " << res << endl;
    }
}



int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
    freopen(argv[1], "r", stdin);
    #endif
    solve();
    return 0;
}


