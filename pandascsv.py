#1. 讀取以空白為分隔符的 CSV 文件
import pandas as pd
df = pd.read_csv('data.txt', delim_whitespace=True)
print(df.head())
#2. 讀取以特定分隔符（如制表符）為分隔的 CSV 文件
df = pd.read_csv('data.txt', sep='\t')
print(df.head())
#3. 讀取以多個空格為分隔符的 CSV 文件
df = pd.read_csv('data.txt', sep=r'\s+')
print(df.head())
#4. 讀取 CSV 文件並忽略空白行
df = pd.read_csv('data.txt', delim_whitespace=True, skip_blank_lines=True)
print(df.head())
#5.讀取沒有標題的 CSV 文件並指定列名
df = pd.read_csv('data.txt', delim_whitespace=True, header=None, names=['Column1', 'Column2', 'Column3'])
print(df.head())


#讀取後 處理方法
# 1. 更改數據類型
import pandas as pd
# 假設已讀取的 DataFrame 為 df
df = pd.read_csv('data.csv')
# 將 'age' 列轉換為整數類型
df['age'] = df['age'].astype(int)
# 將 'income' 列轉換為浮點數類型
df['income'] = df['income'].astype(float)
# 2.重新命名列
df.rename(columns={'old_name': 'new_name'}, inplace=True)
#3.# 將缺失值填充為 0
df.fillna(0, inplace=True)
# 刪除包含缺失值的行
df.dropna(inplace=True)
#4. 格式化顯示數據
df['income'] = df['income'].apply(lambda x: f"${x:,.2f}")
#5. 日期格式化
df['date'] = pd.to_datetime(df['date'])
df['date'] = df['date'].dt.strftime('%Y-%m-%d')
#6. 自訂排序
df.sort_values(by='income', ascending=False, inplace=True)
#7. 添加新列
df['annual_income'] = df['income'] * 12
#8. 顯示格式設置
pd.set_option('display.max_rows', 10)  # 顯示最多 10 行
pd.set_option('display.max_columns', 5)  # 顯示最多 5 列


#1. 讀取 CSV 並轉換為矩陣格式
import pandas as pd
# 讀取 CSV 文件
df = pd.read_csv('data.csv')
# 將 DataFrame 轉換為 NumPy 矩陣
matrix = df.values
print("矩陣格式：")
print(matrix)

#2. 將某一列轉換為類別格式
# 假設你的 DataFrame 如下
data = {
    'Category': ['A', 'B', 'A', 'C', 'B'],
    'Values': [10, 20, 30, 40, 50]
}
df = pd.DataFrame(data)
# 將 'Category' 列轉換為類別格式
df['Category'] = df['Category'].astype('category')
print("類別格式：")
print(df.info())
print(df['Category'].cat.categories)  # 顯示類別

#3. 使用 pivot_table 創建矩陣格式
# 創建一個新的 DataFrame
data = {
    'Date': ['2024-01-01', '2024-01-01', '2024-01-02', '2024-01-02'],
    'Category': ['A', 'B', 'A', 'B'],
    'Values': [10, 20, 15, 25]
}
df = pd.DataFrame(data)
# 使用 pivot_table 創建矩陣
pivot_df = df.pivot_table(values='Values', index='Date', columns='Category', fill_value=0)
print("透視表矩陣格式：")
print(pivot_df)

#4. 將矩陣格式轉換回 DataFrame
# 假設有一個 NumPy 矩陣
import numpy as np
matrix = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
# 轉換為 DataFrame
df_from_matrix = pd.DataFrame(matrix, columns=['A', 'B', 'C'])
print("從矩陣轉換回的 DataFrame：")
print(df_from_matrix)

#流程
#1. 讀取 CSV 檔案
import pandas as pd
# 讀取 CSV 文件
df = pd.read_csv('data.csv')
#2. 檢查數據格式
print("數據格式：")
print(df.dtypes)
#3. 檢查長度
# 檢查 'name' 列的字串長度
df['name_length'] = df['name'].apply(len)
print("姓名長度：")
print(df[['name', 'name_length']])
#4. 檢查缺失值
print("缺失值數量：")
print(df.isnull().sum())
#5. 正規化文字檢查
# 將 'name' 列的所有字母轉為小寫
df['normalized_name'] = df['name'].str.lower()
# 去除 'name' 列的前後空格
df['normalized_name'] = df['normalized_name'].str.strip()
# 檢查 'name' 列是否只包含字母
df['is_alpha'] = df['name'].str.isalpha()
print("字母檢查結果：")
print(df[['name', 'is_alpha']])
# 檢查 'email' 列是否符合電子郵件格式
df['is_email_valid'] = df['email'].str.match(r'^[\w\.-]+@[\w\.-]+\.\w+$')
print("電子郵件格式檢查：")
print(df[['email', 'is_email_valid']])
