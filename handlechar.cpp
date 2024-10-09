

//禁用 Microsoft Visual C++ 的安全性警告
//#define _CRT_SECURE_NO_WARNINGS

//用途：提供基本的輸入輸出功能
//std::cout,std::cin,std::cerr,std::clog
#include <iostream>
//用途：提供通用的工具函數，包括動態內存管理、隨機數生成和程序控制。
//std::malloc,std::atoi,std::rand
#include <cstdlib>
//提供許多通用算法的定義，如排序、查找、操作等。
//std::sort,std::reverse,std::find
#include <algorithm> 


int main()
{
    std::cout << "Hello World!\n";

	char s1[] = "Hellow";
	char s2[] = "Nice to meet you";
	char s3[50];

	
	//strcpy(s3, s1);
	//strncpy(s3, s1, sizeof(s3) - 1);
	//Visual C++ 提供了一些安全的字符串處理函數
	strcpy_s(s3, sizeof(s3), s1);
	std::cout << "s3 length:" << strlen(s3) << "\n";
	//strcat(s3, s1);
	//strncat(s3, s2, sizeof(s3) - strlen(s3) - 1);
	
	//strcmp
	if (strncmp(s3, s1, sizeof(s3)) == 0) {
		std::cout << "The strings are equal." << std::endl;
	}
	else {
		std::cout << "The strings are not equal." << std::endl;
	}

	//reverse
	std::reverse(s3, s3 + strlen(s3));
	std::cout << "reverse:" << s3 <<std::endl;

	// char vs string

	//char
	/*
	   字符陣列，需手動終止（'\0'）
	   手動管理，容易發生內存溢位
	   使用 C 標準庫函數（如 strcpy、strlen）
	   高風險，需小心處理緩衝區溢位
	   在某些情況下更快
	   代碼較繁瑣
	   基本功能
	*/

	//string
	/*
	  封裝在 std::string 類中
	  自動管理內存，安全性更高
	  提供豐富的成員函數和運算符重載
	  更安全，自動處理結尾和長度
	  有額外開銷，但差異通常不大
	  代碼清晰易懂
	  支援賦值、串接、查找、替換等功能
	  不兼容 C 語言函數
	*/
	
	//char 內存溢位
	/*
	   使用安全的字串操作函數：
         使用 strncpy 和 strncat，這些函數允許您指定最大字符數。
         使用 snprintf 來格式化輸出並防止溢位。
	   檢查字串長度：
         在複製或串接字串之前，檢查字串的長度，確保不會超出緩衝區的大小。
	   使用 std::string：
         在 C++ 中，使用 std::string 來自動管理內存，避免手動處理的安全問題。
	*/

	//內存溢位的後果
	/*
        數據損壞：溢出的數據可能覆蓋其他變量或內存區域，導致未定義的行為。
        程式崩潰：如果程序嘗試訪問未分配的內存，可能會導致訪問違規並崩潰。
        安全漏洞：攻擊者可以利用內存溢位來執行任意代碼，這是許多安全漏洞的根源。
	*/
}


