#include <bits/stdc++.h>
using namespace std;

//i番目を抜き去ったgcd(i)の最大値を求める問題。
//gcdは整数が3つ以上ある時、前二つと残りの一つの最大公約数と等しいという性質があるので、
//n個の整数の時も同様にforループで作れる。
//つまり、i番目までのgcdと、i+1番目以降のgcdのgcdを取ってあげて、それらのMAXをforループで探索する。
//その際に、左側と右側の処理と、それをまとめてmaxを探す処理が必要になる。

int get_gcd(int n,int N,long long int *Z){ // nは抜き去る数、Nは総数をスコープできるようにしてるだけ
   

    //main
    if(n == 0){ // n=0のときは、手書き
        long long int temp2 = gcd(Z[1],Z[2]);
        for(int k = 3; k < N ;k++){
            temp2 = gcd(temp2,Z[k]);
                   
        }
        return temp2;
    }
    else if (n == 1){
        long long int temp3 = gcd(Z[0],Z[2]);
        for(int l = 3;l < N ; l++){
            temp3 = gcd(temp3,Z[l]);     
         
        }
        return temp3;
    }
    else{
        long long int temp = gcd(Z[0],Z[1]);

        for (int j = 2 ; j < n ;j++){ // このｊはn番目までの左gcdループ
            temp = gcd(temp,Z[j]);
        }

        for (int m = n+1 ; m < N ;m++){ // 右ループ
            temp = gcd(temp,Z[m]);
        }

        return temp;
    }

// get_gcd関数はどのルートでもforループはｋN回なので、O(N)であるはず。
// しかし、これをmaxループで使うと、O(N^2)になってしまう。
// すると、N<=10^5より、10^10に速度比例すると爆死。
// なので、これを改善する方法がないとやばい。
// (やはりこの問題が鍵になってるっぽい)

}

}
int main(){
    int N;
    long long int Z[N];
    for (int i = 0 ; i < N ; i++){
        cin >> Z[i] ;
    }

    // ここからmaxループ
    long long int memo[N,0];

    for(int p = 0;p < N;p++){
        if(memo[p] != 0){

        }
    }
}


// 累積和の話を勉強してからもっかいチャレンジ