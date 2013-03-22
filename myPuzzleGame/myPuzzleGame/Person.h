/** This file is Person Class. */
#ifndef _INC_PERSON
#define _INC_PERSON

class Person{

private:
	int x;	// place x.
	int y;	// place y.
	int lastx;
	int lasty;

public:
	
	/**
	* Set the first place.
	*/
	Person(){
		x = 6;
		y = 2;
		lastx = 6;
		lasty = 2;
	};

	int getx(){ return x; };
	int gety(){ return y; };
	int getlastx(){ return lastx; };
	int getlasty(){ return lasty; };
	void setx(int x){ this->x = x; };
	void sety(int y){ this->y = y; };
	void updatex(int x);
	void updatey(int y);
};

#endif	// INC_PERSON