#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


typedef pair<int, int> pii;
class Over9000Rocks {
public:

    int countPossibilities(vector <int> lowerBound, vector <int> upperBound) {
        int sz = lowerBound.size();
        vector< pii > pairs;
        for(int s=0; s<(1<<sz); s++){
            int l_sum = 0, u_sum = 0;
            for(int i=0; i<sz; i++){
                if( ((s>>i)&1) == 1){
                    l_sum += lowerBound[i];
                    u_sum += upperBound[i];
                }
            }
            if(u_sum > 9000){
                pairs.push_back( pii(max(l_sum, 9001), u_sum) );
            }
        }
        
        int psz = pairs.size();
        if(psz<=0)return 0;

        sort(pairs.begin(), pairs.end());
        int ans = 0;
        int cur_left = pairs[0].first;
        int cur_right = pairs[0].second;
        for(int i=1; i<pairs.size(); i++){
            if(pairs[i].first > cur_right){
                ans += cur_right - cur_left + 1;
                cur_left = pairs[i].first;
                cur_right = pairs[i].second;
            }else if(pairs[i].first == cur_right){
                cur_right = pairs[i].second;
            }else if(pairs[i].first < cur_right && pairs[i].second<=cur_right){
                continue;
            }else if(pairs[i].first < cur_right && pairs[i].second > cur_right){
                cur_right = pairs[i].second;
            }
        }
        ans += cur_right - cur_left + 1;
        return ans;
    }
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, bool hasAnswer, int p2) {
    cout << "Test " << testNum << ": [" << "{";
    for (int i = 0; int(p0.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << p0[i];
    }
    cout << "}" << "," << "{";
    for (int i = 0; int(p1.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << p1[i];
    }
    cout << "}";
    cout << "]" << endl;
    Over9000Rocks *obj;
    int answer;
    obj = new Over9000Rocks();
    clock_t startTime = clock();
    answer = obj->countPossibilities(p0, p1);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << p2 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer) {
        res = answer == p2;
    }
    if (!res) {
        cout << "DOESN'T MATCH!!!!" << endl;
    } else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
        cout << "FAIL the timeout" << endl;
        res = false;
    } else if (hasAnswer) {
        cout << "Match :-)" << endl;
    } else {
        cout << "OK, but is it right?" << endl;
    }
    cout << "" << endl;
    return res;
}
int main() {
    bool all_right;
    all_right = true;
    
    vector <int> p0;
    vector <int> p1;
    int p2;
    
    {
    // ----- test 0 -----
    int t0[] = {9000};
            p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {9001};
            p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = 1;
    all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
    // ------------------
    }
    
    {
    // ----- test 1 -----
    int t0[] = {9000,1,10};
            p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {9000,2,20};
            p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = 15;
    all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
    // ------------------
    }
    
    {
    // ----- test 2 -----
    int t0[] = {1001,2001,3001,3001};
            p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {1003,2003,3003,3003};
            p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = 9;
    all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
    // ------------------
    }
    
    {
    // ----- test 3 -----
    int t0[] = {9000,90000,1,10};
            p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {9000,90000,3,15};
            p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = 38;
    all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
    // ------------------
    }
    
    {
    // ----- test 4 -----
    int t0[] = {1,1,1,1,1,1};
            p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = {3,4,5,6,7,8};
            p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    p2 = 0;
    all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
    // ------------------
    }
    
    if (all_right) {
        cout << "You're a stud (at least on the example cases)!" << endl;
    } else {
        cout << "Some of the test cases had errors." << endl;
    }
    return 0;
}
// END KAWIGIEDIT TESTING
