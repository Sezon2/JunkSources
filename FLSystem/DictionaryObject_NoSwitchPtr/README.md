# JunkSources for DictionaryObject_NoSwitchPtr v1.00
過去の産物。複数のクラスを切り替えて管理するにあたり、
元々はこのロジックでやっていたが、一々メモリ管理を意識する必要があったため、
別途、切り替え管理を行なうSwitchPtrシリーズを作成し、
現在ではこのSwitchPtrシリーズを使用してクラスの切り替え管理を行なっている。  
このソースコードはSwitchPtrシリーズに置き換える前のダイレクトなメモリ管理方法における、
複数クラスの切り替えのやり方を知りたい傾けに公開しています。

## ■SwitchPtrシリーズとは？
2019/05/19現在、開発中のSwfファイルの汎用コンバータ「SwfGenericConverter」や
今後、開発予定の「UIPlayer」及びそのDemoにおいて、末端のコアライブラリとして使用される、
「AppStdLib」に搭載している、最大10個のクラスをテンプレート引数に登録し、
その登録したクラスのポインタ型でキャストするだけで簡単にキャストしたクラスに切り替えて、
そのままそのクラスを利用する事が出来るものです。  
「AppStdLib」自体は「boost」のような実験場なので、これを公開用に纏めた、
「AppBaseLib」と言うライブラリを「SwfGenericConverter」公開後あたりに公開を予定しています。  
「AppBaseLib」の現在の公開方針としてはGitHubでオープンソースとして公開し、
必要な機能の追加や分離すべき機能の分離など、さまざまな調整を皆さんと行なって行く予定です。  

## ■ライセンスの取り扱いについて
https://ja.wikipedia.org/wiki/MIT_License  
https://qiita.com/yyama2/items/20bdf5e914c20025498a  

**□ライセンスの追加制限など**  
特にありません。  
Masterのライセンスに準拠します。  

## ■パッケージ公開
https://drive.google.com/open?id=11N8CQ2HHZ-_x_JM6rPRWaLH9GSf4lzC-  

## ■mdファイルの書き方について
GitHubで使われるドキュメントの形式「*.md」について、  
このファイルは規則にしたがって半角記号やスペースを入れることで簡単に  
文書をマークアップできるようになっています。  

マークアップの仕方は下記にありますので、ご確認ください。  
https://qiita.com/oreo/items/82183bfbaac69971917f  
