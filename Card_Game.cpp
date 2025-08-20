#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter the number of scores: ";                
    cin>>n;
    int arr[n];
    cout<<"Enter all the "<<n<<" scores:\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
   for(int i=0;i<n;i++){
       int curr=arr[i];
       int prev=i-1;
       while(prev>=0 && arr[prev]>curr){
           arr[prev+1]=arr[prev];
           prev--;
       }
       arr[prev+1]=curr;
       cout<<"The current hand is: ";    //helps to understand how the insertion sort works
       for(int m=0; m<=i;m++){
           cout<<arr[m]<<" ";
           
       }
       cout<<endl;
   }
   cout<<"\nSorted array is: ";
   for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }   
    return 0;
}

