#pragma once
#include

struct BoardSpace
{
public:
	int Start(4);
	int StartSpace;
	int SafetyZone[5];
	int Home(0);

	BoardSpace(int player) {
		switch(player)
			case 1:
				StartSpace = 4;
				break;
			case 2:
				StartSpace = 19;
				break;
			case 3:
				StartSpace = 34;
				break;
			case 4:
				StartSpace = 49;
				break;
	}
};
