#include <stdio.h>

int main(){
  int coins[6] = {500, 100, 50, 10, 5, 1};
  int price;
  int value[6];

  printf("支払金額を入力してください! \n");
  scanf("%d", &price);

  printf("各硬貨は何枚持っていますか?\n");

  printf("500円玉:");
  scanf("%d", &value[0]);

  printf("100円玉:");
  scanf("%d", &value[1]);

  printf("50円玉:");
  scanf("%d", &value[2]);

  printf("10円玉:");
  scanf("%d", &value[3]);

  printf("5円玉:");
  scanf("%d", &value[4]);

  printf("1円玉:");
  scanf("%d", &value[5]);

  int result = 0;
  int sum;
  for ( int i = 0; i < 6; i++ ){
    //枚数制限なしのとき
    sum = price / value[i];

    //枚数制限考慮
    if ( sum > value[i] ){
      sum = value[i];
    }

    //残り金額を求めてresultに枚数を加算
    price -= value[i] * sum;
    result += sum;
  }

  printf("必要な硬貨の枚数は%d枚です\n", result);

  return 0;
}
