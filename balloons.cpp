#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

int balloonLength = 5;

int main(){
	int width;
	cout << "Fill one row with text." << endl;
	string txt;
	cin >> txt;
	width = txt.length();
	vector<int> balloons(width, 0);
	srand(time(0));
	while(true){
		for(int& balloon : balloons){
			if(balloon != 0){
				if(balloon == balloonLength){
					balloon = 0;
					cout << ".";
				}else{
					if(balloon % 2 == 0){
						cout << "\\";
					}else{
						cout << "/";
					}
					++balloon;
				}
			}else{
				if(rand() % 101 == 1){
					cout << "O";
					balloon = 1;
				}else{
					cout << ".";
				}
			}
		}
		cout << endl;
		this_thread::sleep_for(chrono::milliseconds(150));
	}
}
