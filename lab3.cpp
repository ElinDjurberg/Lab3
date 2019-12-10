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

	//std::map<std::string, int> table;
	auto table = std::map<std::string, int>{};
	int counter{0};
	std::string word = "";

	// Vector: To find unique words
	


	//std::locale loc; //tolower
	//std::make_pair<std::string, int>{};

	//std::ifstream in_file{"X://TNG033//Labbar//Lab3NY//Code3//Code3//uppgift1//uppgift1.txt"};
	std::ifstream in_file{"X://TNG033//Labbar//Lab3NY//Code3//Code3//uppgift1//uppgift1_kort.txt"};

	//kollar att filen är ok
	if (!in_file) {
		std::cout << "Could not open input file!!\n";
		return 1;
	}

	//std::istream_iterator<std::string> iterator_in(in_file);
	//std::istream_iterator<std::string> iterator_end();

	//Map kan ta in 2st värden
	
	//in_file >> word)
	//iterator_in != iterator_end
	while (in_file >> word) {
		// för att to-low orden
		//std::transform(word.begin(), word.end(), word.begin(), std::tolower);

		
		//const char* word = word.c_str();

		std::transform(word.begin(), word.end(), word.begin(), [](char c) {return static_cast<char>(std::tolower(c)); });

		//delete diffrent signs
		word.erase(std::remove(word.begin(), word.end(), ','), word.end());
		word.erase(std::remove(word.begin(), word.end(), '.'), word.end());
		word.erase(std::remove(word.begin(), word.end(), '"'), word.end());
		word.erase(std::remove(word.begin(), word.end(), '?'), word.end());
		//word.erase(std::remove(word.begin(), word.end(), '-'), word.end());

		table[word]++;
		++counter;
	}

	//skrive ej vec(table.size()) får då tomma slots eftersom vi tar bort värden i map
	std::vector<std::pair<std::string, int>> vec;

	//for_each ist
	// Range-based loop
	//for(auto& a : table)
	//{
	//	// Lägg till ut över allt från map i en vector. Map sparar unika ord så vectorn kommer endast ha 1 av varje ord
	//	//vector size blir då antalet unika ord.
	//	//first är för att komma åt första i map alltså ordet. First kommer från map
	//	vec.push_back(a.first);
	//}

	//std::fill_n(std::back_inserter(vec), 1, a.first);

	//vektorns storlek är antalet unika ord
	int uniqueValues = 0;



	
//	std::sort(vec.begin(), vec.end(), [](int a.second, int a.second + 1) { return a.second > a.second + 1; });
	// or for example
	//std::sort(v.begin(), v.end(), std::greater<int>());

	//std::vector<int> vec = { -3, 5, 1, 3, -2, 7 };
	

	//std::for_each(vec.begin(), vec.end(),
	//	[&](std::pair<const std::string, int>& a)
	//{
	//	//std::sort(vec.begin(), vec.end(), [](int a.second, int a.second + 1) { return a.second > a.second + 1; });
	//	std::sort(vec.begin(), vec.end(), a.second);
	//});



	//const för att få det att fungera
		std::for_each(table.begin(), table.end(),
		[&](std::pair<const std::string, int>& a) 
		{
			vec.push_back(std::make_pair(a.first, a.second));
			uniqueValues++;
		});

	struct MyComp {
			bool operator()(std::pair<std::string, int>& a, std::pair<std::string, int>& b) { return a.second > b.second; }
		};

	std::sort(vec.begin(), vec.end(), MyComp());

	//vecIt it = std::copy(v.begin(), v.end(), dest.begin() + 1);
	//std::copy(table.begin(), table.end(), vec.begin());
	

	//int uniqueValues = vec.size();
	

	std::cout << "Number of words in the file = " << counter << "\n";
	std::cout << "Number unique  words in the file = " << uniqueValues << "\n\n";

	std::cout << "Frequency table sorted alphabetically ... " << "\n\n";

	std::for_each(table.begin(), table.end(),
	[](auto& a) { std::cout << a.first << " " << a.second << "\n"; });

	std::cout << "Frequency table sorted frequently ... " << "\n\n";

	std::for_each(vec.begin(), vec.end(),
		[](auto& a) { std::cout << a.first << " " << a.second << "\n"; });


	//// Range-based loop
	//for(auto& a : table)
	//{
	//	std::cout << a.first << " " << a.second << "\n";
	//	vec.push_back(a.first);
	//}

	//auto p = std::make_pair(10, "value");
	//auto out_it = std::ostream_iterator<my_pair>{ std::cout, "\n" };
	//stänger fil
	in_file.close();


	return 0;
}