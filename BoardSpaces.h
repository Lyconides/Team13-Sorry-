#pragma once

struct BoardSpace{
public:
	int Start = 4;
	int StartSpace;
	int Home = 0;

	BoardSpace(int player) {
		switch (player) {
		case 1:
			StartSpace = 5;
			break;
		case 2:
			StartSpace = 20;
			break;
		case 3:
			StartSpace = 35;
			break;
		case 4:
			StartSpace = 50;
			break;
		}
	}
};
