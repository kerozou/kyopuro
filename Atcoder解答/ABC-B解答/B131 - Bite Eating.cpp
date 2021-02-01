#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  INF 1000000000
#define  pow(x) pow(10,(x)) 
typedef long long int LL;

int main(){
    int N,L ; cin >> N >> L;
    int sum = N * (L-1) + N * (N+1)/2; //Σ(L+i-1)
    int tmp;
    int res;
    rep(i,N){
        if(i == 0){
            res = L+i; //n
            continue;
        }
        tmp = L+i; //n+1
        if(abs(tmp) > abs(res)){
            continue;
        }
        else{
            res = tmp;
            continue;
        }
    }
    cout << sum - res << endl;
}