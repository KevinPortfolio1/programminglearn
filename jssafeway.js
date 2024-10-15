/*
JavaScript 程式範例，展示了如何提高安全性：
1. 防止 XSS 的範例

使用 textContent 而不是 innerHTML 来插入用户輸入的内容：
可以確保任何插入的内容都被視為文本，而非 HTML


javascript
*/

const userInput = "<script>alert('XSS');</script>";
const safeElement = document.createElement("div");
safeElement.textContent = userInput; // 安全插入
document.body.appendChild(safeElement);


/*
2. 防止 CSRF 的範例
生成 CSRF 令牌並在每個請求中包含它
使用 CSRF 令牌可以確保請求是由用户的意圖發起的
javascript

*/
// 伺服器端生成令牌並發送给前端
const csrfToken = "generatedCsrfToken"; // 假設這是從服務器獲取的令牌

// 發送請求时包含 CSRF 令牌
fetch('/api/resource', {
    method: 'POST',
    headers: {
        'Content-Type': 'application/json',
        'X-CSRF-Token': csrfToken // 將令牌包含在請求頭中
    },
    body: JSON.stringify({ data: "example" })
});

/*
3. 使用 HTTPS 的範例

在代碼中强制使用 HTTPS：
如果不是 HTTPS，就将用户重定向到 HTTPS 版本

javascript
*/


if (location.protocol !== 'https:') {
    window.location.href = 'https://' + window.location.host + window.location.pathname;
}

/*
4. Cookie 的安全設置

設置 HttpOnly 和 Secure 的 Cookie：

HttpOnly 標誌可以防止客户端 JavaScript 訪問該 Cookie，從而减小 XSS 攻擊的風險。
Secure 標誌要求 Cookie 僅在 HTTPS 連接中傳輸
SameSite 標誌防止 CSRF 攻擊，只有同源請求才能發送該 Cookie

javascript

*/
document.cookie = "sessionId=yourSessionId; HttpOnly; Secure; SameSite=Strict";


/*
5. 输入驗證

使用正規表達式驗證用户輸入：
防止一些類型的攻擊（如 SQL 注入）和數劇錯誤

javascript

*/
function validateEmail(email) {
    const regex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
    return regex.test(email);
}

const userEmail = "user@example.com";
if (validateEmail(userEmail)) {
    console.log("Valid email!");
} else {
    console.log("Invalid email!");
}

