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
### 3/10
- BPでの変数の追加、キャスト、型の指定
- C++での変数の追加、キャスト、型の指定、UEならではの変数FString
- Kismet/KismetSystemLibrary.hでUKismetSystemLibraryを使える
- Kismet/KismetStringLibrary.hでfloatをFStringを使える
### 3/11
- [BPでComponentを追加](https://zenn.dev/posita33/books/ue5_starter_cpp_and_bp_001/viewer/chap_02_bp-component)
- [C++でComponentを追加](https://zenn.dev/posita33/books/ue5_starter_cpp_and_bp_001/viewer/chap_02_cpp-component)
- UPROPERTY(EditAnywhere)でUEのエディタの詳細のところで操作できるようになる
- TObjectPtr<〜>で変数を宣言できるらしい。TObjectPtrはスマートポインタ型というらしい
- 変数名 = CreateDefaultSubobject<型>(TEXT("コンポーネントにつけたい名前"));でインスタンス化
- インスタンス->関数でそのインスタンスのクラスに定義されている関数を使えるらしい。
### 3/12
- [BPでConstructionScriptを使い、エディタでプロパティを変更できるようにする](https://zenn.dev/posita33/books/ue5_starter_cpp_and_bp_001/viewer/chap_02_bp-construction_script)
- [C++でConstructionScriptを使い、エディタでプロパティを変更できるようにする](https://zenn.dev/posita33/books/ue5_starter_cpp_and_bp_001/viewer/chap_02_cpp-construction_script)
- コンポーネントはアクターに対して追加されるオブジェクト。プロパティはオブジェクトの状態や設定を保持するデータメンバ。
- コンストラクタとOnConstruction(const FTransform& Transform)の違い

| **比較項目** | **コンストラクタ (`ACPPConstructionScript()`)** | **OnConstruction (`const FTransform& Transform`)** |
|-------------|---------------------------------|---------------------------------|
| **実行タイミング** | アクターのインスタンス作成時に1回のみ実行 | エディターでプロパティ変更時に何度も実行 |
| **エディターでの実行** | 新規アクターを追加するときに実行される | プロパティを変更すると即時実行される |
| **ゲーム実行時の影響** | スポーン時に1回のみ実行 | 通常は実行されない（スポーン時のみ実行） |
| **用途** | コンポーネントの作成、メッシュのロード | プロパティの変更を即座に適用 |

- OnConstruction(const FTransform& Transform)の引数は参照渡し。エディタでプロパティを変更した時に自動でアクターのtransformが渡される。

| **渡し方** | **記述方法** | **データのコピー** | **関数内での変更** | **主な用途** |
|---|---|---|---|---|
| **値渡し（コピー渡し）** | `void func(Type value);` | あり（毎回コピーされる） | できる | 小さなデータ型（`int` や `float` など） |
| **参照渡し** | `void func(Type& value);` | なし | できる | 関数内で変更したい場合（`FVector&` など） |
| **const 参照渡し** | `void func(const Type& value);` | なし | できない | 大きなデータ型（`std::string` や `FTransform` など） |
| **ポインタ渡し** | `void func(Type* value);` | なし（ポインタのみコピー） | できる | `nullptr` を渡す可能性がある場合 |

### 3/13
-[BPで四則演算](https://zenn.dev/posita33/books/ue5_starter_cpp_and_bp_001/viewer/chap_02_bp-calculation)
### 3/14
-[C++で四則演算の途中まで](https://zenn.dev/posita33/books/ue5_starter_cpp_and_bp_001/viewer/chap_02_cpp-calculation)
-.inlはインライン関数（inline function）を定義するためのファイル拡張子
- インライン関数は関数呼び出しのオーバーヘッドを削減するために、コンパイラが関数のコードを直接展開する機能。  
ただの足し算みたいに頻出するけど処理が軽いものをインライン関数にするらしい。
関数の頭にinlineをつけてインライン関数にする。  
通常関数を呼び出すときは以下処理が発生するが3,4だけになる。
1.関数のアドレスを取得  
2.スタックに引数をプッシュ  
3.関数の実行  
4.戻り値を取得  
5.元の処理に戻る  
-kismetは宿命とか運命という意味らしい。  
昔のUEで使われていたビジュアルスクリプティングシステムの名前。  
多分アクターの運命を決めるものだったからそういう名前なんだと思う。
-TEXT("%d")はフォーマット指定子。TEXT()を使うことによってTCHAR* 型として扱われる。"%d"だけだとコンパイルエラーになることがあるみたい。
### 3/15
-[BPでFLow Control](https://zenn.dev/posita33/books/ue5_starter_cpp_and_bp_001/viewer/chap_02_bp-flow_control_branch)
-[C++でFlow Control](https://zenn.dev/posita33/books/ue5_starter_cpp_and_bp_001/viewer/chap_02_cpp-flow_control_branch)
###3/16
-[C++でFunction](https://zenn.dev/posita33/books/ue5_starter_cpp_and_bp_001/viewer/chap_02_cpp-function)のところまで
-Switchでdefaultというケースを設けてエラー処理とか予想外の値に対応した処理を入れるらしい
-値渡しはC#とかもで使っている引数と同じだが、参照渡しは変数そのものを渡しているのでその値を変更すると大元も変わる。参照渡しの方が領域を確保しない分速い。
###3/17
- スーバー残業デーだったので進捗なし
###3/18
-[BPでinputEvent](https://zenn.dev/posita33/books/ue5_starter_cpp_and_bp_001/viewer/chap_02_bp-input_event)
-[C++でinputEvent](https://zenn.dev/posita33/books/ue5_starter_cpp_and_bp_001/viewer/chap_02_cpp-input_event)
- 設定>プロジェクト設定>エンジン>入力からActionMappingsを作成できる。これはプラットフォーム跨いで入力が変わる時に使える。(switchでAボタンのものをPS5で○とか）
- 入力の有効化をしてあげないと入力の処理入れても反応しない。(C#と違うね)
###3/19
- [BPでEventDisPatcher](https://zenn.dev/posita33/books/ue5_starter_cpp_and_bp_001/viewer/chap_02_bp-event_dispatcher)
- [C++でEventDisPatcher](https://zenn.dev/posita33/books/ue5_starter_cpp_and_bp_001/viewer/chap_02_cpp-event_dispatcher)
- イベントのバインドをしておく。イベントの処理を設定する。イベントを発火させる。という流れで実装。
 ![image](https://github.com/user-attachments/assets/e6768435-6f86-4d5d-9fa9-e57be0e9f971)
###3/20
-[BPでArray](https://zenn.dev/posita33/books/ue5_starter_cpp_and_bp_001/viewer/chap_02_bp-array)
-[C++でArray](https://zenn.dev/posita33/books/ue5_starter_cpp_and_bp_001/viewer/chap_02_cpp-array)
-C#とやってることほぼ同じ。BPはノードが多くなって作るの面倒なのでC++でやったほうが楽。
###3/21
-[BPでFlow Control Loop](https://zenn.dev/posita33/books/ue5_starter_cpp_and_bp_001/viewer/chap_02_bp-flow_control_loop)
-[C++でFlow Control Loop](https://zenn.dev/posita33/books/ue5_starter_cpp_and_bp_001/viewer/chap_02_cpp-flow_control_loop)
-C++はC#とやっていること同じ。BPはノード多すぎてメリットあまり感じられない。
###3/23
- 2章完了

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

### 「::」とは？
 ::はCSの.ににているが少し違う。  
  名前空間のメンバの参照、クラスの静的メンバの参照、名前空間を明示的に参照、グローバルスコープを参照(CSの.にはない機能)に使う。インスタンスメンバ参照は.を使うらしい。

### 変数の宣言と定義するファイルはどれか？
.hで変数の宣言はするけど定義は.CPPするのが好ましい。  
.hは複数の.CPPにincludeされるので様々な該当の変数が生まれてしまい参照がわからなくてエラーが出てしまう。

### includeするもの多いし長い問題
printStringをちょっと使うだけなのにkismet関連だけで二つも出てきた。  
処理を描く時も長いヘッダー名書かなきゃ行けない。
AIに聞いたらゲームプログラマーはコード補完と調べる技術を磨くらしい。
ある程度学び始めたら慣れてくるだろうか。
とりあえずコード補完入れる

### よく聞くポインタというやつ
参照するためとかメモリ管理に使うとか聞くけどよくわからない  
今日勉強できるものでもなさそうなので一旦tryに入れて勉強したい。

### Java系とかPythonとかと書き方がかなり違う
これまでおんなじようなプログラミング言語しか触ってこなかったというか、扱いやすいのしか触ってこなかったんだなということを知った。  
どういう差なのか調べても良さそう

### C++で作ったアクターのメッシュが表示されない
コンストラクタはインスタンス化したタイミングで実行されるが、そのタイミングでは間違ったパスを指定していたためだった。
インスタンス後に変更したが出てこなくて困っていて再度上げ直したところ出るようになった。

### BindKeyとBindAction
BindKeyはPCのキー入力に処理を紐づける。BindActionはAction Mappingに対応した入力に処理を紐づける。
微妙に異なっているので気が付かず躓いていた。
基本的に後者を使うことになると思う。

### C++を変更した後レベルにアクターを再配置しないといけない問題。
また発生して時間かかった。
これどうもコードとか書いて自動化することもできるみたい。
Macの端末依存な気もするので一旦tryに入れておく

## 振り返り
### かかった時間
35hくらい

### Good/Keep
- 環境構築で挫折せずC++を始められた。
- ファイル名間違えたおかげでリネームが簡単にできないことを学べた(気をつけてファイル名つけてたけど、Macだと動作が不安定で変なことになった)
- いいC++の入門サイト見つけられてよかった。動画以外も探したのがえらい。
- CSと違うところをAIに質問しながら進められて、サイトに載っている以上に文法の理解を深めながら進められた。
- 基本的な部分はBPも使えるようになった方がいいと思い、一緒に勉強し始めた。
- 仕事が忙しい時期であまり時間が取れていない&疲労があるが勉強続けられている
- プログラミング言語の成り立ちに興味もてた。勉強したら理解が深まりそうな気がする。
- わからないことを細かく調べられて理解が深まっている実感がある。  
  ゲーム完成させるために自分がやりたいことだけ知識つけるみたいな勉強法してきたけど、たまに自分が興味湧かないけど基礎とか現場でよく使うとされているものも学ぶと言語についての理解が深められるな。
- 時間なくても少し進められた
- キングダムハーツを久々にやりたくなって遊んでみたが爽快感がすごい。  
  キーブレードで蓮撃できる  
  エフェクトが目まぐるしい  
  複数の敵を攻撃できる攻撃範囲の広さ  
  ロックオンで敵を狙いやすい。モンハンみたいに攻撃を外すストレスが少ない。ここは難易度下げすぎてしまうかも。ただ、定期的にロックオンが外れることがあり、そこで難易度のバランスとっていそう。
  1度のダメージが大きいUI上大きい。その上1プレイで3分くらい楽しめて満足できる。それを可能にしているのが敵のHPが多さ。
  ジャンプが高いし、二段ジャンプやグライドとかもあってフィールドを三次元に移動できる爽快感がある。  
  移動速度が速い。通常マップとかも移動速度早くて爽快感ある。その分マップも広くすることで短さを感じさせない。さらに壮大な世界への没入感も演出している。  
  スタン状態が短い。復帰コマンドやカウンターなどがあるから素早いバトルを演出できている。  
  シンプルな操作方法。複数のボタンを同時押しで選択しとか増やされるとめんどくさいが、そういうのがないのでストレスなく戦える。
  バトル中の盛り上がりとしてモードチェンジやフィニッシュ技、特殊な三角ボタンの技などがあって盛り上がるし、それでとどめ刺したくなる。
  操作のシンプルかつ自由さ、移動やUI、エフェクトなどの状況が変わるスピード感(それを許容するゲームの設定や世界の大きさ)、バトル中の見せ場、これがキングダムハーツのアクションとしての面白さだなと感じた。
  同じくUEで作っているのでこういうゲーム作りたい。
- C#とほぼ一緒なので飛ばし気味で取り組組めた
- これまで勉強したこと＋C#と同じようなコードを書くようになってきたので勉強スピードが上がってきた。
- 残業した割に結構時間取れた。早く寝れそう。今日で重たい仕事終わったので明日からどんどんゲーム作れると思う。
- 積んでたジャンプ＋の漫画と時のオカリナを少し消化できた。
- 仕事の終わりが見えて気分がスッキリ。
- 予定立てなきゃいけないと思っていたのができた。
- 自分で考えて仕組みを作る、遊びが生まれるもしくは拡張される、新しいというのがないと自分はモチベーションが上がらないことに気がつけた。
  この勉強ではサイトを書き写し、Unityでもやれるような内容かつPrintStringのみでひたすら勉強していたのでつまらなかった。  
  (C++ならではのコードの書き方を学んで新しい知識を獲得している実感はできたのでそこはモチベになったが。)
 
### Bad/Problem
- Macならではの仕様で躓きが多かった。ドキュメントがなくAIも情報が古かったり、Windowsのやり方ばっか教えてきたりするので早くWindowsにしたい。
- 最初動画で勉強してたけどなんか雑談している動画だったので無駄な時間を使ってしまった。
- 最初だから調べつつやっているけど、ちょっとしたことなのに時間がかかる。.hと.CPPで分かれてたり、知識が必要な場所が多かったりして他の言語との違いに翻弄されている気がする。
- 仕事が終わったあと速攻でランニングして風呂入って勉強したら2時間くらい確保できた。
  ということは今までダラダラしすぎ？
  でも、昨日よく寝れたからだと思うので睡眠が大事。
- 言葉の定義大事。何度も見たり聞いたりしてきたことでも曖昧に理解して流しているから身についてなかった。
- 仕事疲れて終了後即寝てしまった。夜眠れなくなるのでやっては行けないとわかりつつ動けないのでやってしまう。生活リズムを週のどっかで崩すとそれをずっと引きずるので生活リズムは崩さないようにする
- 金曜日は土日なのが嬉しすぎて勉強できない
- GitHub日記に結構時間かかってしまう
- 眠れず睡眠不足なのと予定があって勉強時間が確保できない。
- 3/10週に2章終わらす予定だったのにできてない。
- 少し残業してしまった。
- ゲームならではのインプットとかエディタ関連項はなかなかスピード出せない
- 毎回新しいレベルとアクター作らされるけど、それがちりつもで時間かかるな
- 寒すぎ&疲労で運動できなかった。
- 作業の見積もりが甘い。作業時間が少なくて厳しくなっている。
- インプットするためだけで遊びを生み出したり、価値を生み出したりしないコード作成にワクワクできてない
- 面倒な割に成果が地味で進捗悪すぎ。ゲーム作りながら身につくみたいな本買う？

### Try
- コード補完調べる->実際に手を動かした方が理解度深まるのでこのサイトが終わるまではなるべく使わない。
- ポインタを調べる
- 毎日1セクションは必ずやる
- Python,Java,C#,Kotlin,VBA,C++で何が違うのか調べる
- 睡眠大事にする
- 知らない言葉についてもメモ作って定着させる
- 生活リズムを崩さない。ちゃんと８時間寝る。
- この期間ゲームのメモを取るのいいなと思った。あとアクションゲームが好きなのでいろんなの遊びたい。
- 金曜日夜も勉強する
- 金曜日の夜に生活リズム崩すの防ぐ。
 睡眠しっかりとる->仕事が終わったら眠らないでランニング->風呂→勉強
- C++を変更した後レベルにアクターを再配置しないといけない問題の自動化
- 2章終わらせてゲーミングPC手に入れたら一回ゲーム作ってみる期間は2週間。
  目的は一旦作ってみて足りない知識を洗い出したいのとモチベーション向上。
  あとこのままこのサイトで勉強し続けるか参考書レベルが必要ななのか検討したい。
  PerforceとやらでMacとWindowsを連携させてみよう。
- 見積もりを粒度細かく作る
- 3章とかは内容を応用して遊びを作りながらアプトプットやってみる
- 終わった後に振り返りする。
- 半年前の状況と比べて成長したところと足りないところを考える。
- 次の学び方を考える

### Done
- このサイトを3/10の週で終わらせるためにスケジュール立て。量が多いので3週間スパンに変更。今週は2章を終わらせる。
-SNS削除する(宣伝用にSNS入れていたが今は宣伝するものがないので)
- 仕事で生まれたモヤモヤを早期に解消する

### 進捗動画
[3/9](https://youtu.be/5tInei_YqSI)  
[3/10 PrintStringの表示をVariableで指定](https://youtu.be/Q52kg-QowG8)  
[3/11](https://youtu.be/lX7JkiFUGrk)
[3/12](https://youtu.be/UR7440sCLmM)

