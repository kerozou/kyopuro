#include <bits/stdc++.h>
using namespace std;

// 方針
// 全体として、クリアできるパターンが

// 1,白黒白黒白　パターン 10101
// 2,黒白黒白黒　パターン 01010

// の2通りしかない。
// なので、総当りでこれにすればよさそう。
// Sは高々10^5なので、O(N)ならいける。

// とりあえず1番ルートで終わる過程でforループをまわす。
// 010101010　に一致しているか一文字づつチェックして、一致していない数をカウント。
// そのカウント数nが n  >= |S|/2 で場合わけして、超えてなかったらカウントした数が答え。
// 超えてたら、2番のパターンなので、S-n が答えになる。
// これはO(N)のはず。

int main(){
    string S;
    cin >> S;
    int count = 0;
    for(int i = 0;i < S.size();i++){

        if(S[i] == '0'){
            if(i % 2 == 0){ // 偶数個目
                continue;
            }
            else { //　奇数個目
                count += 1;
            }
        }
        else if(S[i] == '1'){
            if(i % 2 == 0){
                count += 1; // 偶数
            }
            else { // 奇数
                continue;
            }
        }
    }
    if(count > (S.size() / 2 ) ){ // >=　とすると、入力が0とかの時に成り立たなくなる。
        cout << S.size() - count << endl;
    }
    else{
        cout << count << endl;
    }
}

// 20190514 AC