#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
using namespace std;

class array_of_sorted_arrays {
public:
    array_of_sorted_arrays(vector<vector<int> > &arrays) {
        this->arrays = arrays;
        this->current_index = 0;
        this->current_array = 0;
    }

    int next() {
        int result = arrays[current_array][current_index];
        current_index++;
        if (current_index == arrays[current_array].size()) {
            current_index = 0;
            current_array++;
        }
        return result;
    }

    bool has_next() {
        return current_array < arrays.size();
    }
    int search(int x) {
        int result = -1;
        for (int i = 0; i < arrays.size(); i++) {
            for (int j = 0; j < arrays[i].size(); j++) {
                if (arrays[i][j] == x) {
                    result = i;
                    break;
                }
            }
        }
        return result;
    }
    void insert(int x) {
        int index = search(x);
        if (index == -1) {
            arrays.push_back(vector<int>(1, x));
        } else {
            arrays[index].push_back(x);
        }
    }
    private:
        vector<vector<int> > arrays;
        int current_index;
        int current_array;
};

int main(){
    vector< vector<int> > arrays;
    array_of_sorted_arrays a(arrays);
	srand(time(NULL));
    int Range = pow(2,30);
    for(int n=10;n<=30;n++){
        float T=0;
        int size = pow(2,n);
        clock_t Startime = clock();
        for(int i=0;i<size;i++){
            int r = rand()%Range;
            a.insert(r);
        }
        clock_t Endtime = clock();
        T += (float)(Endtime - Startime)/CLOCKS_PER_SEC;
        cout << " T_insert(n = " << n << ")= " << T << endl; 

        Startime = clock();
        for(int i=0;i<100000;i++){
            int r = rand()%Range;
            int ans = a.search(r);
        }
        Endtime = clock();
        T += (float)(Endtime - Startime)/CLOCKS_PER_SEC;
        cout << " T_search(n = " << n << ")= " << T << endl << endl; 
    }

    return 0;
}
