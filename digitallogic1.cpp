#include <iostream>

int main()
{
 
	std::cout << "F=!AB!c+!ABC+AB!C \n";
	std::cout << "A B C | F\n";
	std::cout << "--------------\n";
		

	// AND  &&
	// OR   ||
	// NOT  !

		//F=!AB!c+!ABC+AB!C
		for (int A = 0; A <= 1; A++) {
			for (int B = 0; B <= 1; B++) {
				for (int C = 0; C <= 1; C++) {
					// 計算 F
					int F = (!A && B && !C) || (!A && B && C) || (A && B && !C);

					std::cout << A << " " << B << " " << C << " | " << F << "\n";
				}
			}
		}




	


}


