#include <iostream>
#include <algorithm>
#include "face_produces_unhappiness.h"


int solve_face_produces_unhappiness(int n, int k, char faces[]) {
  
  int back = 0;
  int face = 0;
  int happiness = 0;
  
  for(int i=0;i<n;i++) {
    if(i==0) {
      if(faces[0] == faces[1] && faces[0] == 'R') {
	happiness++;
      }
      if(faces[0] == 'L' && faces[1] == 'R') {
	back++;
      }
      if(faces[0] == 'R' && faces[1] == 'L') {
	face++;
      }
      continue;
    }
    
    if(i==n-1) {
      if(faces[n-2] == faces[n-1] && faces[n-1] == 'L') {
	happiness++;
      }
      continue;
    }
    
    if((faces[i] == faces[i-1] && faces[i] == 'L') ||
       (faces[i] == faces[i+1] && faces[i] == 'R')) {
      happiness++;
    } else if(faces[i] == 'R' && faces[i+1] == 'L') {
      face++;
    } else if(faces[i] == 'L' && faces[i+1] == 'R') {
      back++;
    }
    
  }

  int unmatch = std::min(face, back);

  if(unmatch >= k) {
    return happiness + k*2;
  }

  // unamatch < k であればunmatch+1 == kもありえる。
  

  return happiness + unmatch * 2 + 1;
}
