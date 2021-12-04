int superDigit(string n, int k) {
    int t=k;
    long long int number=0;
    for(int i=0;i<n.length();i++)
    {
       number+=  (n[i]-'0'); 
        
    }
    number= number*k;
    long long int newnumber;
    while(true)
    { newnumber=0;
         while(true)
         { newnumber+= number%10;
           number=number/10;
           if(number==0)
             break; 
             
         }
         
        number=newnumber;
        if(newnumber<=9)
         break;
         
    }
    return number;
    

}