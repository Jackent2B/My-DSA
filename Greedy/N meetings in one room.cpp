// algo: sort according to end time.
// check if start time of next meet is greater than the end time of previous meeting
// then push it in the ans 
struct meeting {
    int start;
    int end;
    int pos; 
}; 
bool comparator(struct meeting m1, meeting m2) 
{ 
    // if (m1.end < m2.end) return true; 
    // else if(m1.end > m2.end) return false; 
    // else if(m1.pos < m2.pos) return true; 
    // return false; 
    if(m1.end != m2.end){
        return m1.end<m2.end;
    }
    return m1.pos<m2.pos;
} 
void maxMeetings(int s[], int e[], int n) {
    struct meeting meet[n]; 
    for(int i = 0;i<n;i++) {
        meet[i].start = s[i], meet[i].end = e[i], meet[i].pos = i+1; 
    }
    
    sort(meet, meet+n, comparator); 
    
    vector<int> answer;
    

    int limit = meet[0].end; 
    // first meetin can always be performed
    answer.push_back(meet[0].pos); 
    
    for(int i = 1;i<n;i++) {
        // start time of next meet should be greater than the end time of previous meet
        if(meet[i].start > limit) {
            limit = meet[i].end; 
            answer.push_back(meet[i].pos); 
        }
    }
    for(int i = 0;i<answer.size();i++) {
        cout << answer[i] << " "; 
    }
    
}