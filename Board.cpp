//top part

//Board Game Code (What we have right now) 

#include <iostream> 
#include <fstream> 
#include <string> 
#include <windows.h>

#include "Board.h"

std::string line = "-------";
std::string arro = "------>";
std::string larro = "<------";
std::string splt = "|";
std::string str1 = "\t\t\t\t\t\t\t_______________________________________________________________________________________________________________________";
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
std::string str39 = "\t\t\t\t\t\t\t|      ";
std::string str40 = "|       ";
std::string str41 = "|       |                                                                              ";
std::string str42 = "________ ";
std::string str43 = "|      ";
std::string str44 = "\t\t\t\t\t\t\t|______";
std::string str45 = "|       ";
std::string str46 = "|_______|                                                                             ";
std::string str47 = "/        \\";
std::string str48 = "|______";
std::string str49 = "\t\t\t\t\t\t\t|      ";
std::string str50 = "|       ";
std::string str51 = "|       |                                                                            ";
std::string str52 = "|          ";
std::string str53 = "|      ";
std::string str54 = "\t\t\t\t\t\t\t|      ";
std::string str55 = "|       ";
std::string str56 = "|       |                                                                            ";
std::string str57 = "|   START >";
std::string str58 = "|      ";
std::string str59 = "\t\t\t\t\t\t\t|______";
std::string str60 = "|       ";
std::string str61 = "|_______|                                                                            ";
std::string str62 = "|          ";
std::string str63 = "|______";
std::string str64 = "V";
std::string str65 = "\t\t\t\t\t\t\t|      ";
std::string str66 = "|       ";
std::string str67 = "|       |                                                                             ";
std::string str68 = "\\________/";
std::string str69 = "|       |";
std::string str70 = "\t\t\t\t\t\t\t|      ";
std::string str71 = "|       ";
std::string str72 = "|       |                                                                                       ";
std::string str73 = "|       |";
std::string str74 = "\t\t\t\t\t\t\t|______";
std::string str75 = "|       ";
std::string str76 = "|_______|                                                                                       ";
std::string str77 = "|_______|";
std::string str78 = "\t\t\t\t\t\t\t|       |      ";
std::string str79 = "/         \\                                                                                      ";
std::string str80 = "|       |";
std::string str81 = "\t\t\t\t\t\t\t|       |     ";
std::string str82 = "|           |                                                                                     ";
std::string str83 = "|       |";
std::string str84 = "\t\t\t\t\t\t\t|_______|     ";
std::string str85 = "|   HOME    |                                                                                     ";
std::string str86 = "|_______|";
std::string str87 = "\t\t\t\t\t\t\t|       |     ";
std::string str88 = "|           |                                                                                     ";
std::string str89 = "|       |";
std::string str90 = "\t\t\t\t\t\t\t|       |      ";
std::string str91 = "\\_________/                                                                                      ";
std::string str92 = "|       |";
std::string str93 = "\t\t\t\t\t\t\t|_______|                                                                                                       |_______|";
std::string str94 = "\t\t\t\t\t\t\t|       |                                                                                       ";
std::string str95 = "_________       ";
std::string str96 = "|       ";
std::string str97 = "\t\t\t\t\t\t\t|       |                                                                                      ";
std::string str98 = "/         \\      ";
std::string str99 = "|       ";
std::string str100 = "\t\t\t\t\t\t\t|_______|                                                                                     ";
std::string str101 = "|           |     ";
std::string str102 = "|_______";
std::string str103 = "\t\t\t\t\t\t\t|       |                                                                                     ";
std::string str104 = "|   HOME    |     ";
std::string str105 = "|       ";
std::string str106 = "\t\t\t\t\t\t\t|       |                                                                                     ";
std::string str107 = "|           |     ";
std::string str108 = "|       ";
std::string str109 = "\t\t\t\t\t\t\t|_______|                                                                                      ";
std::string str110 = "\\ _______ /      ";
std::string str111 = "|_______";
std::string str112 = "\t\t\t\t\t\t\t|       |                                                                                       ";
std::string str113 = "|       |       ";
std::string str114 = "|      ";
std::string str115 = "\t\t\t\t\t\t\t|       | ";
std::string str116 = "________                                                                              ";
std::string str117 = "|       |       ";
std::string str118 = "|      ";
std::string str119 = "\t\t\t\t\t\t\t|_______|";
std::string str120 = "/        \\                                                                             ";
std::string str121 = "|_______|       ";
std::string str122 = "|______";
std::string str123 = "\t\t\t\t\t\t\t|      ";
std::string str124 = "^";
std::string str125 = "          |                                                                            ";
std::string str126 = "|       |       ";
std::string str127 = "|      ";
std::string str128 = "\t\t\t\t\t\t\t|      ";
std::string str129 = "<  START  |                                                                            ";
std::string str130 = "|       |       ";
std::string str131 = "|      ";
std::string str132 = "\t\t\t\t\t\t\t|______";
std::string str133 = "          |                                                                            ";
std::string str134 = "|_______|       ";
std::string str135 = "|______";
std::string str136 = "\t\t\t\t\t\t\t|      ";
std::string str137 = "\\________/                                                                             ";
std::string str138 = "|       |       ";
std::string str139 = "|      ";
std::string str140 = "\t\t\t\t\t\t\t|      ";
std::string str141 = "|                                         ";
std::string str142 = "________                                      ";
std::string str143 = "|       |       ";
std::string str144 = "|      ";
std::string str145 = "\t\t\t\t\t\t\t|______";
std::string str146 = "_______________________________________ /        \\                                     ";
std::string str147 = "|_______|       ";
std::string str148 = "|______";
std::string str149 = "\t\t\t\t\t\t\t|      ";
std::string str150 = "       |       |       |       |       |          |                    ";
std::string str151 = "________        ";
std::string str152 = "|       |       ";
std::string str153 = "|      ";
std::string str154 = "\t\t\t\t\t\t\t|      ";
std::string str155 = ">      |       |       |       |       |   HOME   |                   ";
std::string str156 = "/        \\       |       |       ";
std::string str157 = "|      ";
std::string str158 = "\t\t\t\t\t\t\t|______";
std::string str159 = "_______|_______|_______|_______|_______|          |                  ";
std::string str160 = "|          |      |_______|       ";
std::string str161 = "|______";
std::string str162 = "V";
std::string str163 = "\t\t\t\t\t\t\t|      ";
std::string str164 = "|";
std::string str165 = "|                                        ";
std::string str166 = "\\________/                   ";
std::string str167 = "|   START  |      |       |       ";
std::string str168 = "|       |";
std::string str169 = "\t\t\t\t\t\t\t|      ";
std::string str170 = "|";
std::string str171 = "|                                                                     ";
std::string str172 = "|          |      |       |       ";
std::string str173 = "|       |";
std::string str174 = "\t\t\t\t\t\t\t|______";
std::string str175 = "|";
std::string str176 = "|______________________________________________________________________";
std::string str177 = "\\";
std::string str178 = "____";
std::string str179 = "V";
std::string str180 = "___";
std::string str181 = "/";
std::string str182 = "_______";
std::string str183 = "|";
std::string str184 = "___";
std::string str185 = "^";
std::string str186 = "___";
std::string str187 = "|";
std::string str188 = "_______|_______|";
std::string str189 = "\t\t\t\t\t\t\t|       |       |";
std::string str190 = "|       |       |       |       |";
std::string str191 = "       |";
std::string str192 = "\t\t\t\t\t\t\t|       |       |       |       |       |       |       |       |       |       |       |       |       |       |       |";
std::string str193 = "\t\t\t\t\t\t\t|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|";

