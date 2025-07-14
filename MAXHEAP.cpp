

#include<iostream>
#include<map>
using namespace std;
struct MaxHeap{
    vector<int>H;
    void heapifyUp(int child){
        while(child > 0){
            int p = (child - 1)/ 2;
            if(H[p] < H[child]){
                swap(H[p],H[child]);
                child = p;
            }
            else{
                break;
            }
        }
    }
    void push(int val ){
        H.push_back(val);
        int idx = H.size()-1;
        heapifyUp(idx);
    }
    void heapifyDown(int idx){
        int length = H.size();
        while(idx < length){
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;
            int largest = idx;
            if(left < length && H[left] > H[largest]){
                largest = left;
            }
            if(right < length && H[right] > H[largest]){
                largest = right;
            }
            if(largest != idx){
                swap(H[largest],H[idx]);
                idx = largest;
            }
            else{
                break;
            }
        }
    }
    void pop(){
        //take the last data and put at H[0]
        if(H.empty())return;
        int val = H[0];
        H[0] = H.back();
        H.pop_back();
        heapifyDown(0); 
    }
    bool Empty(){
        if(H.size()==0)return 1;
        else return 0;
    }
    int top(){
        if(Empty())return -1;
        return H[0];
    }
};
int main(){
    int n;
    cin >> n;
    vector<int>A(n);
    for(int i = 0 ; i < n ; i++){
        cin >> A[i];
    }
    MaxHeap H1;
    for(int i = 0 ; i < n ; i++){
        H1.push(A[i]);
    }
    
    while(!H1.Empty()){
        cout << H1.top() << endl;
        H1.pop();

    }
    
    
    
    



    

   
    

}
