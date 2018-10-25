#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
			   
//Change the string numbers after angus is done with his part of the code
std::string larro = "<------";
std::string arro = "------>";
std::string line = "-------";
std::string splt = "|";
std::string str83 = "\t\t\t\t\t\t\t |      ";
std::string str84 = "\t\t\t\t\t\t\t |      ";
std::string str85 = "|";
std::string str86 = "|                                                                     ";
std::string str87 = "|          |      |       |       ";
std::string str88 = "|       |";
std::string str89 = "\t\t\t\t\t\t\t |______";
std::string str90 = "|";
std::string str91 = "|______________________________________________________________________";
std::string str92 = "\\____V___/";
std::string str93 = "_______";
std::string str94 = "|___^___|";
std::string str95 = "_______|_______|";
std::string str96 = "\t\t\t\t\t\t\t |       |       |";
std::string str97 = "|       |       |       |       |";
std::string str98 = "       |";
std::string str99 = "\t\t\t\t\t\t\t |       |       |       |       |       |       |       |       |       |       |       |       |       |       |       |";
std::string str100 = "\t\t\t\t\t\t\t |_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|";


int main() {

	std::cout << std::endl << str83;

	std::cout << std::endl << str84;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << str85;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str86;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	std::cout << str87;
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str88 << std::endl << str89;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << str90;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str91;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	std::cout << str92;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str93;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	std::cout << str94;	

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str95 << std::endl << str96;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	std::cout << larro;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	std::cout << line;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	std::cout << line;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	std::cout << line;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str97;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	std::cout << larro;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	std::cout << line;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	std::cout << line;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	std::cout << line;

	//change when you reach to Angus's part to the middle
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt << str98 << std::endl << str99 << std::endl << str100 << std::endl;

	system("pause");
	return 0;
}