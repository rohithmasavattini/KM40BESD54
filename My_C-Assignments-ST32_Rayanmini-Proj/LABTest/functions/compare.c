int datecompare(int d1,int m1,int y1,int d,int m,int y)
{
	if(y1<y)
		return 0;
	if(m1<m)
		return 0;
	if(d1<d)
		return 0;
	else
		return 1;


}
