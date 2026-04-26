#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

int balloonLength = 4;
double balloonProb = 0.05;
int skyr = 60;
int skyg = 160;
int skyb = 255;

int main(){
	CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	int width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	vector<int> balloons(width, 0);
	random_device rd;  
    mt19937 gen(rd()); 
    uniform_int_distribution<> colr(0, 255);
    uniform_real_distribution<double> ballon(0.0, 10.0);
	while(true){
		cout << "\033[48;2;" << skyr << ";" << skyg << ";" << skyb << "m";
		for(int& balloon : balloons){
			if(balloon != 0){
				if(balloon == balloonLength){
					balloon = 0;
					cout << " ";
				}else{
					if(balloon % 2 == 0){
						cout << "\\";
					}else{
						cout << "/";
					}
					++balloon;
				}
			}else{
				if(ballon(gen) <= balloonProb){
					int r = colr(gen), g = colr(gen), b = colr(gen);
					cout << "\033[38;2;" << r << ";" << g << ";" << b << "m0\033[39m";
					balloon = 1;
				}else{
					cout << " ";
				}
			}
		}
		cout << "\033[49m" << endl;
		this_thread::sleep_for(chrono::milliseconds(150));
	}
}
