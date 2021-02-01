#include <bits/stdc++.h>
#include <bitset>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1000000000
#define  pow(x) pow(10,(x)) 
typedef long long int LL;
const int MOD = 1000000007;
//sort(all(x))とするとソートできるよ

int main(){
    int N,M,L;
    cin >> N >> M >> L;
    vector<int> bit_flag(10);
    rep(i,8){
        bit_flag[i] = (1 << i);
    }
    int bit = bit_flag[N] | bit_flag[M] | bit_flag[L];
    cout << "bit " << "= " << bitset<8>(bit) << endl;
    int bit2 = bit_flag[2] | bit_flag[3] | bit_flag[4];
    cout << "bit & bit2 = " << bitset<8>(bit & bit2) << endl;
    cout << "bit | bit2 = " << bitset<8>(bit | bit2) << endl;

    if(bit & bit_flag[5]){
        cout << "bit_5 = ON" << endl;
    }
    else{
        cout << "bit_5 = OFF" << endl;
    }

    if(!(bit & bit_flag[2])){
        cout << "bit_2 = OFF" << endl;
    }
    else{
        cout << "bit_2 = ON" << endl;
    }

    bit |= bit_flag[6];
    cout << "bit = " << bitset<8>(bit) << endl;
    bit &= ~bit_flag[6];
    cout << "bit = " << bitset<8>(bit) << endl;

    int res = __builtin_popcount(bit);
    cout << "bitの内何本立っているか : " << res << endl;
}   