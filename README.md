# mydinput
利用減少FPS讓RO主程式CPU的使用率下降。
##簡述：
原本RO主程式的FPS固定最高在60 FPS，利用下降到一半左右約30 FPS，讓CPU的使用率下降。



##方法原理：
原本RO主程式直接去呼叫dinput.dll中的函式，為了讓RO主程式每次去呼叫dinput.dll中的某個函時，可以讓整個執行序暫停一段時間，使得FPS可以下降，於是我寫了一個自己的dinput.dll，讓RO主程式透過我的dinput.dll以間接的方式去使用那些函式，所以我可以在呼叫那些函式前利用延遲函數sleep()，使執行序暫停一段時間。

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
