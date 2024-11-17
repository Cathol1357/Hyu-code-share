#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// 数秒待機させる関数
void wait_some_seconds(){
    struct timespec ts;
    ts.tv_sec = 0;           
    ts.tv_nsec = 200000000;  // 0.2秒

    // 3秒待機
    for (int i=0; i<15; i++){
        printf(".");
        fflush(stdout);     //バッファをクリア
        nanosleep(&ts, NULL);   //0.2秒待機
    }
    printf("\n");
}

// 抽選関数
void lotty_number(){
    // 乱数のシードを現在時刻に基づいて設定
    srand(time(NULL));

    int random_value = rand() % 100;     // 0 ~ 99の乱数を生成
    
    if(random_value < 30) {
        printf("あなたの本日の出席点は「%d点」です。どんまい。\n", 0);
    }else {
        printf("あなたの本日の主席点は「%d点」です。\n", 2);
    }
}

// 学籍番号を入力する関数
void get_student_number(int student_num[], char labels[], int num_labels) {
    int scan_result;    //エラー判定用

    printf("学籍番号を半角整数一桁で入力してください。\n");
    printf("==========================================\n");
    
    for (int i = 0; i < num_labels; i++) {
        printf("%c = ", labels[i]);
        scan_result = scanf("%d", &student_num[i]);

        // エラー処理
        if (scan_result != 1) {
            printf("エラー : 整数を入力してください。\n");
            while (getchar() != '\n'); // 入力バッファをクリア
            i -= 1;
        } else if (student_num[i] < 0 || 9 < student_num[i]) {
            printf("エラー : 一桁の整数で入力してください。\n");
            i -= 1; 
        }
    }
}

void show_student_number(int student_num[]){
    printf("あなたの学生番号は「物 ");
    for(int i=0; i<2; i++){
        printf("%d", student_num[i]);
    }
    printf("-");
    for(int i = 2; i<6; i++){
        printf("%d", student_num[i]);
    }
    printf("」ですね？抽選を開始します。\n");
}



int main (){
    int scan_result;
    int student_num[6];
    char labels[] = {'A', 'B', 'C', 'D', 'E', 'F'};

    // 学籍番号を取得
    get_student_number(student_num, labels, 6);

    // 学籍番号を出力
    show_student_number(student_num);
    
    // 3秒待機
    wait_some_seconds();
    
    // 出席点数を抽選
    lotty_number();
    

    return 0;
}

