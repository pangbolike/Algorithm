///////////////////////
////author : pangbolike
////for my dear hjr
////^_^
//////////////////////

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const double eps = 1e-8;

int cmp(double x)
{
    if (fabs(x) <= eps) return 0;
    if (x > 0) return 1;
    return -1;
}
inline double sqr(double x)
{
    return x*x;
}
struct point
{
    double x,y;
    point(){}
    point(double a,double b) : x(a),y(b){}
    void input()
    {
        scanf("%lf%lf",&x,&y);
    }
    friend point operator +(const point &a,const point &b)
    {
        return point(a.x+b.x,a.y+b.y);
    }
    friend point operator -(const point &a,const point &b)
    {
        return point(a.x-b.x,a.y-b.y);
    }
    friend bool operator == (const point &a,const point &b)
    {
        return cmp(a.x-b.x) == 0 && cmp(a.y-b.y) == 0;
    }
    point operator *(double len)
    {
        return point(x*len,y*len);
    }
    point operator /(double len)
    {
        return point(x/len,y/len);
    }
    double norm()
    {
        return sqrt(sqr(x) + sqr(y));
    }

    friend bool operator <(const point& a,const point& b)
    {
        return a.x<b.x;
    }
};

double det(const point &a,const point &b)
{
    return a.x*b.y - a.y*b.x;
}
double dot(const point &a,const point &b)
{
    return a.x*b.x + a.y*b.y;
}
double dist(const point &a,const point &b)
{
    return (a-b).norm();
}
void circle_cross_line(const point &a,const point &b, const point &o,double r,point ret[],int &num)
{
    double x0 = o.x,y0=o.y;
    double x1 = a.x,y1 = a.y;
    double x2 = b.x,y2 = b.y;
    double dx = x2 - x1,dy = y2 - y1;
    double A = dx * dx + dy * dy;
    double B = 2 * dx * (x1 - x0) + 2 * dy * (y1 - y0);
    double C = sqr(x1 - x0) + sqr(y1 - y0) - sqr(r);
    double delta = B*B - 4*A*C;
    num = 0;
    if (cmp(delta) >= 0)
    {
        double t1 = (-B - sqrt(delta)) / (2 * A);
        double t2 = (-B + sqrt(delta)) / (2 * A);
        if (cmp(t1 - 1) <= 0 && cmp(t1) >= 0)
        {
            ret[num++] = point(x1 + t1*dx,y1+t1*dy);
        }
        if (cmp(t2 - 1) <= 0 && cmp(t2) >= 0)
        {
            ret[num++] = point(x1 + t2*dx,y1+t2*dy);
        }
        if (num == 2 && ret[0] == ret[1])
            num--;
    }
}




struct circle{
    point c;
    double r;
    void input()
    {
        c.input();
        scanf("%lf",&r);
    }
    circle(){}
    circle(const point& C,double R) : c(C),r(R){}
};


vector<circle> cir;
int n;
point s,t;
vector<point> cross;
double dis_point_segment(const point& pp,const point &ss,const point &tt){
    if (cmp(dot(pp-ss,tt-ss)) < 0) return (pp-ss).norm();
    if (cmp(dot(pp-tt,ss-tt)) < 0) return (pp-tt).norm();
    return fabs(det(ss-pp,tt-pp)/dist(ss,tt));
}
bool checkIsIn(const point &ss,const point& tt)
{
    circle ct;
    for (int i = 0;i < int(cir.size());i++)
    {
        ct = cir[i];
        if (cmp(dis_point_segment(ss,tt,ct.c) - ct.r) <= 0) return true;
    }
    return false;
}
bool checkPointIsIn(const point &pp)
{
    circle ct;
    for (int i = 0;i < int(cir.size());i++)
    {
        ct = cir[i];
        if (cmp(dist(pp,ct.c) - ct.r) <= 0) return true;
    }
    return false;
}
int main()
{
    circle ct;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        ct.input();
        cir.push_back(ct);
    }
    s.input();t.input();
    point p;
    point ret[2];
    int num;
    for (int i=0;i<int(cir.size());i++)
    {
        ct = cir[i];
        circle_cross_line(s,t,ct.c,ct.r,ret,num);
        for (int j=0 ;j<num;j++)
        {
            cross.push_back(ret[j]);
        }
    }
    if (checkPointIsIn(s))
    {
        cross.push_back(s);
    }
    if (checkPointIsIn(t))
    {
        cross.push_back(t);
    }
    sort(cross.begin(),cross.end());
    double ans = 0;
    for (int i=0;i<(int(cross.size()) - 1) ; i++)
    {
        if (checkIsIn(cross[i],cross[i+1]))
            ans  += dist(cross[i],cross[i+1]);
    }
    cout<<ans<<endl;
    return 0;
}