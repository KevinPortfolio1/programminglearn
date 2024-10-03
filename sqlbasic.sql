--查詢
SELECT name, email FROM customers;
--條件
SELECT * FROM orders WHERE amount > 1000;
--聚合函數
SELECT SUM(sale_amount) AS total_sales FROM sales;
--聯接查詢
SELECT e.name, d.department_name
FROM employees e
JOIN departments d ON e.department_id = d.id;
--子查詢
SELECT * FROM orders o
WHERE o.amount > (SELECT AVG(amount) FROM orders WHERE customer_id = o.customer_id);
--更新與刪除
UPDATE customers SET status = 'active' WHERE status = 'inactive';
--資料插入
INSERT INTO products (name, price) VALUES ('新產品', 100);
--聚合函數2
--計算次數
SELECT COUNT(*) AS total_employees FROM employees;
--計算總和
SELECT SUM(sale_amount) AS total_sales FROM sales;
--計算平均值
SELECT AVG(amount) AS average_order_amount FROM orders;
--計算最小值和最大值
SELECT MIN(price) AS min_price, MAX(price) AS max_price FROM products;
--分組統計
SELECT customer_id, SUM(amount) AS total_order_amount
FROM orders
GROUP BY customer_id;
--計算多個聚合函數
SELECT department_id, 
       COUNT(*) AS employee_count, 
       MAX(salary) AS highest_salary, 
       MIN(salary) AS lowest_salary
FROM employees
GROUP BY department_id;
--過濾聚合結果
--DISTINCT 去除查詢結果中重複記錄的關鍵字
SELECT COUNT(DISTINCT customer_id) AS high_value_customers
FROM sales
WHERE sale_amount > 1000;
--常見的 JOIN 類型
--INNER JOIN：返回兩個表中匹配的行
--LEFT JOIN（或 LEFT OUTER JOIN）：返回左邊表中所有的行，以及右邊表中匹配的行；如果右邊沒有匹配，則結果中會顯示 NULL
--RIGHT JOIN（或 RIGHT OUTER JOIN）：返回右邊表中所有的行，以及左邊表中匹配的行；如果左邊沒有匹配，則結果中會顯示 NULL
--FULL JOIN（或 FULL OUTER JOIN）：返回兩個表中的所有行，並在沒有匹配的地方顯示 NULL。
--CROSS JOIN：返回兩個表的笛卡爾積，即每一行的每一行組合

/*

customers 表：
customer_id	      name
1	              Alice
2	              Bob
3	              Charlie

orders 表：
order_id	customer_id	   amount
1	            1	       100
2	            1	       150
3	            2	       200

*/

/*
1. INNER JOIN

name	amount
Alice	100
Alice	150
Bob	    200

2. LEFT JOIN

name	amount
Alice	100
Alice	150
Bob	    200
Charlie	NULL

3. RIGHT JOIN

name	amount
Alice	100
Alice	150
Bob	    200

4. FULL JOIN

name	amount
Alice	100
Alice	150
Bob	    200
Charlie	NULL

5. CROSS JOIN

name	amount
Alice	100
Alice	150
Bob	    200
Alice	100
Alice	150
Bob	    200
Charlie	100
Charlie	150
Charlie	200

*/

/*
WHERE：
    用於在數據從資料表中提取之前過濾行。
    主要用於過濾不需要的記錄，無法使用聚合函數。
	通常在 SQL 執行計畫中比 HAVING 更早執行，因此在行數較多的情況下，能提高查詢效率。
HAVING：
    用於在 聚合後 過濾結果。
    主要用於過濾基於聚合結果的條件，通常與 GROUP BY 一起使用。
    需要在聚合計算之後執行，因此通常效率較低。

*/
SELECT *
FROM orders
WHERE amount > 250;

SELECT customer_id, SUM(amount) AS total_amount
FROM orders
GROUP BY customer_id
HAVING SUM(amount) > 400;

SELECT customer_id, SUM(amount) AS total_amount
FROM orders
WHERE amount > 200
GROUP BY customer_id
HAVING SUM(amount) > 400;

--排序
--基本排序
SELECT *
FROM employees
ORDER BY name ASC;
--降序排序
SELECT *
FROM orders
ORDER BY amount DESC;
--多重排序
SELECT *
FROM customers
ORDER BY city ASC, name ASC;
--排序與聚合結合
SELECT department_id, AVG(salary) AS average_salary
FROM employees
GROUP BY department_id
ORDER BY average_salary DESC;
--分頁應用
SELECT *
FROM orders
ORDER BY order_date ASC
LIMIT 10 OFFSET 20; 
--ASC 和 DESC：ASC 是升序（預設），DESC 是降序。

/*
FLOAT：
    通常表示浮點數，具體大小可能因資料庫而異。
    例如，在 MySQL 中，FLOAT 可以表示 4 字節的單精度浮點數。
DOUBLE：
    表示雙精度浮點數，通常需要 8 字節的儲存空間。
    提供比 FLOAT 更高的精度和範圍。
DECIMAL（或 NUMERIC）：
    雖然不是浮點數，但用於需要高精度的場景，例如財務計算。
    用戶可以定義精度和小數位數，適合用於避免浮點數運算中的精度問題
*/

--1. 定義浮點數類型
CREATE TABLE products (
  weight DECIMAL(10, 2)  -- 10位數字，其中2位是小數
);

--2.插入浮點數數據
INSERT INTO products (product_id, product_name, price, discount, weight)
VALUES (1, 'Apple', 1.99, 0.10, 0.15),
       (2, 'Banana', 0.99, 0.05, 0.12);
	   
--設定浮點數的小數點位數
SELECT product_name, FORMAT(price, 2) AS formatted_price
FROM products;

SELECT product_name, CAST(ROUND(price, 2) AS DECIMAL(10, 2)) AS formatted_price
FROM products;

-- NUMERIC 數據類型可以指定總位數和小數位數
/*
CREATE TABLE products (
    price NUMERIC(10, 2)  -- 10位數字，其中2位是小數
);
*/
-- CAST(expression AS target_data_type) 將一個數據類型轉換為另一個數據類型
-- SELECT CAST('123' AS INT) AS converted_integer;
-- ROUND 
-- SELECT ROUND(123.4567, 2) AS rounded_value;  -- 結果為 123.46
-- *** 根據具體需求選擇合適的數據類型。
-- *** 例如，對於精確計算（如金額），使用 NUMERIC；對於科學計算，使用 FLOAT 或 DOUBLE。


--你想要根據某個條件來將數值設定為正數或負數，可以使用 CASE 表達式
SELECT transaction_id, 
       amount,
       CASE 
           WHEN amount >= 0 THEN amount  -- 設定為正數
           ELSE -amount                  -- 設定為負數
       END AS adjusted_amount
FROM transactions;

