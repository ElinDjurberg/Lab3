#include <fstream>
#include<iostream>
#include<map>
#include<iterator>
#include<utility>
#include<algorithm>
#include<vector>
#include<cmath>

int main() {

	auto table = std::map<std::string, int>{};

	std::string word = "";
	int counter{ 0 };

	std::ifstream in_file{ "C://Users//elidj//Cplus2//Labbar//Lab3//Code3//Code3//uppgift1//uppgift1.txt" };

	if (!in_file) {
		std::cout << "Could not open input file !! \n";
		return 1;
	}

	while (in_file >> word) {
		table[word]++;
		++counter;
	}

	std::cout << counter;

	in_file.close();

	return 0;







}