
// Rat class - a class for rational numbers 
#include <iostream>
using namespace std; 
 
  class Rat{
    //declare n and d. Set to private
    private:
    int n;
    int d;
    
    public:
    // constructors
    // default constructor
    Rat(){
        n=0;
        d=1;
    } 
    // 2 parameter constructor
    Rat(int i, int j){
        n=i;
        d=j;
    } 
    // conversion constructor-can convert ints to rats
    Rat(int i){
        n=i;
        d=1;
    }
    // accessor functions (usually called get() and set(...)  )
    int getN(){ return n;}
    int getD(){ return d;} 
 
    void setN(int i){ n=i;}
    void setD(int i){ d=i;} 
    
    // addition operator
    Rat operator+(Rat r){
        Rat t; //declare temp
        t.n=n*r.d + d*r.n; //bec when you add rationals you do the first numerator(n) times the second denominator(r.d) + the first denominator(d) times the second numerator(r.n) to find the numerator
        t.d=d*r.d; //to find the denominator you do the 2 denominators times eachother
        t.reduce(); //reduce to lowest terms
        return t;
    }
    // subtraction operator
    Rat operator-(Rat r){
      Rat t; //declare a temporary rat called rat t
      t.n=n*r.d - d*r.n; //subtract the rats from eachother and store in n
      t.d=d*r.d; //return the d
      t.reduce(); //reduce to lowest terms
      return t;
    }
    //multiplication
    Rat operator*(Rat r){
      Rat t; //temp
      t.n = n*r.n; //numerator times numerator
      t.d = d*r.d; //denominator times denominator
      t.reduce(); //simplify
      return t;
   }
   //division
   Rat operator/(Rat r){
      Rat t; //temp
      t.n = n*r.d; //numerator times denominator
      t.d = d*r.n; //denominator times numerator
      t.reduce(); //simplify
      return t;
   }
    //finds the gcd
    int gcd(int num, int den){
      int temp; //declare a temp
      while(den!=0){ //while the denominator does not equal 0
        temp=num; //change temp to the value of the numerator
        num=den; //the numerator to the denominator
        den=temp%den; //the denominator to temp mod the denominator
      }
      return num;
    }
    //function to reduce to lowest terms
    void reduce(){
      int theGCD = gcd(n,d); //call the gcd function to find the greatest common divisor and set this value to theGCD
      n=n/theGCD; //set the new value of n to n divided by the gcd 
      d=d/theGCD; //set the new value of d to d divided by the gcd
      //need to make sure the denominator is a positive number
      if (d<0) {
        d=-d;
        n=-n;
      }
    }
    // 2 overloaded i/o operators. friend makes it able to acess things from the class like a member function
    friend ostream& operator<<(ostream& os, Rat r); 
    friend istream& operator>>(istream& is, Rat& r); 
  }; //end Rat 
 
  // operator<<() is NOT a member function but since it was declared a friend of Rat
  // it has access to its private parts. 
  ostream& operator<<(ostream& os, Rat r){
    os<<r.n<<" / "<<r.d<<endl;
    return os;
  } 
  // operator>>() is NOT a member function but since it was declared a friend of Rat
  // it has access to its provate parts. 
  istream& operator>>(istream& is, Rat& r){
    is>>r.n>>r.d;
    return is;
  } 
  int main(){
    Rat x(1,2), y(2,3), z;
    z=x/y;
    cout<<z;
    x.setN(3);
    y.setD(2);
    z=x+y;
    cout<<z; 
    cin>>x;  
    cout<<x; 
    z= x+5;  
    cout<<z;        
    return 0; 
} //main