//remove main function when putting the code into the master branch @Roderick or whoever
//15 white 
//12 red 
//9 blue 
//10 green 
//6 yellow

void board::boardPrint() {
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
	std::cout << splt << std::endl << str39;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str40;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	std::cout << str41;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << str42;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str43;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt << std::endl << str44;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str45;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	std::cout << str46;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << str47;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str48;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt << std::endl << str49;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str50;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	std::cout << str51;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << str52;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str53;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt << std::endl << str54;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str55;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	std::cout << str56;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << str57;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str58;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt << std::endl << str59;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str60;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	std::cout << str61;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << str62;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str63;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << str64;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt << std::endl << str65;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str66;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	std::cout << str67;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << str68;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str69 << std::endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str70;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str71;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	std::cout << str72;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str73 << std::endl << str74;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str75;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	std::cout << str76;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str77 << std::endl << str78;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	std::cout << str79;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str80 << std::endl << str81;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	std::cout << str82;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str83 << std::endl << str84;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	std::cout << str85;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str86 << std::endl << str87;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	std::cout << str88;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str89 << std::endl << str90;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	std::cout << str91;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str92 << std::endl << str93 << std::endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str94;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	std::cout << str95;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str96 << splt << std::endl << str97;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	std::cout << str98;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str99 << splt << std::endl << str100;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	std::cout << str101;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str102 << splt << std::endl << str103;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	std::cout << str104;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str105 << splt << std::endl << str106;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	std::cout << str107;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str108 << splt << std::endl << str109;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	std::cout << str110;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str111 << splt << std::endl << str112;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	std::cout << str113;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str114;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt << std::endl << str115;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << str116;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	std::cout << str117;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str118;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt << std::endl << str119;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << str120;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	std::cout << str121;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str122;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt << std::endl << str123;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << str124;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << str125;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	std::cout << str126;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str127;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt << std::endl << str128;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << str129;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	std::cout << str130;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str131;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt << std::endl << str132;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << str133;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	std::cout << str134;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str135;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt << std::endl << str136;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << str137;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	std::cout << str138;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str139;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt << std::endl << str140;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str141;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << str142;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	std::cout << str143;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str144;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt << std::endl << str145;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << str146;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	std::cout << str147;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str148;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt << std::endl << str149;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << str150;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	std::cout << str151;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	std::cout << str152;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str153;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt << std::endl << str154;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << str155;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	std::cout << str156;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str157;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt << std::endl << str158;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << str159;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	std::cout << str160;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str161;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	std::cout << str162;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << splt << std::endl << str163;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << str164;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str165;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << str166;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	std::cout << str167;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str168 << std::endl << str169;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << str170;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str171;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	std::cout << str172;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str173 << std::endl << str174;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	std::cout << str175;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str176;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	std::cout << str177;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str178;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	std::cout << str179;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str180;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	std::cout << str181;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str182;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	std::cout << str183;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str184;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	std::cout << str185;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str186;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	std::cout << str187;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	std::cout << str188 << std::endl << str189;

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
	std::cout << str190;

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
	std::cout << splt << str191 << std::endl << str192 << std::endl << str193 << std::endl;
}

