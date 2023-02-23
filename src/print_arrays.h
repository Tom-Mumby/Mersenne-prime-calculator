                                                                    
using namespace std;

//prints array with result backwards to screen
void print_array_backwards_to_screen(int arr[], int length, int base){ 

    string baseString = to_string(base);
    int baseDig = baseString.length() - 1;
    int stringLength;

    int total = 0;
    for (int i = 0; i < length; i++){  
        string str = to_string(arr[i]);
        stringLength = str.length();

        if(stringLength!=baseDig && i!=(length-1)){
            for(int i=0;i<(baseDig-stringLength);i++){
                str.insert(0,"0");
            }
        }

        for (int i=str.length()-1; i>=0; i--){
            cout << str[i]; 
            total++;
            }
    }  
    cout << endl;
    cout << "Total Numbers " << total << endl;
} 
//prints array found forward to a text file
void write_array_to_file(int arr[], int length, int base){ 

     ofstream output_file("output_number.txt");

    string baseString = to_string(base);
    int baseDig = baseString.length() - 1;
    int stringLength;


    int total = 0;
    for (int i = length-1; i >= 0; i--){  
        string str = to_string(arr[i]);
        stringLength = str.length();

        if(stringLength!=baseDig && i!=length-1){
            for(int i=0;i<(baseDig-stringLength);i++){
                str.insert(0,"0");
            }
        }

        for (int i=0; i<str.length(); i++){
            output_file << str[i];
            total++;
            if(total % 100 ==0){
                output_file << "\n";
            }
            }
    }  

  output_file.close();
} 

// prints array
void print_array(int arr[], int length){  
    for (int i = 0; i < length; i++)  
    {  
                   cout << arr[i] <<" ";    
    }  
    cout << endl;
}
// prints string
void print(string text){
    cout << text << endl;
} 
// prints int
void print(int text){
    cout << text << endl;
} 
// prints double
void print(double text){
    cout << text << endl;
} 