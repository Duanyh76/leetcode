int compar(const void *i1, const void *i2)
{
    return *(const int*)i1 - *(const int*)i2;
}

bool containsDuplicate(int *num, int numsSize)
{
    if(numsSize == 1)
        return false;
    qsort(num, numsSize, sizeof(int), compar);
    for(int i = 0; i < numsSize-1; i++)
    {
        if(num[i] == num[i+1])
            return true;
    }
    return false;
}