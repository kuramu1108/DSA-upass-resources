#include <iostream>
#include <vector>
#include <cstdio>
#include <ctime>

using namespace std;
int answer = -1;

int find_max_re(vector<int> list) {
    if (list.size() >= 2) {
        int possible_max_1 = list[list.size()-1];
        list.pop_back();
        int possible_max_2 = find_max_re(list);

        if (possible_max_1 > possible_max_2)
            return possible_max_1;
        else
            return possible_max_2;
    } else
        return list[0];
}

int find_max_it(vector<int> list) {
    int max = -9999;
    for (vector<int>::iterator it = list.begin(); it != list.end(); it++) {
        if (*it > max)
            max = *it;
    }
    return max;
}

int main() {
    vector<int> list;
    for (int i = 0; i < 1000; i++) {
        list.push_back(std::rand());
    }

    // list.push_back(5);
    // list.push_back(55);
    // list.push_back(54);
    // list.push_back(52);
    // list.push_back(6);
    // list.push_back(900);
    // list.push_back(30);
    // list.push_back(25);
    // list.push_back(15);
    // list.push_back(0);

    

    // std::clock_t start;
    // double duration;
    // start = std::clock();

    /* Your algorithm here */
    cout << "recursion\n";
    cout << find_max_re(list) << "\n";

    // duration = ( std::clock() - start );
    // std::cout << duration <<'\n';

    // start = std::clock();

    cout << "iteration\n";
    cout << find_max_it(list) << "\n";

    // duration = ( std::clock() - start );
    // std::cout << duration <<'\n';
}