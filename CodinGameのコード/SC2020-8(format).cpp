#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x)(x).begin(), (x).end() // 昇順ソート
#define rall(v)(v).rbegin(), (v).rend() // 降順ソート
#define INF 1LL << 60
typedef long long int LL;
typedef long long int ll;
#define pll pair < ll, ll >
#define F first
#define S second
const int MOD = 1000000007;
template < class T > bool chmax(T & a,const T & b) { if (a < b) { a = b; return true; } return false; }
template < class T > bool chmin(T & a,const T & b) { if (a > b) { a = b; return true; } return false; }

    ///// グローバル

    int dp[4] = {0,-1,0,1};
    int dq[4] = {-1,0,1,0};

    int width; // size of the grid
    int height; // top left corner is (x=0, y=0)
    int mypaclim;   // ローカルのlim を保存
    int cout_ct;    // cout のカウントを何回したか
    int now_time;   // 現在の経過ターン数

    vector<string> fie; // マップ情報
    vector<pair<int,int>> mp;   // 歩行可能マス
    vector<bool> p_received(10,false);  // パックマンが指示を貰っているか true で貰ってる
    vector<pair<int,int>> p_distination(10,{-1,-1});

    // 前回のパックマン達
    vector<int> b_y(10,0);
    vector<int> b_x(10,0);
    vector<string> b_type(10,"");
    vector<int> b_speedTurn(10,0);
    vector<int> b_abicool(10,0);
    vector<int> b_dir(10,-1);
    vector<bool> b_collision(10,false);
    ///////




    /////


int make_direction(int id,vector<int> &p_y,vector<int> &p_x){
    // パックマンの現在向いている方向を返す     方角はdp,dqと同じ
    int t_p = p_y[id] - b_y[id];
    int t_q = p_x[id] - b_x[id];
    int dir = -1;
    rep(j,4)if(t_p == dp[j] && t_q == dq[j])dir = j;
    return dir;
}
    
bool check_collision(int id,vector<int> &p_y,vector<int> &p_x){
    // パックマンが現在衝突中かどうかを判定 true で衝突中
    if(b_y[id] == p_y[id] && b_x[id] == p_x[id])return true;
    else return false;
}

pair<int,int> get_rn_pos(){
    // 歩行可能マスの座標を一つランダムで返す
    int sz = pm.size();
    int rn = rand() % sz;
    return {pm[rn]};
}


////// cout コマンド
void move(int id, pair<int,int> pos){
    // MOVEコマンド　pos にはget_rn_pos() 辺りをいれとくと便利
    cout << "MOVE " << id << " " << pos.F << " " << pos.S;
    if(cout_ct != mypaclim-1)cout << " | ";
    else cout << endl;
    cout_ct++;
}

void speed(int id){
    // SPEEDコマンド
    cout << "SPEED " << id;
    if(cout_ct != mypaclim-1)cout << " | ";
    else cout << endl;
    cout_ct++;
}

void hand_change(int id, string hand){
    // SWITCHコマンド
    cout << "SWITCH " << id << " " << hand;
    if(cout_ct != mypaclim-1)cout << " | ";
    else cout << endl;
    cout_ct++;
}
///////

bool check_received(int id,vector<int> &p_y,vector<int> &p_x){
    // 指示が終わっているかどうかを返す
    if(p_distination[id].F == p_y[id] && p_distination[id].S == p_x[id])return false;
    else return true;
}

int main()
{

    cin >> width >> height; cin.ignore();

    
    fie.resize(height);         // マップ情報

    for (int i = 0; i < height; i++) {
        string row;
        getline(cin, row); // one line of the grid: space " " is floor, pound "#" is wall
        fie[i] = row;
        rep(j,row.size()){
            if(row[j] == ' ')mp.push_back({i,j});
        }
    }


    vector<int> my_pac_id;      //  自機パックマンのid
    vector<int> ene_pac_id;     //  敵パックマンのid

    // 全パックマンの情報達
    vector<int> p_y(10,0);
    vector<int> p_x(10,0);
    vector<string> p_type(10,"");
    vector<int> p_speedTurn(10,0);
    vector<int> p_abicool(10,0);
    vector<int> p_dir(10,-1);
    vector<bool> p_collision(10,false);
    
    ////////


    // game loop
    while (1) {

        ////// グローバル初期化
        cout_ct = 0;
        mypaclim = 0;
        


        //////  毎ターン基本処理
        now_time++;
        


        //////  スコア等入力

        int myScore;
        int opponentScore;
        cin >> myScore >> opponentScore; cin.ignore();
        int visiblePacCount; // all your pacs and enemy pacs in sight
        cin >> visiblePacCount; cin.ignore();


        ///////  パックマン情報入力
        

        int lim = 0;    // 自機の数

        for (int i = 0; i < visiblePacCount; i++) {
            int pacId; // pac number (unique within a team)
            bool mine; // true if this pac is yours
            int x; // position in the grid
            int y; // position in the grid
            string typeId; // unused in wood leagues
            int speedTurnsLeft; // unused in wood leagues
            int abilityCooldown; // unused in wood leagues
            cin >> pacId >> mine >> x >> y >> typeId >> speedTurnsLeft >> abilityCooldown; cin.ignore();

            p_y[pacId] = y;
            p_x[pacId] = x;
            p_type[pacId] = typeId;
            p_speedTurn[pacId] =  speedTurnsLeft;
            p_abicool[pacId] = abilityCooldown;
            
            if(mine){
                lim++;      //  自機カウント
                my_pac_id.push_back(pacId);
            }
            else{
                ene_pac_id.push_back(pacId);
            }
            
        }

        rep(i,lim){
            p_dir[my_pac_id[i]] = make_direction(my_pac_id[i],p_y,p_x);
            p_collision[i] = check_collision(my_pac_id[i],p_y,p_x);
        }

        rep(i,1){
        //  現在のパックマン情報 を 過去のパックマン情報 に渡して更新
            b_y = p_y;
            b_x = p_x;
            b_type = p_type;
            b_speedTurn = p_speedTurn;
            b_abicool = p_abicool;
            b_dir = p_dir;
            b_collision = p_collision;
        }



        //////   ペレット情報入力


        int visiblePelletCount; // all pellets in sight
        cin >> visiblePelletCount; cin.ignore();
        for (int i = 0; i < visiblePelletCount; i++) {
            int x;
            int y;
            int value; // amount of points this pellet is worth
            cin >> x >> y >> value; cin.ignore();
        }



        ///////   処理実行

        if(now_time % 12 == 1){
            rep(i,lim){
                if(p_abicool[my_pac_id[i]] == 0){
                    speed(my_pac_id[i]);
                }
                else{
                    move(my_pac_id[i],get_rn_pos());
                }
            }
        }
        else{
            rep(i,lim){

            }
        }

/*

        if(first){

            rep(i,lim){
                cout << "SPEED " << pacplmy[i].F;
                if(i != lim-1)cout << " | ";
            }
            cout << endl;
            first = false;
        }
        else{
            rep(i,lim){
                cout << "MOVE" << " " << pacplmy[i].F << " " <<  ayx[i].S << " " << ayx[i].F; // MOVE <pacId> <x> <y>
                if(i != lim-1)cout << " | ";
            }
            cout << endl;
        }
*/
    cout << "MOVE 0 10 10" << endl;
    }
}

