identification division.
program-id. s20734621.

data division.

working-storage section.
01 arr.
05 nums pic S9(4)V9(5) occurs 5 times.
01 std pic S9(4)V9(5).
01 meanVal pic S9(4)V9(5) value 0.
01 variableAmount pic S9(4)V9(5) value 0.
01 total pic S9(4)V9(5).
01 i pic 9 value 0.

procedure division.

mainline.
    perform readData
    perform stdDev varying i from 1 by 1 until i >= 6
    display "stdDev = ".
    display std.
    stop run.

stdDev.
    compute meanVal = (nums(1) + nums(2) + nums(3) + nums(4) + nums(5)) / 5.
    compute total = ((nums(i) - meanVal) ** 2).
    add total to variableAmount.
    compute std = (variableAmount / 5) ** (1 / 2).

readData.
    display "Enter number 1:".
    accept nums(1).

    display "Enter number 2:".
    accept nums(2).

    display "Enter number 3:".
    accept nums(3).

    display "Enter number 4:".
    accept nums(4).

    display "Enter number 5:".
    accept nums(5).

end program s20734621.
