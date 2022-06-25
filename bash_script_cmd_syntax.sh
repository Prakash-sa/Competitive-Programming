#use of echo cmd

:'
‘-n’ option is used to print any text without new line and ‘-e’ option is used to remove backslash characters from the output.
'

#!/bin/bash
echo "Printing text with newline"
echo -n "Printing text without newline"
echo -e "\nRemoving \t backslash \t characters\n"



#multiline comment

#!/bin/bash
: '
The following script calculates
the square value of the number, 5.
'
((area=5*5))
echo $area



#using while loop


#!/bin/bash
valid=true
count=1
while [ $valid ]
do
echo $count
if [ $count -eq 5 ];
then
break
fi
((count++))
done


#using for loop

#!/bin/bash
for (( counter=10; counter>0; counter-- ))
do
echo -n "$counter "
done
printf "\n"

#get user input

#!/bin/bash
echo "Enter Your Name"
read name
echo "Welcome $name to LinuxHint"


#using if statement

:'
For comparison, ‘-lt’ is used here. For comparison, you can also use ‘-eq’ for equality, ‘-ne’ for not equality and ‘-gt’ for greater than in bash script.
'

#!/bin/bash
n=10
if [ $n -lt 10 ];
then
echo "It is a one digit number"
else
echo "It is a two digit number"
fi


#Using if statement with AND logic

#!/bin/bash

echo "Enter username"
read username
echo "Enter password"
read password

if [[ ( $username == "admin" && $password == "secret" ) ]]; then
echo "valid user"
else
echo "invalid user"
fi


#Using if statement with OR logic:
#!/bin/bash

echo "Enter any number"
read n

if [[ ( $n -eq 15 || $n  -eq 45 ) ]]
then
echo "You won the game"
else
echo "You lost the game"
fi


#Using else if statement:
#!/bin/bash

echo "Enter your lucky number"
read n

if [ $n -eq 101 ];
then
echo "You got 1st prize"
elif [ $n -eq 510 ];
then
echo "You got 2nd prize"
elif [ $n -eq 999 ];
then
echo "You got 3rd prize"

else
echo "Sorry, try for the next time"
fi


#Using Case Statement:

#!/bin/bash

echo "Enter your lucky number"
read n
case $n in
101)
echo echo "You got 1st prize" ;;
510)
echo "You got 2nd prize" ;;
999)
echo "You got 3rd prize" ;;
*)
echo "Sorry, try for the next time" ;;
esac


#Get Arguments from Command Line:

#!/bin/bash
echo "Total arguments : $#"
echo "1st Argument = $1"
echo "2nd argument = $2"


#Get arguments from command line with names:
#!/bin/bash
for arg in "$@"
do
index=$(echo $arg | cut -f1 -d=)
val=$(echo $arg | cut -f2 -d=)
case $index in
X) x=$val;;

Y) y=$val;;

*)
esac
done
((result=x+y))
echo "X+Y=$result"



#Combine String variables:

#!/bin/bash

string1="Linux"
string2="Hint"
echo "$string1$string2"
string3=$string1+$string2
string3+=" is a good tutorial blog site"
echo $string3


#Get substring of String:


#!/bin/bash
Str="Learn Linux from LinuxHint"
subStr=${Str:6:5}
echo $subStr



#Add Two Numbers:

#!/bin/bash
echo "Enter first number"
read x
echo "Enter second number"
read y
(( sum=x+y ))
echo "The result of addition=$sum"


#Create Function:
#!/bin/bash
function F1()
{
echo 'I like bash programming'
}

F1


#Create function with Parameters:
#!/bin/bash

Rectangle_Area() {
area=$(($1 * $2))
echo "Area is : $area"
}

Rectangle_Area 10 20


#Pass Return Value from Function:

#!/bin/bash
function greeting() {

str="Hello, $name"
echo $str

}

echo "Enter your name"
read name

val=$(greeting)
echo "Return value of the function is $val"


#Make Directory:

#!/bin/bash
echo "Enter directory name"
read newdir
`mkdir $newdir`


#Make directory by checking existence:

#!/bin/bash
echo "Enter directory name"
read ndir
if [ -d "$ndir" ]
then
echo "Directory exist"
else
`mkdir $ndir`
echo "Directory created"
fi


#Read a File:

#!/bin/bash
file='book.txt'
while read line; do
echo $line
done < $file


#Delete a File:

#!/bin/bash
echo "Enter filename to remove"
read fn
rm -i $fn


#Append to File:

#!/bin/bash

echo "Before appending the file"
cat book.txt

echo "Learning Laravel 5">> book.txt
echo "After appending the file"
cat book.txt


#Test if File Exist:

:'
You can check the existence of file in bash by using ‘-e’ or ‘-f’ option. ‘-f’ option is used in the following script to test the file existence. 
'

#!/bin/bash
filename=$1
if [ -f "$filename" ]; then
echo "File exists"
else
echo "File does not exist"
fi



$ ls
$ bash file_exist.sh book.txt
$ bash file_exist.sh book2.txt


#Send Email:


#!/bin/bash
Recipient=”admin@example.com”
Subject=”Greeting”
Message=”Welcome to our site”
`mail -s $Subject $Recipient <<< $Message`



#Get Parse Current Date:

#!/bin/bash
Year=`date +%Y`
Month=`date +%m`
Day=`date +%d`
Hour=`date +%H`
Minute=`date +%M`
Second=`date +%S`
echo `date`
echo "Current Date is: $Day-$Month-$Year"
echo "Current Time is: $Hour:$Minute:$Second"


#Wait Command:

#!/bin/bash
echo "Wait command" &
process_id=$!
wait $process_id
echo "Exited with status $?"


#Sleep Command:

:'
You can set the delay amount by seconds (s), minutes (m), hours (h) and days (d).
'

#!/bin/bash

echo “Wait for 5 seconds”
sleep 5
echo “Completed”







