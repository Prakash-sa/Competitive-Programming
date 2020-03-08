    #include<bits/stdc++.h>
    using namespace std;
    int main()
    {
        int n,i,j;
        multimap<string,int> mp;
        multimap<string, int>::iterator it ; 
        //multimap<string,int>:: iterator it;
        string s;
        cin>>n;
        while(n--){ 
            cin>>i;
            if(i==1){
                cin>>s>>j;
                it=mp.find(s);
                if(it!=mp.end()) it->second+=j;
                else mp.insert(pair<string,int>(s,j));
            }
            else if(i==3){
                cin>>s;
                 it=mp.find(s);
                 if(it!=mp.end()) cout<<it->second<<endl;
                 else cout<<"0"<<endl;
                
            }
            else if(i==2){
                cin>>s;
                it=mp.find(s);
                if(it!=mp.end()) mp.erase(it);

            }

        }
    
    }