int findmin(int price){
	int notes_available = {1,2,5,10,20,50,100,500,1000};
	int count = 0;
	int n = sizeof(notes_available)/sizeof(notes_available[0]);
	int j = n-1;
	while(price){
		if(notes_available[j] <= price ){
			count++;
			price = price - notes_available[j];
		}
		else{
			j--;
		}
	}
	return count;
}