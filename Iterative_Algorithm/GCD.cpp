// Pseudo Code for GCD
//     GCD(m, n) {
//         if(m==0) {
//             print "n as GCD"
//         }else if(n==0){
//             print "m as GCD"
//         }else{
//             while(n! =0) {
//                 r = m%n;
//                 m = n;
//                 n = r;
//             }
//             print "m as GCD"
//         }
//     }

#include<iostream>

using namespace std;

void GCD (int m , int n){
    if(m==0) {
        cout<< m <<" is the GCD of above two number"<<endl;
    }
    else if(n==0){
        cout<< n <<" is the GCD of above two numbers"<<endl;
    }
    else{
        while(n!=0){
            int r= m %n;
            m = n;
            n= r;
        }

        cout<< m << " is the GCD of above two numbers "<< endl;
    }
}

int main(){
    int m , n;
    cout<<"Enter the first number:  ";
    cin>>m;
    cout<<"Enter the second number: ";
    cin>>n;

    GCD(m,n);

    return 0;
}
