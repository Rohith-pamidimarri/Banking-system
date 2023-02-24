#include <iostream>

using namespace std;

class savings{
    int acc;
    float bal;
    float r;
    public:
    savings()
    {
        bal=0;
        acc=0;
        r=0.05;
    }
    int get_acc()
    {
        return acc;
    }
    
    void set_acc(int a)
    {
        acc=a;
    }
    
    float get_bal()
    {
        return bal;
    }
    
    void set_bal(float b)
    {
    	bal=b;
    }
    
    void credit()
    {
        float amt;
        cout<<"ENTER THE AMOUNT:";
        cin>>amt;
        if(amt<0)
        cout<<"pls enter valid amount";
        else
        bal=bal+amt;
    }
    
    void debit()
    {
        int neg;
        cout<<"Enter the amount:";
        cin>>neg;
        if(neg==-1)
             cout<<"pls enter valid amount"<<endl;
        else if(neg>bal)
            cout<<"INSUFFICIENT BALANCE"<<endl;
        else
        bal=bal-neg;
    }
    
    void set_interest()
    {
        float temp;
        cout<<"ENTER THE NEW INTEREST RATE:";
        cin>>temp;
        if(temp==r || temp<0)
            cout<<"INTEREST RATE SHOULD BE NEW AND POSITIVE"<<endl;
        else
            r=temp;
        
    }
    
        
    float interest()
    {
         float temp;
         temp=get_bal();
         temp=(temp*r)/100;
         
         return temp;
    }
    
    float get_inter()
    {
        return r;
    }
    
    void change_nd_update_interest()
    {
         float temp,current;
         temp=get_bal();
         current=(temp*r)/100; 
         
         set_bal(temp+current);
         cout<<get_bal()<<endl;
    }
    
    ~savings()
    {
        
    }

};


class checking
{
      int acc;
      float bal;
      float check_fee;
      
      public:
      
      checking()
      {
          acc=0;
          bal=0;
          check_fee=10;
      }
      
      int get_acc()
      {
          return acc;
      }
      
      void set_acc(int a)
      {
                acc=a;
      }
      
      float get_bal()
      {
           return bal; 
      }
      
      float get_check_fee()
      {
          return check_fee;
      }
      
    void credit()
    {
        float amt;
        cout<<"ENTER THE AMOUNT:";
        cin>>amt;
        if(amt<0 || amt-check_fee<0)
        cout<<"pls enter valid amount";
        else
        bal=bal+amt-check_fee;
    }
      
    void debit()
    {
        int neg;
        cout<<"Enter the amount:";
        cin>>neg;
        if(neg<0)
             cout<<"pls enter valid amount"<<endl;
        else if(neg>bal-check_fee || neg>bal)
            cout<<"INSUFFICIENT BALANCE"<<endl;
        else
        bal=bal-neg-check_fee;
    }
    
    void change_up_fee()
    {
        float temp;
        cout<<"ENTER THE CHECK FEE:";
        cin>>temp;
        if(temp==check_fee || temp<=0 )
            cout<<"CHECK FEE SHOULD BE NEW AND POSITIVE"<<endl;
        else
            check_fee=temp;   
    }
    
        
    void checking_fee()
    {
        cout<<"CHECKING FEE:"<<check_fee<<"/-"<<endl;
    }
  
};

class Acc:public savings,public checking
{
  int ID;
  
  public:
   int count1;
  int count2;
  
  Acc()
  {
      ID=0;
      count1=0;
      count2=0;
  }
  
  void set_id(int id)
  {
      ID=id; 
  }
  
  int get_id()
  {
      return ID;
  }
  
  
    
    
};

int check_id(int id,Acc a[]);
Acc* get_object(int id,Acc a[]);
int check_id_sav(int sav,Acc a[]);
int check_id_che(int sav,Acc a[]);


