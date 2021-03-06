# Vector Addition
vector(x1, y1) and vector(x2, y2)
the sum of two vector: (x1 + x2, y1 + y2)

# Dot product
the dot product of (x1, y1) and (x2, y2) is x1 * x2 + y1 * y2.
We can calculate Cos(0) = (A x B) / (|A| x |B|).

# Line-Point distance
```
//compute the dot product AB . BC
int dot(int[] A, int[] B, int[] C){
    AB = new int[2];
    BC = new int[2];
    AB[0] = B[0] - A[0]; //xB - xA
    AB[1] = B[1] - A[1]; //yB - yA
    BC[0] = C[0] - B[0]; //xC - xB
    BC[1] = C[1] - B[1]; //yC - yB
    int dot = AB[0] * BC[0] + AB[1] * BC[1];
    return dot;
}
//compute the cross product AB x AC 
//used to find direction or 3 three points stays in one line.
int cross(int[] A, int[] B, int[] C){
	AB = new int[2];
	AC = new int[2];
	AB[0] = B[0] - A[0]; // xB - xA
	AB[1] = B[1] - A[1]; // yB - yA
	AC[0] = C[0] - A[0]; // xC - xA
	AC[1] = C[1] - A[1]; // yC - yA
	int cross = AB[0] * AC[1] - AB[1] * AC[0];
}

//Compute the distance from A to B
double distance(int[] A, int[] B){
	int d1 = A[0] - B[0];
	int d2 = A[1] - B[1];
	return sqrt(d1 * d1 + d2 * d2);
}

//Compute the distance from AB to c
//if isSegment is true, AB is a segment, not a line. java
double linePointDist(int[] A, int[] B, int[] C, boolean isSegment){
	double dist = cross(A, B, C) / distance(A, B);
	if(isSegment){
		int dot1 = dot(A, B, C);
		if(dot1 > 0){
			return distance(B, C);
		}
		int dot2 = dot(B, A ,C);
		if(dot2 > 0){
			return distance(A ,C);
		}
	} 
	return abs(dist);
}
// Compute the distance from AB to C with c\c++ operator
double linePointDist(point A, point B, point C, bool isSegment){
	double dist = ((B-A)^(C-A))/sqrt((B-A)(B-A));
	if(isSegment){
		int dot1 = (C - B) * (B - A);
		if(dot1 > 0) return sqrt((B - C) * (B - C));
		int dot2 = (c - A) * (A - B);
		if(dot2 > 0) return sqrt((A - C) * (A - C));
	}
	return abs(dist);
}
//calculate intersect
//cross product
inline int direction(Point &pi, Point &pj, Point &pk) {
	return (pk.x-pi.x)*(pj.y-pi.y)-(pj.x-pi.x)*(pk.y-pi.y);
}

inline bool onsegment(Point &pi, Point &pj, Point &pk) {
	return (inside(min(pi.x,pj.x),pk.x,max(pi.x,pj.x)) && inside(min(pi.y,pj.y),pk.y,max(pi.y,pj.y)));
}

inline bool intersect(Point &p1, Point &p2, Point &p3, Point &p4) {
	int d1, d2, d3, d4;
	d1 = direction(p3, p4, p1);
	d2 = direction(p3, p4, p2);
	d3 = direction(p1, p2, p3);
	d4 = direction(p1, p2, p4);
	if(((d1>0 && d2<0)||(d1<0 && d2>0)) && ((d3>0 && d4<0)||(d3<0 && d4>0))) return true;
	if(!d1 && onsegment(p3, p4, p1)) return true;
	if(!d2 && onsegment(p3, p4, p2)) return true;
	if(!d3 && onsegment(p1, p2, p3)) return true;
	if(!d4 && onsegment(p1, p2, p4)) return true;
	return false;
}

# cirlce area
int pi = 3.14;
int are = pi * r * r; //radius
```

# Polygon area
```
int area = 0;
int N = lengthof(p);
for(int i = 1; i + 1 < N; i++){
	int x1 = p[i][0] - p[0][0];
	int y1 = p[i][1] - p[0][1];
	int x2 = p[i + 1][0] - p[0][0];
	int y2 = p[i + 1][0] - p[0][1];
	int cross = x1 * y2 - x2 * y1;
	area += cross;
}
return abs(area / 2);
```
# Line-Line intersection
Updating

# Finding a Circle From 3 points
Updating

# Reflection
if the line of reflection is given: Ax + By = C
To find a line perdendicular: -Bx + Ay = D.

# Rotation
Updating

# ConvexHull


```
convexHull(point[] X){
	int N = lengthof(X);
	int p = 0;
	//First find the leftmost point
	for(int i = 1; i < N; i++){
		if(X[i] < X[p]){
		 	p = i;
		}
	}
	int start = p;
	do{
		int n = -1;
		for(int i = 0; i < N; i++){
			//Don't go back to the same point you came frome
			if(i == p) continue;

			// if there is no N yet, set it to i
			if(n == -1) n = i;
			int cross = (X[i] - X[p]) x (X[n] - X[p]);
			if(cross < 0){
				//as described above, set N = X
				n = i;
			}
		}
		p = n;
	}while(start != p);
	
}
```

```
//if onEdge is true, use as many points possible for the convexhull, otherwise as few as possible.
convexHull(point[] X, boolean onEdge){
	int N = lengthof(X);
	int p = 0;
	boolean[] used = new boolean[N];
	for(int i = 1; i < N; i++){
		if(X[i] < X[p]){
			p = i;
		}
	}
	int start = p;
	do{
		int n = -1;
		int idst = onEdge ? INF : 0;
		for(int i = 0; i < N; i++){
			//Don't go back to the same point you come from
			if(i == p) continue;
			
			//Don't go to a visited point
			if(used[i]) continue;
			
			//if there is no N yet, set it to X
			if(n == -1) n = i;
			int cross = (X[i] - X[p]) x (X[n] - X[p]);
			
			//d is the distance from P to X
			int d = (X[i] - X[p]) * (X[i] - X[p]);
			if(cross < 0){
				//as descriebd above, set N = X
				n = i;
				dist = d;
			}else if(cross == 0){
				//In this case, both N and X are in the same direction. if onEdge is true pick the closest one, otherwise pick the farthest one.
				if(onEdge && d < dist){
					dist = d;
					n = i;
				}else if(!onEdge && d > dist){
					dist = d;
					n = i;
				}
			}
			p = n;
			used[p] = true;
		}while(start != p);
	}
}
```

*src: Topcoder*