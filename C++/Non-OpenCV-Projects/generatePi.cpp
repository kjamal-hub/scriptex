#include <iostream>
#include <cmath>
#include <random>

using namespace std;

float uniRandomPi(int n){

    int no_points_circle = 0;
    int no_points_total = 0;

    float x;
    float y;
    float distance;

    random_device rand;
    mt19937 gen(rand());
    uniform_real_distribution<> dis(0.0, 1.0);

    for (int i = 0; i < n; i++) {
          x = dis(gen);
          y = dis(gen);
        distance = pow(x, 2) + pow(y, 2);

          if (distance <= 1) {
              no_points_circle += 1;
}
          no_points_total += 1;
    }
    
    cout << 4.0 * (no_points_circle) / (no_points_total);

    return 1;
}

int main() {

    uniRandomPi(10000);
    return 1;
}