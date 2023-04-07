#include <stdio.h>

int gcd(int m, int n){
  if ( n == 0 ){
    return m;
  }

  return gcd(n, m % n);
}

int main(){
  int m;
  int n;
  int ans;

  printf("割られる数を入力してください!");
  scanf("%d", &m);
  printf("割る数を入力してください!");
  scanf("%d", &n);

  ans = gcd(m,n);
  printf("入力値:%d ÷ %d",m, n);
  printf("ユークリッドの互除法で求めた答えは%dです\n", ans);

  return 0;
}
