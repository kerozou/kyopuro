#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1LL << 60
typedef long long int LL;
const int MOD = 1000000007;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }
//sort(all(x))とするとソートできるよ
// 10^x は pow(10,(x)) 
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

int main(){
    vector<int> L(3);
    rep(i,3)cin >> L[i];
    sort(all(L));
    int A = L[0];
    int B = L[1];
    int C = L[2];
    


    if(abs(A-C) % 2 == 0 && abs(B-C) % 2 == 0){     // abs がどっちも偶数
        cout << (abs(A-C)+abs(B-C))/2 << endl;      // 2++ の動作だけでいいので
    }
    else if(abs(A-C) % 2 != 0 && abs(B-C) % 2 != 0){    // abs がどっちも奇数
        cout << (abs(A+1-C)+abs(B+1-C))/2 +1 << endl;   // 1回A,Bそれぞれ1足して、以降は2++だけ
    }
    else{   //abs が　偶数　と　奇数
        if(abs(A-C) % 2 == 0){  // A-C が偶数、B-Cが奇数のとき
            cout << (abs(A-C)+abs(B-C-1))/2 + 1 << endl;
        }
        else{   // A-C が奇数、B-Cが偶数のとき
            cout << (abs(A-C-1)+abs(B-C))/2 + 1 << endl;
        }
    }
}