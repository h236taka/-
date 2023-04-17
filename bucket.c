#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000

void bucketSort(int a[], int num){
  int *buckets; /* バケツ */
  int *start; /* 各バケツの先頭位置 */
  int *count; /* 各値の出現数 */

  int i, j;
  int bucket_size;
  int max;

  /* データの最大値を求める */
  max = 0;
  for (i = 0; i < num; i++) {
    if (max < a[i]) {
      max = a[i];
    }
  }
  bucket_size = max + 1;

  /* バケツの数に応じてメモリを確保 */
  count = (int*)malloc(sizeof(int) * bucket_size);
  start = (int*)malloc(sizeof(int) * bucket_size);

  /* ソートするデータの数に応じてメモリを確保 */
  buckets = (int*)malloc(sizeof(int) * num);

  /* 各値の出現数を0に初期化 */
  for (i = 0; i < bucket_size; i++) {
    count[i] = 0;
  }

  /* a[i]の値がいくつあるかをカウント */
  for (i = 0; i < num; i++) {
    count[a[i]]++;
  }

  /* 配列上のラベルiのバケツの先頭位置を決める */

  /* 値0のデータを入れるバケツは配列の先頭とする */
  start[0] = 0;
  for (i = 1; i < bucket_size; i++) {
    /* 値iのデータを入れるバケツは、
    値i-1のデータを入れるバケツの先頭位置から
    値i-1のデータの個数ずらした位置とする */
    start[i] = start[i - 1] + count[i - 1];
  }

  /* ソートを実行 */
  for (i = 0; i < num; i++) {

    /* 対応するバケツにデータを格納 */
    buckets[start[a[i]]] = a[i];

    /* 数値a[i]の格納先を１つ後ろにずらす */
    start[a[i]]++;
  }

  /* ラベルが小さいバケツから順にデータを取り出していく */
  j = 0;
  for (i = 0; i < num; i++) {
    /* 配列aに取り出したデータを入れる */
    a[j] = buckets[i];
    j++;
  }

  free(count);
  free(start);
  free(buckets);


  printf("配列[");
  for ( int i = 0; i < num; i++ ){
    printf("%d ", a[i]);
  }
  printf("]\n");

}

int main(void){
  int n;

  printf("配列の要素数を入力:");
  scanf("%d", &n);

  if ( n >= SIZE ){
    printf("要素数がオーバーしています\n");
    exit(1);
  }

  int a[n];

  printf("配列の要素を入力\n");

  for ( int i = 0; i < n; i++ ){
    printf("配列の%d番目の要素:", i);
    scanf("%d", &a[i]);
  }

  bucketSort(a,n);


  return 0;
}
