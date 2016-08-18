//Third Largest Value
/*
 * Complete the function below.
 */
#include <climits>
int ThirdLargest(vector < int > arr) {
    int first = arr[0];
    int second = INT_MIN;
    int third = INT_MIN;
    int length = arr.size();
    for(int i = 0; i < length; i++)
    {
        if(arr[i] > first)
            first = arr[i];
    }
    for(int u = 0; u < length; u++)
    {
        if(arr[u] > second && arr[u] < first)
            second = arr[u];
    }
    for(int z = 0; z < length; z++)
    {
        if(arr[z] > third && arr[z] < first && arr[z] < second)
            third = arr[z];
    }
    return third;
}