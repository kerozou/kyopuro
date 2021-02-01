#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1000000000
#define  pow(x) pow(10,(x)) 
typedef long long int LL;
const int MOD = 1000000007;
//sort(all(x))とするとソートできるよ

//vectorにソートした入力を入れる。
//今回はNが偶数なので、N/2　と　(N/2)+1　の間で区切れる。
//同じ数になるということなので、これら2つが＝になるとOUT。
//あとは、0インデックスに注意して、（N/2)+1　-　（N/2)　個をcoutすればよい。
int main(){
    int N;cin >> N;
    vector<int> v(N);
    rep(i,N){
        cin >> v[i];
    }
    sort(all(v));
    if(v[(N-1)/2] == v[((N-1)/2)+1]){
        cout << 0 << endl;
    }
    else{
        cout << v[((N-1)/2)+1] - v[(N-1)/2] << endl;
    }
}