program main

    implicit none
    
    !array dec.
    real, dimension(5) :: arr
    real :: stdOutput

    !call subroutine
    call readData(arr)
    
    !calculate stdOutput
    stdOutput = stdDev(arr)
    
    print '(A)'
    WRITE (*, '("Standard Deviation: ")') 
    WRITE (*, *) stdOutput

    !contains in as subprograms
    contains

    !stdDev function
    function stdDev(arr)
    
        real, dimension(5) :: arr
        integer :: i
        real :: meanArr
        real :: stdDev
        real :: sumArr

        !calculate mean
        meanArr = 0
        do i = 1, 5
            meanArr = meanArr + arr(i)
        end do
        meanArr = meanArr / 5

        !calculate deviation with sumArr
        sumArr = 0
        do i = 1, 5
            sumArr = sumArr + (arr(i) - meanArr) ** 2
        end do

        stdDev = sqrt(sumArr / 4) 

    end function stdDev 
    
    !readData subroutine
    subroutine readData(arr)
        implicit none
        real, dimension(5) :: arr
        integer :: i
        do i = 1,5
            PRINT '("Enter array element number ", I0, ": ")', i
            READ *, arr(i)
        end do
        !to check content in array:
        !PRINT *, arr
    end subroutine readData
    
end program 