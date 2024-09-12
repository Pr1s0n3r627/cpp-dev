#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
struct Node{
string id;
Node* next;
Node(string x):id(x),next(NULL){}
};
int main(){
int N;
cin>>N;
if(N==0)cout<<"No locations entered\n";
else{
unordered_map<string,Node*>mp;
Node *head=NULL,*tail=NULL;
for(int i=0;i<N;i++){
string loc;
cin>>loc;
Node* temp=new Node(loc);
if(!head)head=temp;
else tail->next=temp;
tail=temp;
mp[loc]=temp;
}
string loop_loc;
cin>>loop_loc;
if(loop_loc!="none"&&mp.find(loop_loc)!=mp.end())tail->next=mp[loop_loc];
Node *slow=head,*fast=head;
bool loop=false;
while(fast&&fast->next){
slow=slow->next;
fast=fast->next->next;
if(slow==fast){
loop=true;
break;
}
}
if(loop)cout<<"Loop detected\n";
else cout<<"No loop detected\n";
}
return 0;
}