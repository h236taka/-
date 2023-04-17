#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

//深さ優先探索
vector<bool> seen;
void dfs(const Graph &G, int v){
  seen[v] = true; //vを訪問済みとする

  //vから行ける各頂点next_vについて
  for ( auto next_v : G[v] ){
    if ( seen[next_v] ){
      continue; //next_vが探索済みならば探索しない
    }
    cout << next_v << ":searchOK(dfs)" << endl;
    dfs(G,next_v);
  }

}

int main(){
  //頂点数と辺数
  int N, M;
  cin >> N >> M;

  //グラフ入力受け取り(有向グラフとする)
  Graph G(N);
  for ( int i = 0; i < M; ++i ){
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
  }

  //探索
  seen.assign(N,false); //初期状態では全頂点が未訪問
  for ( int v = 0; v < N; ++v ){
    if ( seen[v] ){
      continue;
    }
    cout << v << ":searchOK(main)" << endl;
    dfs(G,v);
  }

}
