#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

/*
    ACCEPTED
    BFS ensures that first found will be the best (minimun).
*/

int ni[] = {-1, -2, -2, -1, 1, 2,  2,  1};
int nj[] = {-2, -1,  1,  2, 2, 1, -1, -2};

bool visited[8][8];
int sx, sy;

struct Point{
	int x, y, height;
	Point(int _x, int _y, int _height){
		x = _x, y = _y;
		height = _height;
	}
};

bool valid(int x, int y){
    return x>=0 && y>=0 && x<8 && y<8;
}

int BFS(int a, int b){
    queue<Point> q;
    q.push( Point(a,b,0) );

    int nx, ny;
    while(!q.empty()){

        Point p = q.front(); q.pop();

        visited[p.x][p.y] = true;

        if (p.x==sx && p.y==sy) return p.height;

        for (int i=0; i<8; i++){
            nx = p.x + ni[i];
            ny = p.y + nj[i];
            if (!visited[nx][ny] && valid(nx, ny)){
                q.push( Point(nx, ny, p.height+1) );
            }
        }
    }
    return -1;
}


void clean(){
    for (int i=0; i<8; i++)
        for (int j=0; j<8; j++) visited[i][j] = false;
}

int main(){
    char source[2], sink[2];
    int x, y;
    while(scanf("%s %s",&source, &sink), source[0]!='#'){
        clean();
        sx = sink[0] - 'a', sy = sink[1] - '0'-1;
        x = source[0]-'a',  y = source[1]- '0'-1;
        //cout << "Desde "<<x<<","<<y<<" hasta "<<sx<<","<<sy<<endl;
        printf("To get from %s to %s takes %d knight moves.\n",source, sink,
            BFS(x, y));
    }
    return 0;
}
