#include <iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
#include<windows.h>
using namespace std;
class Array_Mehtods
{
private:
    long int *arr;
    int size_of_array;
public:
    Array_Mehtods()
    {
        cout <<"Enter size of array : "<<endl;
        int s;
        cin >> s;
        while(s<1)
        {
            cout <<"Invalid this value for size !!! "<<endl;
            cout <<"Enter size of array again : "<<endl;
            cin >> s;
        }
        set_size_of_Array(s);  // set a value for size of array
        arr = new long int [get_size_of_array()];
        set_elements_in_array();
    }
    void set_size_of_Array(int s)
    {
        size_of_array = s;
    }
    int get_size_of_array()
    {
        return size_of_array;
    }
    void set_elements_in_array()
    {
        cout <<"Please , Enter an elements in array : "<<endl;
        for(int i=0;i<get_size_of_array();i++)
        {
            cin >> arr[i];
        }
    }
    void print_array()
    {
        cout <<"The elements in array are : ";
        for(int i=0;i<get_size_of_array();i++)
        {
            cout <<arr[i]<< "  ";
        }
        cout << endl;
    }
    int get_size_of_array_in_byte()  // return size of array in byte
    {
        return sizeof(long int) * get_size_of_array();
    }
    int num_of_even_numbers_in_array()
    {
        int cnt =0;
        for(int i=0;i<get_size_of_array();i++)
        {
            if(arr[i]%2==0)
                cnt++;
        }
        return cnt;
    }
    int num_of_odd_numbers_in_array()
    {
        int cnt =0;
        for(int i=0;i<get_size_of_array();i++)
        {
            if(arr[i]%2 !=0)
                cnt++;
        }
        return cnt;
    }
    int num_of_positive_numbers_in_array()
    {
        int cnt =0;
        for(int i=0;i<get_size_of_array();i++)
        {
            if(arr[i]>0)
                cnt++;
        }
        return cnt;
    }
    int num_of_nagative_numbers_in_array()
    {
        int cnt =0;
        for(int i=0;i<get_size_of_array();i++)
        {
            if(arr[i]<0)
                cnt++;
        }
        return cnt;
    }
    int num_of_zero_numbers_in_array()
    {
        int cnt =0;
        for(int i=0;i<get_size_of_array();i++)
        {
            if(arr[i]==0)
                cnt++;
        }
        return cnt;
    }
    long int sum_of_even_numbers_in_array()
    {
        long int sum =0;
        for(int i=0;i<get_size_of_array();i++)
        {
            if(arr[i]%2==0)
                sum+= arr[i];
        }
        return sum;
    }
    long int sum_of_odd_numbers_in_array()
    {
        long int sum =0;
        for(int i=0;i<get_size_of_array();i++)
        {
            if(arr[i]%2!=0)
                sum+= arr[i];
        }
        return sum;
    }
    long int sum_of_all_numbers_in_array()
    {
        long int sum =0;
        for(int i=0;i<get_size_of_array();i++)
        {
                sum+= arr[i];
        }
        return sum;
    }
    long double average_of_all_numbers_in_array()
    {
        return sum_of_all_numbers_in_array()/double(get_size_of_array()); // use data type double for return an average with fractions not an integer only
    }
    long int get_min_element_in_array()
    {
        long int temp = arr[0];
        for(int i=0;i<get_size_of_array();i++)
        {
            if(arr[i]<temp)  // compare all elements with temp variable for return minimum element in array
                temp = arr[i];
        }
        return temp;
    }
    long int get_max_element_in_array()
    {
        long int temp = arr[0];
        for(int i=0;i<get_size_of_array();i++)
        {
            if(arr[i]>temp)  // compare all elements with temp variable for return maximum element in array
                temp = arr[i];
        }
        return temp;
    }
    long long  multiply_all_elements_in_array()
    {
        long long result = 1;
        for(int i=0;i<get_size_of_array();i++)
        {
            result = result * arr[i];
        }
        return result;
    }
    void sort_elements_in_array_DES()
    {
        long int temp;
        for(int i=0;i<get_size_of_array();i++)
        {
            for(int j=0;j<get_size_of_array();j++)
            {
                if(arr[j]<arr[i])
                {
                    temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
            }
        }
        //print_array();
    }
    void sort_elements_in_array_ASC()
    {
        long int temp;
        for(int i=0;i<get_size_of_array();i++)
        {
            for(int j=0;j<get_size_of_array();j++)
            {
                if(arr[j]>arr[i])
                {
                    temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
            }
        }
        //print_array();
    }
    int sequential_search(long int n)
    {
        for(int i=0;i<get_size_of_array();i++)
        {
            if(arr[i]==n)
                return i;
        }
        return -1;
    }
    int binary_search_(int left_,int right_,long int num)
    {
        sort_elements_in_array_ASC();
        if(right_>=left_)
        {
            int med = left_+(right_-left_)/2;
            if(arr[med]==num)
                return med;
            if(arr[med]>num)
            {
                return binary_search_(left_,med-1,num);
            }
            return binary_search_(med+1,right_,num);
        }
        return -1;
    }
    void swap_min_element_with_max_element()
    {
        int max_index = sequential_search(arr[sequential_search(get_max_element_in_array())]);
        int min_index = sequential_search(arr[sequential_search(get_min_element_in_array())]);
        long int temp = arr[max_index];
        arr[max_index] = arr[min_index];
        arr[min_index] = temp;
        print_array();
    }
    void reverse_array()
    {
        /*
        for(int i = 0,j=get_size_of_array()-1;true;i++,j--)
        {
            long int temp = arr[i];
            arr[i]=arr[j];
            arr[j] = temp;
            if(get_size_of_array()%2==0 && i==(j-1))
                break;
            if(get_size_of_array()%2!=0 && i==j)
                break;
        }*/
        cout <<"The elements in array in reverse order are  : ";
        for(int i=get_size_of_array()-1;i>=0;i--)
        {
            cout <<arr[i]<< "  ";
        }

    }
    void print_histogram()
    {
        print_array();
        for(int i=0;i<get_size_of_array();i++)
        {
            cout <<arr[i]<<" : ";
            if(arr[i]>=0) // if element positive or zero print '+' in times of element value for example if arr[1]==5  print -> +++++
            {
                for(int j=0;j<arr[i];j++)
                 {
                    cout <<" + ";
                    if(j==arr[i]-1)
                      cout<<endl;
                 }
            }
            else    // if element negative print '-' in times of element value for example if arr[1]==-5  print -> -----
            {
                arr[i] = arr[i] * -1;   // for calculate an absolute value for element
                for(int j=0;j<arr[i];j++)
                 {
                    cout <<" - ";
                    if(j==arr[i]-1)
                      cout<<endl;
                 }
            }

        }
    }
    long int power_(long int num,int pow)
    {
        int half_pow = pow/2;
        long int result = 1;
        for(int i=1;i<=half_pow;i++)
        {
            result = result * num;
        }
        if(pow%2==0)
            return result * result;
        return result * result * num;
    }
    void power_of_min_number_in_array()
    {
        print_array();

       long int min_pow = get_min_element_in_array();
        cout <<"The minimum elements in array is : "<< min_pow<<" , then elements in array with power "<<min_pow<< " are : "<<endl;

        for(int i=0;i<get_size_of_array();i++)
        {
            cout <<power_(arr[i],min_pow)<<"  ";
        }
    }
    void power_of_any_number(int pow)
    {
        print_array();

        cout <<"The power that you enter it is : "<< pow<<" , then elements in array with power "<<pow<< " are : "<<endl;

        for(int i=0;i<get_size_of_array();i++)
        {
            cout <<power_(arr[i],pow)<<"  ";
        }
    }
    void shift_right()
    {
        int i= get_size_of_array()-1;
        int j= i-1;
        long int temp = arr[i];
        while(j>=0&&i>=0)
        {
           arr[i] = arr[j];
           i--;
           j--;
           arr[i] = temp;
        }

    }
    void shift_left()
    {
        int i= 0;
        int j= i+1;
        long int temp = arr[i];
        while(j<get_size_of_array()&&i<get_size_of_array())
        {
           arr[i] = arr[j];
           i++;
           j++;
           arr[i] = temp;
        }
     // print_array();
    }
    int convert_digit_from_char_to_int(char ch)
    {
        if(ch =='0')
            return 0;
        else if(ch=='1')
            return 1;
        else if(ch=='2')
            return 2;
        else if(ch=='3')
            return 3;
        else if(ch=='4')
            return 4;
        else if(ch=='5')
            return 5;
        else if(ch=='6')
            return 6;
        else if(ch=='7')
            return 7;
        else if(ch=='8')
            return 8;
        else if(ch=='9')
            return 9;
        else
            return 0;
    }
    void count_all_digits_in_array()
    {
        string digits ="";
        for(int i=0;i<get_size_of_array();i++)
        {
            digits += to_string(arr[i]); // convert an int to string
        }
        cout <<"All digits in array are: "<<endl;
        for(int i=0;i<digits.size();i++)
        {
            cout <<digits[i]<< " ";
        }

        cout << endl;
        cout <<"The sum of digits is : ";
        for(int i=0;i<digits.size()-1;i++)
        {
           if(digits[i]=='-')
            continue;
           else
            cout <<digits[i]<<" + ";
        }
        cout <<digits[digits.size()-1]<< " = ";
        int sum = 0;
        for(int i=0;i<digits.size();i++)
        {
            sum += convert_digit_from_char_to_int(digits[i]);
        }

        cout <<sum<<endl;
    }
    void insert_front()
    {
        cout <<"Please , Enter a number for inserting it at the front of array : "<<endl;
        long int new_value;
        cin >> new_value;
        int position = 1;
        for(int i=get_size_of_array()-1;i>=position-1;i--)
            arr[i+1]=arr[i];
        arr[position-1]=new_value;
        size_of_array++;
        print_array();
    }
    void insert_back()
    {
        cout <<"Please , Enter a number for inserting it at the end of array : "<<endl;
        long int new_value;
        cin >> new_value;
        int position = get_size_of_array();
        for(int i=get_size_of_array()-1;i>=position-1;i--)
            arr[i+1]=arr[i];
        arr[position-1]=new_value;
        size_of_array++;
        print_array();
    }
    void insert_at_position()
    {
        cout <<"Please , Enter a Position for inserting this new value in array : "<<endl;
        int position ;
        cin >> position;
        if(position==1)
            insert_front();
        else if(position==get_size_of_array())
        insert_back();
        else if(position>get_size_of_array()||position<1)
            cout <<"Invalid this position !!!"<<endl;
        else
        {
            cout <<"Please , Enter a number for inserting it at the position "<<position<<" in array : "<<endl;
            long int new_value;
            cin >> new_value;
            for(int i=get_size_of_array()-1;i>=position-1;i--)
                arr[i+1]=arr[i];
            arr[position-1]=new_value;
            size_of_array++;
           print_array();
        }

    }
    void delete_front()
    {
       int position = 1;
       for(int i=position-1;i<get_size_of_array()-1;i++)
       {
           arr[i] = arr[i+1];
       }

        size_of_array--;
        print_array();

    }
    void delete_back()
    {
        int position = get_size_of_array();
       for(int i=position-1;i<get_size_of_array()-1;i++)
       {
           arr[i] = arr[i+1];
       }

        size_of_array--;
        print_array();
    }
    void delete_at_position()
    {
        cout <<"Enter the number for position for delete an element at this index "<<endl;
       int position;
       cin >> position;
       if(position ==1)
        delete_front();
       else if (position==get_size_of_array())
        delete_back();
       else if(position<1 || position> get_size_of_array())
         cout <<"Invalid this position !!!"<<endl;
       else
       {

           for(int i=position-1;i<get_size_of_array()-1;i++)
           {
               arr[i] = arr[i+1];
           }

        size_of_array--;
        print_array();
       }

    }
    bool check_is_palindrom(long int num)
    {
        string n = to_string(num);
        string element="";
        for(int i=0;i<n.size();i++)
        {
            if(n[i]!='+'||n[i]!='-') // for filter string
                 element+=n[i];
        }
        if(element.size()==1)
            return true;
        if(element.size()%2 !=0)
        {
            for(int i=0,j=element.size()-1;i!=j;i++,j--)
            {
                if(element[i] != element[j])
                    return false;
            }
        }
        if(element.size()%2 ==0)
        {
            for(int i=0,j=element.size()-1;i<j;i++,j--)
            {

                if(element[i] != element[j])
                    return false;
            }
        }
        return true;
    }
    void num_of_palindrom_elements_in_array()
    {
        vector<int> palindrom_numbers;
        int cnt=0;
        for(int i=0;i<get_size_of_array();i++)
        {
            if(check_is_palindrom(arr[i])==true)
            {
                cnt++;
                palindrom_numbers.push_back(arr[i]);
            }
        }
        cout <<"Number of palindrome elements in array are : "<<cnt<<endl;
        cout <<"And the elements are : ";
        for(int i=0;i<palindrom_numbers.size();i++)
            cout <<palindrom_numbers[i]<<" ";
        cout <<endl;
    }
    bool is_divisible(long int num)
    {
        for(int i=0;i<get_size_of_array();i++)
        {
            if(num % arr[i] !=0)
            return false;

        }
        return true;
    }
    long int LCM()
    {
        if(num_of_zero_numbers_in_array()>=1)
            return 0;
        long int max_element_in_array = get_max_element_in_array();
        int i=1;
        while(true)
        {
            if(is_divisible(max_element_in_array*i)==true)
               break;

                i++;
        }
        return max_element_in_array*i;
    }
    long int GCD()
    {
        return multiply_all_elements_in_array()/LCM();
    }
    bool check_is_prime(long int num)
    {
        if(num<2)
            return false;
        if(num==2)
            return true;
        if(num%2==0)
            return false;
        int cnt=0;
        for(int i=1;i<=num;i++)
        {
            if(num % i == 0)
                cnt++;
            if(cnt>2)
                return false;
        }
        return true;
    }
    void num_of_prime_elements_in_array()
    {
        vector<long int> prime_numbers;
        int cnt=0;
        for(int i=0;i<get_size_of_array();i++)
        {
            if(check_is_prime(arr[i])==true)
            {
                cnt++;
                prime_numbers.push_back(arr[i]);
            }
        }
        cout <<"Number of prime elements in array are : "<<cnt<<endl;
        cout <<"And the elements are : ";
        for(int i=0;i<prime_numbers.size();i++)
            cout <<prime_numbers[i]<<" ";
        cout <<endl;
    }
    long int sum_of_divisible_number(long int num)
    {
        long int sum = 0;
        for(int i=1;i<num;i++)
        {
            if(num % i ==0)
                sum  = i + sum;

        }
        return sum;
    }
    void perfect_numbers_in_array()
    {
        vector<long int> perfect_numbers;
        int cnt=0;
        for(int i=0;i<get_size_of_array();i++)
        {
            if(sum_of_divisible_number(arr[i])==arr[i])
            {
                cnt++;
                perfect_numbers.push_back(arr[i]);
            }
        }
        cout <<"Number of perfect elements in array are : "<<cnt<<endl;
        cout <<"And the elements are : ";
        for(int i=0;i<perfect_numbers.size();i++)
            cout <<perfect_numbers[i]<<" ";
        cout <<endl;
    }
    void shift_zero_right_of_array()
    {
        if(num_of_zero_numbers_in_array()!=0)
        {
            long int new_arr[get_size_of_array()];
            int front_index =-1,back_index = get_size_of_array();
            int cnt=0;
            while(cnt<get_size_of_array())
             {
                if(arr[cnt]==0)
                 {
                   back_index--;
                   new_arr[back_index] = arr[cnt];
                 }
                else
                 {
                  front_index++;
                  new_arr[front_index] = arr[cnt];
                 }
               cnt++;
             }
           for(int i=0;i<get_size_of_array();i++)
              cout <<new_arr[i]<<" ";
        }
        else
            print_array();
        cout <<endl;

    }
    ~Array_Mehtods()
    {
        delete [] arr;
        arr = 0;
    }
};
int main()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,3);
    Array_Mehtods sameh;
      SetConsoleTextAttribute(h,14);
    cout <<"1 st method is : Print Array : "<<endl;
    cout <<"-------------------------------"<<endl;
    sameh.print_array();
    cout <<endl;
      SetConsoleTextAttribute(h,10);
    cout <<"2 st method is : Print Size Of Array In Bytes : "<<endl;
    cout <<"------------------------------------------------"<<endl;
    cout <<sameh.get_size_of_array_in_byte()<< " Bytes ." <<endl;
    cout <<endl;
      SetConsoleTextAttribute(h,14);
    cout <<"3 st method is : Print Number Of Even Elements In Array : "<<endl;
    cout <<"----------------------------------------------------------"<<endl;
    cout <<sameh.num_of_even_numbers_in_array()<<endl;
    cout <<endl;
      SetConsoleTextAttribute(h,10);
    cout <<"4 st method is : Print Number Of Odd Elements In Array : "<<endl;
    cout <<"---------------------------------------------------------"<<endl;
    cout <<sameh.num_of_odd_numbers_in_array()<<endl;
    cout <<endl;
      SetConsoleTextAttribute(h,14);
    cout <<"5 st method is : Print Number Of Positive Elements In Array : "<<endl;
    cout <<"--------------------------------------------------------------"<<endl;
    cout <<sameh.num_of_positive_numbers_in_array()<<endl;
    cout <<endl;
      SetConsoleTextAttribute(h,10);
    cout <<"6 st method is : Print Number Of Nagative Elements In Array : "<<endl;
    cout <<"--------------------------------------------------------------"<<endl;
    cout <<sameh.num_of_nagative_numbers_in_array()<<endl;
    cout <<endl;
      SetConsoleTextAttribute(h,14);
    cout <<"7 st method is : Print Number Of Zero Elements In Array : "<<endl;
    cout <<"----------------------------------------------------------"<<endl;
    cout <<sameh.num_of_zero_numbers_in_array()<<endl;
    cout <<endl;
      SetConsoleTextAttribute(h,10);
    cout <<"8 st method is : Print Summation of Even Elements In Array : "<<endl;
    cout <<"-------------------------------------------------------------"<<endl;
    cout <<sameh.sum_of_even_numbers_in_array()<<endl;
    cout <<endl;
      SetConsoleTextAttribute(h,14);
    cout <<"9 st method is : Print Summation of Odd Elements In Array : "<<endl;
    cout <<"------------------------------------------------------------"<<endl;
    cout <<sameh.sum_of_odd_numbers_in_array()<<endl;
    cout <<endl;
      SetConsoleTextAttribute(h,10);
    cout <<"10 st method is : Print Summation of All Elements In Array : "<<endl;
    cout <<"-------------------------------------------------------------"<<endl;
    cout <<sameh.sum_of_all_numbers_in_array()<<endl;
    cout <<endl;
      SetConsoleTextAttribute(h,14);
    cout <<"11 st method is : Print Average of All Elements In Array : "<<endl;
    cout <<"-----------------------------------------------------------"<<endl;
    cout <<sameh.average_of_all_numbers_in_array()<<endl;
    cout <<endl;
      SetConsoleTextAttribute(h,10);
    cout <<"12 st method is : Print Multiplication of All Elements In Array : "<<endl;
    cout <<"------------------------------------------------------------------"<<endl;
    cout <<sameh.multiply_all_elements_in_array()<<endl;
    cout <<endl;
      SetConsoleTextAttribute(h,14);
    cout <<"13 st method is : Print Maximum Element In Array : "<<endl;
    cout <<"---------------------------------------------------"<<endl;
    cout <<sameh.get_max_element_in_array()<<endl;
    cout <<endl;
      SetConsoleTextAttribute(h,10);
    cout <<"14 st method is : Print Minimum Element In Array : "<<endl;
    cout <<"---------------------------------------------------"<<endl;
    cout <<sameh.get_min_element_in_array()<<endl;
    cout <<endl;
      SetConsoleTextAttribute(h,14);
    cout <<"15 st method is : Swap Maximum Element With Minimum In Array : "<<endl;
    cout <<"---------------------------------------------------------------"<<endl;
    cout <<"The maximum Element is  : " <<sameh.get_max_element_in_array()<<" , And Minimum Element is : "<<sameh.get_min_element_in_array()<< endl<<"The Array After Swapping this Two Elements is : "<<endl;
    sameh.swap_min_element_with_max_element();
    cout <<endl;
      SetConsoleTextAttribute(h,10);
    cout <<"16 st method is : Searching for An Element In Array Using Sequential Search: "<<endl;
    cout <<"-----------------------------------------------------------------------------"<<endl;
      long int num;
      cout <<"Please , Enter number : "<<endl;
      cin >> num;
      if(sameh.sequential_search(num) != -1)
        cout <<"Number : "<< num <<" is exist in Array ."<<endl;
      else
      cout <<"Number : "<< num <<" is not exist in Array ."<<endl;
      cout <<"Sequential Search Takes Time Complexity O(N) "<<endl;
    cout <<endl;
      SetConsoleTextAttribute(h,14);
    cout <<"17 st method is : Searching for An Element In Array Using Binary Search: "<<endl;
    cout <<"-----------------------------------------------------------------------------"<<endl;
      long int val;
      cout <<"Please , Enter number : "<<endl;
      cin >> val;
      if(sameh.sequential_search(val) != -1)
        cout <<"Number : "<< val <<" is exist in Array ."<<endl;
      else
      cout <<"Number : "<< val <<" is not exist in Array ."<<endl;
      cout <<"Binary Search Takes Time Complexity O(LOG(N)) . "<<endl;
    cout <<endl;

