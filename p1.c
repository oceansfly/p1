#include <stdio.h>

int main(void) {
    int N, M;
    scanf("%d %d", &N, &M);

    int A[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    int X;
    scanf("%d", &X);

    int route[X][2];
    for (int i = 0; i < X; i++) {
        scanf("%d %d", &route[i][0], &route[i][1]);
    }

    int totalFare = 0;
    int currentRoute = 1; // 初期位置は1番目の路線
    int currentStation = 1; // 初期位置は1番目の駅

    for (int i = 0; i < X; i++) {
        int targetRoute = route[i][0];
        int targetStation = route[i][1];

        if (currentRoute != targetRoute) {
            currentRoute = targetRoute;
        }

        // 駅ごとの運賃を計算して加算
        if(targetStation-1 > currentStation-1){
            int fare = A[currentRoute - 1][targetStation - 1] - A[currentRoute - 1][currentStation - 1];
            totalFare += fare;
        }else{
            int fare = A[currentRoute - 1][currentStation - 1] - A[currentRoute - 1][targetStation - 1];
            totalFare += fare;
        }

        // 現在地を更新
        currentStation = targetStation;
    }

    printf("%d\n", totalFare);

    return 0;
}

/*
Paiza 市では、電車が N 路線運行しています。それぞれの路線は、M 個の駅を有しています。

運賃は、i 番目 (1 ≦ i ≦ N) の路線の 1 番目の駅から j 番目 (1 ≦ j ≦ M) の駅まで移動したとき A_{i, j} 円となります。k 番目 (1 ≦ k ≦ j) の駅から j 番目の駅まで移動した場合は、A_{i, j} と A_{i, k} の差額だけ運賃がかかります。j 番目の駅から k 番目の駅に移動する場合も同様です。
ここで、指定されたルートで電車を用いて目的地に行くことを考えたとき、運賃がいくらになるか計算するプログラムを作成してください。なお、スタート地点は 1 番目の路線の 1 番目の駅であり、現在地が j 番目の駅である場合、どの路線の j 番目の駅も 0 円で移動することが出来ます。
また、目的地が i 番目の路線の駅となっている場合、i 番目の路線を用いて移動することとします。

例えば、入力例 1 は以下のようになります。
図1

評価ポイント
10回のテストケースで、正答率、実行速度、メモリ消費量をはかり得点が決まります。
より早い解答時間で提出したほうが得点が高くなります。
複数のテストケースで正しい出力がされるか評価（+50点）
解答までの速さ評価（+50点）
入力される値
入力は以下のフォーマットで与えられます。

N M
A_{1, 1} A_{1, 2} ... A_{1, M}
A_{2, 1} A_{2, 2} ... A_{2, M}
...
A_{N, 1} A_{N, 2} ... A_{N, M}
X
R_1 S_1
R_2 S_2
...
R_X S_X
・1 行目には、路線の数を表す整数 N と、駅の数を表す整数 M がこの順で半角スペース区切りで与えられます。
・1 + i 行目 (1 ≦ i ≦ N) には、i 番目の路線において 1 番目の駅から j 番目 (1 ≦ j ≦ M) の駅まで移動するのにいくらかかるかを表す整数 A_{i, j} が半角スペース区切りで与えられます。
・1 + N + 1 行目には、ゴールまでに経由すべき駅の数を表す整数 X が与えられます。
・2 + N + i 行目 (1 ≦ i ≦ X) には、i 番目に経由すべき駅を表す整数 R_i, S_i が与えられます。これは、現在地から R_i 番目の路線の S_i 番目の駅に向かうべきであることを意味します。
・入力は合計で 2 + N + X 行となり、入力値最終行の末尾に改行が 1 つ入ります。

それぞれの値は文字列で標準入力から渡されます。標準入力からの値取得方法はこちらをご確認ください
期待する出力
指定されたルートを辿った場合にかかる運賃を表す整数を出力してください。

出力最終行の末尾に改行を入れ、余計な文字、空行を含んではいけません。

条件
すべてのテストケースにおいて、以下の条件をみたします。

・1 ≦ N ≦ 100
・1 ≦ M ≦ 100
・0 ≦ A_{i, j} ≦ 100 (1 ≦ i ≦ N, 1 ≦ j ≦ M)
・A_{i, j} ≦ A_{i, j+1}
・1 ≦ X ≦ N × M - 1
・1 ≦ R_k ≦ N (1 ≦ k ≦ X)
・1 ≦ S_k ≦ M (1 ≦ k ≦ X)
入力例1
3 4
0 1 2 3
0 4 5 6
0 7 8 9
3
1 4
3 2
2 2
出力例1
5
入力例2
1 9
0 2 7 10 13 33 74 76 82
4
1 6
1 4
1 5
1 3
出力例2
65
入力例3
8 9
0 1 3 4 22 34 60 63 85
0 35 44 50 53 56 61 90 99
0 7 15 35 42 51 53 96 100
0 23 40 41 44 64 67 83 91
0 5 36 47 59 70 81 87 97
0 5 11 14 30 34 64 76 90
0 4 5 22 57 62 90 91 98
0 8 13 25 35 41 60 68 82
10
2 6
3 4
6 1
4 4
5 4
8 6
1 8
5 6
4 6
5 1
出力例3
259 
*/