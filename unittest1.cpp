using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyLibrary2
{
    public class Calculator
    {
        public int Add(int a, int b)
        {
            return a + b;
        }
    }
}


using Microsoft.VisualStudio.TestTools.UnitTesting;
using MyLibrary2;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyLibrary2.Tests
{
    [TestClass()]
    public class CalculatorTests
    {

        [TestMethod]
        public void Add_WhenCalled_ReturnsSum()
        {
            // Arrange
            //Arrange：設置測試所需的變數（在這裡是 a 和 b）
            var calculator = new Calculator();
            int a = 5;
            int b = 10;

            // Act
            //Act：調用被測試的方法，將結果存儲在 result 變數中
            var result = calculator.Add(a, b);

            // Assert
            //Assert：檢查 result 是否等於預期值 
            //使用 Assert.AreEqual 來驗證實際值與預期值的一致性。

            Assert.AreEqual(15, result);
        }
    }
}


/*
Output

測試名稱:	Add_WhenCalled_ReturnsSum
測試結果:	成功
測試持續時間:	0:00:00.0117493

[2024/10/08 Informational] ------ 探索測試開始 ------
[2024/10/08 Informational] ========== 探索測試結束: 找到 1 個 (0:00:03.5298126) ==========
[2024/10/08 Informational] ------ 回合測試開始 ------
[2024/10/08 Informational] ========== 回合測試結束: 執行了 1 回合 (0:00:01.3235053) ==========

*/