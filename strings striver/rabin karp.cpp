rabinkarp(string s, string p)
{
	int lenp = p.length();
	int num = 0;
	for(int i=0;i<lenp;i++)
	{
		num = num*10 + (p[i]-96);
	}
	int cntr=0, int d = 0;
	for(int i=0;i<s.length();i++)
	{
		if(cntr==lenp)
		{
			if(d==num)
				return;
			d-=(s[i-(lenp-1)]-96* pow(10,lenp-1));
		}
		else
		{
			d = d*10 + s[i]-96;
			cntr++;
		}
	}
}