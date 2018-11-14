
  int main(int argc, char** argv) {
    
   ..........
   while(x!=xf && y!=yf){
   findnextstep();
   
   robotposition();
   }
   

 }

  



void findnextstep(){
    x1=x-1; 
    y1=y-1;
    vx1=-(xl-x1)^2^0.5;
    vy1=-(yl-y1)^2^0.5;
    v1= vx + vy;
    if (xob1==x1&&yob1==y1)
        v1=-99999999999999999;
     if (xob2==x1&&yob2==y1)
        v1=-99999999999999999;
    
    
    x2=x; 
    y2=y-1;
    vx2=-(xl-x2)^2^0.5;
    vy2=-(yl-y2)^2^0.5;
    v2= vx2 + vy2;
     if (xob2==x2&&yob2==y2)
        v2=-99999999999999999;
 if (xob1==x2&&yob1==y2)
        v2=-99999999999999999;
    
    x3=x+1; 
    y3=y-1;
    vx3=-(xl-x3)^2^0.5;
    vy3=-(yl-y3)^2^0.5;
    v3= vx3 + vy3;
 if (xob1==x3&&yob1==y3)
        v3=-99999999999999999;
 if (xob2==x3&&yob2==y3)
        v3=-99999999999999999;
    x4=x-1; 
    y4=y;
    vx4=-(xl-x4)^2^0.5;
    vy4=-(yl-y4)^2^0.5;
    v4= vx4 + vy4;
     if (xob1==x4&&yob1==y4)
        v4=-99999999999999999;
     if (xob2==x4&&yob2==y4)
        v4=-99999999999999999;

    

    x6=x+1; 
    y6=y;
    vx6=-(xl-x6)^2^0.5;
    vy6=-(yl-y6)^2^0.5;
    v6= vx6 + vy6;
 if (xob1==x6&&yob1==y6)
        v6=-99999999999999999;
 if (xob2==x6&&yob2==y6)
        v6=-99999999999999999;
    
    x7=x-1; 
    y7=y+1;
    vx7=-(xl-x7)^2^0.5;
    vy7=-(yl-y7)^2^0.5;
    v7= vx7 + vy7;
 if (xob1==x7&&yob1==y7)
        v7=-99999999999999999;
 if (xob2==x7&&yob2==y7)
        v7=-99999999999999999;
    x8=x; 
    y8=y+1;
    vx8=-(xl-x8)^2^0.5;
    vy8=-(yl-y8)^2^0.5;
    v8= vx8 + vy8;
 if (xob1==x8&&yob1==y8)
        v8=-99999999999999999;
     if (xob2==x8&&yob2==y8)
        v8=-99999999999999999;

    x9=x+1; 
    y9=y+1;
    vx9=-(xl-x9)^2^0.5;
    vy9=-(yl-y9)^2^0.5;
    v9= vx9 + vy9;
     if (xob9==x9&&yob9==y9)
        v9=-99999999999999999;
     if (xob2==x9&&yob2==y9)
        v9=-99999999999999999;
    
    
    vmax=MAX(v1,v2,v3,v4,v6,v7,v8,v9);
    if(vmax==v1){
        x=x1;
        y=y1;
       printf("POSITION OF robot IS: (%d,%d),this is step %d \n",x1,y1,t);
       t=t+1;
       }
        if(vmax==v2){
        x=x2;
        y=y2;
       printf("POSITION OF robot IS: (%d,%d),this is step %d \n",x2,y2,t);
       t=t+1;
       }
        if(vmax==v3){
        x=x3;
        y=y3;
       printf("POSITION OF robot IS: (%d,%d),this is step %d \n",x3,y3,t);
       t=t+1;
       }
        if(vmax==v4){
        x=x4;
        y=y4;
       printf("POSITION OF robot IS: (%d,%d),this is step %d \n",x4,y4,t);
       t=t+1;
       }
        if(vmax==v5){
        x=x5;
        y=y5;
       printf("POSITION OF robot IS: (%d,%d),this is step %d \n",x5,y5,t);
       t=t+1;
       }
        if(vmax==v6){
        x=x6;
        y=y6;
       printf("POSITION OF robot IS: (%d,%d),this is step %d \n",x6,y6,t);
       t=t+1;
       }
        if(vmax==v7){
        x=x7;
        y=y7;
       printf("POSITION OF robot IS: (%d,%d),this is step %d \n",x7,y7,t);
       t=t+1;
       }
        if(vmax==v8){
        x=x8;
        y=y8;
       printf("POSITION OF robot IS: (%d,%d),this is step %d \n",x8,y8,t);
       t=t+1;
       }
        if(vmax==v9){
        x=x9;
        y=y9;
       printf("POSITION OF robot IS: (%d,%d),this is step %d \n",x9,y9,t);
       t=t+1;
       }
}