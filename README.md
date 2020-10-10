# ソフトウェア設計Ⅱの課題

# 概要
あなたは高専に入学しました。留年せずに頑張ろう！

# ルール
- 毎回、四則演算の問題が10問出題される。
  - 6問以上正解なら、学年が上がり、6問未満なら学年が留まる(留年)

# 構造体
```c=
typedef struct {
    int sum_points; //獲得点数
    int diff_point; //赤点との差分
} point;
```

点数関係の構造体

```c=
typedef struct {
    int school_grade;　//学年
    int count_repeat_year; //留年回数
    int turn; // ターン
} board;
```

ゲーム進行において必要な情報が入ってる構造体

# 関数
```c=
void checkGrade(board person){ }
```

学年チェックを行う。
ここで、学年、留年回数、ターン回数を見ることができる。

```c=
int shouldPromotion(point add_point, board player){ }
```

問題生成を行い、解答してもらう。
今のところ、四則演算のみ。
```c=
void updateGrade(board *main_character, int isFlag){ }
```

学年、ターン更新を行う。
留年回数も必要に応じて行う。

```c=
void message(){ }
```

終わりのメッセージを表示する。

