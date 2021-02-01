std::vector<bool> IsPrime;
void sieve(LL max){
    if(max+1 > IsPrime.size()){     // resizeで要素数が減らないように
        IsPrime.resize(max+1,true); // IsPrimeに必要な要素数を確保
    } 
    IsPrime[0] = false; // 0は素数ではない
    IsPrime[1] = false; // 1は素数ではない

    for(LL i=2; i*i<=max; ++i) // 0からsqrt(max)まで調べる
        if(IsPrime[i]) // iが素数ならば
            for(LL j=2; i*j<=max; ++j) // (max以下の)iの倍数は
                IsPrime[i*j] = false;      // 素数ではない
}



// エラトステネスの篩
// 一応O(NloglogN)らしい。
// もっとやばい高速化もできるっぽい。ぐぐろう。

// IsPrime に収納される。
// size_t を LL に変えた。