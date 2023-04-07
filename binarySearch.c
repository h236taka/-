#include <stdio.h>
#define SIZE 10
#define TRUE 1
#define FALSE 0

int checkBool(int mid, int key){

  if ( mid == key ){
    return TRUE;
  }
  else{
    return FALSE;
  }
}
int binary_search(int key){
  int left, mid, right;

  left = 0;
  right = SIZE;

  while ( right - left > 1 ){
    mid = left + ( right - left ) / 2;
    if ( checkBool(mid,key) == TRUE ){
      right = mid;
    }
    else{
      left = mid;
    }
  }

  return right;
}

int main(){
  int border;
  int key = 5;

  border = binary_search(key);
  printf("0~10の間の入力値に対する最小のtrue領域は%dです\n", border);

  return 0;
}
