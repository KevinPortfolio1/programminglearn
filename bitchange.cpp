

#include <iostream>

#include <bitset>
#include <iomanip>

void decimalToBinary(int n) {
	std::cout << "Binary: " << std::bitset<5>(n) << std::endl;
}

void decimalToOctal(int n) {
	std::cout << "Octal: " << std::oct << n << std::endl;
}

void decimalToHexadecimal(int n) {
	std::cout << "Hexadecimal: " << std::hex << n << std::endl;
}

/*

不用套件方法

void decimalToBinary(int n) {
	if (n == 0) {
		std::cout << "Binary: 0" << std::endl;
		return;
	}

	int binary[32];
	int index = 0;

	while (n > 0) {
		binary[index] = n % 2;
		n = n / 2;
		index++;
	}

	std::cout << "Binary: ";
	for (int i = index - 1; i >= 0; i--) {
		std::cout << binary[i];
	}
	std::cout << std::endl;
}

void decimalToOctal(int n) {
	if (n == 0) {
		std::cout << "Octal: 0" << std::endl;
		return;
	}

	int octal[11];
	int index = 0;

	while (n > 0) {
		octal[index] = n % 8;
		n = n / 8;
		index++;
	}

	std::cout << "Octal: ";
	for (int i = index - 1; i >= 0; i--) {
		std::cout << octal[i];
	}
	std::cout << std::endl;
}

void decimalToHexadecimal(int n) {
	if (n == 0) {
		std::cout << "Hexadecimal: 0" << std::endl;
		return;
	}

	char hex[20];
	int index = 0;

	while (n > 0) {
		int remainder = n % 16;
		if (remainder < 10) {
			hex[index] = '0' + remainder; // '0' to '9'
		} else {
			hex[index] = 'A' + (remainder - 10); // 'A' to 'F'
		}
		n = n / 16;
		index++;
	}

	std::cout << "Hexadecimal: ";
	for (int i = index - 1; i >= 0; i--) {
		std::cout << hex[i];
	}
	std::cout << std::endl;
}

*/

int main()
{
    std::cout << "c++ 十進位轉2,8,16進位值!\n";

	int number = 31;

	decimalToBinary(number);
	decimalToOctal(number);
	decimalToHexadecimal(number);

}


