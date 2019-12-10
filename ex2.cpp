#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <locale>  //to lower
#include <cctype>
//#include <vector>
#include <numeric>
#include <iterator>
#include <utility>
//
#include <algorithm>
#include <vector>
#include <cmath>

//#include <iomanip>

//Obs vi får endast ha 1 loop

int main() {


	auto table = std::map<std::string, int>{};
	int counter{ 0 };
	std::string word = "";

	


	std::ifstream in_file{ "X://TNG033//Labbar//Lab3NY//Code3//Code3//uppgift2//uppgift2_kort.txt" };

	//kollar att filen är ok
	if (!in_file) {
		std::cout << "Could not open input file!!\n";
		return 1;
	}

	while (in_file >> word) {
	

		//delete diffrent signs
		//word.erase(std::remove(word.begin(), word.end(), ','), word.end());
		//word.erase(std::remove(word.begin(), word.end(), '.'), word.end());
		//word.erase(std::remove(word.begin(), word.end(), '"'), word.end());
		//word.erase(std::remove(word.begin(), word.end(), '?'), word.end());
		////word.erase(std::remove(word.begin(), word.end(), '-'), word.end());

	
	}

	
	in_file.close();


	return 0;
}