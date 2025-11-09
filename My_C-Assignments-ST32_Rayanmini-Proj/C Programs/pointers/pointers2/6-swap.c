int swap(int *arr)
{
        int t;
        t=*arr;
        *arr=*(arr+1);
        *(arr+1)=t;

}

