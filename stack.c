#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int init(int *top){

  *top = 0;

}

//スタックが満杯かチェック
void isFull(int st[]){
  int count;

  count = 0;
  for ( int i = 0; i < SIZE; i++ ){
    //printf("%d\n", st[i]);
    if ( st[i] != 0 ){
      count++;
    }
  }

  if ( count == SIZE ){
    printf("スタックが満杯です...\n");
    exit(1);
  }

}
//スタックが空かチェック
void isEmpty(int st[]){
  int count;

  count = 0;
  for ( int i = 0; i < SIZE; i++ ){
    //printf("%d\n", st[i]);
    if ( st[i] == 0 ){
      count++;
    }
  }

  if ( count == SIZE ){
    printf("スタックが空です...\n");
    exit(1);
  }

}

int push(int x, int *top, int st[]){

  isFull(st); //スタックが満杯かチェック

  st[*top] = x;  //xを格納する
  printf("st[%d]に%dを格納しました!\n", *top,x);
  ++*top; //topの値を+1した値を代入

  //printf("%d\n", *top);

}

void pop(int *top, int st[]){
  int popData;

  isEmpty(st);

  /*for ( int i = 0; i < SIZE; i++ ){
    printf("st[%d]:%d\n", i, st[i]);
  }*/

  --*top;
  popData = st[*top];
  printf("st[%d]から%dを取り出しました!\n", *top, popData);
  st[*top] = 0;
  //printf("top:%d\n", *top);

}

int main(void){
  int top;
  int st[SIZE];

  init(&top);  //初期化

  for ( int i = 0; i < SIZE; i++ ){
    st[i] = 0;  //初期化
  }

  push(3,&top,st);  //スタックに3を挿入
  push(5,&top,st);  //スタックに5を挿入
  push(7,&top,st);  //スタックに7を挿入
  //push(8,&top,st);  //スタックに8を挿入
  //push(3,&top,st);  //スタックに3を挿入

  pop(&top,st);
  push(1,&top,st);
  pop(&top,st);

  return 0;
}
