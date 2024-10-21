/*
JavaScript 的文字編碼主要涉及

  UTF-8 編碼：
    JavaScript 字符串是基於 UTF-16 編碼的，但在與其他系統（如網絡請求、文件存取）交互時，
	通常使用 UTF-8。確保你的伺服器和客戶端都使用 UTF-8 編碼，以避免亂碼問題。
	
  字符串處理：
    JavaScript 中的字符串可以包含多種字符（如漢字、符號等）
*/
const greeting = "你好，世界！";
console.log(greeting);

/*
轉碼：
    當處理 URL 或表單數據時，使用 encodeURIComponent() 和 decodeURIComponent() 進行編碼和解碼
*/
const uri = "https://example.com/?search=你好";
const encodedUri = encodeURIComponent(uri);
console.log(encodedUri); // https%3A%2F%2Fexample.com%2F%3Fsearch%3D%E4%BD%A0%E5%A5%BD

/*
JSON 編碼：
    使用 JSON.stringify() 和 JSON.parse() 來處理包含多字節字符的對象：
*/
const data = { message: "你好，世界！" };
const jsonString = JSON.stringify(data);
const parsedData = JSON.parse(jsonString);
console.log(parsedData.message); // 你好，世界！

/*
字符長度：
    使用 string.length 可以獲取字符串的字符數，但對於某些多字節字符（如 emoji），可能不準確。
	可以用 Array.from() 來正確計算
*/
const str = "👋 你好";
console.log(Array.from(str).length); // 4

/*
顯示編碼：
    確保 HTML 文件中包含 <meta charset="UTF-8">，以正確顯示多語言字符。
*/

/*
 常見編碼標準
    UTF-8：
        最常用的編碼方式，支持多種語言，包括中文。
		每個字符可由 1 至 4 個字節組成，對於中文字符通常使用 3 個字節。
    GB2312：
       主要支持簡體中文字符。
	   常用於早期的中文處理系統。
    GBK：
        GB2312 的擴展，支持更多的漢字，包含簡體和繁體中文。
    Big5：
        主要用於繁體中文
  
  
1. Unicode
    定義：
        Unicode 是一個字符集，旨在為世界上所有的字符和符號提供唯一的編碼。
		它包括幾乎所有語言的字符（如拉丁字母、漢字、阿拉伯字母等）。

    範圍：
        Unicode 定義了超過 143,000 個字符，包括文字、符號和表情符號，並為每個字符分配了一個唯一的數字編碼（稱為碼點）。

    版本：
        Unicode 不斷更新，增加新的字符和符號。每個版本都有一個唯一的編號（如 Unicode 15.0）。

2. UTF

    定義：
        UTF（Unicode Transformation Format）是一系列將 Unicode 編碼轉換為字節序列的編碼方案。
		常見的 UTF 包括 UTF-8、UTF-16 和 UTF-32。

    類型：
        UTF-8：
            變長編碼，最多使用 4 個字節來表示一個字符。ASCII 字符（0-127）用 1 個字節表示，
			其他字符用 2 到 4 個字節表示。
			UTF-8 是互聯網上最常用的編碼方式。
        UTF-16：
            通常使用 2 個字節表示基本字符，使用 4 個字節表示增補字符（例如某些漢字和表情符號）。
        UTF-32：
            固定使用 4 個字節表示所有字符，簡單但不夠高效，因為對於大多數字符來說會浪費空間。

總結
    Unicode 是字符集的標準，提供了字符的唯一編碼。
    UTF 是將 Unicode 編碼轉換為字節的方式，根據需要選擇不同的 UTF 方案以適應不同的應用場景。

*/