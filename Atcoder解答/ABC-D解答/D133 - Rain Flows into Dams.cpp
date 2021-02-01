#include <bits/stdc++.h>
using namespace std;
#define  rep(i, n) for(int i = 0; i < n; i++) 
typedef long long int LL;

////
int main(){
    // 入力
    LL N;cin >> N;
    vector<LL> A(N);
    rep(i,N)cin >> A[i];

    // 全体の降雨量
    LL sum_1 = 0;
    rep(i,N)sum_1 += A[i];

    // x0 以外の各 xi の和
    LL sum_2 = 0;
    rep(i,N){
        if(i % 2 == 0)continue;
        else sum_2 += A[i];
    }
    sum_2 *= 2;         // 全体の降雨量から x0 を除いたものにするために2倍

    // x0 生成
    vector<LL> x(N);    // 各山の降雨量vector生成
    x[0] = sum_1 - sum_2;

    // 各 xi 生成
    rep(i,N){
        if(i == 0)continue;
        x[i] = 2*A[i-1] - x[i-1];
    }

    // 出力
    rep(i,N)cout << x[i] << " ";
    
}

