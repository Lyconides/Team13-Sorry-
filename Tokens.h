#pragma once
//reference: https://www.geeksforgeeks.org/c-classes-and-objects/
class TokenClass {
public:
	int Player;
	bool Start;
	bool SafeZone;
	bool Home;
	int Location;

	TokenClass(int p) {
		Player = p;
		setStart(true);
		setSafeZone(false);
		setHome(false);
	}

	void setStart(bool start){
		Start = start;
	}
	void setSafeZone(bool safe) {
		SafeZone = safe;
	}
	void setHome(bool home) {
		Home = home;
	}
	void setLocation(int space) {
		Location = space;
	}

	bool getStart() {
		return Start;
	}
	bool getSafeZone() {
		return SafeZone;
	}
	bool getHome() {
		return Home;
	}
	int getLocation() {
		return Location;
	}
	int getPlayer() {
		return Player;
	}

}