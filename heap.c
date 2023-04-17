#include <stdio.h>
#include <stdlib.h>

//  配列の最大値
#define MAX_LENGTH 12

//  配列aに登録されている要素の個数（

void swap(int*,int,int);
int downheap(int*,int,int);
void showData(int*,int);
void heap_sort(int*,int);

int main(){
  //  ソートする行列(最初は０にしておく
  int array[MAX_LENGTH+1] = {12,15,10,7,6,1,3,7,5,3,2};
  //  ソートする処理
  heap_sort(array,MAX_LENGTH);

  return 0;
}

//  配列の成分の入れ替え
void swap(int* pArray,int m,int n)
{
  int tmp = pArray[m];
  pArray[m] = pArray[n];
  pArray[n] = tmp;
}
//  ヒープの要素を沈める処理。pArray[start]から、pArray[end]までを要素とする。
int downheap(int* pArray,int start,int end){
  int parent,child,r = 0;
  child = end;    //  子ノードのスタート位置
  //  末端の要素から、たどり、親要素よりも値が大きければ、入れ替える処理を繰り返す。
  do{
    //  親ノードの番号取得
    parent = start + (child - start) / 2;
    //  バイナリツリーの末端の最初が親よりも大きければ、入れ替える。
    if( pArray[child] > pArray[parent] ){
      swap(pArray,child,parent);
      r = 1;
    }
    //  iをデクリメント
    child--;
  }while(parent > start);  //  子ノードが、startの位置を超えてしまったら、終了
  return r;
}

//  配列の表示
void showData(int* pArray,int length){
  int i;
  for(i = 1; i < length+1; i++){
    printf("%d ",pArray[i]);
  }
  printf("\n");
}

//  ヒープソート
void heap_sort(int* pArray,int size)
{
  int i = 1;
  showData(pArray,size);
  while(downheap(pArray,i,size)){
    //  途中経過を出力
    showData(pArray,size);
    i++;
  }
}
