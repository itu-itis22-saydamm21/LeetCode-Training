void    sorting(double *arr, int sum){
    int i;
    int j;
    int tmp;
    while(i < sum - 1){
        j = i + 1;
        while(j < sum){
            if(arr[i] > arr[j]){
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
            j++;
        }
        i++;
    }
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    double *merged;
    int i;
    int i1;
    int i2;
    int sum = nums1Size + nums2Size;
    double result;
    merged = malloc(sizeof(double) * (sum));
    i = 0;
    for(int i1=0;i1 < nums1Size; i1++){
        merged[i] = nums1[i1];
        i++;
    }
    for(int i2=0;i2 < nums2Size; i2++){
        merged[i] = nums2[i2];
        i++;
    }
    sorting(merged, sum);
    if(sum % 2 == 0){
        result = ((merged[sum/2 - 1] + merged[sum/2]) / 2);
        free(merged);
        return(result);
    }
    else{
        result = merged[sum/2];
        free(merged);
        return(result);
    }
}