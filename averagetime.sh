#!/bin/bash
#Hamza Ilyas
#hi3zk
#2.14.18
#averagetime.sh

#prompts for the dictionary entry
echo 'Dictionary File:'
#when entered, this value is read as a dictionary parameter to be used
read dictionary
#prompts for the grid file entry
echo 'Grid File:'
#when entered, this value is read as the grid parameter to be used 
read grid

#these are 5 variables produce their own time reading in the parameters above.
RUNNING_TIME1=`./a.out $dictionary $grid | tail -1`
RUNNING_TIME2=`./a.out $dictionary $grid | tail -1`
RUNNING_TIME3=`./a.out $dictionary $grid | tail -1`
RUNNING_TIME4=`./a.out $dictionary $grid | tail -1`
RUNNING_TIME5=`./a.out $dictionary $grid | tail -1`

#calculate and print out the average of the runtimes
echo "Average Running Time:" $(((RUNNING_TIME1+RUNNING_TIME2+RUNNING_TIME3+RUNNING_TIME4+RUNNING_TIME5)/5))



