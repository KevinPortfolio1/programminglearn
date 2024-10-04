//反轉字串
function reverseString(str) {
    return str.split('').reverse().join('');
}
//檢查質數
function isPrime(num) {
    if (num <= 1) return false;
    for (let i = 2; i <= Math.sqrt(num); i++) {
        if (num % i === 0) return false;
    }
    return true;
}
//扁平化數組
function flattenArray(arr) {
    return arr.reduce((flat, toFlatten) => {
        return flat.concat(Array.isArray(toFlatten) ? flattenArray(toFlatten) : toFlatten);
    }, []);
}
//合併兩個對象
function mergeObjects(obj1, obj2) {
    return { ...obj1, ...obj2 };
}
//找出數組中的重複數字
function findDuplicate(arr) {
    const seen = new Set();
    for (const num of arr) {
        if (seen.has(num)) return num;
        seen.add(num);
    }
    return null;
}
//斐波那契數列
function fibonacci(n) {
    const fib = [0, 1];
    for (let i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib.slice(0, n);
}
//防抖函數 (Debounce)
function debounce(func, delay) {
    let timeout;
    return function(...args) {
        clearTimeout(timeout);
        timeout = setTimeout(() => func.apply(this, args), delay);
    };
}
//節流函數 (Throttle)
function throttle(func, limit) {
    let lastFunc;
    let lastRan;
    return function(...args) {
        if (!lastRan) {
            func.apply(this, args);
            lastRan = Date.now();
        } else {
            clearTimeout(lastFunc);
            lastFunc = setTimeout(function() {
                if ((Date.now() - lastRan) >= limit) {
                    func.apply(this, args);
                    lastRan = Date.now();
                }
            }, limit - (Date.now() - lastRan));
        }
    };
}
//Promise 鏈
function delay(ms) {
    return new Promise(resolve => setTimeout(resolve, ms));
}
//串行執行 Promise
async function executePromisesInOrder(promises) {
    for (const promise of promises) {
        await promise();
    }
}
/*
使用正規表達式的注意事項
    test() 方法: 用於檢查字串是否匹配正規表達式，返回布林值。
    match() 方法: 用於檢索字串中符合正規表達式的所有匹配項，返回匹配的結果或 null。
    replace() 方法: 用於根據正規表達式替換字串中的匹配項。
*/

/*
1. 基本字符

    .: 匹配任何單一字符（除了換行符）。
        示例: a.c 可以匹配 abc、a-c 等。

    ^: 匹配字串的開始。
        示例: ^Hello 只匹配以 Hello 開頭的字串。

    $: 匹配字串的結束。
        示例: world$ 只匹配以 world 結尾的字串。

2. 字符類

    [abc]: 匹配方括號內的任一字符（如 a、b、c）。
        示例: [aeiou] 匹配任一元音字母。

    [^abc]: 匹配不在方括號內的任一字符。
        示例: [^aeiou] 匹配任何不是元音的字符。

    [a-z]: 匹配字母範圍（小寫字母）。

    [A-Z]: 匹配字母範圍（大寫字母）。

    [0-9]: 匹配數字範圍。

3. 頻率修飾符

    *: 匹配前面的字符零次或多次。
        示例: ab*c 可以匹配 ac、abc、abbc 等。

    +: 匹配前面的字符一次或多次。
        示例: ab+c 可以匹配 abc、abbc 但不匹配 ac。

    ?: 匹配前面的字符零次或一次。
        示例: ab?c 可以匹配 ac 或 abc。

    {n}: 匹配前面的字符正好 n 次。
        示例: a{3} 只匹配 aaa。

    {n,}: 匹配前面的字符至少 n 次。
        示例: a{2,} 可以匹配 aa、aaa 等。

    {n,m}: 匹配前面的字符至少 n 次，但不超過 m 次。
        示例: a{2,4} 可以匹配 aa、aaa 或 aaaa。

4. 邊界

    \b: 匹配單詞邊界。
        示例: \bcat\b 匹配 cat 但不匹配 cater。

    \B: 匹配非單詞邊界。

5. 轉義字符

    \: 用來轉義特殊字符，如 \., \*, \+ 等。
        示例: \. 匹配字面意義上的 . 而不是任何字符。

6. 特殊字符

    \d: 匹配任何數字，相當於 [0-9]。
    \D: 匹配任何非數字字符，相當於 [^0-9]。
    \w: 匹配任何字母數字字符（包括底線），相當於 [a-zA-Z0-9_]。
    \W: 匹配任何非字母數字字符，相當於 [^a-zA-Z0-9_]。
    \s: 匹配任何空白字符（如空格、制表符、換行符）。
    \S: 匹配任何非空白字符。

7. 分組和選擇

    (): 用於分組，可以用來應用修飾符或捕獲匹配的子串。
        示例: (abc)+ 可以匹配 abc、abcabc 等。

    |: 表示邏輯或（OR）。
        示例: cat|dog 可以匹配 cat 或 dog。

*/
//1. 驗證電子郵件地址
function isValidEmail(email) {
    const emailRegex = /^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/;
    return emailRegex.test(email);
}
//2.驗證手機號碼（台灣格式）
function isValidTaiwanPhone(phone) {
    const phoneRegex = /^(09\d{2}-?\d{6})$/;
    return phoneRegex.test(phone);
}
//3. 檢查字串中是否包含特殊字符
function containsSpecialChars(str) {
    const specialCharsRegex = /[!@#$%^&*(),.?":{}|<>]/;
    return specialCharsRegex.test(str);
}
//4. 提取字串中的數字
function extractNumbers(str) {
    const numberRegex = /\d+/g;
    return str.match(numberRegex).map(Number);
}
//5. 檢查是否是有效的網址
function isValidURL(url) {
    const urlRegex = /^(https?:\/\/)?([\da-z.-]+)\.([a-z.]{2,6})([\/\w .-]*)*\/?$/;
    return urlRegex.test(url);
}
//6. 檢查是否為有效的密碼
function isValidPassword(password) {
    const passwordRegex = /^(?=.*[A-Za-z])(?=.*\d)[A-Za-z\d]{8,}$/;
    return passwordRegex.test(password);
}


