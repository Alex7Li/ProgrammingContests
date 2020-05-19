# include <bits/stdc++.h>
//https://www.codingame.com/ide/puzzle/coders-strike-back
#define CHECKPOINT_RADIUS = 600;
#define MAP_WIDTH 16000;
#define MAP_HEIGHT 9000;
using namespace std;
typedef pair<int, int> Loc;

class Checkpoint;

class GameObject;


class GameObject {
public:
    Loc l;
};

class Checkpoint : public GameObject {
public:
}

double angleDeviation(Loc from) {

};

class Pod : public GameObject {
public:
    void move(Loc dest, double thrust) {
        cout << dest.first << " " << dest.second << " " << (int) thrust << endl;
    };
}

/**
 * This code automatically collects game data in an infinite loop.
 * It uses the standard input to place data into the game variables such as x and y.
 * YOU DO NOT NEED TO MODIFY THE INITIALIZATION OF THE GAME VARIABLES.
 **/
int main() {
    Pod myPod;
    Pod foePod;
    // game loop
    while (1) {
        int x; // x position of your pod
        int y; // y position of your pod
        int nextCheckpointX; // x position of the next check point
        int nextCheckpointY; // y position of the next check point
        Checkpoint next;
        cin >> myPod.l.first >> myPod.l.second;
        cin >> next.first >> next.second;
        int nextCheckpointDist;
        int nextCheckpointAngle;
        cin >> nextCheckpointDist >> nextCheckpointAngle;
        cerr << nextCheckpointAngle;
        cin >> foePod.l.first >> foePod.l.second;
        double thrust = max(0.0, (100 * cos(nextCheckpointAngle)));
        thrust = min(thrust * 10, 100);
        myPod.move(next.l, thrust);
    }
}
