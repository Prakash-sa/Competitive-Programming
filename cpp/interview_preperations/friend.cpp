/*
A friend class can access private, protected, and public members of other classes in which it is declared as friends.
Like friend class, friend function can also access private, protected, and public members. 
But, Friend functions are not member functions.
*/

class A{
    private: 
    int data_a;
    public:
    A(int x){
        data_a=x;
    }

    friend int fun(A,B);
}

class B{
    private:
    int data_b;
    public:
    A(int x){
        data_b=x;
    }
    friend int fun(A,B);
}

int fun(A a,B b){
    return a.data_a+b.data_b;
}

int main(){
    A a(10);
    B b(20);
    cout<<fun(a,b)<<endl;
    return 0;
}