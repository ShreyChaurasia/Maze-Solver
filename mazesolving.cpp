#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
using namespace std;


int mat[50][50];
int s1,s2;
int e1,e2;
int vis[50][50];
vector <vector <pair <int,int> > > par(50, vector <pair <int,int> >(50));
int xx[] = {1,0,0,-1};
int yy[] = {0,1,-1,0};
          //D R  L U
bool check(int x,int y,int n,int m){
    return x>=0 &&  x < n && y>=0 && y<m;
}


void print(){
    stack <char> ans;
    int t1,t2;
    t1 = e1;
    t2 = e2;
    while(t1 != s1 || t2 != s2){
        for(int i=0;i<4;++i){
            int pp = t1 + xx[i];
            int qq = t2 + yy[i];
            if(pp == par[t1][t2].first && qq == par[t1][t2].second){
                if(i == 0){
                    ans.push('U');
                }
                else if(i == 1){
                    ans.push('L');
                }
                else if(i == 2){
                    ans.push('R');
                }
                else{
                    ans.push('D');
                }
                t1 = pp;
                t2 = qq;
            }
        }
    }
    while(!ans.empty()){
        cout<<ans.top()<<" ";
        ans.pop();
    }
}



bool SolveTheMaze(int n, int m){
    queue <pair <int,int> > q;
    q.push({s1, s2});
    vis[s1][s2] = 1;
    bool flag = false;

    while(!q.empty()){
        pair <int,int> temp = q.front();
        q.pop();
        

        if(temp.first == e1 && temp.second == e2){
            flag = true;
            break;
        }

        for(int i=0;i<4;++i){
            int x = temp.first + xx[i];
            int y = temp.second + yy[i];
            if(check(x, y, n, m) && !vis[x][y] && mat[x][y] != -1){
                par[x][y] = {temp.first, temp.second};
                vis[x][y] = 1;
                q.push({x,y});
            }
        }
    }

    return flag;
}

int main()
{

	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,x,y;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>mat[i][j];
        }
    }
   
    
    cin>>s1>>s2;
   
    cin>>e1>>e2;
   
    if(SolveTheMaze(n, m)){
        cout<<"Follow this path"<<"\n";
        print();
    }
    else{
        cout<<"You are stuck";
    }
}