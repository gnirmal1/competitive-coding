#include "bits/stdc++.h"
using namespace std;

struct window{
    int x, y, width, height;
    window(int a, int b, int w, int h) : x(a), y(b), width(w), height(h) {}
};

class compare{
    public:
        bool operator() (window &a, window &b){
            return a.x > b.x;
        }
};

vector<window> screen;
int xm, ym, commandNum;

bool intersect(window &w1, window &w2){
    return !(w1.x + w1.width < w2.x || w1.y + w1.height < w2.y || w1.x > w2.x + w2.width || w1.y > w2.y + w2.height);
}

bool contains(window &w, int x, int y){
    return ((w.x <= x && x <= w.x + w.width) && (w.y <= y && y <= w.y + w.height));
}

void solve(string &command){
    int n = screen.size();

    if (command == "OPEN"){
        int x, y, w, h;
        cin >> x >> y >> w >> h;
        if((x + w) > xm || (y + h) > ym){
            printf("Command %d: OPEN - window does not fit", commandNum);
            return;
        }
        window new_window = window(x, y, w, h);
        for(int i = 0; i < n; ++i){
            if(intersect(screen[i], new_window)){
                printf("Command %d: OPEN - window does not fit", commandNum);
                return;
            }
        }
        screen.push_back(new_window);
    }

    else if (command == "CLOSE"){
        int x, y;
        cin >> x >> y;
        for(int i = 0; i < n; ++i){
            if(contains(screen[i], x, y)){
                screen.erase(screen.begin() + i);
                return;
            }
        }
        printf("Command %d: CLOSE - no window at given position", commandNum);
    }

    else if (command == "RESIZE"){
        int x, y, w, h;
        cin >> x >> y >> w >> h;
        for(int i = 0; i < n; ++i){
            if(contains(screen[i], x, y)){
                window new_window = window(screen[i].x, screen[i].y, w, h);
                for(int j = 0; j < n; ++j){
                    if(intersect(screen[j], new_window)){
                        printf("Command %d: RESIZE - window does not fit", commandNum);
                        return;
                    }
                }
                screen[i].width = w;
                screen[i].height = h;
                return;
            }
        }
        printf("Command %d: RESIZE - no window at given position", commandNum);
    }

    else if (command == "MOVE"){
        int x, y, dx, dy;
        cin >> x >> y >> dx >> dy;
        if(dx == 0 && dy == 0) return;
        sort(screen.begin(), screen.end(), compare());
        for(int i = 0; i < n; ++i){
            if(contains(screen[i], x, y)){
                window move = screen[i];
                if(dy == 0){
                    vector<window> moved;
                    moved.push_back(move);
                    int sum = 0;
                    for(int j = i + 1; j < n; ++j){
                        window w = screen[j];
                        if(!(w.y + w.width < move.y || move.y + move.width < w.y)){
                            if(sum < dx) 
                            sum = min(dx, sum + w.x - (move.x + move.width));
                        }
                    }

                }
            }
        }

    }



}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> xm >> ym;
    commandNum = 0;
    string command;
    while(cin >> command);{
        commandNum++;
        solve(command);
    }
}
