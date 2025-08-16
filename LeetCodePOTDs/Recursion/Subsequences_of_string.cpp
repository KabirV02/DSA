// https://www.naukri.com/code360/problems/subsequences-of-string_985087?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_16

#include <bits/stdc++.h> 
using namespace std;

int n;

void solve(string& str,vector<string>& result,string output,int i){

	if(i>=n){
		if(output.length() > 0){
		result.push_back(output);
		}
		return;
	}

	solve(str,result,output,i+1);	
	output.push_back(str[i]);
	solve(str,result,output,i+1);

}

vector<string> subsequences(string str){
	
	n = str.length();
	vector<string> result;
	string output = "";
	int i=0;
	solve(str,result,output,i);
	return result;

	
}
