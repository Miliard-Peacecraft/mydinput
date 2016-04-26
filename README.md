# mydinput
解決RO主程式消耗CPU使用率的問題。
##簡述：
自從換了新電腦後，我一直很納悶為什麼RO這個我國一(目前出社會了)就有的老遊戲還可以占用CPU那麼多的使用率，那時我推測應該是某段程式碼產生了busy waiting，但是不知道出現在哪。

之後我上網Google是否有能下降RO主程式CPU使用率的方法，結果查到了"RoExt 視窗調整大師"，但是這個DLL (動態連結程式庫)使用後，只有在RO主程式沒在操作時才會下降CPU的使用率，始終沒有解決根本的問題，但也因為"RoExt 視窗調整大師"讓我知道了busy waiting是dinput.dll中的函式不間斷地被RO主程式呼叫。


##方法原理：
原本RO主程式直接去呼叫dinput.dll中的函式，為了讓RO主程式在不間斷地呼叫dinput.dll中的某個函式前加入延遲函數sleep()來降低CPU使用率，於是我寫了一個自己的dinput.dll，讓RO主程式透過我的dinput.dll以間接的方式去使用那些函式。

我設定延遲函數讓執行緒暫停7 ms，讓FPS保持大約30左右。

![image](http://truth.bahamut.com.tw/s01/201604/ba7bd23905e1303a9b4c09e2c6afd148.PNG)



##如何使用：
將我寫的dinput.dll放置到RO的資料夾中即可，跟Ragnarok.exe同一個資料夾，windows下的環境預設是會先讀取相同資料夾下的DLL，找不到才會到系統中讀取。

千萬不要把我寫的dinput.dll去覆蓋原本系統的dinput.dll。

刪除的方式也很簡單，直接把RO的資料夾內我的寫的dinput.dll刪除即可。


##相關資源：
這個dinput.dll有兩種取得方式。

###第一種直接下載我的dinput.dll：
先聲明如果使用了我的dinput.dll，使你的帳號被盜或是電腦中毒...等問題，我一概不負任何責任，雖然我的dinput.dll裡沒有參雜任何會導致上述問題的程式碼，但在此我還是要特別聲明。

下載網址

https://drive.google.com/file/d/0B5HLtFRW8JM-VXBCQ1lNNTc5dkU/view?usp=sharing

###第二種下載原始專案自己編譯自己的dinput.dll：
我將原始專案上傳至github，完整程式碼透明公開，如果對第一種方法有疑慮的人，強烈建議使用第二種方法。

此專案是VS2013的專案，因此要先安裝VS2013和相關的程式庫。

VS2013主程式 & 語言套件下載

https://www.visualstudio.com/zh-tw/downloads/download-visual-studio-vs.aspx

![image](http://truth.bahamut.com.tw/s01/201604/38fc0efdb04ea57f8e83ed7efde65a60.PNG)

程式庫Multibyte MFC Library for Visual Studio 2013

https://www.microsoft.com/zh-tw/download/details.aspx?id=40770

##使用前後比較：
###使用前

![image](http://truth.bahamut.com.tw/s01/201604/4fda6097aa28158595b520afba2c30a3.PNG)

###使用後

![image](http://truth.bahamut.com.tw/s01/201604/e952f9c89cb6eaccb7968978e5489a9c.PNG)
