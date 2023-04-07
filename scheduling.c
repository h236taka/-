#include <stdio.h>
#define PAIR 2

int main(){
  int n;

  printf("スケジュールの個数を入力してください: ");
  scanf("%d", &n);

  int interbal[n][PAIR];

  for ( int i = 0; i < n; i++ ){
    do{
      printf("%d番目のスケジュールの開始時間と終了時間を入力してください\n", i+1);
      printf("開始時刻:");
      scanf("%d", &interbal[i][PAIR-2]);  //開始時刻
      printf("終了時刻:");
      scanf("%d", &interbal[i][PAIR-1]);  //終了時刻

      if ( interbal[i][PAIR-2] >= interbal[i][PAIR-1] ){
        printf("開始時刻と終了時刻に不備があります\n");
      }
      if ( interbal[i][PAIR-2] < 0 || interbal[i][PAIR-1] < 0 ){
        printf("開始時刻と終了時刻に不備があります\n");
      }


    } while ( interbal[i][PAIR-2] >= interbal[i][PAIR-1]);
  }

  int res = 0;
  int current_end_time = 0;

  for ( int i = 0; i < n; i++ ){
    //最後に選んだ区間と被るのは除く
    if ( interbal[i][PAIR-2] < current_end_time ){
      continue;
    }

    res++;
    current_end_time = interbal[i][PAIR-1];
  }

  printf("スケジュールが被らず最大にこなすことができるスケジュールの数は%d件です\n", res);

  return 0;
}
