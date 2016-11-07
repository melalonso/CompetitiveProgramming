#include <iostream>
using namespace std;

int R, C, curR, curC;
char maze[65][65], dir, orientation;
int movI, movJ;
string line;

int main() {
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> R >> C;
    getline(cin, line);
	for (int i =0; i<R; i++){
        getline(cin, line);
		for (int j =0; j<line.size(); j++){
			maze[i][j] = line[j];
		}
	}
	cin >> curR >> curC;
    curR--; curC--;
    orientation = 'N';
	while (cin >> dir && dir != 'Q'){
		if (dir != 'F'){
			if (orientation=='N'){
				movI = 0;
				dir == 'R' ? movJ = 1: movJ = -1;
			}else if (orientation=='S'){
				movI = 0;
				dir == 'R' ? movJ = -1 : movJ = 1;
			}else if (orientation=='W'){
				movJ = 0;
				dir=='R' ? movI = -1 : movI = 1;
			}else{
				movJ = 0;
				dir=='R' ? movI = 1 : movI = -1;
			}

            if (movI) movI==1 ? orientation = 'S': orientation = 'N';
            else movJ==1 ? orientation = 'E': orientation = 'W';

		}else if(maze[curR+movI][curC+movJ] != '*'){
			curR += movI; curC += movJ;
		}
	}
	cout << curR+1 <<" "<<curC+1<<" "<<orientation<<"\n";
	return 0;
}