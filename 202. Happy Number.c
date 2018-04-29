int count(int n)
{
    int re = 0;
    int temp;
    while(n)
    {
        temp = n % 10;
        n /= 10;
        re += temp * temp;
    }
    return re;
}

bool isHappy(int n)
{
    int fast, slow;
    fast = slow = n;
    do{
        slow = count(slow);
        fast = count(fast);
        fast = count(fast);
    }while(slow != fast);
    if(slow == 1)
        return true;
    return false;
}