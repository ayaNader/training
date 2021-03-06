#include <bits/stdc++.h>

using namespace std;

class ColorTheCells {
public:
	vector<int>dt;
	vector<int>startTime;
	int n;
	int dp[8][1<<8];
	int mi=1e9;
	void go(short pos,int msk,int time){
		if(msk==(1<<n)-1){
			mi=min(mi,time);
			return;
		}
		if(time>=mi)
			return;
		if(dp[pos][msk]<time)
			return;
		dp[pos][msk]=time;
		if(pos+1<n){
			if(((1<<(pos+1))&msk)==0){
				int newmsk=msk|(1<<(pos+1));
				startTime[pos+1]=time+1+dt[pos+1];
				go(pos,newmsk,time+1);
				startTime[pos+1]=0;
				go(pos+1,msk,time+1);
			}
			else{
				if(startTime[pos+1]<=time)
					go(pos+1,msk,time+1);
				else
					go(pos+1,msk,startTime[pos+1]+1);
			}
		}
		if(pos-1>=0){
			if(((1<<(pos-1))&msk)==0){
				int newmsk=msk|(1<<(pos-1));
				startTime[pos-1]=time+1+dt[pos-1];
				go(pos,newmsk,time+1);
				startTime[pos-1]=0;
				go(pos-1,msk,time+1);
			}
			else{
				if(startTime[pos-1]<=time)
					go(pos-1,msk,time+1);
				else
					go(pos-1,msk,startTime[pos-1]+1);
			}
		}
		return;
	}
	int minimalTime(vector <int> dryingTime) {
		dt=dryingTime;
		n=dryingTime.size();
		startTime.resize(n,0);
		for(int i=0;i<8;i++)
			for(int j=0;j<(1<<8);j++)
				dp[i][j]=1e9;
		go(0,0,0);
		return mi;
	}
};
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	ColorTheCells *obj;
	int answer;
	obj = new ColorTheCells();
	clock_t startTime = clock();
	answer = obj->minimalTime(p0);
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

	vector <int> p0;
	int p1;

	{
		// ----- test 0 -----
		int t0[] = {2,2,3};
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 6;
		all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 1 -----
		int t0[] = {1,2,100,1};
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 7;
		all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 2 -----
		int t0[] = {33,58,21,44};
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 26;
		all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 3 -----
		int t0[] = {35198,26281,72533,91031,44326,43178,85530};
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 26287;
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
