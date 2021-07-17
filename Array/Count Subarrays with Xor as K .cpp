int solve(vector <int> &vec, int k){
	unordered_map<int,int> mp;

	int count = 0;
	int xorr = 0;

	for(int i=0; i<vec.size(); i++){
		xorr = xorr ^ vec[i];
		if(xorr == k)
			count++;
		if(mp.find(xorr ^ k) != mp.end()){
			count = count + mp[xorr ^ k];
		}
		mp[xorr]++;
	}
	return count;
}