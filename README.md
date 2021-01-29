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

## 関数仕様

```c=
void  getWord(char *word)
```
単語リストを取得

```c=
void showStatus(char *word)
```

ステータスを表示

```c=
int chooseRepeat(t_PlayerStatus player)
```

問題数を計算

```c=
int levelOne(t_PlayerStatus player)
int levelTwo(t_PlayerStatus player)
int levelThree(t_PlayerStatus player)
```

難易度ごとの問題の出題

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

## 基本関数のリスト ※関数仕様とほぼ同じ箇所多々あり

```c=
void  getWord(char *word)
```
単語ファイルを読み込み、ランダムで最短文字数以上の単語をwordに代入する

```c=
void checkStatus(t_PlayerStatus player)
```
プレイヤーの情報(学年、留年回数、ターン数)を表示する

```c=
void showStatus(char *word)
```
単語問題の状態を表示する。ここでは2,3文字目を隠す。

```c=
int chooseRepeat(t_PlayerStatus player);
```
返り値 repeat
程よい回数繰り返すための数字をrepeatに返す。

```c=
int levelOne(t_PlayerStatus player)
```
返り値 cnt 
ランダムに加算または減算の問題を出題し、
正解数をカウントしcntに返す。

```c=
int levelTwo(t_PlayerStatus player)
```
返り値 cnt
ランダムに乗算または除算の問題を出題し、
正解数をカウントしcntに返す。

```c=
int levelThree(t_PlayerStatus player)
```
返り値 cnt
ランダムに英単語の虫食い問題を出題し、
正解数をカウントしcntに返す。

```c=
int tryExam(t_PlayerScore scores, t_PlayerStatus player)
```
学年に応じて出題する問題を切り替え出題し、
採点、進級の可否を表示する。

```c=
void updateStatus(t_PlayStatus *player, int isFlag)
```
問題の正答率に応じて学年または留年回数の追加とターン数を増やす。

```c=
void finishMessage();
```
終了メッセージを表示する。

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


# 作成者
WalkerZC
