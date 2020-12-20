#include <iostream>
#include <vector>

using namespace std;

bool is_pleasing(const vector<int>& trees)
{
    int state = 0;
    for (unsigned int i = 0; i < trees.size() - 1; ++i) {
        if (trees[i] < trees[i + 1] && (state > 0 || state == 0)) {
            state--;
        }
        else if (trees[i] > trees[i + 1] && (state < 0 || state == 0)) {
            state++;
        }
        else {
            return false;
        }
    }

    return true;
}

int solution(const vector<int>& trees) {

    if (trees.size() < 4 || trees.size() > 200) {
        return -1;
    }

    if (is_pleasing(trees)) {
        return 0;
    }

    int res = 0;

    for (unsigned int i = 0; i < trees.size(); ++i) {
        vector<int> tmp(trees);
        tmp.erase(tmp.begin()+i);
        if (is_pleasing(tmp)) {
            res++;
        }
    }

    return res > 0 ? res : -1;
}

int main()
{
    vector<int> v = {1, 3, 1, 2};
    int res = solution(v);
    if (!res) {
        cout << "Trees are pleasing" << endl;
    }
    else {
        cout << "Trees are NOT pleasing! Number of possible cut is: " << res << endl;
    }

    return 0;
}
