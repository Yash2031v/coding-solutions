class Solution {
  public:
  vector<int>c;
    void merge(vector<int>&item,int low,int high,int mid){
        c.resize(item.size());
        int i = low;
        int j = mid+1;
        int k = low;
        
        while(i<=mid && j<=high){
            if(item[i]<item[j]){
                c[k]=item[i];
                i++;
                k++;
            }else{
                c[k]=item[j];
                j++;
                k++;
            }

        }
        while(i<=mid){
            c[k]=item[i];
            i++;
            k++;
        }
        while(j<=high){
            c[k]=item[j];
            k++;
            j++;
        }
        int t = 0;
        for(int i = low; i <= high; i++){
        item[i] = c[i];
        }
    }
    void mergeSort(vector<int>&item,int low,int high){
        int mid = (low+high)/2;
        if(low<high){
            mid = (low+high)/2;
            mergeSort(item,low,mid);
            mergeSort(item,mid+1,high);
            merge(item,low,high,mid);

        }
    }
};