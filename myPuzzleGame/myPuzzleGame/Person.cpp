/** This file is Person.cpp .*/

#include "Person.h"

void Person::updatex(int x_in){

	this->lastx = this->x;
	this->lasty = this->y;

	if(x_in == 1){
		if(this->x == 7){
			return;
		}
		this->x += 1;
	}

	if(x_in == -1){
		if(this->x == 2){
			return;
		}
		this->x += -1;
	}


}

void Person::updatey(int y_in){

	this->lastx = this->x;
	this->lasty = this->y;
	
	if(y_in == 1){
		if(this->y == 4){
			return;
		}
		this->y += 1;
	}

	if(y_in == -1){
		if(this->y == 2){
			return;
		}
		this->y += -1;
	}


}