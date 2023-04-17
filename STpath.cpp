#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;  //2次元配列

//深さ優先探索
vector<bool> seen;
void dfs(const Graph &G, int v){
  seen[v] = true; //vを訪問済みとする

  //vから行ける次の頂点について
  for ( auto next_v : G[v] ){
    if ( seen[next_v] ){
      continue; //next_vが探索済みなら探索しない
    }
    dfs(G,next_v);  //再帰的に探索
  }

}

int main(){
  //頂点数と辺数、s(始点)とt(終点)
  int N, M, s, t;

  cin >> N >> M >> s >> t;

  //グラフ入力受取
  Graph G(N);
  for ( int i = 0; i < M; i++ ){
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
  }

  //頂点sをスタートした探索
  seen.assign(N,false); //全頂点を未訪問に設定
  dfs(G,s);

  //tにたどり着けるかどうか
  if ( seen[t] ){
    cout << "yes" << endl;
  }
  else{
    cout << "no" << endl;
  }
}
