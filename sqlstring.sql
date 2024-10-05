--1. 基本的文字比對
SELECT * FROM employees
WHERE name = 'John Doe';
--2. 使用 LIKE 進行部分匹配
SELECT * FROM employees
WHERE name LIKE 'John%';
--3. 忽略大小寫的比對
SELECT * FROM employees
WHERE LOWER(name) = LOWER('john doe');
--4. 使用 IN 比對多個值
SELECT * FROM employees
WHERE name IN ('John Doe', 'Jane Smith', 'Alice Johnson');
--5. 使用 NOT LIKE 進行排除匹配
SELECT * FROM employees
WHERE name NOT LIKE 'A%';
--6. 使用正則表達式（在 PostgreSQL 中）
SELECT * FROM employees
WHERE name ~ '^J.*';
--7. 多個條件的組合
SELECT * FROM employees
WHERE name LIKE 'John%' AND department = 'Sales';
--8. 使用 CHARINDEX（在 SQL Server 中）
SELECT * FROM employees
WHERE CHARINDEX('John', name) > 0;

