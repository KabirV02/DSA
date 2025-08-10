/*
  In this approach we are getting the power of 2 upto 2^29 than convert it into string than sort
  and after that we are converting the given number into string and sort it at last we compare both
  string 
*/

class Solution {
public:
 
    string powers(int i){
        string result  = to_string(i);
        sort(begin(result),end(result));
        return result;
    }
   
    bool reorderedPowerOf2(int n) {
        string given = to_string(n);
        sort(begin(given),end(given));
        for(int i=0;i<=29;i++){
            string powerSorted = powers(1 << i); 
            if(given == powerSorted){
                return true;
            }
        }
   return false;
    }
};

/*In this approach firstly we are storing all powers of 2 upto 29 in a unordered_set in sorted way 
  than we simple sort the given number by converting it into string at end if number is present in 
  set we return true else false  */ 

class Solution {
public:
    unordered_set<string> st;

    void buildSet(){
        for(int i=0;i<=29;i++){
            string powers = to_string((1 << i));
            sort(begin(powers),end(powers));
            st.insert(powers);
        }
    }

    bool reorderedPowerOf2(int n) {
        if(st.empty()){
            buildSet();
        }
        string given = to_string(n);
        sort(begin(given),end(given));
        return st.count(given);
    }
};