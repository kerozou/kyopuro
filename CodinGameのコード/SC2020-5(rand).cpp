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
/**
 * Grab the pellets as fast as you can!
 **/

int dp[4] = {0,-1,0,1};
int dq[4] = {-1,0,1,0};


int main()
{
    int width; // size of the grid
    int height; // top left corner is (x=0, y=0)
    cin >> width >> height; cin.ignore();

    vector<pair<int,int>> mp;

    for (int i = 0; i < height; i++) {
        string row;
        getline(cin, row); // one line of the grid: space " " is floor, pound "#" is wall

        rep(j,row.size()){
            if(row[j] == ' ')mp.push_back({i,j});
        }
    }

    vector<pair<int,int>> ayx(5);
    vector<pair<int,int>> prepac(10,{-1,-1});

    int turn = 0;
    int prehand = 0;

    bool first = true;

    // game loop
    while (1) {
        if(turn % 20 == 0)first = true;
        turn++;

        int myScore;
        int opponentScore;
        cin >> myScore >> opponentScore; cin.ignore();
        int visiblePacCount; // all your pacs and enemy pacs in sight
        cin >> visiblePacCount; cin.ignore();


        vector<pair<int,pair<int,int>>> pacpl(visiblePacCount);
        vector<pair<int,pair<int,int>>> pacplmy;
        vector<vector<bool>> perok(height,vector<bool>(width));
        vector<int> hand(3,0);
        int maxhand;
        string hand_form;

        int mypacnum = 0;
        for (int i = 0; i < visiblePacCount; i++) {
            int pacId; // pac number (unique within a team)
            bool mine; // true if this pac is yours
            int x; // position in the grid
            int y; // position in the grid
            string typeId; // unused in wood leagues
            int speedTurnsLeft; // unused in wood leagues
            int abilityCooldown; // unused in wood leagues
            cin >> pacId >> mine >> x >> y >> typeId >> speedTurnsLeft >> abilityCooldown; cin.ignore();

            if(mine)mypacnum++;
            
            pacpl[i].F = pacId;
            pacpl[i].S.F = y;
            pacpl[i].S.S = x;

            if(mine){
                pacplmy.push_back({pacId,{y,x}});
            }
        }

        int lim = mypacnum;


        int visiblePelletCount; // all pellets in sight
        cin >> visiblePelletCount; cin.ignore();
        for (int i = 0; i < visiblePelletCount; i++) {
            int x;
            int y;
            int value; // amount of points this pellet is worth
            cin >> x >> y >> value; cin.ignore();
            perok[y][x] = true;
        }

        rep(i,lim){
            if(ayx[i].F == -1 && ayx[i].S == -1){
                int sz = mp.size();
                int rn = rand() % sz;
                ayx[i].F = mp[rn].F;
                ayx[i].S = mp[rn].S;            
            }

            if(pacplmy[i].S.S == ayx[i].S && pacplmy[i].S.F == ayx[i].F){
                int sz = mp.size();
                int rn = rand() % sz;
                ayx[i].F = mp[rn].F;
                ayx[i].S = mp[rn].S;  
            }

            int pid = pacplmy[i].F;
            int ny = pacplmy[i].S.F;
            int nx = pacplmy[i].S.S;
            int py = prepac[pid].F;
            int px = prepac[pid].S;

            if(py == ny && px == nx){
                int sz = mp.size();
                int rn = rand() % sz;
                ayx[i].F = mp[rn].F;
                ayx[i].S = mp[rn].S;
            }
            else{
                rep(j,4){
                    if(0 <= ny+dp[j] && ny+dp[j]  < height && 0 <= nx+dq[j] && nx+dq[j]  < width){
                        if(perok[ny+dp[j]][nx+dq[j]]){
                            ayx[i].F = ny+dp[j];
                            ayx[i].S = nx+dq[j];
                            break;
                        }
                    }
                }
            }

            prepac[pid].F = ny;
            prepac[pid].S = nx;


        }


        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

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

    }
}


// とりあえず目的地に着いたらランダムで行先を決めるAI。
// 20秒に一回加速


/*
    5匹までのパックマンの独立移動に対応。
    何かにぶつかった時にランダムで行先を変更。
*/

