bool isSameAfterReversals(int num) 
{
    if(num == 0) return true;
    //int res = 0;
    
    int remainder = num % 10; 
    if(remainder == 0 ) return false;
    else return true;     
}