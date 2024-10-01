#include <iostream>
#include <unordered_map>
#include <chrono>
#include <string>

using namespace std;

int main()
{
	
	unordered_map<int, string> hashTable;

	
	for (int i = 0; i < 1000000; ++i) {
		hashTable[i] = "Value " + to_string(i); 
	}

	int target = 999999; 
	auto start = chrono::high_resolution_clock::now(); 

	
	auto it = hashTable.find(target);

	auto end = chrono::high_resolution_clock::now(); 
	chrono::duration<double, milli> duration = end - start; 

	
	if (it != hashTable.end()) {
		cout << "找到元素: " << it->first << " => " << it->second << endl;
	}
	else {
		cout << "元素未找到" << endl;
	}

	cout << "執行時間: " << duration.count() << " 毫秒" << endl;
	cout << "所需記憶體: " << sizeof(hashTable) + hashTable.size() * sizeof(pair<int, string>) << " bytes" << endl;

	return 0;
}

/*

Input 
  hashTable * 1000000

Output

找到元素: 999999 => Value 999999
執行時間: 0.0027 毫秒
所需記憶體: 32000040 bytes

*/