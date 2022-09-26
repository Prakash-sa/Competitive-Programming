/*
compile time polymorphism:-

1. call is resolve by compiler
2. fast execution
3. achieved by function and operator overloading

run time polymorphism

1. come to know at run time which method will be called. The call is not resolved by the compiler.
2. slow execution because it is known at the run time.
3. achieved by virtual functions and pointers.
*/

//compile time

int add(int a,int b){
    return a+b;
}


int add(int a,int b,int c){
    return a+b+c;
}

int main(){
    cout<<add(2,3)<<endl;
    cout<<add(2,3,4)<<endl;
    return 0;
}


//run time 

class A{
    public:
    virtual void fun(){
        cout<<"base ";
    }
};

class B:public A{
    public:
    void fun(){
        cout<<"derived ";
    }
};

int main(){
    A *a=new B;
    a->fun();
    return 0;
}
