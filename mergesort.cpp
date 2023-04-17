#include <iostream>
#include <vector>
using namespace std;

//配列aの区間[left, right)をソートする
//[left, right)はleft, left + 1, left + 2, ..., right -1番目を表す
void MergeSort(vector<int> &a, int left, int right){
  if ( right - left == 1 ){
    return;
  }

  int mid = left + ( right - left ) / 2;

  //左半分をソートする
  MergeSort(a, left, mid);

  //右半分をソート
  MergeSort(a, mid, right);

  //一時的に「左」と「右」のソートをコピー
  vector<int> buf;

  for ( int i = left; i < mid; i++ ){
    buf.push_back(a[i]);
  }

  for ( int i = mid; i < right; i++ ){
    buf.push_back(a[i]);
  }

  //Merge
  int index_left = 0;
  int index_right = (int)buf.size() - 1;

  for ( int i = left; i < right; i++ ){
    //左側を採用
    if ( buf[index_left] <= buf[index_right] ){
      a[i] = buf[index_left++];
    }
    //右側を採用
    else{
      a[i] = buf[index_right--];
    }
  }
}

int main(){
  int N;  //要素数
  cin >> N;
  vector<int> a(N);

  for ( int i = 0; i < N; i++ ){
    cin >> a[i];
  }

  MergeSort(a,0,N);
  cout << endl;

  for ( int i = 0; i < N; i++ ){
    cout << a[i] << endl;
  }

}
