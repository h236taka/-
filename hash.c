#include <stdio.h>

/* ハッシュテーブルのサイズ */
#define NUM_BUCKET 10

/* バケットの状態を表す定数 */
#define FULL 0
#define EMPTY 1

/* バケットの中身を表現する構造体 */
typedef struct _BUCKET {
  int data; /* バケットに格納されたデータ */
  int state; /* バケットの状態 */
} BUCKET;

/* ハッシュテーブル */
static BUCKET hash_table[NUM_BUCKET];

/******************************
* ハッシュ値を算出する関数
* data：ハッシュ値の元になるデータ
* 返却値：算出したハッシュ値
******************************/
unsigned int hash(int data) {
  unsigned int u_data = data;

  return u_data % NUM_BUCKET;
}

/******************************
* ハッシュテーブルを初期化する関数
******************************/
void initialize(void) {
  int i;

  for (i = 0; i < NUM_BUCKET; i++) {
    hash_table[i].data = 0;
    hash_table[i].state = EMPTY;
  }
}

/******************************
* ハッシュテーブルの終了処理を行う関数
******************************/
void finalize(void) {
  int i;

  for (i = 0; i < NUM_BUCKET; i++) {
    hash_table[i].data = 0;
    hash_table[i].state = EMPTY;
  }
}

/******************************
* ハッシュテーブルにデータを追加する関数
* data：追加したいデータ
* 返却値：追加した位置のアドレス（成功時）
*      ：NULL（失敗時）
******************************/
BUCKET* add(int data) {   //構造体が戻り値のとき BUCKET(構造体名)* 関数名 とする
  unsigned int i;

  /* ハッシュ値の算出 */
  i = hash(data);

  if (i >= NUM_BUCKET) {
    return NULL;
  }

  /* ハッシュ値の位置のバケットにデータ格納 */
  if (hash_table[i].state != FULL) {
    hash_table[i].data = data;
    hash_table[i].state = FULL;

    return &hash_table[i];
  }

  return NULL;
}

/******************************
* ハッシュテーブルからデータを探索する関数
* data：探索したいデータ
* 返却値：見つかった位置のアドレス（成功時）
*      ：NULL（失敗時）
******************************/
BUCKET* search(int data) {

  unsigned int i;

  /* ハッシュ値の算出 */
  i = hash(data);

  if (i >= NUM_BUCKET) {
    return NULL;
  }

  /* ハッシュ値の位置のバケットと比較 */
  if (hash_table[i].state != EMPTY) {
    if (hash_table[i].data == data) {

      /* dataが見つかった */
      return &hash_table[i];
    }
  }

  return NULL;
}

/******************************
* ハッシュテーブルからデータを削除する関数
* data：削除したいデータ
* 返却値：削除した位置のアドレス（成功時）
*      ：NULL（失敗時）
******************************/
BUCKET* delete(int data) {

  unsigned int i;

  /* ハッシュ値の算出 */
  i = hash(data);

  if (i >= NUM_BUCKET) {
    return NULL;
  }

  /* ハッシュ値の位置のバケットの中身を削除 */
  if (hash_table[i].state != EMPTY) {
    if (hash_table[i].data == data) {

      /* バケットの状態を空に設定 */
      hash_table[i].state = EMPTY;

      return &hash_table[i];
    }
  }

  return NULL;
}

int main(void) {
  unsigned int datas[10] = {
    101, 520, 245, 323, 999,
    678, 924, 2, 96, 777
  };
  int i;

  initialize();

  /* データの格納 */
  for (i = 0; i < 10; i++) {
    if (add(datas[i])) {
      printf("%d is ADDED\n", datas[i]);
    }
  }

  /* データの探索 */
  for (i = 0; i < 10; i++) {
    if (search(datas[i])) {
      printf("%d is FOUND\n", datas[i]);
    }
  }

  /* データの探索が失敗することを確認 */
  if (search(987)) {
    printf("%d is FOUND\n", 987);
  }

  if (search(654)) {
    printf("%d is FOUND\n", 654);
  }

  /* データの削除が失敗することを確認 */
  if (delete(654)) {
    printf("%d is DELETED\n", 654);
  }

  /* データの削除 */
  for (i = 0; i < 10; i++) {
    if (delete(datas[i])) {
      printf("%d is DELETED\n", datas[i]);
    }
  }

  finalize();

  return 0;
}
