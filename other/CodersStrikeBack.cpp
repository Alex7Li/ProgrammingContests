#include <utility>
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <complex>
#include <cmath>
#include <cstring>
//https://www.codingame.com/ide/puzzle/coders-strike-back
#define CHECKPOINT_RADIUS 600
#define POD_RADIUS 400
#define MAP_WIDTH 16000
#define MAP_HEIGHT 9000
#define PI 3.14159265359f
// PI/180
#define TO_RADIAN 0.017453292519943f
using namespace std;
typedef complex<float> Loc;

float normalizeAngle(float angle);

int turn = 0;

class Checkpoint;

class GameObject;


class GameObject {
public:
    Loc l;
};

double dist(Loc l1, Loc l2) {
    return abs(l1 - l2);
}

class Checkpoint : public GameObject {
public:
    /*
     * Let A = from, B = center of this checkpoint.
     * We return the maximum angle theta such that a line at angle theta from AB will
     * touch this checkpoint
     * What is the angle a ship to the center of this checkpoint
     * and the direction that ship is pointing?
     */
    float angleDeviation(Loc from) {
        if (dist(from, l) < CHECKPOINT_RADIUS) {
            return PI / 2.0;
        }
        return asin(CHECKPOINT_RADIUS / dist(from, l));
    }
};

class Pod : public GameObject {
    int podIndex = 0;
    bool canBoost = true;
    int lastMoved = -1;
    complex<float> v = complex<float>(0,0);
    float angle = 0;
    int nextInd = -1;
public:
    Pod(int index) {
        podIndex = index;
    }

    void readTurnInfo(int nCheckpoints) {
        int x, y, vX, vY, angle, nextCheckpoint;
        cin >> x >> y >> vX >> vY >> angle >> nextCheckpoint;
        y = MAP_HEIGHT - y;
        vY = MAP_HEIGHT - vY;
        angle = -angle;
        processTurnInfo(x, y, vX, vY, angle, nextCheckpoint, nCheckpoints);
    }

    void processTurnInfo(int newX, int newY, int vX, int vY, int ang, int nextCheckpointIndex, int nCheckpoints) {
        if (turn == 1) {
            v = complex<float>(0,0);
        } else {
            v = complex<float>(newX - l.real(), newY - l.imag());
        }
        angle = ang / PI;
        angle *= TO_RADIAN;
        l = complex<float>(newX, newY);
        if (nextInd > nextCheckpointIndex) {
            nextCheckpointIndex += nCheckpoints;
        }
        nextInd = nextCheckpointIndex;
    }

    complex<float> expectedPositionNextTurn(vector<Checkpoint> &checkpoints) {
        return l + v + 100.0f * (checkpoints[nextInd].l - l) / abs(checkpoints[nextInd].l - l);
    }

    bool move(Loc dest, float thrust) {
        if (lastMoved == turn) {
            return false;
        }
        lastMoved = turn;
        cout << (int) dest.real() << " " << MAP_HEIGHT - (int) dest.imag() << " " << (int) thrust << endl;
        return true;
    };

    bool boost(Loc dest) {
        if (!canBoost || lastMoved == turn) {
            return false;
        }
        canBoost = false;
        lastMoved = turn;
        cout << (int) dest.real() << " " << MAP_HEIGHT - (int) dest.imag() << " BOOST" << endl;
        return true;
    };

    bool shield(Loc dest) {
        if (lastMoved == turn) {
            return false;
        }
        lastMoved = turn;
        cout << (int) dest.real() << " " << MAP_HEIGHT - (int) dest.imag() << " SHIELD" << endl;
        return true;
    };

    void decide_move(vector<Checkpoint> &checkpoints, vector<shared_ptr<Pod>> &foePods) {
        Checkpoint next = checkpoints[nextInd];
        complex<float> directionToThrust = next.l - l;
        if (v != complex<float>(0.0f, 0.0f)) {
            angle = arg(v) - arg(directionToThrust);
            // make angle between plus minus pi
            angle = normalizeAngle(angle);
        }
        int nextDist = abs(directionToThrust);
        // this if statement is necessary, otherwise we will spiral in the opposite direction
        if (abs(angle) < 2 * PI / 3) {
            directionToThrust *= polar(1.0f, -angle / 2);
        }
        complex<float> thrustLoc = l + directionToThrust;
        if (podIndex == 0 || nextInd > checkpoints.size()) {
            if (nextDist > 5000 && abs(angle) < PI / 6) {
                boost(next.l);
            }
        }else{
            if (nextDist > 9000 && abs(angle) < PI / 6) {
                boost(next.l);
            }

        }
        for (int i = 0; i < foePods.size(); i++) {
            if (dist(foePods[i]->expectedPositionNextTurn(checkpoints),
                     expectedPositionNextTurn(checkpoints)) < POD_RADIUS * 2 + 5) {
                if (dist(foePods[i]->expectedPositionNextTurn(checkpoints), next.l) >
                    dist(expectedPositionNextTurn(checkpoints), next.l)) {
                    shield(thrustLoc);
                }
            }
        }

        move(thrustLoc, 100);
    }

};

void getInfo() {
    while (true) {
        string str;
        getline(cin, str);
        cerr << str << "\n";
    }
}

float normalizeAngle(float a) {
    while (a > PI) {
        a -= 2 * PI;
    }
    while (a < -PI) {
        a += 2 * PI;
    }
    return a;
}

#ifdef TESTING
int begin_test(int argc, char **argv);
#endif

int main(int argc, char **argv) {
#ifdef TESTING
    begin_test(argc, argv);
#else
    int laps, ncheckpoints;
    cin >> laps >> ncheckpoints;
    vector<shared_ptr<Pod>> myPods(2);
    vector<shared_ptr<Pod>> foePods(2);
    myPods[0] = make_shared<Pod>(0);
    myPods[1] = make_shared<Pod>(1);
    foePods[0] = make_shared<Pod>(0);
    foePods[1] = make_shared<Pod>(1);
    vector<Checkpoint> checkpoints(laps * ncheckpoints);
    for (int i = 0; i < ncheckpoints; i++) {
        int x, y;
        cin >> x >> y;
        checkpoints[i].l = complex<float>(x, MAP_HEIGHT - y);
    }
    for (int i = ncheckpoints; i < laps * ncheckpoints; i++) {
        checkpoints[i].l = checkpoints[i - ncheckpoints].l;
    }
    bool firstLap = true;
    // game loop
    while (1) {
        turn++;
        /*Read input*/
        myPods[0]->readTurnInfo(ncheckpoints);
        myPods[1]->readTurnInfo(ncheckpoints);
        foePods[0]->readTurnInfo(ncheckpoints);
        foePods[1]->readTurnInfo(ncheckpoints);
        /*Begin algorithm*/
        for (int i = 0; i < myPods.size(); i++) {
            myPods[i]->decide_move(checkpoints, foePods);
        }
    }
#endif
}
