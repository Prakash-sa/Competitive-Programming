// static members

/*
when a variable in a class is declared static, space for it is allocated for the lifetime of the program. 
No matter how many objects of that class have been created, there is only one copy of the static member.
So same static member can be accessed by all the objects of that class.

A static member function can be called even if no objects of the class exist and the static function are accessed using 
only the class name and the scope resolution operator.
 * /

 /*
 
 call by value:- pass the copied of actual parameteers to the function's formal parameters. 
 any changes in the values inside the function, then that change will not affect the actual value.

 call by reference:- the reference of actual parameters is sent to the functions formal parameters. 
 any changes in the values inside the function will be reflected in the actual values.

 */