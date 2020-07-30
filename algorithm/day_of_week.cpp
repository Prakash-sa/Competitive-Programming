int dayofweek(int d,int m,int y){
    int t[]={0,3,2,5,0,3,5,1,4,6,2,4};
    if(m<3)y--;
    return (y+y/4-y/100+y/400+t[m-1]+d)%7;
    
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	
	int d,m,y;
	    cin>>d>>m>>y;
	    string s[]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
            cout<<s[dayofweek(d,m,y)]<<endl;
	}
	return 0;
}