void board::gridPrint()
{
	const int LENR(16), LENC(15);

	// Grid cordinates. The grid is 16 X 15 (16 rows and 15 columns)
	std::string grid[LENR][LENC] = { {"016", "017", "018", "019", "020", "021", "022", "023", "024", "025", "026", "027", "028", "029", "030"},
								 {"015", "   ", "R01", "   ", "R00", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "031"},
								 {"014", "   ", "R02", "   ", "   ", "   ", "   ", "   ", "B06", "B05", "B04", "B03", "B02", "B01", "032"},
								 {"013", "   ", "R03", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "033"},
								 {"012", "   ", "R04", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "B00", "034"},
								 {"011", "   ", "R05", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "035"},
								 {"010", "   ", "R06", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "036"},
								 {"009", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "037"},
								 {"008", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "038"},
								 {"007", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "Y06", "   ", "039"},
								 {"006", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "Y05", "   ", "040"},
								 {"005", "G00", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "Y04", "   ", "041"},
								 {"004", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "Y03", "   ", "042"},
								 {"003", "G01", "G02", "G03", "G04", "G05", "G06", "   ", "   ", "   ", "   ", "   ", "Y02", "   ", "043"},
								 {"002", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "Y00", "   ", "Y01", "   ", "044"},
								 {"001", "058", "057", "056", "055", "054", "053", "052", "051", "050", "049", "048", "047", "046", "045"} };

	// The two types of horizontal divides used when printing the grid.
	std::string hori("-------------------------------------------------------------");
	std::string shift("\t\t\t\t\t\t\t\t\t\t      ");

	for (int row = 0; row < LENR; row++)
	{
		std::cout << shift;
		std::cout << hori << std::endl;
		for (int col = 0; col < LENC; col++)
		{
			if (col == 0)
				std::cout << shift;

			std::cout << "|" << grid[row][col];
		}
		std::cout << "|" << std::endl;
	}
	std::cout << shift << hori << std::endl;
}

void board::locPrint(TokenClass ** tokens, unsigned int rows, unsigned int cols) // prints the location of each player's pieces.
{
	std::cout << std::endl;
	for (int i = 0; i < rows; i++) // the row is the player number
	{
		
		switch (i + 1) // setting the text colours
		{
			case 1: // Player 1 (Red)
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
				break;
			case 2: // Player 2 (Blue)
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x01);
				break;
			case 3: // Player 3 (Yellow)
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x06);
				break;
			case 4: // Player 4 (Green)
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x02);
				break;
		}
		// std::cout << i << std::endl;
		for (int j = 0; j < cols; j++)
		{
			// Prints the location of the piece
			if (tokens[i][j].getStart()) // checks to see if the pawn is at it's starting space
			{
				std::cout << "Player" << i + 1 << " | Pawn " << j + 1 << ": START" << std::endl;

				
			}
			else if(tokens[i][j].getSafeZone()) // checks to see if the pawn is in it's safe zone.
			{
				std::cout << "Player" << i + 1 << " | Pawn " << j + 1 << ": SAFE" << std::endl;
			}
			else if (tokens[i][j].getHome()) // checks to see if the pawn is at home.
			{
				std::cout << "Player" << i + 1 << " | Pawn " << j + 1 << ": HOME" << std::endl;
			}
			else // Prints the location of the pawn. if this is gone into, it means the pawn isn't on any special tile (sliders not withstanding)
			{
				std::cout << "Player " << i + 1 << " | Pawn " << j + 1 << ": " << tokens[i][j].getLocation() << std::endl;
			}

			// (tokens[i][j].getHome()) ? std::cout << "Player" << i + 1 << " | Pawn " << j + 1 << ": HOME" << std::endl : std::cout << "Player " << i + 1 << " | Pawn " << j + 1 << ": " << tokens[i][j].getLocation() << std::endl;
		}

		std::cout << std::endl;
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07); // setting the text colour back to white.
}