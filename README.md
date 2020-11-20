# ソフトウェア設計Ⅱの課題

# 概要
あなたは高専に入学しました。留年せずに頑張ろう！

# 要求仕様
## ゲームシステム
### ルール
- 毎回、四則演算の問題が10問出題される。
  - 6問以上正解なら、学年が上がり、6問未満なら学年が留まる(留年)

## ゲーム内要素
### プレイヤー

## インタフェース

# テスト計画
## 単体テスト
## 結合テスト
## 全体テスト

# 設計書
## データ構造
```c=
typedef struct {
    int sumScores;//点数
    int diffScore;//赤点との差分
} t_PlayerScore;
```

点数関係の構造体

```c=
typedef struct {
    int schoolGrade; //学年
    int countRepeatYear;//留年回数
    int myTurn; //ターン
} t_PlayerStatus;
```

ゲーム進行において必要な情報が入ってる構造体

## 関数使用
```c=
void checkStatus(t_PlayerStatus player){ }
```

学年チェックを行う。
ここで、学年、留年回数、ターン回数を見ることができる。

```c=
int tryExam(t_PlayerScore scores, t_PlayerStatus player){ }
```

問題生成を行い、解答してもらう。
今のところ、四則演算のみ。
```c=
void updateStatus(t_PlayerStatus *player, int isFlag){ }
```

学年、ターン更新を行う。
留年回数も必要に応じて行う。

```c=
void finishMessage(){ }
```

終わりのメッセージを表示する。

# テスト
## 単体テスト
## 結合テスト
## 全体テスト

# その他
## 命名規則
[C言語における命名規則のポイントと実例
](http://www.c-lang.org/detail/naming_conventions.html)と[C Coding Standard
](https://users.ece.cmu.edu/~eno/coding/CCodingStandard.html)、[Recommended C Style and Coding Standards
](https://www.doc.ic.ac.uk/lab/cplus/cstyle.html)を参考にした
