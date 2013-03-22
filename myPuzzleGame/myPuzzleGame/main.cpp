#include <iostream>
#include <vector>

#include "Person.h"

#define IMAX 5
#define JMAX 8

using namespace std;

typedef  vector< vector<char> > mat2d ;

Person *person;	// 人
mat2d cc;	// ２次元配列

void initialDraw();

void initialize(){
	initialDraw();
}

void initialDraw(){

	for(int j=0; j<JMAX; j++){
		cc[0][j] = '#';
	}
	cc[0][JMAX] = '\0';
	
	//cout << "# .. p #" << endl;
	cc[1][0] = '#';
	cc[1][1] = ' ';
	cc[1][2] = '.';
	cc[1][3] = '.';
	cc[1][4] = ' ';
	cc[1][5] = 'p';
	cc[1][6] = ' ';
	cc[1][7] = '#';
	cc[1][8] = '\0';

	//cout << "# oo   #" << endl;
	cc[2][0] = '#';
	cc[2][1] = ' ';
	cc[2][2] = 'o';
	cc[2][3] = 'o';
	cc[2][4] = ' ';
	cc[2][5] = ' ';
	cc[2][6] = ' ';
	cc[2][7] = '#';
	cc[2][8] = '\0';

	//cout << "#      #" << endl;
	cc[3][0] = '#';
	cc[3][1] = ' ';
	cc[3][2] = ' ';
	cc[3][3] = ' ';
	cc[3][4] = ' ';
	cc[3][5] = ' ';
	cc[3][6] = ' ';
	cc[3][7] = '#';
	cc[3][8] = '\0';

	for(int j=0; j<JMAX; j++){
		cc[4][j] = '#';
	}
	cc[4][JMAX] = '\0';

	for(int i=0; i<IMAX; i++){
		for(int j=0; j<JMAX+1; j++){
			if(cc[i][j] != '\0'){
				cout << cc[i][j];
			}
			else{
				cout << endl;
			}
		}
	}


	//cout << "########" << endl;
	//cout << "# .. p #" << endl;
	//cout << "# oo   #" << endl;
	//cout << "#      #" << endl;
	//cout << "########" << endl;

	cout << "a:left s:right w:up z:down. command?" << endl;

}

char getInput(){
	
	char c;
	cin >> c;
	//cout << c << endl;
	return c;
}

void updateGame(char in_c){
	switch(in_c){
		case 'a':
			person->updatex(-1);
			break;
		case 's':
			person->updatex(1);
			break;
		case 'w':
			person->updatey(-1);
			break;
		case 'z':
			person->updatey(1);
			break;
		default:
			break;

	}
}

void draw(){

	int lastx;
	int lasty;
	int x;
	int y;

	for(int j=0; j<JMAX; j++){
		cc[0][j] = '#';
	}
	cc[0][JMAX] = '\0';
	
	//cout << "# .. p #" << endl;
	cc[1][0] = '#';
	cc[1][2] = '.';
	cc[1][3] = '.';
	cc[1][7] = '#';
	cc[1][8] = '\0';

	//cout << "# oo   #" << endl;
	cc[2][0] = '#';
	cc[2][7] = '#';
	cc[2][8] = '\0';

	//cout << "#      #" << endl;
	cc[3][0] = '#';
	cc[3][7] = '#';
	cc[3][8] = '\0';

	for(int j=0; j<JMAX; j++){
		cc[4][j] = '#';
	}
	cc[4][JMAX] = '\0';

	lastx = person->getlastx();
	lasty = person->getlasty();
	x = person->getx();
	y = person->gety();

	if((x == 1) && ((y == 2) || (y == 3))){
		cc[y-1][x-1] = 'P';
	} else {
		cc[y-1][x-1] = 'p';
	}

	if((x != lastx ) || (y != lasty)){
		cc[lasty-1][lastx-1] = ' ';
	}

	for(int i=0; i<IMAX; i++){
		for(int j=0; j<JMAX+1; j++){
			if(cc[i][j] != '\0'){
				cout << cc[i][j];
			}
			else{
				cout << endl;
			}
		}
	}

	cout << "a:left s:right w:up z:down. command?" << endl;
}

int main(){
	//char c;
	//cin >> c;
	//cout << "Input Character is " << c << endl;

	//二次元配列の確保
	cc.resize(IMAX);
	for (int i=0;i<IMAX;i++) cc[i].resize(JMAX+1);

	initialize();

	person = new Person();
	char inChar;

	while(true){
		inChar = getInput();
		updateGame(inChar);
		draw();
	}

	delete person;

	return 0;
}