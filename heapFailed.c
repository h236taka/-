#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

void printArray(int array[]){

  printf("配列は,[");
  for ( int i = 0; i < SIZE; i++ ){
    printf("%d ", array[i]);
  }
  printf("]です.\n");
}

void isHeapEmpty(int heap[]){

  for ( int i = 0; i < SIZE; i++ ){
    if ( heap[i] == -1 ){
      //printf("ヒープに値が埋められていません:(%d番目の配列 添え字は0スタート)\n", i);
      //exit(1);
    }
  }
}

void push(int x, int heap[]){
  int i;
  int p;

  if ( x < 0 ){
    printf("pushする値は正の値にしてください\n");
    exit(1);
  }

  i = SIZE-1;
  do{
    p = ( i - 1 ) / 2; //親の頂点番号
    if ( heap[i] >= x ){  //逆転がなければ終了
      break;
    }

    heap[i] = heap[p];  //自分の値を親の値にする(自分の値が親の値より大きいため)
    //printf("heap[%d]:%d\n", i, heap[i]);
    i = p;  //自分は上に行く(親に)
  } while ( i > 0 );

  heap[i] = x; //xは最終的にこの位置に持ってくる

}

int graphTop(int heap[]){

  isHeapEmpty(heap);

  return heap[0]; //最大値(根の部分)
}

int heapSize(int heap[]){
  int heapsize;

  heapsize = 0;

  for ( int i = 0; i < SIZE; i++ ){
    if ( heap[i] != -1 ){
      heapsize++;
    }
  }

  return heapsize;
}

//最大値を削除
void pop(int heap[]){
  int leftChild, rightChild;

  isHeapEmpty(heap);

  int x = heap[SIZE-1]; //heapの末尾
  heap[SIZE-1] = -1;  //heapの末尾を削除

  int i = 0;  //heapの根から下ろしていく

  while ( i * 2 + 1 < heapSize(heap) ){ //i * 2 + 1は左側の子の配列の添え字
    //子頂点同士を比較して大きい方を左側の子とする
    leftChild = i * 2 + 1;
    rightChild = i * 2 + 2;

    if ( rightChild < heapSize(heap) && heap[rightChild] > heap[leftChild] ){
      leftChild = rightChild;
    }

    if ( heap[leftChild] <= x ){  //逆転がなければ終了
      break;
    }

    heap[i] = heap[leftChild];  //自分の値を子頂点の値とする
    i = leftChild;  //自分は下に行く
  }
  heap[i] = x;  //xは最終的にこの位置に持ってくる

}

int main(void){
  int array[SIZE] = {-1,-1,-1,-1,-1};

  push(5,array);  //heapに値を挿入
  push(2,array);  //heapに値を挿入
  push(10,array);  //heapに値を挿入
  push(3,array);  //heapに値を挿入
  push(11,array);  //heapに値を挿入

  printf("ヒープの最大値:%d\n",graphTop(array));

  pop(array);

  printf("ヒープの最大値:%d\n",graphTop(array));

  pop(array);

  printf("ヒープの最大値:%d\n",graphTop(array));

  pop(array);

  printf("ヒープの最大値:%d\n",graphTop(array));

  pop(array);

  printf("ヒープの最大値:%d\n",graphTop(array));

  return 0;
}
