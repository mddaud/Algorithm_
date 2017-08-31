/** 
  https://www.interviewbit.com/problems/sliding-window-maximum/
*/

vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
   deque<int> dq;
   vector<int> Answer;
   int sz = A.size();
   
   for(int i = 0; i < B; i++){
       while((!dq.empty()) && A[i] >= A[dq.back()]) dq.pop_back();
       dq.push_back(i);
   }
   
   for(int i = B; i < sz; i++){
       Answer.push_back(A[dq.front()]);
       while((!dq.empty()) &&(dq.front() <= i-B) ) dq.pop_front();
       while((!dq.empty()) && A[i] >= A[dq.back()]) dq.pop_back();
       dq.push_back(i);
   }
   Answer.push_back(A[dq.front()]);
   return Answer;
}
