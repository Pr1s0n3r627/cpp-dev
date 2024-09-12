#include<iostream>
#include<vector>
using namespace std;
int main(){
int N;
cin>>N;
if(N==0)cout<<"No vehicles entered\n";
else{
vector<int>v(N);
for(int i=0;i<N;i++)cin>>v[i];
for(int i=0;i<N;i++)cout<<v[i]<<" -> ";
cout<<"NULL\n";
for(int i=N-1;i>=0;i--)cout<<v[i]<<" -> ";
cout<<"NULL\n";
}
return 0;
}