#include <stdio.h>
#define SIZE 7

int abstruct(int num){

  if ( num < 0 ){
    num = -num;
  }

  //printf("絶対値の返り値は%d\n", num);

  return num;
}

int checkMin(int min1, int min2){
  int ans;

  if ( min1 < min2 ){
    ans = min1;
  }
  else{
    ans = min2;
  }

  return ans;
}

int main(){
  int dp[SIZE];
  int height[SIZE] = {2,9,4,5,1,6,10};
  int min1; //最小値候補1
  int min2; //最小値候補2
  int i;

  for ( i = 0; i < SIZE; i++ ){
    dp[i] = 0;                                
  }

  /*for ( i = 0; i < SIZE; i++ ){
    printf("%d\n", height[i]);
  }*/

  for ( i = 1; i < SIZE; i++ ){
    if ( i == 1 ){
      dp[i] = abstruct(height[i] - height[i-1]);  //比較する他の経路が存在しない
    }
    else{
      min1 = dp[i-1] + abstruct(height[i] - height[i-1]);
      min2 = dp[i-2] + abstruct(height[i] - height[i-2]);

      printf("iが%d時点でのmin1は%dです\n", i, min1);
      printf("iが%d時点でのmin2は%dです\n", i, min2);

      dp[i] = checkMin(min1,min2);
      printf("iが%d時点での最小値は%dです\n", i,dp[i]);
    }
  }

  printf("最小のコストは%dです。\n", dp[SIZE-1]);

  return 0;
}
