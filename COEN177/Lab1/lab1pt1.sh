# Name: Karishma Khanna
# Date: 4/1/21
# Title: Lab1 - Unix/Linux Commands and Basic Shell Programming
# Description: (Part 1) This program checks how many users are logged on and confirms the user.
# Then, it lets them compute the area of a rectangle by entering height & width.

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
    echo "Enter height of rectangle: "
    read height
    echo "Enter width of rectangle: "
    read width
    area=`expr $height \* $width`
    echo "The area of the rectangle is $area"
    echo "Would you like to repeat for another rectangle [Yes/No]?"
    read response
done
