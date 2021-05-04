# OOP01-Big-Num-Calculator
## 題目名稱：大數計算機
### 題目說明：
請以C++ 程式語言設計大數計算機，支援Integer(整數)、Decimal(小數)運算，而且還
須支援變數功能，亦即可以定義變數及該變數的型態。
除此之外，請遵循以下運算法則：<br>
運算子優先權<br>
1.( )<br>
2.! 由左至右<br>
3.^ 由右至左<br>
4.+- (正負號) 由右至左<br>
5.\* \/ 由左至右<br>
6.+ - 由左至右<br><br>
● 整數與整數運算其結果為整數。<br>
● 整數與浮點數運算其結果為浮點數(順序相反亦然)。<br>
● 除了支援任意數之間的加減乘除之外，還要有Power(冪次)及正整數的Factorial(階
乘)。<br>
● 輸出Decimal 時，請直接輸出至小數點後100 位，不必四捨五入或者無條件進位等動
作，Decimal 的小數請以分數實作，亦即：<br>
1.0 / 3.0 * 3 = 1.00000000…，而非 0.999999999999...。<br>
● 程式必須可以讓使用者將任意運算式的值賦予變數，而且可以重新賦值，例如：<br>
  - Set Integer A = 100 + 5! + Power(5, 2)<br>
  - Set Integer A = 3<br>
  - Set Decimal A = 1.0<br>
  - A = A + A<br>
* 輸入格式自訂，測資只會給算式，Demo 的時候請自己輸入。<br>
* 輸出格式自訂，以方便助教閱讀為原則。<br>
* 輸出時機<br>
- Set Integer A = 3 // 不用輸出<br>
- A = 1 + 5 // 不用輸出<br>
- A // 輸出 6<br>
- A + A // 輸出 12<br>
- 1 * 33 + 4 // 輸出 37<br>
* 當輸入非法運算式 (Ex: 除0、小數的階乘)，需要輸出錯誤資訊，不能直接讓程式
崩潰。
