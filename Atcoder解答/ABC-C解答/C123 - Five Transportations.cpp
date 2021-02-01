#include <bits/stdc++.h>
using namespace std;
// C - Five Transportations 123 を解こう　明日

// 解きます


int main(){
    long long int N,A,B,C,D,E;
    cin >> N >> A >> B >> C >> D >> E ;
    cout << max({(N-1)/A,(N-1)/B,(N-1)/C,(N-1)/D,(N-1)/E,}) + 5 << endl;
}


//　ぴったり賞だったときを除くために -1 してる。　+でやると、めんどい。
//  long　long　を使う点と、max、minを3つ以上に使う時は、
//  ({ , , , })というように中にさらに{}を挟む必要がある。

//20190515 AC