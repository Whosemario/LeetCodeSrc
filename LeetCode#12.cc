class Solution {
public:
    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function   
        
        map<int,string> table ;
        table[1]="I";table[4]="IV";table[5]="V";table[9]="IX";table[10]="X";
        table[40]="XL";table[50]="L";table[90]="XC";table[100]="C";
        table[400]="CD";table[500]="D";table[900]="CM";table[1000]="M";
        
        string ret = "";
        int base[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        
        for(int i=0;i<13&&num;i++){
            int n = num/base[i];
            if(n){
                for(int j=0;j<n;j++) ret+=table[base[i]];
            }
            num%=base[i];
        }
        
        return ret;
        
    }
};