#include "Fraction.h"
//here
Fraction::Fraction(string sValue)
{
    bool isNeg = false;
    string tempnum1 = "";
    string tempden1 = "";
     int i=0;
     if (sValue.at(0)=='-'){
         isNeg = true;
         sValue.erase(sValue.begin());
     }
    for(i; sValue[i]!='/' &&i<=sValue.length();i++){
        sValue += sValue[i-1];
       // cout << "this is svalue "<<sValue<<endl;
        //string type num1 = s;
    }
     //cout << "this is svalue "<<sValue<<endl;
    i++;

    for((i+1);sValue[i]!='/';i++){
        tempden1 += sValue[i];

    }
//cout << "this is tempden1 "<<tempden1<<endl;
   // strden1 = tempden1;
    i++;

    //for(i;i<sValue.length();i++){
       // tempnum1 += sValue[i];
    //}
//cout << "this is tempnum1 "<<tempnum1<<endl;
   // strnum1 = tempnum1;

    num1 = atoi(sValue.c_str());
    if (isNeg) num1*(-1);
    //cout << "this is num1" << endl;

    den1 = atoi(tempden1.c_str());
    //cout << "this is den1 "<<den1<<endl;
    this->num1 = num1;
    this->den1 = den1;

    Reduction();

}

int Fraction::getFraction()
{    return iValue;}

int Fraction::getNumerator()
{   return num1; }

int Fraction::getDenominator()
{    return den1;}


 void Fraction::Reduction()
{
     ostringstream convert;

     if(den1 == 0)
    {
        cout << "Cannot solve equation!!!!" << endl; //use throw catch

    }

     for(int i=1;i<=num1 && i<=den1;i++){
    	 if(num1%i==0 && den1%i == 0 ){
               gcd=i;
          }
     }

        lcd = (num1 * den1) / gcd;			//find the The Least Common Denominator
        //cout << "The Least Common Denominator is: "<< lcd << endl;

        //cout<<"Greatest Common Divison (GCD):"<<gcd<<endl;
       
        this->num1 = (num1 / gcd);
        this->den1 = (den1 / gcd);
        //cout<<"this->num1 = (num1 / gcd); is "<<num1<<endl;
        //cout<<" this->den1 = (den1 / gcd); is "<<den1<<endl;

        if(this->den1 == 1){
            convert << this->num1;
           cansimptoInt = true;}
        else{
            convert << this->num1 << "/" << this->den1;
        cansimptoInt = false;}
        //convert << num1 << "/" << den1;
         answer = convert.str();
        
    }
    


