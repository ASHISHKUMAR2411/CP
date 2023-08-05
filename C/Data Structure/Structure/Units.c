#include<stdio.h>
#include<stdlib.h>
struct metric
{
    float m;
    float c;
}p,q;
struct british 
{
    float f;
    float i;
}r,s;
struct metric print(struct metric P);
struct british Print(struct british Q);
void summ(struct metric P,struct british Q);
void sumb(struct metric P,struct british Q);
int main()
{
    p=print(p);
    r=Print(r);
    summ(p,r);
    sumb(p,r);
    return 0;
}
struct metric print(struct metric P)
{
    printf("\n enter the length in m ");
    scanf("%f",&P.m);
    printf("\n enter the remaining length in cm ");
    scanf("%f",&P.c);
    return P;
}
struct british Print(struct british Q)
{
    printf("\n enter the length in foot ");
    scanf("%f",&Q.f);
    printf("\n enter the remaining length in inches ");
    scanf("%f",&Q.i);
    return Q;
}
void summ(struct metric P,struct british Q)
{
    int n ,m;
    q.m = P.m+ (Q.f * 0.305);
    n=(int)q.m;
    q.m = ((int)(q.m*100.00))%100;
    q.c = P.c+ (Q.i * 2.54) + q.m;
    if(q.c>=100.00)
    {
        q.m += ((int)q.c/100) ; 
        q.c = q.c/100; 
    }
    else
    {
        q.c=q.c;
    }
    printf("%d m %f cm ",n,q.c);

}
void sumb(struct metric P,struct british Q)
{
    int n ,m;
    s.f = (P.m/0.305)+ Q.f;
    n=(int)s.f;
    s.f = ((int)(s.f*12))%12;
    s.i = (P.c/2.54) + Q.i  + s.f;
    if(s.i>=12.00)
    {
        s.f += (int)((int)s.i/12) ; 
        s.i = s.i/12; 
    }
    else
    {
        s.i=s.i;
    }
    printf("%d foot %f inches ",n,s.i);
}

