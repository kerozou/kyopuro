#include <iostream>
#include <vector>
using namespace std;

typedef pair<int,int> pint;
typedef pair<pint,pint> ppint;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int> > a(H, vector<int>(W, 0));
    int odd = 0;
    for (int i = 0; i < H; ++i) for (int j = 0; j < W; ++j) {
        cin >> a[i][j];
        if (a[i][j] & 1) ++odd;
    }
    
    vector<ppint> res;
    int num = 0;
    int x = 0, y = 0;
    for (int iter = 0; iter < W*H; ++iter) {
        if (a[x][y] & 1) ++num;
            
        int nx = x, ny = y;
        if (x % 2 == 0) {
            if (ny == W-1) ++nx;
            else ++ny;
        }
        else {
            if (ny == 0) ++nx;
            else --ny;
        }
        if (num & 1) if (num < odd) res.push_back(ppint(pint(x, y), pint(nx, ny)));
        x = nx, y = ny;
    }
        
    cout << res.size() << endl;
    for (auto p : res) {
        cout << p.first.first+1 << " " << p.first.second+1 << " " << p.second.first+1 << " " << p.second.second+1 << endl;
    }
}

// ABC109 D - Make Them Even

// 3回実装したけどバグりまくったからけんちょんさんのコードまんま
// http://drken1215.hatenablog.com/entry/2018/09/08/233600

// x が縦軸で yが横軸になってる

