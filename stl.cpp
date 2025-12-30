#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> v;
	vector<int> c(5,100);
	v.push_back(1);
	v.emplace_back(2);
	v.emplace_back(3);
	
	vector<int>::iterator it = v.begin();
	it++;
	cout<<*(it)<<" "<<endl;
	
	for(int i = 0;i<3;i++){
	    cout<<v[i]<<" ";
	}
	cout<<endl;
	
	v.insert(v.begin()+1,3,4);
	
	for(auto it = v.begin(); it!=v.end();it++){
	    cout<<*(it)<<" ";
	}
	cout<<endl;
	
	v.erase(v.begin()+1,v.begin()+3);
	
	for(auto it:v){
	    cout<<it<<" ";
	}
	
	cout<<endl<<v[2]<<endl;
	cout<<c[4];

}
