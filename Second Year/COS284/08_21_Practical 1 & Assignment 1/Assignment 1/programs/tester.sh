#!/usr/bin/env bash
#High values = higher accuracy
lambda=500; #tests per lambda
count=50; #how many lambda you want to calculate

####################################################################

function calc() {
  awk "BEGIN{print $*}";  #awk BEGIN used to add floating-point nums
}

####################################################################

function line() {
  echo "=================================================="
}

function space() {
  echo ""
}

function cpp_lambda() {
  for (( i = 0; i < $lambda; i++ )); do
    ./main
  done
}

function java_lambda() {
  for (( i = 0; i < $lambda; i++ )); do
    java Main;
  done
}

function py_lambda() {
  for (( i = 0; i < $lambda; i++ )); do
    python main.py;
  done
}

function asm_lambda() {
  for (( i = 0; i < $lambda; i++ )); do
    ./main
  done
}

####################################################################
function run_cpp() {
  space
  echo "Testing C++:"
  cpp_runtime=0                                    #set runtime to 0
  cpp_fastest=0                         #initialize fastest variable
  cd ./cpp                                       #cd into c++ folder
  for (( j = 0; j < $count; j++ )); do       #for loop with count=50  
    cpp_start="$(date +'%s.%N')"                #takes time of start
    cpp_lambda                                    #executes 1 lambda
    cpp_lambda="$(date +"%s.%N - ${cpp_start}" | bc)" >&2   #set end
    echo "C++ lambda" $j "=" `calc $cpp_lambda /1` "(s)"  #print end
    #sum runtime
    cpp_runtime=`calc $cpp_runtime + $cpp_lambda`
    if [[ $j = "0" ]]; then        #if j == 0, assume 1st is fastest
        cpp_fastest=${cpp_lambda}     #set fastest to current lambda
    fi
    if [[ $cpp_lambda < $cpp_fastest ]]; then    #compare to fastest
        cpp_fastest=0
        cpp_fastest=${cpp_lambda}              #override old fastest
    fi
  done
  cd ..                                       #cd back to .sh folder
  cpp_fastest=`calc $cpp_fastest / 1`          #print fastest lambda
  cpp_average=`calc $cpp_runtime / $count`  #print avarage, sum / 50
}
####################################################################

function run_java() {
  space
  echo "Testing Java"
  java_runtime=0
  java_fastest=0;
  cd ./java
  for (( j = 0; j < $count; j++ )); do
    java_start="$(date +'%s.%N')"
    java_lambda
    java_lambda="$(date +"%s.%N - ${java_start}" | bc)" >&2
    echo "C++ lambda" $j "=" `calc $java_lambda /1` "(s)"
    #sum runtime
    java_runtime=`calc $java_runtime + $java_lambda`
    if [[ $j = "0" ]]; then
        java_fastest=${java_lambda}
    fi
    if [[ $java_lambda < $java_fastest ]]; then
        java_fastest=${java_lambda}
    fi
  done
  cd ..
  java_fastest=`calc $java_fastest / 1`
  java_average=`calc $java_runtime / $count`
}

####################################################################

function run_python() {
  space
  echo "Testing Python"
  py_runtime=0
  py_fastest=0;
  cd ./python
  for (( j = 0; j < $count; j++ )); do
    py_start="$(date +'%s.%N')"
    py_lambda
    py_lambda="$(date +"%s.%N - ${py_start}" | bc)" >&2
    echo "C++ lambda" $j "=" `calc $py_lambda /1` "(s)"
    #sum runtime
    py_runtime=`calc $py_runtime + $py_lambda`
    if [[ $j = "0" ]]; then
        py_fastest=${py_lambda}
    fi
    if [[ $py_lambda < $py_fastest ]]; then
        py_fastest=${py_lambda}
    fi
  done
  cd ..
  py_fastest=`calc $py_fastest / 1`
  py_average=`calc $py_runtime / $count`
}

####################################################################

function run_assembly() {
  space
  echo "Testing Assembler"
  asm_runtime=0
  asm_fastest=0;
  cd ./asm
  for (( j = 0; j < $count; j++ )); do
    asm_start="$(date +'%s.%N')"
    asm_lambda
    asm_lambda="$(date +"%s.%N - ${asm_start}" | bc)" >&2
    echo
    echo "C++ lambda" $j "=" `calc $asm_lambda /1` "(s)"
    #sum runtime
    asm_runtime=`calc $asm_runtime + $asm_lambda`
    if [[ $j = "0" ]]; then
        asm_fastest=${asm_lambda}
    fi
    if [[ $asm_lambda < $asm_fastest ]]; then
        asm_fastest=${asm_lambda}
    fi
  done
  cd ..
  asm_fastest=`calc $asm_fastest / 1`
  asm_average=`calc $asm_runtime / $count`
}

####################################################################
#Function calls for each language
run_cpp
run_java
run_python
run_assembly

#REPORTING data:
line
space
#c++
####################################################################
#output of summaries of each language:
echo "C++ summary:"
space                                    #functino to add blank line
cd ./cpp
echo "Exec file size: " `stat --printf="%s" main` "(KB)"
cd ..
echo "Total exe time: " $cpp_runtime "(s)"         #print total time
echo "Average lambda: " $cpp_average "(s)"       #print average time
echo "Fastest lambda: " $cpp_fastest "(s)"       #print fastest time
space
line                                    #function to make line break
space
#py
echo "Java summary:"
space
cd ./java
echo "Exec file size: " `stat --printf="%s" main.class` "(KB)"
cd ..
echo "Total exe time: " $java_runtime "(s)"
echo "Average lambda: " $java_average "(s)"
echo "Fastest lambda: " $java_fastest "(s)"
space
line
space
#python
echo "Python summary:"
space
cd ./python
echo "Exec file size: " `stat --printf="%s" main.py` "(KB)"
cd ..
echo "Total exe time: " $py_runtime "(s)"
echo "Average lambda: " $py_average "(s)"
echo "Fastest lambda: " $py_fastest "(s)"
space
line
space
#asm
echo "Assembler summary:"
space
cd ./asm
echo "Exec file size: " `stat --printf="%s" main` "(KB)"
cd ..
echo "Total exe time: " $asm_runtime "(s)"
echo "Average lambda: " $asm_average "(s)"
echo "Fastest lambda: " $asm_fastest "(s)"
space
line
