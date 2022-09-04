
# convolution5x5
画像を読み込み、RGB値を取得し、任意の重み付け係数を用いてすべての画素に対して再計算します。  
位置を変えながらすべての画素に対して計算を行うことをコンボリューションと呼ぶそうです。  
フィルタ処理と呼んだほうが馴染みがあるかもしれません。  
デモでは、近傍8点を用いたラプラシアンフィルタと平滑化処理を行っています。  
画像読み込み、GUIにはQtを使用しています。  

## Demo
基本の写真です。  
![base](https://user-images.githubusercontent.com/12496951/188319350-bad6953b-2771-453f-875c-6e6ba92938e6.PNG)  

近傍8点を用いたラプラシアンフィルタです。エッジ強調みたいな感じ?  
![laplacian](https://user-images.githubusercontent.com/12496951/188319352-718aaad8-b15b-4f5e-a1a4-67ebb69b8746.PNG)  

平滑化フィルタです。  
![smooth](https://user-images.githubusercontent.com/12496951/188319356-65ede0e3-0730-4d40-b173-309c1a590bb7.PNG)  

## Dependency
- MSVC 15+  
- Qt 5.13.1

## Build
CMakeLists.txtではQTDIRを環境変数から取得して使用しています。  
また、ここではWSL2とPowerShell、CMakeを使用したビルド方法を記述します。  
CMakeは環境変数のPATHへ追加しています。  

1. このリポジトリをクローンします。  
2. 以下のコマンドでビルドします。  
   ex. VS2017 の場合  
   powershell.exe cmake -S . -B build -G "\\"Visual Studio 15 2017 Win64\\""  
   powershell.exe cmake --build build  

   ex. VS2019以上の場合  
   powershell.exe cmake -S . -B build  
   powershell.exe cmake --build build  

3. 実行時に必要なDLL群はコピーしていません。実行の際には注意してください。


## License
This software is released under the MIT License, see LICENSE.

## References
[C言語で学ぶ実践CG・映像合成](https://www.ohmsha.co.jp/book/9784274500169/)  
[コンピュータ画像処理(改訂2版)](https://www.ohmsha.co.jp/book/9784274228193/)  
[ベッドの下で元カノの帰りを待っていたストーカー化する元カレの写真素材](https://www.pakutaso.com/20160432099post-7538.html)
