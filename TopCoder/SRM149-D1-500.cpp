/*
  idea:
  - starting with a given index checking number of all possible divisons
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
class MessageMess {
public:
	string ans="";
	string msg;
	map<string,bool>dic;
	ll dp[60];
	ll go(short ind,string tmp){
		if(ind==msg.length()){
			ans=tmp;
			ans.pop_back();
			return 1ll;
		}
		if(dp[ind]!=-1)
			return dp[ind];
		ll ret=0ll;
		for(short i=ind;i<msg.length();i++){
			string sub=msg.substr(ind,i-ind+1);
			if(dic[sub])
				ret+=go(i+1,tmp+sub+" ");
		}
		return dp[ind]=ret;
	}
	string restore(vector <string> dictionary, string message) {
		msg=message;
		for(short i=0;i<dictionary.size();i++)
			dic[dictionary[i]]=1;
		memset(dp,-1,sizeof dp);
		ll tmp=go(0,"");
		if(tmp==0)
			ans="IMPOSSIBLE!";
		else if(tmp>1)
			ans="AMBIGUOUS!";
		return ans;
	}
};
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, string p1, bool hasAnswer, string p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << "\"" << p1 << "\"";
	cout << "]" << endl;
	MessageMess *obj;
	string answer;
	obj = new MessageMess();
	clock_t startTime = clock();
	answer = obj->restore(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p2 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
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

	vector <string> p0;
	string p1;
	string p2;

	{
	// ----- test 0 -----
	string t0[] = {"HI","YOU","SAY"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "HIYOUSAYHI";
	p2 = "HI YOU SAY HI";
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	string t0[] = {"ABC","BCD","CD","ABCB"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "ABCBCD";
	p2 = "AMBIGUOUS!";
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	string t0[] = {"IMPOSS","SIBLE","S"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "IMPOSSIBLE";
	p2 = "IMPOSSIBLE!";
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	string t0[] = {"IMPOSS","SIBLE","S","IMPOSSIBLE"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "IMPOSSIBLE";
	p2 = "IMPOSSIBLE";
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
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
