	int isPlaindrome(string S)
	{
	   int i=0;
	   int j=S.size()-1;
	   while(i<j){
	       if(S[i]!=S[j]){
	           	return 1;
	       }
	       else{
                j++;
                i--;
	       }
	   }
	   return 0;
	}