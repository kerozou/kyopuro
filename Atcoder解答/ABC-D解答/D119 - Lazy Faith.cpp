 #include<bits/stdc++.h>
 
 using namespace std;
 typedef long long ll;
 #define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
 #define erep(i, n) for (ll i = 0; i <= (ll)(n); ++i)
 #define FOR(i,a,b) for (ll i = (a); i < (ll)(b); ++i)
 #define EFOR(i,a,b) for (ll i = (a); i <= (ll)(b); ++i)
 template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } }
 template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } }
 
 
 int main() {
     int a, b, q; cin >> a >> b >> q;
     vector<ll> s(a);
     vector<ll> t(b);
     vector<ll> x(q);
     rep(i, a) cin >> s[i];
     rep(i, b) cin >> t[i];
     rep(i, q) cin >> x[i];
 
     // 昇順ソート
     sort(s.begin(), s.end());
     sort(t.begin(), t.end());
 
     rep(i, q) {
         ll ans = LONG_MAX;
 
         ll s_itr = upper_bound(s.begin(), s.end(), x[i]) - s.begin();
         ll t_itr = upper_bound(t.begin(), t.end(), x[i]) - t.begin();
         // 領域外アクセス対応
         if(s_itr == a) s_itr--;
         if(t_itr == b) t_itr--;
 
         rep(j, 2) rep(k, 2) {
             // 領域外アクセス対応
             ll s_tmp = max((ll)0, (s_itr-j));
             ll t_tmp = max((ll)0, (t_itr-k));
 
             ll tmp_a = abs(s[s_tmp] - x[i]) + abs(t[t_tmp]-s[s_tmp]);
             ll tmp_b = abs(t[t_tmp] - x[i]) + abs(s[s_tmp]-t[t_tmp]);
             chmin(ans, tmp_a);
             chmin(ans, tmp_b);
         }
 
         cout << ans << endl;
     }
     
     return 0;
 }
 

 // ABC-D119 D - Lazy Faith

 // 自前で描いたらバグり散らかした
 // 自分はLsLt,LsRt なんてかんじに神社と寺を8通りで行き来するパターンをかいてlower_boundで描いてバグった。
 // あと、領域がいに行ったときにINFとってたぶんおかしなことになってた気がする。

 // https://scrapbox.io/esaka-sandbox/AtCoder_Beginner_Contest_119_-_D_-_Lazy_Faith
 // 上記URLのコードそのまま。

 // 今回の学びは
 // ・愚直に総当たりのコードは危ない。
 // ・二分探索は領域外アクセスの危険性がある
 // ということだった。

 // 方針は間違えてなかった。
 
 // 上のコードではupper_bound で行き過ぎたときや、領域外にぶっ飛んだ時に0やケツを参照してるけど、これってどうなのか？
 // max で領域外-jが負になるときはつまり現在地が神社よりも左であるとき。
 // この時に左に行っちゃうと地の果てまで歩いて行っちゃうから、無理やり右に歩かせてるってこと。

 // 必ずしも8通り全パターンを試す必要はなく、無理とわかったら進路を強制するという発想がすごいと思った。
 // マラソンとかで使えそう。

 