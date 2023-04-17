#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>;

//入力: グラフG,探索の始点s
//出力: sから各頂点への最短路長を表す配列
vector<int> BFS(const Graph &G, int s){
  int N = (int)G.size();  //頂点数
  vector<int> dist(N, -1);  ///全頂点を未訪問に設定
  queue<int> que;

  //初期条件(頂点0を初期頂点とする)
  dist[s] = 0;
  que.push(s);

  //BFS開始(キューが空になるまで探索を行う)
  while ( !que.empty() ){
    int v = que.front();  //キューから先頭の頂点を取り出す
    que.pop();

    //vからたどれる頂点を全て調べる
    for ( int x : G[v] ){
      if ( dist[x] != -1 ){
        continue; //既に発見済みの頂点は探索しない
      }

      //新たな頂点xについて距離情報を更新してキューに挿入
      dist[x] = dist[v] + 1;
      que.push(x);
    }
  }

  return dist;
}

int main(){
  int N, M;

  cout << "頂点数を入力してください" << endl;
  cin >> N;

  cout << "辺数を入力してください" << endl;
  cin >> M;

  Graph G(N);
  //グラフ入力受けとり
  for ( int i = 0; i < M; i++ ){
    int a, b;
    cin >> a >> b;

    G[a].push_back(b);
    G[b].push_back(a);
  }

  //頂点0を始点としたＢＦＳ
  vector<int> dist = BFS(G,0);
  //cout << "finished BFS" << endl;

  //結果出力(各頂点の頂点0からの距離を取る)
  for ( int v = 0; v < N; v++ ){
    cout << v << ":" << dist[v] << endl;
  }

}
