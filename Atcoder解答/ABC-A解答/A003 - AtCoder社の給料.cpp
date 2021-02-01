#include <bits/stdc++.h>
using namespace std;

// 10行目の平均値を出す計算で除算を最後にしないと、計算値が狂うので注意（1敗）

main(){
    int N,sum;
    cin >> N ;
    sum = ((N+1)*N)/2 ;
    int ave = (sum * 10000) / N;
    cout << ave << endl;
}