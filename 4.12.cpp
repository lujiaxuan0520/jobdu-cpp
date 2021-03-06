#include<iostream>
#include<math.h>
#include<string>
#include<stdio.h>
using namespace std;
class bigInteger
{
public:
    int digit[1000];
    int size;
    void init()
    {
        for(int i=0;i<1000;i++)
        {
            digit[i]=0;
            size=0;
        }
    }
    void setInteger(string str)
    {
        size=ceil(str.size()/4.0);
        int index=str.size()-4;
        int c=0;
        while(index>=0)
        {
            int q=str[index]-'0';
            int b=str[index+1]-'0';
            int s=str[index+2]-'0';
            int g=str[index+3]-'0';
            int sum=g+s*10+b*100+q*1000;
            digit[c]=sum;
            c++;
            index-=4;
        }
        if(index==-4) return;
        else if(index==-3)
            digit[c]=str[0]-'0';
        else if(index==-2)
            digit[c]=10*(str[0]-'0')+(str[1]-'0');
        else if(index==-1)
            digit[c]=100*(str[0]-'0')+10*(str[1]-'0')+(str[2]-'0');
        return;
    }
    bigInteger operator+(const bigInteger &b)
    {
        int carry=0;
        int maxSize=max(this->size,b.size);
        bigInteger result;
        result.init();
        for(int i=0;i<maxSize;i++)
        {
            int tmp=this->digit[i]+b.digit[i]+carry;
            result.digit[i]=tmp%10000;
            result.size++;
            if(tmp>=10000)
                carry=1;
            else
                carry=0;
        }
        if(carry==1)
        {
            result.digit[maxSize]=1;
            result.size++;
        }

        return result;
    }
    bigInteger operator*(const int &x)
    {
        int carry=0;
        bigInteger result;
        result.init();
        result.size=size;
        for(int i=0;i<size;i++)
        {
            long long sum=x*digit[i]+carry;
            if(sum>=10000)
            {
                result.digit[i]=sum%10000;
                carry=sum/10000;
            }
            else
            {
                result.digit[i]=sum;
                carry=0;
            }
        }
        if(carry!=0)
        {
            result.digit[size]=carry;
            result.size++;
        }
        return result;
    }
    void printInteger()
    {
        for(int i=size-1;i>=0;i--)
        {
            if(i!=size-1)
                printf("%04d",digit[i]);
            else
                cout<<digit[i];
        }
        cout<<endl;
    }
};
int main()
{
    int n;
    while(cin>>n)
    {
        bigInteger x;
        x.init();
        x.setInteger("1");
        for(int i=1;i<=n;i++)
        {
            x=x*i;
        }
        x.printInteger();
    }
    return 0;
}