void Fraction::Addition(Fraction& fracB){
    if(den1 == 0 || fracB.getDenominator() == 0)
    {
        cout << "Cannot solve equation!!!!" << endl; //use throw catch
        
    }
   for(int i=1;i<=den1 && i<=fracB.getDenominator();i++){
      if(den1%i == 0 && fracB.getDenominator()%i ==0){
    	  	  gcd=i;
       }else{}//do nothing;
   	}
    //cout << "______GCD is: " << gcd << endl;
     lcd = (den1 * (fracB.getDenominator())) / gcd;
     //cout << "The Least Common Denominator is: "<< lcd << endl;


    if((den1/lcd) == 1){
    	cansimptoInt=true;
    }else{
    	cansimptoInt=false;
    }


     a = lcd / den1;
         //cout << a<< endl;
         
     int b = lcd/(fracB.getDenominator());
        
        num1 = a * num1;
        //cout << num1 << endl;

        int num2 = b * fracB.getNumerator();
        //cout <<" int num2 = b * fracB.getNumerator();"<< num2 << endl;

        new_fraction = (num1 + num2);
        
        cout << "new_fraction = (num1 + num2): " <<new_fraction << endl; //can run to here.
     if (new_fraction < lcd){
         //new_fraction = 2;	lcd =3

         //cout << new_fraction << "/" << lcd<< endl;
         for(int i=1;i<=new_fraction && i<=lcd;i++){
    	 if(new_fraction%i==0 && lcd%i == 0 ){
               gcd=i;
          }
         }
         //lcd = (num1 * den1) / gcd;

         this->new_fraction = (new_fraction)/ gcd;
         this->lcd = (lcd)/gcd;

         if(this->lcd == 1){
             ostringstream convert;
             convert << new_fraction;
             answer = convert.str();
         }
         else if(this->lcd != 1){
    	 ostringstream convert;
    	 convert <<new_fraction << "/" << lcd;
    	 answer = convert.str();
         }

    }
     else if (new_fraction > lcd){
         //cout << new_fraction << "/" << lcd << endl;
         for(int i=1;i<=new_fraction && i<=lcd;i++){
    	 if(new_fraction%i==0 && lcd%i == 0 ){
               gcd=i;
          }
         }
         //lcd = (num1 * den1) / gcd;

         this->new_fraction = (new_fraction)/ gcd;
         this->lcd = (lcd)/gcd;


         if(this->lcd == 1){
             ostringstream convert;
             convert << new_fraction;
             answer = convert.str();
         }
         else if(this->lcd != 1){
    	 ostringstream convert;
    	 convert <<new_fraction << "/" << lcd;
    	 answer = convert.str();
         }
//
    }

     else if(new_fraction == lcd){
        cout << "The answer is: 1";
        ostringstream convert;
                convert << "The answer is: 1";
                answer = convert.str();
    }


     else{
        cout << 1;
        ostringstream convert;
        convert << 1;
        answer = convert.str();
    }


        
       
        

        //cout << reduced_num << "/" << reduced_den << endl;
        //cout << new_fraction <<"/"<<lcd<< endl;
        
   
    cout<<"____im finished the fraction add()"<<endl;
}
    
    
    



 void Fraction::Subtraction(Fraction& fracB){
  
    
     if(den1 == 0 || fracB.getDenominator() == 0)
    {
        cout << "Cannot solve equation!!!!" << endl; //use throw catch
        
    }
    
    
        for(int i=1;i<=den1 && i<=fracB.getDenominator();i++){


                if(den1%i == 0 && fracB.getDenominator()%i ==0){

                     gcd=i;

                }

        }
     
   
        
        lcd = (den1 * (fracB.getDenominator())) / gcd;
        
        //cout << "The Least Common Denominator is: "<< lcd << endl;
    
        
        
         a = lcd / den1;
         //cout << a<< endl;

        int b = lcd/(fracB.getDenominator());

        num1 = a * num1;
        //cout << num1 << endl;

        int num2 = b * fracB.getNumerator();

        //cout << num2 << endl;

        
        
        
        
        
       int new_fraction = (num1 - num2);
        
        if(new_fraction == 0){
            ostringstream convert;
            convert << "The answer is: 0";
            answer = convert.str();
            //cout << "The answer is: 0" << endl;
            
        }
        
       if (new_fraction < lcd){
         //new_fraction = 2;	lcd =3

         //cout << new_fraction << "/" << lcd<< endl;
         for(int i=1;i<=new_fraction && i<=lcd;i++){
    	 if(new_fraction%i==0 && lcd%i == 0 ){
               gcd=i;
          }
         }
         //lcd = (num1 * den1) / gcd;

         this->new_fraction = (new_fraction)/ gcd;
         this->lcd = (lcd)/gcd;

         if(this->lcd == 1){
             ostringstream convert;
             convert << new_fraction;
             answer = convert.str();
         }
         else if(this->lcd != 1){
    	 ostringstream convert;
    	 convert <<new_fraction << "/" << lcd;
    	 answer = convert.str();
         }

    }
    else if (new_fraction > lcd){
         //cout << new_fraction << "/" << lcd << endl;
         for(int i=1;i<=new_fraction && i<=lcd;i++){
    	 if(new_fraction%i==0 && lcd%i == 0 ){
               gcd=i;
          }
         }
         //lcd = (num1 * den1) / gcd;

         this->new_fraction = (new_fraction)/ gcd;
         this->lcd = (lcd)/gcd;


         if(this->lcd == 1){
             ostringstream convert;
             convert << new_fraction;
             answer = convert.str();
         }
         else if(this->lcd != 1){
    	 ostringstream convert;
    	 convert <<new_fraction << "/" << lcd;
    	 answer = convert.str();
         }
//
    }
    if(new_fraction == lcd){
        //cout << "The answer is: 1";
        ostringstream convert;
                convert << "The answer is: 1";
                answer = convert.str();
    }
        
       
        
        else{
            ostringstream convert;
            convert << "The answer is: " << new_fraction << "/" << lcd;
            answer = convert.str();
            //cout << "The answer is: " << new_fraction << "/" << lcd << endl;
        }
            
        
        
    }
        
       
    



 void Fraction::Multiplication(Fraction& fracB){
    
     
    
     if(den1 == 0)
    {
        cout << "Cannot solve equation!!!!" << endl;
        
    }
    
    //Multiplication Error!!!! Can someone please solve this??
    final_num = num1 * fracB.getNumerator();
    final_den = den1 * fracB.getDenominator();

    //cout <<"NUM1 and DEN1" << final_num << "/" << final_den << endl;
    

    if (final_num < final_den){
        for(int i=1;i<=final_num && i<=final_den;i++){
    	 if(final_num%i==0 && final_den%i == 0 ){
               gcd=i;
          }
         }
         //lcd = (num1 * den1) / gcd;

         reduced_num = (final_num)/ gcd;
         reduced_den = (final_den)/gcd;

         //cout << reduced_num <<"/"<< reduced_den << endl;
         ostringstream convert;
         convert << reduced_num <<"/"<< reduced_den << endl;
         answer = convert.str();

         if(reduced_den == 1){
             ostringstream convert;
             convert << reduced_num;
             answer = convert.str();
         }
    }

    if (final_num > final_den){
        for(int i=1;i<=final_num && i<=final_den;i++){
    	 if(final_num%i==0 && final_den%i == 0 ){
               gcd=i;
          }
         }
         //lcd = (num1 * den1) / gcd;

         reduced_num = (final_num)/ gcd;
         reduced_den = (final_den)/gcd;

         //cout << reduced_num <<"/"<< reduced_den << endl;
         ostringstream convert;
         convert << reduced_num <<"/"<< reduced_den << endl;
         answer = convert.str();

         if(reduced_den == 1){
             ostringstream convert;
             convert << reduced_num;
             answer = convert.str();
         }
    }
    if(final_num == final_den){
            ostringstream convert;
            convert << 1;
            answer = convert.str();
                //cout << "The answer is: 1";

    }

    
    
    //cout << final_num <<"/"<< final_den << endl;
    
        }


    

