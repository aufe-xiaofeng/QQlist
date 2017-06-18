#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
long GetBkn(string skey)
{
    int hash = 5381;
    for (int i = 0, len = skey.length(); i < len; ++i) 
        hash += (hash << 5) + (int)skey[i];
    return hash & 2147483647;
}
int main()
{
	string skey;
	string groupNum;
	cout<<"please enter skey\n提示不需要输入@\n";
	cin>>skey;
	skey="@"+skey;
	cout<<"请输入查询的群号\n";
	cin>>groupNum; 
	char x[10];
	sprintf(x,"%ld",GetBkn(skey));
	string link="http://qqweb.qq.com/c/activedata/get_mygroup_data?bkn="+string(x)+"&gc="+groupNum;
	cout<<link<<endl;
	system("pause");	
}
