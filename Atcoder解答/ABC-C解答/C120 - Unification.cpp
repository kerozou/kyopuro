#include <bits/stdc++.h>
using namespace std;

// 消し方によらず、0 と 1 の個数で決まるという点に着目したい。
// この前の移動手段の問題と似ていて、ボトルネックになる部分に着目することが重要な問題。

// あと、細かい点として、int a,b = 0;　みたいな初期化はOUT。int a = 0; int b = 0;と分けるように。

int main(){
    string S;
    cin >> S;
    int r = 0;
    int b = 0;
    for (int i = 0; i < S.size() ; i++){
        if(S[i] == '0'){
            r += 1;
        }
        else {
            b += 1;
        }
    }
    cout << min(r,b)*2 << endl;
}

// 20190516 AC