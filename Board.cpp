//Board Game Code (What we have right now)

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

std::string str1 = "\t\t\t\t\t\t\t _______________________________________________________________________________________________________________________";
std::string str2 = "\t\t\t\t\t\t\t|       |";
std::string str3 = "-------|-------|-------|------>";
std::string str4 = "|       |       |       |       |";
std::string str5 = "-------|-------|-------|------>";
std::string str6 = "|       |       |";
std::string str7 = "\t\t\t\t\t\t\t|       |       |       |       |       |       |       |       |       |       |       |       |       |       |       |";
std::string str8 = "\t\t\t\t\t\t\t|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|";
std::string str9 = "_______|_______|_______|";
std::string str10 = "\t\t\t\t\t\t\t|       |       ";
std::string str11 = "|   V   |      /    ^    \\                                                                      ";
std::string str12 = "|      ";
std::string str13 = "|";
std::string str14 = "|";
std::string str15 = "\t\t\t\t\t\t\t|       |	";
std::string str16 = "|       |     |           |                    ";
std::string str17 = "________                                         ";
std::string str18 = "|      ";
std::string str19 = "|";
std::string str20 = "|";
std::string str21 = "\t\t\t\t\t\t\t|_______|	";
std::string str22 = "|_______|     |   START   |                   ";
std::string str23 = "/        \\ _______________________________________";
std::string str24 = "|______";
std::string str25 = "|";
std::string str26 = "|";
std::string str27 = "\t\t\t\t\t\t\t|      ";
std::string str28 = "^";
std::string str29 = "|       ";
//std::string str30 = "";
//std::string str31 = "";
//std::string str32 = "";
//std::string str33 = "";
//std::string str34 = "";
//std::string str = ;
//std::string str = ;
//std::string str = ;
//std::string str = ;
//std::string str = ;
//std::string str = ;


//remove main function when putting the code into the master branch
//15 white
//12 red
//9 blue
//10 green
int main() {

	std::cout << str1 << std::endl << str2;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	std::cout << str3;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str4;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	std::cout << str5;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str6 << std::endl << str7 << std::endl << str8 << str9 << std::endl << str10;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	std::cout << str11;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str12;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << str13;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str14 << std::endl << str15;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	std::cout << str16;
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << str17;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str18;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << str19;
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str20 << std::endl << str21;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	std::cout << str22;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << str23;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str24;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << str25;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str26 << std::endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str27;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << str28;
   
    system("pause");
	return 0;
}