void Fraction::Division(Fraction& fracB){
    
    
     if(den1 == 0)
    {
        cout << "Cannot solve equation!!!!" << endl;
        
    }

     //cout <<"fracB.getDenominator is: " << fracB.getDenominator() << endl;
    
     // Division Error!!! Can someone please solve this
    final_num = num1 * fracB.getDenominator();
    final_den = den1 * fracB.getNumerator();

    cout << "FRACTION IS: " << final_num << final_den << endl;
    
    if (final_num < final_den){
        for(int i=1;i<=final_num && i<=final_den;i++){
    	 if(final_num%i==0 && final_den%i == 0 ){
               gcd=i;
          }
         }
         //lcd = (num1 * den1) / gcd;

         reduced_num = (final_num)/ gcd;
         reduced_den = (final_den)/gcd;

         //cout << reduced_num <<"/"<< reduced_den << endl;
         ostringstream convert;
         convert << reduced_num <<"/"<< reduced_den << endl;
         answer = convert.str();

         if(reduced_den == 1){
             ostringstream convert;
             convert << reduced_num;
             answer = convert.str();
         }
    }
    if (final_num > final_den){
        for(int i=1;i<=final_num && i<=final_den;i++){
    	 if(final_num%i==0 && final_den%i == 0 ){
               gcd=i;
          }
         }
         //lcd = (num1 * den1) / gcd;

         reduced_num = (final_num)/ gcd;
         reduced_den = (final_den)/gcd;

         //cout << reduced_num <<"/"<< reduced_den << endl;
         ostringstream convert;
         convert << reduced_num <<"/"<< reduced_den << endl;
         answer = convert.str();

         if(reduced_den == 1){
             ostringstream convert;
             convert << reduced_num;
             answer = convert.str();
         }
    }
    if(final_num == final_den){
            ostringstream convert;
            convert << 1;
            answer = convert.str();
                //cout << "The answer is: 1";

    }

    
        else{
            ostringstream convert;
            convert << final_num << "/" << final_den;
            answer = convert.str();
            //cout << final_num << "/" << final_den << endl;
        }

    
    
    
    }

bool Fraction::canSimplifytoInteger(){
     return cansimptoInt;
 }

//Returns the answer as a string
string Fraction::getAnswer()
{
    //cout<< answer << endl;;
    return answer;
}



