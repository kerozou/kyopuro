// 写像12相
// http://kuno4n.hateblo.jp/

// 使用例
ABC-132 D - Blue and Red Balls  // count_7



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    count 1 : 区別: ボール:有   箱:有   少なくとも一つ入る
// 2次元DPなので、O(N^2)程度で、N=10^3くらいまで？
// 集合N から 集合M への全射と考えてよい。
// マスオに集合論的な解き方が載ってるよ(包除原理)

int s,t;
LL dp[1010][1010];

// S(n, m) = S(n-1, m) * m + S(n-1, m-1) * m
LL count_1(LL n,LL m){  // ボールがn個、箱がm個
    if(n < m) return 0;
    memset(dp, 0, (LL)sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1;i <= n;++i) for(int j = 1;j <= m;++j){
        dp[i][j] += dp[i-1][j] * j;
        dp[i][j] += dp[i-1][j-1] * j;
        dp[i][j] %= MOD;
    }
    return dp[n][m];
}

// テストコード
int main(){
    cin >> s >> t;
    int tmp = count_1(s,t);
    cout << tmp << endl;
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



    count 2 : 区別: ボール:有   箱:有   高々一つ入る
// 集合N から 集合M への単射と考えてよいので、mPn が答え
// 当然ながら n > m の時は箱から溢れるのでNG
// while内のn-- が0になるまでPermutationを計算するので、O(n)程度。
int s,t;

LL count_2(LL n,LL m){  // ボールがn個、箱がm個
    if(n > m)return 0;
    LL res = 1;
    while(n--){
        res = (res * m--) % MOD;
    }
    return res;
}

// テストコード
int main(){
    cin >> s >> t;
    int tmp = count_2(s,t);
    cout << tmp << endl;
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




    count 3 : 区別: ボール:有   箱:有   入れ方に制限なし
// m^n になるのは自明。集合N の各要素に m 通りの選択肢があるので。



// x^y (繰り返し二乗法)(modPow)
// これは、x^y mod k を求める手法で、
// k が素数で、x が k の倍数でなければ x^(m-1) = 1 である（フェルマーの小定理)
// これを使うと、計算量が O(log k) かつ、LLの範囲までいけちゃう。
// http://satanic0258.hatenablog.com/entry/2016/04/29/004730

int s,t;

int modPow(LL x, LL y){
    LL r = 1, a = x % MOD;
    while(y > 0){
        if((y&1) == 1) r = (r*a) % MOD; // x^y の y が奇数の時に x をかけて y を偶数にしてる。
        a = (a*a) % MOD;
        y /= 2;
    }
    return r;
}

int count_3(int n, int m){
    return modPow(m, n);        // m,n の順序に注意。m^n なので。
}

// テストコード
int main(){
    cin >> s >> t;
    int tmp = count_3(s,t);
    cout << tmp << endl;
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




    count 4 : 区別: ボール:有   箱:無   少なくとも一つ入る
// （有・無）シリーズは、集合P = {p1,p2,p3,...,pm} の各要素を n 個に分割するだけなので、「集合の分割」という。

// 全射かつ、箱に区別がないの場合なので、count_1をm!で割ってもでる。
// ただ、MOD逆元とかそのへんがいる。
// 相異なる N 個のものを M グループに分けるときの場合の数を「第二種スターリング数」といい、S(n,m)もしくは nSm とあらわし、次の漸化式が成り立つ。

// S(n, m) = S(n-1, m) * m + S(n-1, m-1)
// 証明はマスオの§13-5にあるよ

// 以上の式をDPすればよい。

int s,t;

LL dp[1010][1010];

// S(n, m) = S(n-1, m) * m + S(n-1, m-1)
int count_4(int n, int m){
    if(n < m) return 0;    
    memset(dp, 0, (LL)sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1;i <= n;++i) for(int j = 1;j <= m;++j){
        dp[i][j] += dp[i-1][j] * j;
        dp[i][j] += dp[i-1][j-1];            
        dp[i][j] %= MOD;
    }    
    return dp[n][m];
}

// テストコード
int main(){
    cin >> s >> t;
    int tmp = count_4(s,t);
    cout << tmp << endl;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



    count 5 : 区別: ボール:有   箱:無   高々一つ入る
// 単射で、箱に区別がないので、入れ方をしても区別が無くて 1 通りになる。

int count_5(int n, int m){
    if(n > m) return 0;
    return 1;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    count 6 : 区別: ボール:有   箱:無   入れ方に制限なし
// 結局、集合の分割なので、count_4 の全射のDPを作ることで、「箱が1個」「箱が2個」... 「箱がm個」の場合にボールを n個 使い切った場合の数をゲットできる。
// なので、dp[n][i]を [1,m] まで足せばいい。
// これはベル数（n = m)のときもいける。
// dpなのでO(nm)

// 空箱があってもいいので、if(n > m)return 0; はいらない。

int s,t;

LL dp[1010][1010];

LL count_6(LL n, LL m){
    // count4_1 と同様のdpを前もって実施
    memset(dp, 0, (int)sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++){
        dp[i][j] += dp[i-1][j] * j;
        dp[i][j] += dp[i-1][j-1];            
        dp[i][j] %= MOD;
    }
    
    // count4_1における「箱が1個の場合」「箱が2個の場合」……「箱がm個の場合」を足す
    LL res = 0;
    for(int i = 1; i <= m; i++) res = (res + dp[n][i]) % MOD;
    return res;
}

// テストコード
int main(){
    cin >> s >> t;
    LL tmp = count_6(s,t);
    cout << tmp << endl;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    count 7 : 区別: ボール:無   箱:有   少なくとも一つ入る
// 球に区別がない時の全射は、和が n になるタイプの不定方程式の整数解の個数である。(マスオP.77)
// n個のボールを横に並べて、n-1個の隙間にm-1個の仕切りを入れれば良いので、n-1個からm-1個を選ぶ組み合わせ。
// 前処理 COMinit(): O(n)
// クエリ処理 COM(n, k): O(1)

int s,t;

const int MAX = 10000;      //  ここのサイズ選びめっちゃ注意。5*10^5とかにしてたら余裕でTLEこく。

LL fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
// 二項係数計算
LL COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
// n-1 C m-1
int count_7(int n, int m){
    if(n < m) return 0;
    // 前処理
    COMinit();
    return COM(n-1,m-1);
}

// テストコード
int main(){
    cin >> s >> t;
    LL tmp = count_7(s,t);
    cout << tmp << endl;
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    count 8 : 区別: ボール:無   箱:有   高々一つ入る
// 玉に区別のない単射。なので、行先の箱m から n個選ぶだけ。
// 前処理 COMinit(): O(n)
// クエリ処理 COM(n, k): O(1)

int s,t;

const int MAX = 5100000;     //  ここのサイズ選びめっちゃ注意。5*10^5とかにしてたら余裕でTLEこく。

LL fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
// 二項係数計算
LL COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
int count_8(int n, int m){
    if(n > m) return 0;
    // 前処理
    COMinit();
    return COM(m,n);
}


// テストコード
int main(){
    cin >> s >> t;
    LL tmp = count_8(s,t);
    cout << tmp << endl;
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



    count 9 : 区別: ボール:無   箱:有   入れ方に制限なし
// どのような分配も許されるので、各球に対して、m種類の箱から重複を許してn個とる重複組み合わせ　mHn になる。
// これは m+n-1Cn になる。
// 前処理 COMinit(): O(n)
// クエリ処理 COM(n, k): O(1)
// 計算量は二項係数のO(n)になるっぽいぞ
// dp でやるとO(n^2 * m)でもできるっぽい。

int s,t;

const int MAX = 5100000;     //  ここのサイズ選びめっちゃ注意。5*10^5とかにしてたら余裕でTLEこく。

LL fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
// 二項係数計算
LL COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
// nHm
int count_9(int n, int m){
    // 範囲外アクセスに注意して下さい
    // 前処理
    COMinit();
    return COM(n+m-1,m);
}



// テストコード
int main(){
    cin >> s >> t;
    LL tmp = count_9(s,t);
    cout << tmp << endl;
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



    count 10 : 区別: ボール:無   箱:無   少なくとも一つ入る
// 区別なしの全射。
// 球1個の箱が ある ない の排反な場合で考えて足す。
// 排反はDPと相性がいい？

int s,t;

LL dp[1010][1010];

int count_10(int n, int m){
    if(n < m) return 0;
    
    memset(dp, 0, (int)sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            
            // ボール1個の箱が少なくとも1つある場合。
            // 1個箱に入れて、残りi-1個をj-1個の箱に分ける。
            dp[i][j] += dp[i-1][j-1];
            
            // ボール1個の箱が無い場合。
            // まず1個づつ、j個の箱に入れてしまう。残りi-j個をj個の箱に分ける。 
            // すべての箱から1個取り除いたもので考えるということ。
            if(i >= j) dp[i][j] += dp[i-j][j];
            
            dp[i][j] %= MOD; 
        }
    }
    return dp[n][m];
}


// テストコード
int main(){
    cin >> s >> t;
    LL tmp = count_10(s,t);
    cout << tmp << endl;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    count 11 : 区別: ボール:無   箱:無   高々一つ入る
// count5と同じく、n≦m なら問答無用で1通りです。

int count11(int n, int m){
    if(n > m) return 0;
    return 1;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    count 12 : 区別: ボール:無   箱:無   入れ方に制限なし
// 「分割数」っていう問題らしい。蟻本にものってるよ
// n = m のとき、特に n の分割数っていうらしい。
// これは、集合自分自身のなかで分割するからじゃない？包徐原理の話。

// count12は 1~m 個の箱に球が入ってる場合を全部足してあげればいい。
// 箱が区別されないのでこれで分かる。
// なので、count10のDPを 1~m まで足してあげれば答えになる。

int s,t;

LL dp[1010][1010];

int count_12(int n, int m){
    // まずcount10と同様のdp
    memset(dp, 0, (int)sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] += dp[i-1][j-1];
            if(i >= j) dp[i][j] += dp[i-j][j];
            dp[i][j] %= MOD; 
        }
    }
    
    // 1～mのsumをとる
    LL res = 0;
    for(int i = 1; i <= m; i++) res = (res + dp[n][i]) % MOD;
    return res;
}


// テストコード
int main(){
    cin >> s >> t;
    LL tmp = count_12(s,t);
    cout << tmp << endl;
}