      SetConsoleTextAttribute(h,10);
    cout <<"18 st method is : Print Reverse of Array : "<<endl;
    cout <<"-------------------------------------------"<<endl;
    sameh.reverse_array();
    sameh.print_array();
    cout <<endl;
      SetConsoleTextAttribute(h,14);
    cout <<"19 st method is : Print Histogram of All Elements In Array : "<<endl;
    cout <<"-------------------------------------------------------------"<<endl;
    sameh.print_histogram();
    cout <<endl;
      SetConsoleTextAttribute(h,10);
    cout <<"20 st method is : Shifting Right an Array : "<<endl;
    cout <<"--------------------------------------------"<<endl;
    sameh.shift_right();
    cout <<"Array after shifting it right is : "<<endl;
    sameh.print_array();
    cout <<endl;
      SetConsoleTextAttribute(h,14);
    cout <<"21 st method is : Shifting Left an Array : "<<endl;
    cout <<"-------------------------------------------"<<endl;
    sameh.shift_left();
    cout <<"Array after shifting it left is : "<<endl;
    sameh.print_array();
    cout <<endl;
      SetConsoleTextAttribute(h,10);
    cout <<"22 st method is : Sorting an Array Ascending : "<<endl;
    cout <<"-----------------------------------------------"<<endl;
    sameh.sort_elements_in_array_ASC();
    sameh.print_array();
    cout <<endl;
      SetConsoleTextAttribute(h,14);
    cout <<"23 st method is : Sorting an Array Descending : "<<endl;
    cout <<"------------------------------------------------"<<endl;
    sameh.sort_elements_in_array_DES();
    sameh.print_array();
    cout <<endl;
      SetConsoleTextAttribute(h,10);
    cout <<"24 st method is : Calculate Power of Minimum Element in Array : "<<endl;
    cout <<"----------------------------------------------------------------"<<endl;
    sameh.power_of_min_number_in_array();
    cout <<endl<<endl;
      SetConsoleTextAttribute(h,14);
    cout <<"25 st method is : Calculate Power of Element in Array : "<<endl;
    cout <<"----------------------------------------------------------------"<<endl;
    int p;
    cout <<"Enter a number for power : "<<endl;
    cin >> p;
    while(p<1)
    {
        cout <<"Enter a positive and non zero number for power again : "<<endl;
        cin >> p;
    }
    sameh.power_of_any_number(p);
    cout <<endl<<endl;
      SetConsoleTextAttribute(h,10);
    cout <<"26 st method is : Count All Digits In Array : "<<endl;
    cout <<"----------------------------------------------"<<endl;
    sameh.count_all_digits_in_array();
    cout <<endl;
      SetConsoleTextAttribute(h,14);
    cout <<"27 st method is : Print the Prime Numbers in Array: "<<endl;
    cout <<"----------------------------------------------------"<<endl;
    sameh.num_of_prime_elements_in_array();
    cout <<endl;
      SetConsoleTextAttribute(h,10);
    cout <<"28 st method is : Print the Palindrome Numbers in Array: "<<endl;
    cout <<"---------------------------------------------------------"<<endl;
    sameh.num_of_palindrom_elements_in_array();
    cout <<endl;
      SetConsoleTextAttribute(h,14);
    cout <<"29 st method is : Print the Perfect Numbers in Array: "<<endl;
    cout <<"------------------------------------------------------"<<endl;
    sameh.perfect_numbers_in_array();
    cout <<endl;
      SetConsoleTextAttribute(h,10);
    cout <<"30 st method is : Calculate LCM : "<<endl;
    cout <<"----------------------------------"<<endl;
    cout <<sameh.LCM();
    cout <<endl<<endl;
      SetConsoleTextAttribute(h,14);
    cout <<"31 st method is : Calculate GCD : "<<endl;
    cout <<"----------------------------------"<<endl;
       if(sameh.LCM()==0)
         cout <<"Cannot calculate GCD because the value of LCM = 0 "<<endl;
       else
         cout <<sameh.GCD()<<endl<<endl;
           SetConsoleTextAttribute(h,10);
    cout <<"32 st method is : Insertion at Front of Array : "<<endl;
    cout <<"------------------------------------------------"<<endl;
    sameh.insert_front();
    cout <<endl;
      SetConsoleTextAttribute(h,14);
    cout <<"33 st method is : Insertion at End of Array : "<<endl;
    cout <<"----------------------------------------------"<<endl;
    sameh.insert_back();
    cout <<endl;
      SetConsoleTextAttribute(h,10);
    cout <<"34 st method is : Insertion at Any Position in Array : "<<endl;
    cout <<"-------------------------------------------------------"<<endl;
    sameh.insert_at_position();
    cout <<endl;
      SetConsoleTextAttribute(h,14);
    cout <<"35 st method is : Deletion from a Front of Array : "<<endl;
    cout <<"---------------------------------------------------"<<endl;
    sameh.delete_front();
    cout <<endl;
      SetConsoleTextAttribute(h,10);
    cout <<"36 st method is : Deletion from a End of Array : "<<endl;
    cout <<"-------------------------------------------------"<<endl;
    sameh.delete_back();
    cout <<endl;
      SetConsoleTextAttribute(h,14);
    cout <<"37 st method is : Deletion at Any Position in Array : "<<endl;
    cout <<"------------------------------------------------------"<<endl;
    sameh.delete_at_position();
    cout <<endl;
      SetConsoleTextAttribute(h,10);
    cout <<"38 st method is : Shifting Zeros Right of Array : "<<endl;
    cout <<"--------------------------------------------------"<<endl;
    sameh.shift_zero_right_of_array();
    cout <<endl;
      SetConsoleTextAttribute(h,14);
    cout <<"39 st method is : Insertion at Front of Array Again: "<<endl;
    cout <<"-----------------------------------------------------"<<endl;
    sameh.insert_front();
    cout <<endl;
      SetConsoleTextAttribute(h,10);
    cout <<"40 st method is : Insertion at End of Array Again : "<<endl;
    cout <<"----------------------------------------------------"<<endl;
    sameh.insert_back();
    cout <<endl;
      SetConsoleTextAttribute(h,14);
    cout <<"41 st method is : Insertion at Any Position in Array Again : "<<endl;
    cout <<"-------------------------------------------------------------"<<endl;
    sameh.insert_at_position();
    cout <<endl;
      SetConsoleTextAttribute(h,10);
    cout <<"42 st method is : Print the Prime Numbers After Inserting a new Elements in Array : "<<endl;
    cout <<"-------------------------------------------------------------------------------------"<<endl;
    sameh.num_of_prime_elements_in_array();
    cout <<endl;
      SetConsoleTextAttribute(h,14);
    cout <<"43 st method is : Sorting an Array Ascending After Inserting a new Elements in Array : "<<endl;
    cout <<"---------------------------------------------------------------------------------------"<<endl;
    sameh.sort_elements_in_array_ASC();
    sameh.print_array();
    cout <<endl;
      SetConsoleTextAttribute(h,10);

        SetConsoleTextAttribute(h,7);
    return 0;
}
