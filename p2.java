/*あなたは、映画館の席の予約をしようとしています。

座席は、縦の位置を表す p と横の位置を表す q の (p, q) で指定でき、最も左上の席が (0, 0) となっています。
映画館には、最も見やすい席が 1 席存在し、最も映画を見やすい席とのマンハッタン距離が小さいほど、映画を見やすくなっています。

マンハッタン距離とは、ある 2 点 (p, q)、(s, t) に対して、|p - s| + |q - t| で与えられる距離を表します。

あなたは、できるだけ映画を見やすい席を予約しようと思っています。
最も見やすい席とすでに予約されている席の情報が与えられるので、まだ予約されていない席の中で、最も映画を見やすい席を求めてください。

入力例 1 の場合、映画館の席は縦 4 列、横 5 列の計 20 箇所の席があります。最も見やすい席は (2, 3) にあります。

最も見やすい席 (2, 3) は予約済みであり、予約されていない席で最も見やすい席とのマンハッタン距離が最も小さい席は、以下の図のように、マンハッタン距離 2 の (0, 3), (3, 2), (2, 1) の 3 箇所です。それぞれの位置のマンハッタン距離は、|2 - 0| + |3 - 3|, |2 - 3| + |3 - 2|, |2 - 2| + |3 - 1| と計算されます。まだ予約されていない席の中で、最も映画を見やすい席をすべて出力してください。どのような出力順序でも構いません。

入力される値
入力は以下のフォーマットで与えられます。

N H W P Q
p_1 q_1
p_2 q_2
...
p_N q_N
・1 行目にすでに予約されている座席の数 N、映画館の座席の縦の数 H、映画館の座席の横の数 W、最も見やすい席の p 座標、q 座標を表す P, Q がそれぞれ半角スペース区切りで与えられます。
・続く N 行のうちの i 行目 (1 ≦ i ≦ N) には、それぞれ i 番目の予約されている座席の p 座標、q 座標を表す整数 p_i, q_i がこの順で半角スペース区切りで与えられます。
・入力は合計で N + 1 行となり、入力値最終行の末尾に改行が 1 つ入ります。

それぞれの値は文字列で標準入力から渡されます。標準入力からの値取得方法はこちらをご確認ください
期待する出力
まだ予約されていない席の中で、最も映画を見やすい席を以下の形式ですべて出力してください。
a_1 b_1
a_2 b_2
...
a_K b_K
・まだ予約されていない席の中で、最も映画を見やすい席の数 K に対し、期待する出力は K 行からなります。
・i 行目 (1 ≦ i ≦ K) にはそれぞれ i 番目の最も映画を見やすい空席の p 座標、q 座標を表す a_i, b_i をこの順で半角スペース区切りで出力して下さい。
・すべて整数で出力してください。
・出力最終行の末尾に改行を入れ、余計な文字、空行を含んではいけません。
条件
すべてのテストケースにおいて、以下の条件をみたします。

・1 ≦ H, W ≦ 100
・1 ≦ N < H × W
・0 ≦ P < H
・0 ≦ Q < W
・0 ≦ p_i < H (1 ≦ i ≦ N)
・0 ≦ q_i < W (1 ≦ i ≦ N)
・各 i, j (1 ≦ i, j ≦ N) について i ≠ j のとき (p_i, q_i) ≠ (p_j, q_j)
入力例1
9 4 5 2 3
1 0
1 2
1 3
1 4
2 2
2 3
2 4
3 3
3 4
出力例1
0 3
2 1
3 2
入力例2
4 3 2 2 0
0 0
1 0
1 1
2 1
出力例2
2 0
*//

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int h = sc.nextInt();
        int w = sc.nextInt();
        int P = sc.nextInt();
        int Q = sc.nextInt();
        
        // 予約済み座席の情報を保存するためのセット
        Set<Integer> reservedSeats = new HashSet<>();
        for (int i = 0; i < n; i++) {
            int p = sc.nextInt();
            int q = sc.nextInt();
            // 座席 (p, q) は予約済みであることを示す
            reservedSeats.add(p * (w + 1) + q);
        }

        int minManhattanDistance = Integer.MAX_VALUE;
        List<Integer> bestSeats = new ArrayList<>();

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                int manhattanD = Math.abs(P - i) + Math.abs(Q - j);
                if (!reservedSeats.contains(i * (w + 1) + j) && manhattanD < minManhattanDistance) {
                    // まだ予約されていない座席で、マンハッタン距離が最小の座席
                    bestSeats.clear();
                    bestSeats.add(i);
                    bestSeats.add(j);
                    minManhattanDistance = manhattanD;
                } else if (!reservedSeats.contains(i * (w + 1) + j) && manhattanD == minManhattanDistance) {
                    // まだ予約されていない座席で、マンハッタン距離が最小と等しい座席
                    bestSeats.add(i);
                    bestSeats.add(j);
                }
            }
        }
        
        for (int i = 0; i < bestSeats.size(); i += 2) {
            System.out.println(bestSeats.get(i) + " " + bestSeats.get(i + 1));
        }
    }
}
