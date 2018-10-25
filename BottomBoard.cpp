//top part

//Board Game Code (What we have right now) 

#include <iostream> 
#include <fstream> 
#include <string> 
#include <windows.h>

std::string line = "-------";
std::string arro = "------>";
std::string splt = "|";
std::string str1 = "\t\t\t\t\t\t\t _______________________________________________________________________________________________________________________";
std::string str2 = "\t\t\t\t\t\t\t|       |";
std::string str3 = "|       |       |       |       |";
std::string str4 = "|       |       |";
std::string str5 = "\t\t\t\t\t\t\t|       |       |       |       |       |       |       |       |       |       |       |       |       |       |       |";
std::string str6 = "\t\t\t\t\t\t\t|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|";
std::string str7 = "\t\t\t\t\t\t\t|       |       ";
std::string str8 = "|   V   |      /    ^    \\                                                                      ";
std::string str9 = "|      ";
std::string str10 = "\t\t\t\t\t\t\t|       |	";
std::string str11 = "|       |     |           |                    ";
std::string str12 = "________                                         ";
std::string str13 = "|      ";
std::string str14 = "\t\t\t\t\t\t\t|_______|	";
std::string str15 = "|_______|     |   START   |                   ";
std::string str16 = "/        \\ _______________________________________";
std::string str17 = "|______";
std::string str18 = "\t\t\t\t\t\t\t|      ";
std::string str19 = "^";
std::string str20 = "|       ";
std::string str21 = "|       |     |           |                  ";
std::string str22 = "|          |       |       |       |       |       ";
std::string str23 = "|      ";
std::string str24 = "\t\t\t\t\t\t\t|      ";
std::string str25 = "|       ";
std::string str26 = "|       |      \\_________/                   ";
std::string str27 = "|   HOME   |       |       |       |       |      <";
std::string str28 = "|      ";
std::string str29 = "\t\t\t\t\t\t\t|______"; 
std::string str30 = "|       "; 
std::string str31 = "|_______|                                    "; 
std::string str32 = "|          |_______|_______|_______|_______|_______";
std::string str33 = "|______";  
std::string str34 = "\t\t\t\t\t\t\t|      "; 
std::string str35 = "|       "; 
std::string str36 = "|       |                                     "; 
std::string str37 = "\\________/                                        "; 
std::string str38 = "|      "; 
std::string str39 = ""; 
std::string str40 = "";
std::string str41 = ""; 
std::string str42 = ""; 
std::string str43 = ""; 
std::string str44 = ""; 
std::string str45 = ""; 
std::string str46 = ""; 
std::string str47 = ""; 
std::string str48 = ""; 
std::string str49 = ""; 
std::string str50 = ""; 
//std::string str = ""; 
//std::string str = ""; 


//remove main function when putting the code into the master branch 
//15 white 
//12 red 
//9 blue 
//10 green 
int main() {
	std::cout << str1 << std::endl << str2; 

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	std::cout << line;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	std::cout << line;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	std::cout << line;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	std::cout << arro;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str3;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	std::cout << line;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt;
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	std::cout << line;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	std::cout << line;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	std::cout << arro;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str4 << std::endl << str5 << std::endl << str6 << std::endl << str7;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	std::cout << str8;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str9;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt << std::endl << str10;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	std::cout << str11;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << str12;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str13;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt << std::endl << str14;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	std::cout << str15;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << str16;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str17;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt << std::endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str18;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << str19;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str20;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	std::cout << str21;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << str22;
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str23;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt << std::endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str24;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str25;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	std::cout << str26;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << str27;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str28;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt << std::endl;;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str29;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str30;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	std::cout << str31;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << str32;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str33;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt << std::endl << str34;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str35;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	std::cout << str36;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << str37;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str38;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt << std::endl;;

	system("pause");
	return 0;
}




//bottom part

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