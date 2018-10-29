#pragma once

struct BoardSpace{
public:
	int Start = 4;
	int StartSpace;
	int SafeZoneGate;
	int Home = 0;

	BoardSpace(int player) {
		switch (player) {
		case 1:
			StartSpace = 5;
			SafeZoneGate = StartSpace - 2;
			break;
		case 2:
			StartSpace = 20;
			SafeZoneGate = StartSpace - 2;
			break;
		case 3:
			StartSpace = 35;
			SafeZoneGate = StartSpace - 2;
			break;
		case 4:
			StartSpace = 50;
			SafeZoneGate = StartSpace - 2;
			break;
		}
	}
};

