/*

Virtual Functions
It is a member functoin in the base class that you redefine in a derived class. 

*/

class base{
    public:
    virtual void fun(){

    }
};

/*

Pure Functions
It is a function that has no implementatoin and is declared by assigning 0. It has no body.
*/

class base{
    public:
    virtual void fun()=0;
};

