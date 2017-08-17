/*
   idea:
   - finding all possible combinations of W,B for each i,j+1 when the goal of the current index is either W or B
   - using that information for each row finding all possible strings that can be in the second row to give the desired output for 
   that row
   - then muliplying the results for each row...since it is know that for all these possible strings it will always give the desired
   output which is then used to check for the next row's possible strings
*/


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

#define mod 1000000007;

class AlgridTwo {
public:
	map<pair<string,char>,vector<string>>mp;
	void init(){
		vector<string>in;
		//BB
		in.push_back("WW");in.push_back("BW");
		mp[make_pair("BB",'W')]=in;
		in.clear();in.push_back("BB");in.push_back("WB");
		mp[make_pair("BB",'B')]=in;
		//BW,WB
		in.clear();in.push_back("WW");in.push_back("BW");in.push_back("BB");in.push_back("WB");
		mp[make_pair("BW",'B')]=in;
		mp[make_pair("WB",'W')]=in;
		//WW
		in.clear();in.push_back("BW");in.push_back("BB");
		mp[make_pair("WW",'B')]=in;
		in.clear();in.push_back("WW");in.push_back("WB");
		mp[make_pair("WW",'W')]=in;
	}
	bool check(string s,string goal,string ad){
		for(int i=0;i<s.length()-1;i++){
			string sub=s.substr(i,2);
			if(sub=="BB"){
				swap(ad[i],ad[i+1]);
			}
			else if(sub=="WW"){
				continue;
			}
			else if(sub=="BW"){
				ad[i]=ad[i+1]='B';
			}
			else if(sub=="WB"){
				ad[i]=ad[i+1]='W';
			}
		}
		if(ad==goal)return true;
		else return false;
	}
	int fnd(int i,string s,string goal,string ad){
		int res=0;
		if(i==s.length()-1){
			if(check(s,goal,ad))return 1;
			return 0;
		}
		string sub=s.substr(i,2);
		vector<string>v=mp[{sub,goal[i]}];
		for(int j=0;j<v.size();j++){
			if(!i)res+=fnd(i+1,s,goal,v[j]);
			else if(!ad.length()||(ad.length()&&v[j][0]==ad[ad.length()-1]))
				res+=fnd(i+1,s,goal,ad+v[j][1]);
		}
		return res;
	}
	int makeProgram(vector <string> output) {
		init();
		int res=1;
		for(int i=0;i<output.size()-1;i++){
			res*=fnd(0,output[i],output[i+1],"");
			res%=mod;
		}
		return res;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	AlgridTwo *obj;
	int answer;
	obj = new AlgridTwo();
	clock_t startTime = clock();
	answer = obj->makeProgram(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
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

	vector <string> p0;
	int p1;

	{
		// ----- test 0 -----
		string t0[] = {"BB","WB"};
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 1;
		all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 1 -----
		string t0[] = {"BBWBBB","WBWBBW"};
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 8;
		all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 2 -----
		string t0[] = {"BWBWBW","WWWWWW","WBBWBW"};
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 0;
		all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 3 -----
		string t0[] = {"WWBWBWBWBWBWBWBW","BWBWBWBWBWBWBWBB","BWBWBWBWBWBWBWBW"};
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 73741817;
		all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
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
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!