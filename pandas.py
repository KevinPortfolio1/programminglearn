#Pandas Series
import pandas as pd
a = [1, 7, 2]
myvar = pd.Series(a)
print(myvar)
#Pandas DataFrames
import pandas as pd
data = {
  "calories": [420, 380, 390],
  "duration": [50, 40, 45]
}
#load data into a DataFrame object:
df = pd.DataFrame(data)
print(df)
#Pandas Read CSV
import pandas as pd
df = pd.read_csv('data.csv')
print(df.to_string())
#Pandas Read JSON
import pandas as pd
df = pd.read_json('data.json')
print(df.to_string()) 
#Pandas - Analyzing DataFrames
import pandas as pd
df = pd.read_csv('data.csv')
print(df.head(10)) 
#Creating data DataFrame
pd.DataFrame({'Yes': [50, 21], 'No': [131, 2]})
#Output
"""
 	Yes No
0 	50 	131
1 	21 	2
"""
#select

# import pandas
import pandas as pd
# List of Tuples
employees = [('Stuti', 28, 'Varanasi', 20000),
            ('Saumya', 32, 'Delhi', 25000),
            ('Aaditya', 25, 'Mumbai', 40000),
            ('Saumya', 32, 'Delhi', 35000),
            ('Saumya', 32, 'Delhi', 30000),
            ('Saumya', 32, 'Mumbai', 20000),
            ('Aaditya', 40, 'Dehradun', 24000),
            ('Seema', 32, 'Delhi', 70000)
            ]
# Create a DataFrame object from list
df = pd.DataFrame(employees,
                columns =['Name', 'Age',
                        'City', 'Salary'])
# Show the dataframe
df

"""
Output:

    Name    Age    City    Salary
0    Stuti    28    Varanasi    20000
1    Saumya    32    Delhi    25000
2    Aaditya    25    Mumbai    40000
3    Saumya    32    Delhi    35000
4    Saumya    32    Delhi    30000
5    Saumya    32    Mumbai    20000
6    Aaditya    40    Dehradun    24000
7    Seema    32    Delhi    70000

"""
