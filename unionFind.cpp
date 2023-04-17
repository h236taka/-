#include <iostream>
#include <vector>
using namespace std;

//union-find
struct UnionFind {
  vector<int> par, siz;

  //初期化
  UnionFind(int n) : par(n,-1) , siz(n,1) { }

  //根を求める
  int root(int x){
    if ( par[x] == -1 ){
      return x; //xが根の場合は根を返す
    }
    else{
      return par[x] = root(par[x]); //xの親par[x]を根に設定する
    }
  }

  //xとyが同じグループに属するかどうか(根が一致するかどうか)
  bool issame(int x, int y){
    return root(x) == root(y);
  }

  //xを含むグループとyを含むグループを併合する
  bool unite(int x, int y){
    //x,yをそれぞれ根まで移動する
    x = root(x);
    y = root(y);

    //既に同じグループの時は何もしない
    if ( x == y ){
      return false;
    }

    //union by size ( y側のサイズが小さくなるようにする)
    if ( siz[x] < siz[y] ){
      swap(x,y);
    }

    //yをxの子とする
    par[y] = x;
    siz[x] += siz[y];
    return true;
  }

  //xを含むグループのサイズ
  int size(int x){
    return siz[root(x)];
  }
};

int main(){
  UnionFind uf(7);  //{0}, {1}, {2}, {3}, {4}, {5}, {6}, {7}

  uf.unite(1,2);  //{1,2}
  uf.unite(2,3);  //{1,2,3}
  uf.unite(5,6);  //{5,6}

  cout << uf.issame(1,3) << endl; //true
  cout << uf.issame(2,5) << endl; //false

  uf.unite(1,6);  //{1,2,3,5,6}
  cout << uf.issame(2,5) << endl; //true

}
