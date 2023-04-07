#include <stdio.h>
#define SIZE 100

int binary_search(int key, int ArrayNumber, int array[]){
  int left, right, mid;

  left = 0;
  right = ArrayNumber - 1;  //配列の右端

  while ( right >= left ){
    mid = left + ( right - left ) / 2;  //区間の真ん中
    if ( array[mid] == key ){
      return mid;
    }
    else if ( array[mid] > key ){
      right = mid - 1;
    }
    else if ( array[mid] < key ){
      left = mid + 1;
    }
    else{
      return -1;
    }
  }

  return -1;
}

int main(){
  int n;
  n = SIZE;
  int array[SIZE];
  int input;
  int output;

  for ( int i = 0; i < n; i++ ){
    array[i] = i;
  }

  printf("探索したい数を入力してください ");
  scanf("%d", &input);

  output = binary_search(input,n,array);
  if ( output == -1 ){
    printf("入力した数は配列に含まれていません\n");
  }
  else{
    printf("%dは配列の左から%d番目にあります!\n", input,output);
  }

  return 0;
}
