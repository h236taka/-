#include <stdio.h>

int checkValueMax(int max1, int max2){

  if ( max1 < max2 ){
    max1 = max2;
    return max1;
  }
  else{
    return max2;
  }

}

int main(){
  int n, w;
  int max1; //価値の最大値候補1
  int max2; //価値の最大値候補2

  n = 6;
  w = 15;  //容量

  int value[n];
  int weight[n];
  int dp[n][w];

  for ( int i = 0; i < n; i++ ){
    if ( i == 0 ){
      weight[i] = 10;
      value[i] = 120;
    }
    else if ( i == 1 ){
      weight[i] = 12;
      value[i] = 130;
    }
    else if ( i == 2 ){
      weight[i] = 7;
      value[i] = 80;
    }
    else if ( i == 3 ){
      weight[i] = 9;
      value[i] = 100;
    }
    else if ( i == 4 ){
      weight[i] = 21;
      value[i] = 250;
    }
    else if ( i == 5 ){
      weight[i] = 16;
      value[i] = 185;
    }
  }

  //初期化
  for ( int i = 0; i < n; i++ ){
    for ( int j = 0; j < w; j++ ){
      dp[i][j] = 0;
    }
  }

  //DP LOOP
  for ( int i = 0; i < n; i++ ){
    for ( int j = 0; j < w; j++ ){
      if ( j - weight[i] >= 0 ){
        //i番目の品物を選ぶ場合
        max1 = dp[i+1][j];
        max2 = dp[i][j-weight[i]] + value[i];
        dp[i+1][j] = checkValueMax(max1,max2);
      }

      //i番目の品物を選ばない場合
      dp[i+1][j] = checkValueMax(max1,max2);
    }
  }

  printf("価値の最大値:%d\n", dp[n][w]);

  return 0;

}
