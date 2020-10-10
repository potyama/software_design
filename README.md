# ソフトウェア設計Ⅱの課題

# 概要
あなたは高専に入学しました。留年せずに頑張ろう！

# ルール
- 毎回、四則演算の問題が10問出題される。
  - 6問以上正解なら、学年が上がり、6問未満なら学年が留まる(留年)

# 構造体
```C
typedef struct {
    int sum_points;
    int diff_point;
} point;
```
点数関係

```C
typedef struct {
    int school_grade;
    int count_repeat_year;
    int turn;
} board;
```
学校関連

# 関数
```C
void checkGrade(board person){ }
```
学年チェック

```C
int shouldPromotion(point add_point, board player){ }
```
問題生成

```C
void updateGrade(board *main_character, int isFlag){ }
```
学年更新

```C
void message(){ }
```
終わりのメッセージを表示

詳しくはまた今度書く。