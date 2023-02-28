int totalMoney(int n)
{
    int count = n / 7 + 1;
    int start = 1;
    int result = 0;
    int end = 7;
    for(int i = 0; i < count; i++)
    {
        if(i == count - 1)
        {
            for(int j = 0; j < n%7; j++)
            {
                result += start;
                start++;
            }
            return(result);
        }
        result += ((start + start + 6) * 7) / 2;
        start++;
    }
    return result;
}