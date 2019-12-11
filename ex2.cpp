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
#include <set>

//#include <iomanip>

//Obs vi får endast ha 1 loop

int main() {

	//auto table = std::map<std::string, int>{};
	////int counter{ 0 };
	//std::string word = "";


	//std::ifstream in_file{ "X://TNG033//Labbar//Lab3NY//Code3//Code3//uppgift2//uppgift2_kort.txt" };

	////kollar att filen är ok
	//if (!in_file) {
	//	std::cout << "Could not open input file!!\n";
	//	return 1;
	//}


	//std::istream_iterator<std::string> first(in_file);
	//std::istream_iterator<std::string> last;
	//std::copy(first, last, std::back_inserter(table));


	////std::vector<std::string> vec;
	////std::vector<std::pair<std::string, int>> vec;

	//std::for_each(table.begin(), table.end(),
	//	[](auto& a) { std::cout << a.first << " " << a.second << "\n"; });

	//in_file.close();

	//return 0;



	
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


		


		table[word]++;
		++counter;
	}

	//skrive ej vec(table.size()) får då tomma slots eftersom vi tar bort värden i map
	std::vector<std::pair<std::string, int>> vec;

	int uniqueValues = 0;





		//const för att få det att fungera
	std::for_each(table.begin(), table.end(),
		[&](std::pair<const std::string, int>& a)
	{
		vec.push_back(std::make_pair(a.first, a.second));
		uniqueValues++;
		
	});
	//ny loop +sorterar
std::sort(vec.begin(), str.end());


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


	in_file.close();


	return 0;

















	//MyDataType needs to implement an operator>>
	//auto table = std::map<std::string, std::set<int>>{};


	//std::istream_iterator<std::string> first(in_file);
	//std::istream_iterator<std::string> last;
	//std::copy(first, last, std::back_inserter(vec));


	//std::map<std::string, int> vec;

	//std::istream_iterator<std::string> iterator_in(in_file);
	//std::istream_iterator<std::string> iterator_end();


	//std::vector<std::pair<std::string, int>> vec;



	//std::istream_iterator<int> first(in_file);
	//std::istream_iterator<int> last;

	//std::vector<std::string> vec;

	//std::copy(first, last, std::back_inserter(vec));

	////läser ut s.20 föreläsning 12
	////std::ostream_iterator<int> iteratorOut(std::cout, ",");
	////nätet
	////std::copy(l.begin(), l.end(), std::ostream_iterator <int>(std::cout, " "));
	////std::ostream_iterator <int>(std::cout, " "));

	//std::for_each(table.begin(), table.end(),
	//	[](auto& a) { std::cout << a.first << " " << a.second << "\n"; });

	//in_file.close();


	//return 0;
}




//std::istream& operator>>(std::istream &in, std::string & out)
//{
//	std::string str;
//	std::getline(in, str);
//	//Do something with str without using loops
//	return in;
//}