#include <stdio.h>
#include <math.h>

#define NMAX 1000

typedef struct segment {
  int x1,y1,x2,y2;
} segment;


double dist2(double x1, double y1, double x2, double y2) { 
  return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

double dist_squared(int x, int y, segment s) {
  double l2,t;
  l2 = dist2(s.x1,s.y1,s.x2,s.y2);
  if (l2 == 0) return dist2(x,y,s.x1,s.y1);
  t = ((x - s.x1) * (s.x2 - s.x1) + (y - s.y1) * (s.y2 - s.y1)) / l2;
  if (t < 0) return dist2(x,y,s.x1,s.y1);
  if (t > 1) return dist2(x,y,s.x2,s.y2);
  return dist2(x, y, s.x1 + t * (s.x2 - s.x1), s.y1 + t * (s.y2 - s.y1));
}

double dist_point_segment(int x, int y, segment s) {
  return sqrt(dist_squared(x, y, s)); 
}

int main()
{
  int i,n,l,h;
  double d,diam;
  int x,y,x2,y1,y2;
  int side;
  segment haste_dir,haste_esq,aleta;

  while (scanf("%d",&n)==1) {
    scanf("%d %d", &l, &h);
    haste_esq.x1=0;
    haste_esq.y1=0;
    haste_esq.x2=0;
    haste_esq.y2=h;
    haste_dir.x1=l;
    haste_dir.y1=0;
    haste_dir.x2=l;
    haste_dir.y2=h;
    scanf("%d %d %d", &y1, &x, &y);
    diam=l-x; // primeira haste, esquerda
    side=0;
    for(i=0;i<n-1;++i) {
      scanf("%d %d %d", &y1, &x2, &y2);
      aleta.x2=x2;
      aleta.y2=y2;
      aleta.y1=y1;
      if (side) { // haste esquerda
	aleta.x1=0;
	if (diam>l-x2) {
	  diam=l-x2;
	}
      }
      else { // haste direita
	aleta.x1=l;
	if (diam>x2)    {
	  diam=x2;
	}
      }
      d=dist_point_segment(x,y,aleta);
      if (diam>d) {
      	diam=d;
      }
      x=x2;
      y=y2;
      side=1-side;
    }
    printf("%.2f\n",diam);
  }
  return 0;
}
