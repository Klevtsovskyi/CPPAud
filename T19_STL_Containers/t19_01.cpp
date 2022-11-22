#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <climits>
using namespace std;


int main() {
    srand(time(nullptr));

    int n = 10;
    vector<int> service_time(n);
    for (int i = 0; i < service_time.size(); i++) {
        service_time[i] = rand() % 81 + 20;
        cout << service_time[i] << ' ';
    }
    cout << endl;

    vector<int> waiting_time(n);
    int current_time = 0;
    for (int i = 0; i < waiting_time.size(); i++) {
        if (current_time <= 60 * i) {
            waiting_time[i] = 0;
            current_time = 60 * i + service_time[i];
        }
        else {
            waiting_time[i] = current_time - 60 * i;
            current_time += service_time[i];
        }
    }
    for (int t: waiting_time) {
        cout << t << ' ';
    }
    cout << endl;

    int min_service_time = INT_MAX;
    int min_service_time_i = -1;
    int max_waiting_time = -1;
    int max_waiting_time_i = -1;

    for (int i = 0; i < n; i++) {
        if (service_time[i] < min_service_time) {
            min_service_time = service_time[i];
            min_service_time_i = i;
        }
        if (waiting_time[i] > max_waiting_time) {
            max_waiting_time = waiting_time[i];
            max_waiting_time_i = i;
        }
    }
    cout << min_service_time << ' ' << min_service_time_i << endl;
    cout << max_waiting_time << ' ' << max_waiting_time_i << endl;

    return 0;
}
