# Unreal Engineの修行_3
## 修行の目標
UEでハイエンドなゲームを作り  
6月末までにSteamやコンシューマーPFでゲームをリリースする。

## 今回学びたいこと
C++の入門レベルの知識
理由：AAAタイトルではC++で作ることが多いらしい。(BPだと重い&自由度がC++の方が高いので)

## 学ぶ手段
C++入門として[このサイト](https://zenn.dev/posita33/books/ue5_starter_cpp_and_bp_001/viewer/chap_00_about)をなぞっていく

## 学び
### 3/9
サイトの[ここまで](https://zenn.dev/posita33/books/ue5_starter_cpp_and_bp_001/viewer/chap_02_cpp-print_string)やった。
- エディターの勉強  
  Visual Studio,RiderがメインらしいVSCodeは重くてあまり使われないらしい。
  Visual Studio2022はMacで使えない。Riderは有料だが非商用なら無料で使えるみたい。あと一番軽いらしい。
  Android Studioを作っている会社(JetBrains)なので見た目が一緒。
- C++の作成
- 生成したてのC++の構造  
  .hと.CPPというのが生成されて.hはクラス名や関数の宣言、.CPPには関数の中身を書くらしい。
- Hello Worldの出力
  
## つまずきと対応
### UE上のC++ファイル名をリネームできない
UE上ではできない。コードエディタ上でリネームし、ファイル名が記載されているところ全部変更しなきゃいけない。  
その後windows上だとエクスプローラーで.uprojectを左クリックし、Generate Visual Studio Project Filesをすると治るらしい。
Macでは.uprojectを左クリックしてもGenerate Visual Studio Project Filesがなく、UE上の表示だけ治らなかった。  
書いているサイトとかもないのと、windowsに買い替えるので無視することにした。(暇だったらいつか。)

### UEでRiderが開かない
エディタ設定のsource code Editorの設定をRiderにすればいいとのことだった。  
しかし。WindowsではUEウィンドウのファイルの中にエディタ設定という項目があるのだがMacにはなかった。  
Macは画面全体のUnrealEdhitorの中の環境設定がエディタ設定にあたり、その中にあった。  
ただ、Macではそもそもそこの設定を変えてもRiderを開くことはできないらしい。
RiderLinkというのをRider側で入れて再起動すると連携ができた。
プラグインで検索しても出てこないが、右下のポップアップでなぜか出てきたのでそこからインストールできた。

## 振り返り
### かかった時間
7hくらい

### Good/Keep
- 環境構築で挫折せずC++を始められた。
- ファイル名間違えたおかげでリネームが簡単にできないことを学べた(気をつけてファイル名つけてたけど、Macだと動作が不安定で変なことになった)
- いいC++の入門サイト見つけられてよかった。動画以外も探したのがえらい。

### Bad/Problem
- Macならではの仕様で躓きが多かった。ドキュメントがなくAIも情報が古かったり、Windowsのやり方ばっか教えてきたりするので早くWindowsにしたい。
- 最初動画で勉強してたけどなんか雑談している動画だったので無駄な時間を使ってしまった。

### Try
- このサイトを3/10の週で終わらせるためにスケジュール立て

### Done


### 進捗動画
[3/9](https://youtu.be/5tInei_YqSI)
