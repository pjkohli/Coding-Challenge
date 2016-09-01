
#include <iostream>
const int MaxLength = 100;
using namespace std ;

//Function to merge two sublists
void merge(double arr[], int first, int last, int mid);

//Function to sort an array. Complexity - O(logn)
void mergesort(double arr[], int first, int last)
{
    int mid;
    if(first<last)
    {
        mid=(first+last)/2;
        mergesort(arr,first,mid);
        mergesort(arr,mid+1,last);
        merge(arr,first,last,mid);
    }
}

//Merge Function
void merge(double arr[], int first, int last, int mid)
{
    int i, j, k;
    double temp[MaxLength];
    i = first;
    j= first;
    k = mid+1;
    while( i<= mid && k<=last)
    {
        if(arr[i] < arr[k])
        {
            temp[j] = arr[i];
            i++;
            j++;
        }
        else
        {
            temp[j]=arr[k];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        temp[j] = arr[i];
        i++;
        j++;
    }
    while(k<=last)
    {
        temp[j]=arr[k];
        j++;
        k++;
    }
    for(i=first; i < j; i++)
    {
        arr[i] = temp[i];
    }
}

//Function to find mean of numbers in an array. Complexity - O(n)
void mean(double arr[], int n)
{
    double sum = 0;
    double avg = 0;
    for (int i=0; i<n; i++)
    {
        sum = sum+arr[i];
    }
    avg = sum/n;
    cout<<"\n Mean is "<< avg;
    
}


//Function to find mode of numbers in an array. Complexity - O(n)
void mode(double arr[], int n)
{
    int i=0;
    int count = 0;
    int maxcount = 0;
    double result;
    while(i<n)
    {
        count = 1;
        for (int j=i+1; j<n && arr[i] == arr[j]; j++)
        {
            count++;
        }
        if (maxcount<count)
        {
            maxcount = count;
            result = arr[i];
        }
        i = i + count;
    }
   // cout<<"\n count is "<<maxcount;
    cout<<"\n Mode is "<< result<<" with frequency: "<< maxcount;
 
}

//Function to find median of numbers in an array. Complexity - O(1)
void median(double arr[], int n)
{
    int mid = n/2;
    double result =0;
    
    if(n%2 == 0)
    {
        result = (arr[mid] + arr[mid-1]) /2;
    }
    else
    {
        result = arr[mid];
    }
    
    cout<<"\n Median is "<< result<<"\n";
    
}

int main()
{
    double arr[MaxLength];
    int n;
    char choice;
    try
    {
        cout<< "Enter the length of an array: ";
        cin>>n;
        
        //Handle array out of Bound
        if (n > MaxLength || n < 1)
        {
            throw "Array Out of Bounds";
        }
        
        //Choice to enter negative number or not
        cout<< "\n Do you want to input negative numbers? \n Enter Y or N: ";
        cin>>choice;
        if(choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
        {
            throw "You have entered wrong choice";
        }
        
        //Input the array
        cout<< "\n Enter the elements of an array: \n";
        for(int i = 0; i<n; i++)
        {
            cin>>arr[i];
            
            //Handle input out of range
            if(arr[i]> 1.7e+308 || arr[i]< - 1.7e+308)
            {
                throw "Element out of range";
            }
            
            //Handle negative number when choice is N
            if (choice == 'N' || choice == 'n' )
            {
                if(arr[i]<0)
                {
                    // Throw exception if negative number is entered
                   throw "You cannot enter Negative numbers";
                    
                    /*//Or Ask user to Re-enter number
                    cout<< "\nSorry u have entered negative number";
                    cout<< "\nPlease re-enter the number /n";
                    i--; */
                    
                }
            }
        }
    
        //Sort the array
        mergesort(arr,0,n-1);
        cout<< "\n Sorted array is: ";
        for (int i=0; i<n; i++)
        {
            cout<< arr[i]<<"   ";
        }
    }
    
    //Handling Exceptions
    catch (const char* msg)
    {
        cerr << msg << endl;
        return 0;
    }
    
    //Function calling
    mean(arr, n);
    mode(arr,n);
    median(arr,n);
    
    return 0 ;
}

