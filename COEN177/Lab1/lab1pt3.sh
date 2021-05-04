# Name: Karishma Khanna
# Date: 4/1/21
# Title: Lab1 - Unix/Linux Commands and Basic Shell Programming
# Description: (Part 3) This program checks how many users are logged on and confirms the user.
# Then, it lets them compute the area of a circle by entering the radius.

#!/bin/sh
echo Executing $0
echo $(/bin/ls | wc -l) files
wc -l $(/bin/ls)
echo "HOME="$HOME
echo "USER="$USER
echo "PATH="$PATH
echo "PWD="$PWD
echo "\$\$"=$$
user=`whoami`
numusers=`who | wc -l`
echo "Hi $user! There are $numusers users logged on."
if [ $user = "alkhanna" ] # I changed the user to my directory name alkhanna
then
    echo "Now you can proceed!"
else
    echo "Check who logged in!"
    exit 1
fi
response="Yes"
while [ $response != "No" ]
do
    echo "Enter radius of circle: " # use radius as the parameter
    read radius
    area=$(echo $radius*$radius*3.14159265 |bc) # expression for circle area
    echo "The area of the circle is: $area"
    echo "Would you like to repeat for another circle [Yes/No]?"
    read response
done
