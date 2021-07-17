int minimumPlatfroms(int arr[], int dep[], int n){
	// sort both arrival and departure array seprately
	sort(arr, arr + n);
	sort(dep, dep + n);
	int ans = 1;
	int platNeeded = 1;
	
	int i = 1;
	int j = 0;
	while(i<n && j<n){
		if(arr[i]<=arr[j]){
			platNeeded++;
			i++;
		}
		else if(arr[i]>arr[j]){
			platNeeded--;
			j++;
		}
		ans = max(ans,platNeeded);
	}
	return platNeeded;
}