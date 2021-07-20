#include<bits/stdc++.h>
using namespace std;
class Point{
	public:
	int x;
	int y;
	Point(int x,int y){
		this->x=x;
		this->y=y;
	}
};
Point po;
void swap(Point &p1, Point &p2){
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}
int distSq(Point p1, Point p2){
    return (p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y);
}
int orientation(Point p, Point q, Point r){
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;  
    return (val > 0)? 1: 2;
}
int cmp(const void *vp1, const void *vp2){ 
   Point *p1 = (Point *)vp1; 
   Point *p2 = (Point *)vp2; 
   int o = orientation(p0, *p1, *p2); 
   if (o == 0) 
     return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1; 
   return (o == 2)? -1: 1; 
}
int main(){
	int n,a,b;
	cin>>n;
	vector<Point> point;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		point.push_back(make_pair(a,b));
	}
	//minimum y point
	Point min(INT_MAX,INT_MAX);
	for(int i=0;i<point.size();i++){
		if(point[min].y>point[i].y){
			if(point[min].x>point[i].x){
				min=i;
			}
		}
	}
	swap(point[0],point[min]);
	po=point[0];
	//sorting point on basis of angle
	qsort(point[1],n-1,sizeof(Point),cmp);
	int m=1;
	for(int i=1;i<n-1;i++){
		while(i<n-1&&orientation(po,point[i],point[i+1])==0){
			i++;
		}
		point[m]=point[i];
		m++;
	}
	if(m<3)	return;
	stack<Point> s;
	s.push(point[0]);
	s.push(point[1]);
	s.push(point[2]);
	for(int i=3;i<m;i++){
		while(orientation(

}
