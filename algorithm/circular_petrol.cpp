//https://practice.geeksforgeeks.org/problems/circular-tour-1587115620/1/

int tour(petrolPump p[],int n)
{
    int s=0,def=0,cap=0;
    for(int i=0;i<n;i++){
        cap+=p[i].petrol-p[i].distance;
        if(cap<0){
            s=i+1;
            def+=cap;
            cap=0;
        }
    }
    if(def+cap>0)return s;
    return -1;
}