int main()
{
    
    Acc a[100];
    /*int i;
    for(i=0;i<100;++i)
    {
    	a[i].count1=0;
    	a[i].count2=0;
    }*/
    int n,l;
    int count=0,id;
    Acc *current;
    int temp;
    int sav,flag=0;
    while(1)
    {
        cout<<"ENTER"<<endl<<"1.OPEN ACCOUNT"<<endl<<"2.CREDIT"<<endl<<"3.DEBIT"<<endl<<"4.CHANGE INTEREST"<<endl<<"5.CALCULATE INTEREST"<<endl<<"6.Calculate and Update Interest"<<endl<<"7.Change/Update Fee Amount "<<endl<<"8.Print Checking Fee"<<endl<<"9. Transact and Update"<<endl<<"10.EXIT"<<endl;
        cin>>n;
        
        switch(n)
        {
            case 1:
            cout<<"ENTER"<<endl<<"1.NEW USER"<<endl<<"2.OLD USER"<<endl;
            cin>>l;
            
            if(l==1)
            {
                     cout<<"ENTER YOUR ID:";
                      cin>>id;
                      
                      if(id<=0)
                      {
                        cout<<"PLS ENTER A VALID ID"<<endl;
                        break;
                      }
                      
                      temp=check_id(id,a);
                      
                      if(temp==1)
                      {
                          cout<<"ID HAS ALREADY PRESENT PLEASE A TRY A NEW ONE"<<endl;
                          break;
                      }
                       
                      a[count++].set_id(id);
                      cout<<"CONGRATULATIONS!!!"<<endl<<"YOUR ID IS GENERATED SUCCESSFULLY!!"<<endl<<"NOTE:NOW YOUR A OLD USER OF OUR BANK"<<endl;
                      cout<<"ENTER"<<endl<<"1.SAVINGS"<<endl<<"2.CHECKINGS"<<endl;
                      cin>>l;
                      
                      if(l==1)
                      {
                          current=get_object(id,a);
                          cout<<current->get_id()<<endl;
                          if(current->count1>=1)
                          {
                              cout<<"YOUR SAVINGS ACC'S HAS ALREADY BEEN TAKEN"<<endl<<"THANK YOU"<<endl;
                              break;
                          }
                            cout<<"YOUR ACC NO SHOULD BE OFF THE FORM 1XX"<<endl;
                            cout<<"ENTER YOUR ACC NO:";
                            cin>>sav;
                            
                            if(sav/100!=1 || sav==1)
                            {
                                cout<<"INVALID ACC NO..PLS FOLLOW THE NOTE MENTIONED ABOVE"<<endl;
                                break;
                            }
                             
                            temp=check_id_sav(sav,a);
                            
                            if(temp==1)
                            {
                                cout<<"ACC NO ALREADY EXISTED PLS TRY A NEW ONE"<<endl<<"THANK YOU"<<endl;
                                break;
                            }
                            
                            current->savings::set_acc(sav);
                            current->count1++;
                            cout<<current->count1<<endl;
                            cout<<"CONGRATULATIONS!!!"<<endl<<"YOU SAVINGS ACCOUNT IS CREATED SUCCESSFULLY!!"<<endl;
                           

                      }
                      
                      else if(l==2)
                      {
                          current=get_object(id,a);
                          if(current->count2>=1)
                          {
                              cout<<"YOUR CHECKINGS ACC'S HAS ALREADY BEEN TAKEN"<<endl<<"THANK YOU"<<endl;
                              break;
                          }
                            cout<<"YOUR ACC NO: SHOULD BE OFF THE FORM 2XX"<<endl;
                            cout<<"ENTER YOUR ACC NO:";
                            cin>>sav;
                            
                            if(sav/100!=2 || sav==2)
                            {
                                cout<<"INVALID ACC NO..PLS FOLLOW THE NOTE MENTIONED ABOVE"<<endl;
                                break;
                            }
                             
                            temp=check_id_che(sav,a);
                            
                            if(temp==1)
                            {
                                cout<<"ACC NO ALREADY EXISTED PLS TRY A NEW ONE"<<endl<<"THANK YOU"<<endl;
                                break;
                            }
                            
                            current->checking::set_acc(sav);
                            current->count2++;
                            cout<<"CONGRATULATIONS!!!"<<endl<<"YOUR CHECKINGS ACCOUNT IS CREATED SUCCESSFULLY!!"<<endl;
                           
                          
                      }
                      
                      else
                        cout<<"ENTER A VALID INPUT"<<endl;
                
            }
            
            else if(l==2)
            {
                      cout<<"ENTER YOUR ID:";
                      cin>>id;
                      
                      if(id<=0)
                      {
                        cout<<"PLS ENTER A VALID ID"<<endl;
                        break;
                      }
                      
                      temp=check_id(id,a);
                      
                      if(temp==0)
                      {
                          cout<<"YOUR ID DOES NOT EXIST..PLS CHECK"<<endl;
                          break;
                      }

                      cout<<"ENTER"<<endl<<"1.SAVINGS"<<endl<<"2.CHECKINGS"<<endl;
                      cin>>l;
                      
                      if(l==1)
                      {
                      	
                          current=get_object(id,a);
                          cout<<current->get_id()<<endl;
                          cout<<current->count1<<endl;
                          if(current->count1>=1)
                          {
                              cout<<"YOUR SAVINGS ACC'S HAS ALREADY BEEN TAKEN"<<endl<<"THANK YOU"<<endl;
                              break;
                          }
                            cout<<"YOUR ACC NO SHOULD BE OFF THE FORM 1XX"<<endl;
                            cout<<"ENTER YOUR ACC NO:";
                            cin>>sav;
                            
                            if(sav/100!=1 || sav==1)
                            {
                                cout<<"INVALID ACC NO..PLS FOLLOW THE NOTE MENTIONED ABOVE"<<endl;
                                break;
                            }
                             
                            temp=check_id_sav(sav,a);
                            
                            if(temp==1)
                            {
                                cout<<"ACC NO ALREADY EXISTED PLS TRY A NEW ONE"<<endl<<"THANK YOU"<<endl;
                                break;
                            }
                            
                            current->savings::set_acc(sav);
                           current->count1++;
                             cout<<current->count1<<endl;
                            cout<<"CONGRATULATIONS!!!"<<endl<<"YOU SAVINGS ACCOUNT IS CREATED SUCCESSFULLY!!"<<endl;
                           

                      }
                      
                      else if(l==2)
                      {
                          current=get_object(id,a);
                          if(current->count2>=1)
                          {
                              cout<<"YOUR CHECKINGS ACC'S HAS ALREADY BEEN TAKEN"<<endl<<"THANK YOU"<<endl;
                              break;
                          }
                            cout<<"YOUR ACC NO: SHOULD BE OFF THE FORM 2XX"<<endl;
                            cout<<"ENTER YOUR ACC NO:";
                            cin>>sav;
                            
                            if(sav/100!=2 || sav==2)
                            {
                                cout<<"INVALID ACC NO..PLS FOLLOW THE NOTE MENTIONED ABOVE"<<endl;
                                break;
                            }
                             
                            temp=check_id_che(sav,a);
                            
                            if(temp==1)
                            {
                                cout<<"ACC NO ALREADY EXISTED PLS TRY A NEW ONE"<<endl<<"THANK YOU"<<endl;
                                break;
                            }
                            
                            current->checking::set_acc(sav);
                            current->count2++;
                            cout<<"CONGRATULATIONS!!!"<<endl<<"YOUR CHECKINGS ACCOUNT IS CREATED SUCCESSFULLY!!"<<endl;
                           
                      }
                
                      else
                        cout<<"ENTER A VALID INPUT"<<endl;
                      
                
            }
            
            else
                cout<<"ENTER A VALID INPUT"<<endl;
            break;
                
            case 2:
                      cout<<"ENTER YOUR ID:";
                      cin>>id;
                      
                      if(id<=0)
                      {
                        cout<<"PLS ENTER A VALID ID"<<endl;
                        break;
                      }
                      
                      temp=check_id(id,a);
                      
                      if(temp==0)
                      {
                          cout<<"YOUR ID DOES NOT EXIST..PLS CHECK"<<endl;
                          break;
                      }

                      cout<<"ENTER"<<endl<<"1.SAVINGS"<<endl<<"2.CHECKINGS"<<endl;
                      cin>>l;
                      
                      if(l==1)
                      {
                          current=get_object(id,a);
                          if(current->count1==0)
                          {
                              cout<<"YOU DO NOT HAVE A SAVINGS ACC"<<endl<<"PLS CREATE YOUR SAVINGS ACCOUNT FIRST"<<endl;
                              break;
                          }
                          cout<<"ENTER YOUR ACC NO:";
                            cin>>sav;
                             
                            temp=check_id_sav(sav,a);
                            
                            if(temp==0 || current->savings::get_acc()!=sav)
                            {
                                if(temp==0)
                                    cout<<"YOUR ACC.NO DOES NOT EXIST"<<endl;
                                else
                                    cout<<"YOUR ACC.NO:DOES NOT MATCH WITH YOUR ID"<<endl;
                                break;
                            }
                          current->savings::credit();
                      }
                      
                      else if(l==2)
                      {
                          current=get_object(id,a);
                           if(current->count2==0)
                          {
                              cout<<"YOU DO NOT HAVE A CHECKING ACC"<<endl<<"PLS CREATE YOUR CHECKINGS ACCOUNT FIRST"<<endl;
                              break;
                          }
                          cout<<"ENTER YOUR ACC NO:";
                            cin>>sav;
                             
                            temp=check_id_che(sav,a);
                            
                            if(temp==0 || current->checking::get_acc()!=sav)
                            {
                                if(temp==0)
                                    cout<<"YOUR ACC.NO DOES NOT EXIST"<<endl;
                                else
                                    cout<<"YOUR ACC.NO:DOES NOT MATCH WITH YOUR ID"<<endl;
                                break;
                            }
                          current->checking::credit();
                      }
                      
                      else
                        cout<<"PLS ENTER A VALID INPUT"<<endl;
                    break;
                    
            case 3:
                      cout<<"ENTER YOUR ID:";
                      cin>>id;
                      
                      if(id<=0)
                      {
                        cout<<"PLS ENTER A VALID ID"<<endl;
                        break;
                      }
                      
                      temp=check_id(id,a);
                      
                      if(temp==0)
                      {
                          cout<<"YOUR ID DOES NOT EXIST..PLS CHECK"<<endl;
                          break;
                      }

                      cout<<"ENTER"<<endl<<"1.SAVINGS"<<endl<<"2.CHECKINGS"<<endl;
                      cin>>l;
                      
                      if(l==1)
                      {
                          current=get_object(id,a);
                          if(current->count1==0)
                          {
                              cout<<"YOU DO NOT HAVE A SAVINGS ACC"<<endl<<"PLS CREATE YOUR SAVINGS ACCOUNT FIRST"<<endl;
                              break;
                          }
                          cout<<"ENTER YOUR ACC NO:";
                            cin>>sav;
                             
                            temp=check_id_sav(sav,a);
                            
                            if(temp==0 || current->savings::get_acc()!=sav)
                            {
                                if(temp==0)
                                    cout<<"YOUR ACC.NO DOES NOT EXIST"<<endl;
                                else
                                    cout<<"YOUR ACC.NO:DOES NOT MATCH WITH YOUR ID"<<endl;
                                break;
                            }
                          current->savings::debit();
                      }
                      
                      else if(l==2)
                      {
                          current=get_object(id,a);
                          if(current->count2==0)
                          {
                              cout<<"YOU DO NOT HAVE A CHECKING ACC"<<endl<<"PLS CREATE YOUR CHECKINGS ACCOUNT FIRST"<<endl;
                              break;
                          }
                          cout<<"ENTER YOUR ACC NO:";
                            cin>>sav;
                             
                            temp=check_id_sav(sav,a);
                            
                            if(temp==0 || current->checking::get_acc()!=sav)
                            {
                                if(temp==0)
                                    cout<<"YOUR ACC.NO DOES NOT EXIST"<<endl;
                                else
                                    cout<<"YOUR ACC.NO:DOES NOT MATCH WITH YOUR ID"<<endl;
                                break;
                            }
                          current->checking::debit();
                      }
                      
                      else
                        cout<<"PLS ENTER A VALID INPUT"<<endl;
                    break;
                    
            case 4:
                    cout<<"ENTER YOUR ID:";
                      cin>>id;
                      
                      if(id<=0)
                      {
                        cout<<"PLS ENTER A VALID ID"<<endl;
                        break;
                      }
                      
                      temp=check_id(id,a);
                      
                      if(temp==0)
                      {
                          cout<<"YOUR ID DOES NOT EXIST..PLS CHECK"<<endl;
                          break;
                      }
                      
                      current=get_object(id,a);
                      if(current->count1==0)
                          {
                              cout<<"YOU DO NOT HAVE A SAVINGS ACC"<<endl<<"PLS CREATE YOUR SAVINGS ACCOUNT FIRST"<<endl;
                              break;
                          }
                          cout<<"ENTER YOUR ACC NO:";
                            cin>>sav;
                             
                            temp=check_id_sav(sav,a);
                            
                            if(temp==0 || current->savings::get_acc()!=sav)
                            {
                                if(temp==0)
                                    cout<<"YOUR ACC.NO DOES NOT EXIST"<<endl;
                                else
                                    cout<<"YOUR ACC.NO:DOES NOT MATCH WITH YOUR ID"<<endl;
                                break;
                            }
                      current->savings::set_interest();
                      
                      break;
                      
            case 5:
                      cout<<"ENTER YOUR ID:";
                      cin>>id;
                      
                      if(id<=0)
                      {
                        cout<<"PLS ENTER A VALID ID"<<endl;
                        break;
                      }
                      
                      temp=check_id(id,a);
                      
                      if(temp==0)
                      {
                          cout<<"YOUR ID DOES NOT EXIST..PLS CHECK"<<endl;
                          break;
                      }
                      
                      current=get_object(id,a);
                      if(current->count1==0)
                          {
                              cout<<"YOU DO NOT HAVE A SAVINGS ACC"<<endl<<"PLS CREATE YOUR SAVINGS ACCOUNT FIRST"<<endl;
                              break;
                          }
                          cout<<"ENTER YOUR ACC NO:";
                            cin>>sav;
                             
                            temp=check_id_sav(sav,a);
                            
                            if(temp==0 || current->savings::get_acc()!=sav)
                            {
                                if(temp==0)
                                    cout<<"YOUR ACC.NO DOES NOT EXIST"<<endl;
                                else
                                    cout<<"YOUR ACC.NO:DOES NOT MATCH WITH YOUR ID"<<endl;
                                break;
                            }
                      cout<<"INTEREST:"<<current->savings::interest()<<endl;
                      break;
                      
            
            case 6:
                      cout<<"ENTER YOUR ID:";
                      cin>>id;
                      
                      if(id<=0)
                      {
                        cout<<"PLS ENTER A VALID ID"<<endl;
                        break;
                      }
                      
                      temp=check_id(id,a);
                      
                      if(temp==0)
                      {
                          cout<<"YOUR ID DOES NOT EXIST..PLS CHECK"<<endl;
                          break;
                      }
                      
                      current=get_object(id,a);
                      if(current->count1==0)
                          {
                              cout<<"YOU DO NOT HAVE A SAVINGS ACC"<<endl<<"PLS CREATE YOUR SAVINGS ACCOUNT FIRST"<<endl;
                              break;
                          }
                          cout<<"ENTER YOUR ACC NO:";
                            cin>>sav;
                             
                            temp=check_id_sav(sav,a);
                            
                            if(temp==0 || current->savings::get_acc()!=sav)
                            {
                                if(temp==0)
                                    cout<<"YOUR ACC.NO DOES NOT EXIST"<<endl;
                                else
                                    cout<<"YOUR ACC.NO:DOES NOT MATCH WITH YOUR ID"<<endl;
                                break;
                            }
                      current->savings::change_nd_update_interest();
                      
                      break;
            
            case 7:
                      cout<<"ENTER YOUR ID:";
                      cin>>id;
                      
                      if(id<=0)
                      {
                        cout<<"PLS ENTER A VALID ID"<<endl;
                        break;
                      }
                      
                      temp=check_id(id,a);
                      
                      if(temp==0)
                      {
                          cout<<"YOUR ID DOES NOT EXIST..PLS CHECK"<<endl;
                          break;
                      }
                      
                      current=get_object(id,a);
                       if(current->count2==0)
                          {
                              cout<<"YOU DO NOT HAVE A CHECKING ACC"<<endl<<"PLS CREATE YOUR CHECKINGS ACCOUNT FIRST"<<endl;
                              break;
                          }
                          cout<<"ENTER YOUR ACC NO:";
                            cin>>sav;
                             
                            temp=check_id_che(sav,a);
                            
                            if(temp==0 || current->checking::get_acc()!=sav)
                            {
                                if(temp==0)
                                    cout<<"YOUR ACC.NO DOES NOT EXIST"<<endl;
                                else
                                    cout<<"YOUR ACC.NO:DOES NOT MATCH WITH YOUR ID"<<endl;
                                break;
                            }
                      current->checking::change_up_fee();
                      break;
            
            case 8:
                      cout<<"ENTER YOUR ID:";
                      cin>>id;
                      
                      if(id<=0)
                      {
                        cout<<"PLS ENTER A VALID ID"<<endl;
                        break;
                      }
                      
                      temp=check_id(id,a);
                      
                      if(temp==0)
                      {
                          cout<<"YOUR ID DOES NOT EXIST..PLS CHECK"<<endl;
                          break;
                      }
                      
                      current=get_object(id,a);
                       if(current->count2==0)
                          {
                              cout<<"YOU DO NOT HAVE A CHECKING ACC"<<endl<<"PLS CREATE YOUR CHECKINGS ACCOUNT FIRST"<<endl;
                              break;
                          }
                          cout<<"ENTER YOUR ACC NO:";
                            cin>>sav;
                             
                            temp=check_id_che(sav,a);
                            
                            if(temp==0 || current->checking::get_acc()!=sav)
                            {
                                if(temp==0)
                                    cout<<"YOUR ACC.NO DOES NOT EXIST"<<endl;
                                else
                                    cout<<"YOUR ACC.NO:DOES NOT MATCH WITH YOUR ID"<<endl;
                                break;
                            }
                      cout<<"CHECKING FEE:"<<current->checking::get_check_fee()<<endl;
                      break;
            
            case 9:
                      cout<<"ENTER YOUR ID:";
                      cin>>id;
                      
                      if(id<=0)
                      {
                        cout<<"PLS ENTER A VALID ID"<<endl;
                        break;
                      }
                      
                      temp=check_id(id,a);
                      
                      if(temp==0)
                      {
                          cout<<"YOUR ID DOES NOT EXIST..PLS CHECK"<<endl;
                          break;
                      }
                      
                      current=get_object(id,a);
                      if(current->count1!=0)
                      {
                          cout<<"SAVINGS ACC NO:"<<current->savings::get_acc()<<endl;
                          cout<<"BALANCE:"<<current->savings::get_bal()<<endl;
                          cout<<"INTEREST RATE:"<<current->savings::get_inter()<<endl;
                      }
                      
                      if(current->count2!=0)
                      {
                          cout<<"CHECKING ACC NO:"<<current->checking::get_acc()<<endl;
                          cout<<"BALANCE:"<<current->checking::get_bal()<<endl;
                          cout<<"CHECKING FEE:"<<current->checking::get_check_fee()<<endl;
                          
                      }
                      
                      if(current->count1==0)
                      {
                          cout<<"USER DOES NOT HAVE A SAVINGS ACCOUNT"<<endl;
                          
                      }
                      
                      if(current->count2==0)
                      {
                          cout<<"USER DOES NOT HAVE A CHECKINGS ACCOUNT"<<endl;
                      }
            
                    break;
                    
            case 10:
                    flag=1;
                    break;
            
        }
        
        if(flag==1)
            break;
    }
    
    

    return 0;
}

int check_id(int id,Acc a[])
{
    int i;
    for(i=0;i<100;++i)
    {
        if(id==a[i].get_id())
         return 1;
    }
    
    return 0;
}

Acc* get_object(int id,Acc a[])
{
    int i;
    
    for(i=0;i<100;++i)
    {
        if(id==a[i].get_id())
             return (&a[i]);
    }
    
    return &a[0];
}

int check_id_sav(int sav,Acc a[])
{
    int i;
    for(i=0;i<100;++i)
    {
        if(sav==a[i].savings::get_acc())
            return 1;
    }
    
    return 0;
}

int check_id_che(int sav,Acc a[])
{
    int i;
    for(i=0;i<100;++i)
    {
        if(sav==a[i].checking::get_acc())
            return 1;
    }
    
    return 0;
    
}
