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

	//***************Detta funkar med att läsa in det med iterators********************//

	//std::vector<std::string> vec;
	//
	//std::ifstream in_file{ "C://Users//elidj//Cplus2//Labbar//Lab3//Code3//Code3//uppgift2//uppgift2_kort.txt" };

	////kollar att filen är ok
	//if (!in_file) {
	//	std::cout << "Could not open input file!!\n";
	//	return 1;
	//}
	//else {
	//	std::cout << "Open!!\n";
	//}

	////Läser in filen till en iterator
	//std::istream_iterator<std::string> first(in_file);
	//std::istream_iterator<std::string> last;
	//

	////skriver ut iteratorn till consolen
	//std::copy(first, last, std::ostream_iterator<std::string>(std::cout, " "));

	//in_file.close();
	//return 0;

	//*******************************************************************//
	//*******************************************************************//


	//************Läser in med kopy****************************//


	//std::vector<std::string> vec;
	//
	//std::ifstream in_file{ "C://Users//elidj//Cplus2//Labbar//Lab3//Code3//Code3//uppgift2//uppgift2_kort.txt" };

	////kollar att filen är ok
	//if (!in_file) {
	//	std::cout << "Could not open input file!!\n";
	//	return 1;
	//}
	//else {
	//	std::cout << "Open!!\n";
	//}

	////LÄser in en fil och kopierar över till en vector
	//std::copy(std::istream_iterator<std::string>(in_file), std::istream_iterator<std::string>(),
	//std::back_inserter(vec));

	//std::copy(vec.begin(), vec.end(), std::ostream_iterator<std::string>(std::cout, " "));


	////hash map
	////sorterar om orden i bokstavsordning


	////Läser in filen till en iterator
	////std::istream_iterator<std::string> first(in_file);
	////std::istream_iterator<std::string> last;
	//
	////skriver ut iteratorn till consolen
	////std::copy(first, last, std::ostream_iterator<std::string>(std::cout, " "));

	//in_file.close();
	//return 0;




	//*******************************************************************//

	//TRYING TO READ IN IN MAP

	//std::vector<std::string> vec;

	//Göra ett nytt enklare namn istället för std::map<std::string, std::set<std::string>> 
	using My_table = std::map<std::string, std::set<std::string>>;
	
	std::ifstream in_file{ "C://Users//elidj//Cplus2//Labbar//Lab3//Code3//Code3//uppgift2//uppgift2_kort.txt" };

	//kollar att filen är ok
	if (!in_file) {
		std::cout << "Could not open input file!!\n";
		return 1;
	}
	else {
		std::cout << "Open!!\n";
	}


	//LÄser in en fil och kopierar över till en vector
	//std::copy(std::istream_iterator<std::string>(in_file), std::istream_iterator<std::string>(),
	//std::back_inserter(vec));

	//std::copy(vec.begin(), vec.end(), std::ostream_iterator<std::string>(std::cout, " "));


	//hash map
	//sorterar om orden i bokstavsordning



	//Läser in filen till en iterator
	std::istream_iterator<std::string> first(in_file);
	std::istream_iterator<std::string> last;
	

	
		//ska sortera orden
		//ska lägga in dem i map
		

	//////////////////////////////////////////////////


	auto table = My_table{};

	struct insertMap {
		 

	public: 
		insertMap(My_table &x) : T{ x } {}//ska den se ut så med {}


		void operator() (std::string a) { 
			std::string temp{ a };
			std::sort(temp.begin(), temp.end());
			std::cout << a << std::endl;
			//counter++;
			//T[temp] är pekaren
			if (T[temp].size == 0) {
				T[temp] = std::set<std::string>{a};
			}
			else {
				T[temp].insert(a);
			}
			//else insert i T[temp]
			//T[temp] = a;
			//T.insert(*a);
		}


		//2st strukts en för set

		//function() som sorterar och lägger in i map samt insert i set.
		//using för att byta namn std::map<std::string, std::set<std::string>>
		//tabel[x].insert(....)
		//constructor to map
		//insert in map
		//ex 4 set 6
		//class abs
		//constructor
		//function

		//private &to the map
		//using nytt namn för map
		//mytabel & 

	private:

		My_table &T;
	};		//lambda expression	//auto glambda = [](auto a, auto&& b) { return a < b; };

	//skicka in .counter
	//denna läser in en fil
	std::for_each(first, last, insertMap{ table });
	


	/////////////////////////////////////////////////////

	//ska den vara const?? Vi vill ju sortera den??
	////map sorterar väl automatiskt fast kanske inte orden?
	//std::for_each(first, last, [](std::string& p)//[](std::string& p) är detta rätt
	//{
	//	//sortera
	//	//läg in i map
	//	//p är den sträng vi läser in och det är den som ska sorteras i bokstavsordning
	//	//	//std::for_each(Map.begin(), Map.end(), CallMyMethod);
	//	//lägg in i map
	//	//lägger den endast in unika ord??
	//	//lägger detta in 
	//	table[p]++;

	//	//iterator table.insert({ key, element })
	//	

	//	//läg in i set om den redan finns

	//	//skriv ut
	//	std::cout << p << std::endl;


	//});


	//skriver ut iteratorn till consolen
	//std::copy(first, last, std::ostream_iterator<std::string>(std::cout, " "));

	in_file.close();
	return 0;




	//**********************************************************************//





























	////vill kopiera över till en map
	//	auto table = std::map<std::string, int>{};
	//	int counter{ 0 };
	//	std::string word = "";



	//std::cout << std::endl << std::endl << "HEjhej fei" << std::endl;

	//std::copy(first, last, std::back_inserter(vec));

	//FUNKAR EJ har denna lyckats kopiera över vectorn till en map? 
		//std::copy(vec.begin(), vec.end(), std::inserter(table, table.begin()));

		//FUNKAR EJ samma som den en rad upp
		//std::map<std::string, int> m2((vec.begin()), vec.end());


	//Bör skriva ut map, funkar ej
	/*std::for_each(table.begin(), table.end(),
		[](auto& a) { std::cout << a.first << " " << a.second << "\n"; });*/

	//kopiera bara om typ if statment
	//std::copy_if
	//std::vector<std::pair<std::string, int> > vec;

	//auto table = std::map<std::string, int>{};
//int counter{ 0 };
//std::string word = "";


	//std::vector<std::string> vec;
	//std::vector<std::pair<std::string, int>> vec;

	/*std::for_each(vec.begin(), vec.end(),
		[](auto& a) { std::cout << vec << "\n"; });*/

		//std::for_each(vec.begin(), vec.end(), TimesThree());





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