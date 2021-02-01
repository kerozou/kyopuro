// x^y (繰り返し二乗法)(modPow)
// これは、x^y mod k を求める手法で、
// k が素数で、x が k の倍数でなければ x^(m-1) = 1 である（フェルマーの小定理)
// これを使うと、計算量が O(log k) かつ、LLの範囲までいけちゃう。
// http://satanic0258.hatenablog.com/entry/2016/04/29/004730

int s,t;

int modPow(LL x, LL y){
    LL r = 1, a = x % MOD;
    while(y > 0){
        if((y&1) == 1) r = (r*a) % MOD;
        a = (a*a) % MOD;
        y /= 2;
    }
    return r;
}

