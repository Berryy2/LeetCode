// if its zero then the number won't be the same when its double reversed so, return false.
// else then the number will be the same when double reversed so, return true.
bool isSameAfterReversals(int num) 
{
    // Edge case if the num is zero then its double reverse is itself.
    if(num == 0) return true;
    // Getting remanider of the num to get the value of the last digit.
    int remainder = num % 10; 
    // Returnin false if the last digit was zero.
    if(remainder == 0 ) return false;
    // else, the number will give the same when double reversed(return true).
    else return true;     
}
