 //secant method
 #include<iostream>
 #include<cmath>
 using namespace std;
 
double function(double x){
    // return x*x -  4;
    // return sin(x-4);
    // return log(x)-1;
    
}

 int main()
 {
    double x1,x2,x3,temp1,temp2;
    cout<<"Enter the initial guess: ";
    cin>>x1>>x2;

    while(1){
        if(function(x1)==function(x2)){
            cout<<"Error: Division by zero"<<endl;
            break;
        }
        
        x3 = x1 - (x2-x1)*function(x1)/(function(x2)-function(x1));
        if(fabs(x3-x2)<0.001){
            cout<<"The root is: "<<x3<<endl;
            break;
        }
        x1 = x2;
        x2 = x3;
        if(fabs(x3)<0.001){
            cout<<"The root is: "<<x3<<endl;
            break;
        }
    }
 
    return 0;
 }