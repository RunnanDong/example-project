/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Toothless521
 *
 * Created on 2016年12月8日, 上午1:09
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <ctype.h>
#include <limits.h>
#define ARRAYSIZE 100

typedef struct total_graph_inf{
    int firstobstacledir1;
    int firstobstacledir2;
    int secondobstacledir1;
    int secondobstacledir2;
    int speed_of_obstacle;
    int speed_of_obstacle2;
    int ROOM_SIZE;
    int initialpositionofrobot1, initialpositionofrobot2;
    int finalpositionofrobot1, finalpositionofrobot2;
    int leftpositionofob1, rightpositionofob1;
    int leftpositionofob2;
    int rightpositionofob2;
    int distanceObs1;//distance between wall and obs
    int distanceObs2;
    int x_changing;
    int y_changing;
}graph_inf;
typedef struct ArrayForgraph{
    graph_inf array[ARRAYSIZE];
} ArrayForGraph_inf;


enum error {
    INCORRECT_NUMBER_OF_COMMAND_LINE_ARGUMENTS = 1,
    FILE_FAILED_TO_OPEN,
    FILE_FAILED_TO_CLOSE,
    PARSING_ERROR_INVALID_FORMAT,
    PARSING_ERROR_EMPTY_FILE,
    INTEGER_IS_NOT_A_VERTEX,
};
int count=0;
int x,y,x1,y1,vx1,vy1,v1,x2,y2,vx2,vy2,v2;
int x3,y3,vx3,vy3,v3;
int x4,y4,vx4,vy4,v4;
int x7,y7,vx7,vy7,v7;
int x6,y6,vx6,vy6,v6;
int x8,y8,vx8,vy8,v8;
int x9,y9,vx9,vy9,v9;
int xl,yl;
int xob1,yob1;
int xob2,yob2;
int vmax;
int t=0;


void parse_getlineforrobot(FILE* fp,ArrayForGraph_inf graphInfunction[ARRAYSIZE]);
void obs1Position_distance(ArrayForGraph_inf graphInfunction[ARRAYSIZE]);
void obs2Position_distance(ArrayForGraph_inf graphInfunction[ARRAYSIZE]);
void obsPosition_direction(ArrayForGraph_inf graphInfunction[ARRAYSIZE]);
void obs2Position_direction(ArrayForGraph_inf graphInfunction[ARRAYSIZE]);
void findnextstep(ArrayForGraph_inf graphInfunction[ARRAYSIZE]);
/*
 * 
 */

  int main(int argc, char** argv) {
   ArrayForGraph_inf graphInfunction[ARRAYSIZE];
   unsigned int answer;
   
    //printf("(%d,%d)"graphInfunction[0].array[0].x_changing,graphInfunction[0].array[0].y_changing);
    if (argc != 2){
         exit(1);
    }
    FILE* fp = fopen(argv[1], "r");
    
    if (!fp)
    {
        printf("1,FILE_FAILED_TO_OPEN\n");
        exit(1);
    }
    
   parse_getlineforrobot(fp,graphInfunction);
   //printROOM_SIZE();
   //printf("*************************************************************************************************\n");
   /*printf("Now ROOM SIZE IS: %d * %d\n", graphInfunction[0].array[0].ROOM_SIZE,graphInfunction[0].array[0].ROOM_SIZE);
   printf("Initial position of bots: (%d,%d)\n",graphInfunction[0].array[0].initialpositionofrobot1,graphInfunction[0].array[0].initialpositionofrobot2);
   printf("final position of bots: (%d,%d)\n",  graphInfunction[0].array[0].finalpositionofrobot1,graphInfunction[0].array[0].finalpositionofrobot2);
   printf("position of obstacle1 is: (%d,%d)\n",graphInfunction[0].array[0].leftpositionofob1,graphInfunction[0].array[0].rightpositionofob1);
   printf("SPEED OF OBSTACLE IS: %d\n",graphInfunction[0].array[0].speed_of_obstacle);
   printf("direction of obstacle1 is :(%d,%d)\n",graphInfunction[0].array[0].firstobstacledir1,graphInfunction[0].array[0].firstobstacledir2);
   printf("POSITION OF OBSTACLE2 IS: (%d,%d)\n",graphInfunction[0].array[0].leftpositionofob2, graphInfunction[0].array[0].rightpositionofob2);
   printf("SPEED OF OBSTACLE2 IS %d\n", graphInfunction[0].array[0].speed_of_obstacle2);
   printf("direction of obstacle2 is :(%d,%d)\n",graphInfunction[0].array[0].secondobstacledir1, graphInfunction[0].array[0].secondobstacledir2);
    */
    
   obs1Position_distance(graphInfunction);
   obs2Position_distance(graphInfunction);
   //printf("Now obs1 is %d\nobs2 is %d\n", graphInfunction[0].array[0].distanceObs1,graphInfunction[0].array[0].distanceObs2);
   printf("\n\n");
   printf("\nOpstacle1's moving path:\n");
   obsPosition_direction(graphInfunction);
   printf("*************************************************************************************************\n");
   printf("\nOpstacle2's moving path:\n");
   obs2Position_direction(graphInfunction);
   //int x;
   //for(x=0;x<10;x++){
      // printf("(%d,%d)\n",graphInfunction[x].array[0].leftpositionofob1,graphInfunction[x].array[0].rightpositionofob1);
   //}
    graphInfunction[0].array[0].x_changing=graphInfunction[0].array[0].initialpositionofrobot1;
    graphInfunction[0].array[0].y_changing=graphInfunction[0].array[0].initialpositionofrobot2;
     printf("\nRobts moving path:\n");
   while (graphInfunction[0].array[0].x_changing != graphInfunction[0].array[0].finalpositionofrobot1 || graphInfunction[0].array[0].y_changing!= graphInfunction[0].array[0].finalpositionofrobot2) {
        
       findnextstep(graphInfunction);
       count++;
   }
  }

  

void parse_getlineforrobot(FILE* fp,ArrayForGraph_inf graphInfunction[ARRAYSIZE])
{
    signed int firstobstacledir1;
    signed int firstobstacledir2;
    signed int secondobstacledir1;
    signed int secondobstacledir2;
    int count=0;
    int speed_of_obstacle;
    int speed_of_obstacle2;
    char* line = NULL;
    unsigned int ROOM_SIZE;
    int initialpositionofrobot1, initialpositionofrobot2;
    int finalpositionofrobot1, finalpositionofrobot2;
    int leftpositionofob1, rightpositionofob1;
    int leftpositionofob2;
    int rightpositionofob2;
    char **endptr=NULL;
    int j,k;
    char directionofob1[2];
    //int i=1;
    
    //Check if file is empty
    int c = fgetc(fp);
    if (c==EOF)
       exit(PARSING_ERROR_EMPTY_FILE);
    ungetc(c,fp);
	
    size_t nbytes = 0;
    int linelen=0;



    // Read the number of vertices. 
     linelen = getline(&line, &nbytes, fp);
    
    // EmptyLine
     if (linelen == -1) 
        {exit(PARSING_ERROR_INVALID_FORMAT);}

    // Removing the newline and adding the NULL character
     line[linelen-1] = '\0';
    
    // Check that everything on the line is a digit
     j = 1;
     
     while (j< linelen -1)
      if (isdigit(line[j++])==0)
         exit(PARSING_ERROR_INVALID_FORMAT);
      
     
    //Compute the number of vertices
    ROOM_SIZE = strtoumax(line,endptr,0);
    
    //Check that number of vertices are >0
    if (ROOM_SIZE==0){
        exit(PARSING_ERROR_INVALID_FORMAT);
    }
    
    graphInfunction[0].array[0].ROOM_SIZE=ROOM_SIZE;
    printf("ROOM SIZE IS: %d * %d\n", ROOM_SIZE, ROOM_SIZE);
      // Initialize the graph.
    //Read in the edges.
     if((linelen=getline(&line, &nbytes, fp)) != -1)
    {
        line[linelen-1] = '\0'; //removing the newline and adding the NULL character
        //printf("%s\n", line);
        //First character has to be a (
       
        if (line[0] != '(')
           exit(PARSING_ERROR_INVALID_FORMAT);

        //Second character is a digit
        j = 1;
        if (isdigit(line[j++])==0)
            exit(PARSING_ERROR_INVALID_FORMAT);
        
        // Check that everything before a , is a digit
        while ((j< linelen -1) && (line[j] != ','))
            if (isdigit(line[j++])==0)
               exit(PARSING_ERROR_INVALID_FORMAT);
        
        
        
        //This is the starting point of the edge
         initialpositionofrobot1=strtoumax(&line[1],endptr,0);
        
        //Check that the starting point is a legitimate vertex
         if ((initialpositionofrobot1>ROOM_SIZE) || (initialpositionofrobot1==0))
             exit(INTEGER_IS_NOT_A_VERTEX);
        
         
        k=++j;
        
        //Check if you reached the end of line and if the charatcer after the , is a digit
        if (isdigit(line[j++])==0)
           exit(PARSING_ERROR_INVALID_FORMAT);
    
        // Check that everything before a ) is a digit
         while ((j< linelen -1) && line[j] != ')')
           if (isdigit(line[j++])==0)
               exit(PARSING_ERROR_INVALID_FORMAT);
        
       
        
        // Check if there is a )
        if (line[j] != ')')
            exit(PARSING_ERROR_INVALID_FORMAT);
        
        //Check that the line ends at )
        if (line[j+1]!='\0')
           exit(PARSING_ERROR_INVALID_FORMAT);
        
       //This is the starting point of the edge
         initialpositionofrobot2=strtoumax(&line[k],endptr,0);
       
        //Check that the starting point is a legitimate vertex
        if ((initialpositionofrobot2>ROOM_SIZE)||(initialpositionofrobot2==0))
            exit(INTEGER_IS_NOT_A_VERTEX);
       graphInfunction[0].array[0].initialpositionofrobot1=initialpositionofrobot1;
       graphInfunction[0].array[0].initialpositionofrobot2=initialpositionofrobot2;
       printf("Initial position of bots: (%d,%d)\n",  initialpositionofrobot1,  initialpositionofrobot2);
       
       //Insert the edge*/
 }
    
      if((linelen=getline(&line, &nbytes, fp)) != -1)
    {
        line[linelen-1] = '\0'; //removing the newline and adding the NULL character
        //printf("%s\n", line);
        //First character has to be a (
       
        if (line[0] != '(')
           exit(PARSING_ERROR_INVALID_FORMAT);

        //Second character is a digit
        j = 1;
        if (isdigit(line[j++])==0)
            exit(PARSING_ERROR_INVALID_FORMAT);
        
        // Check that everything before a , is a digit
        while ((j< linelen -1) && (line[j] != ','))
            if (isdigit(line[j++])==0)
               exit(PARSING_ERROR_INVALID_FORMAT);
        
        
        
        //This is the starting point of the edge
         finalpositionofrobot1=strtoumax(&line[1],endptr,0);
        
        //Check that the starting point is a legitimate vertex
         if ((finalpositionofrobot1>ROOM_SIZE) || (finalpositionofrobot1==0))
             exit(INTEGER_IS_NOT_A_VERTEX);
        
         
        k=++j;
        
        //Check if you reached the end of line and if the charatcer after the , is a digit
        if (isdigit(line[j++])==0)
           exit(PARSING_ERROR_INVALID_FORMAT);
    
        // Check that everything before a ) is a digit
         while ((j< linelen -1) && line[j] != ')')
           if (isdigit(line[j++])==0)
               exit(PARSING_ERROR_INVALID_FORMAT);
        
       
        
        // Check if there is a )
        if (line[j] != ')')
            exit(PARSING_ERROR_INVALID_FORMAT);
        
        //Check that the line ends at )
        if (line[j+1]!='\0')
           exit(PARSING_ERROR_INVALID_FORMAT);
        
       //This is the starting point of the edge
         finalpositionofrobot2=strtoumax(&line[k],endptr,0);
       
        //Check that the starting point is a legitimate vertex
        if ((finalpositionofrobot2>ROOM_SIZE)||(finalpositionofrobot2==0))
            exit(INTEGER_IS_NOT_A_VERTEX);
       graphInfunction[0].array[0].finalpositionofrobot1=finalpositionofrobot1;
       graphInfunction[0].array[0].finalpositionofrobot2=finalpositionofrobot2;       
       printf("final position of bots: (%d,%d)\n",  finalpositionofrobot1,finalpositionofrobot2);
       
       //Insert the edge*/
   }
    
    
    
       if((linelen=getline(&line, &nbytes, fp)) != -1)
    {
        line[linelen-1] = '\0'; //removing the newline and adding the NULL character
        //printf("%s\n", line);
        //First character has to be a (
       
        if (line[0] != '(')
           exit(PARSING_ERROR_INVALID_FORMAT);

        //Second character is a digit
        j = 1;
        if (isdigit(line[j++])==0)
            exit(PARSING_ERROR_INVALID_FORMAT);
        
        // Check that everything before a , is a digit
        while ((j< linelen -1) && (line[j] != ','))
            if (isdigit(line[j++])==0)
               exit(PARSING_ERROR_INVALID_FORMAT);
        
        
        
        //This is the starting point of the edge
         leftpositionofob1=strtoumax(&line[1],endptr,0);
        
        //Check that the starting point is a legitimate vertex
         if ((leftpositionofob1>ROOM_SIZE) || (leftpositionofob1==0))
             exit(INTEGER_IS_NOT_A_VERTEX);
        
         
        k=++j;
        
        //Check if you reached the end of line and if the charatcer after the , is a digit
        if (isdigit(line[j++])==0)
           exit(PARSING_ERROR_INVALID_FORMAT);
    
        // Check that everything before a ) is a digit
         while ((j< linelen -1) && line[j] != ')')
           if (isdigit(line[j++])==0)
               exit(PARSING_ERROR_INVALID_FORMAT);
        
       
        
        // Check if there is a )
        if (line[j] != ')')
            exit(PARSING_ERROR_INVALID_FORMAT);
        
        //Check that the line ends at )
        if (line[j+1]!='\0')
           exit(PARSING_ERROR_INVALID_FORMAT);
        
       //This is the starting point of the edge
         rightpositionofob1=strtoumax(&line[k],endptr,0);
       
        //Check that the starting point is a legitimate vertex
        if ((rightpositionofob1>ROOM_SIZE)||(rightpositionofob1==0))
            exit(INTEGER_IS_NOT_A_VERTEX);
       graphInfunction[0].array[0].leftpositionofob1=leftpositionofob1;
       graphInfunction[0].array[0].rightpositionofob1=rightpositionofob1;
       printf("position of obstacle1 is: (%d,%d)\n",leftpositionofob1,rightpositionofob1);
       
       //Insert the edge*/
   }
    
     linelen = getline(&line, &nbytes, fp);
     
      if (linelen == -1) 
        {exit(PARSING_ERROR_INVALID_FORMAT);}

    // Removing the newline and adding the NULL character
     line[linelen-1] = '\0';
     
    // Check that everything on the line is a digit
     j = 1;
    
     while (j< linelen -1)
      if (isdigit(line[j++])==0)
         exit(PARSING_ERROR_INVALID_FORMAT);
      
     
    //Compute the number of vertices
    speed_of_obstacle = strtoumax(line,endptr,0);
    
    //Check that number of vertices are >0
    if ( speed_of_obstacle==0)
        exit(PARSING_ERROR_INVALID_FORMAT);
    
    graphInfunction[0].array[0].speed_of_obstacle=speed_of_obstacle;
    printf("SPEED OF OBSTACLE1 IS: %d\n",graphInfunction[0].array[0].speed_of_obstacle);
     

   
  linelen=getline(&line, &nbytes, fp);
  
  if(linelen<7 || linelen>8)
  {
      exit(PARSING_ERROR_INVALID_FORMAT);
  }
  else
  {
      line[linelen-1]='\0';
      if(line[0]!='(')
      {exit(PARSING_ERROR_INVALID_FORMAT);}
      
   
    firstobstacledir1=strtoumax(&line[1],endptr,0);
          
         
      
      //printf("%d\n", firstobstacledir1);
      if (firstobstacledir1!=0 && firstobstacledir1!=+1 && firstobstacledir1!=-1)
      {
          exit(INTEGER_IS_NOT_A_VERTEX);
      }
      if(firstobstacledir1==0)
      {
          if(line[2]!=',')
          {exit(PARSING_ERROR_INVALID_FORMAT);}
          firstobstacledir2=strtoumax(&line[3],endptr,0);
          //printf("%d\n", firstobstacledir2);
      
      }
      else if(firstobstacledir1==1 || firstobstacledir1==-1)
      {
          if(line[3]!=',')
          {exit(PARSING_ERROR_INVALID_FORMAT);}
          firstobstacledir2=strtoumax(&line[4],endptr,0);
          //printf("%d\n", firstobstacledir2);
      }
    graphInfunction[0].array[0].firstobstacledir1=firstobstacledir1;
    graphInfunction[0].array[0].firstobstacledir2=firstobstacledir2;
    printf("direction of obstacle1 is :(%d,%d)\n",  firstobstacledir1, firstobstacledir2);
      //if(isdigit)
      
      
      
      
    free(line);
  }
  linelen=getline(&line, &nbytes, fp);
  if(linelen==-1)
  {exit(PARSING_ERROR_INVALID_FORMAT);}
  else
  {
      
        line[linelen-1] = '\0'; //removing the newline and adding the NULL character
        //printf("%s\n", line);
        //First character has to be a (
       
        if (line[0] != '(')
           exit(PARSING_ERROR_INVALID_FORMAT);

        //Second character is a digit
        j = 1;
        if (isdigit(line[j++])==0)
            exit(PARSING_ERROR_INVALID_FORMAT);
        
        // Check that everything before a , is a digit
        while ((j< linelen -1) && (line[j] != ','))
            if (isdigit(line[j++])==0)
               exit(PARSING_ERROR_INVALID_FORMAT);
        
        
        
        //This is the starting point of the edge
         leftpositionofob2=strtoumax(&line[1],endptr,0);
        
        //Check that the starting point is a legitimate vertex
         if ((leftpositionofob2>ROOM_SIZE) || (leftpositionofob2==0))
             exit(INTEGER_IS_NOT_A_VERTEX);
        
         
        k=++j;
        
        //Check if you reached the end of line and if the charatcer after the , is a digit
        if (isdigit(line[j++])==0)
           exit(PARSING_ERROR_INVALID_FORMAT);
    
        // Check that everything before a ) is a digit
         while ((j< linelen -1) && line[j] != ')')
           if (isdigit(line[j++])==0)
               exit(PARSING_ERROR_INVALID_FORMAT);
        
       
        
        // Check if there is a )
        if (line[j] != ')')
            exit(PARSING_ERROR_INVALID_FORMAT);
        
        //Check that the line ends at )
        if (line[j+1]!='\0')
           exit(PARSING_ERROR_INVALID_FORMAT);
        
       //This is the starting point of the edge
         rightpositionofob2=strtoumax(&line[k],endptr,0);
       
        //Check that the starting point is a legitimate vertex
        if ((rightpositionofob2>ROOM_SIZE)||(rightpositionofob2==0))
            exit(INTEGER_IS_NOT_A_VERTEX);
       graphInfunction[0].array[0].leftpositionofob2=leftpositionofob2;
       graphInfunction[0].array[0].rightpositionofob2=rightpositionofob2;
       printf("POSITION OF OBSTACLE2 IS: (%d,%d)\n",leftpositionofob2, rightpositionofob2);
      
      
      
      
  }
  
  linelen=getline(&line, &nbytes, fp);
   if (linelen == -1) 
        {exit(PARSING_ERROR_INVALID_FORMAT);}

    // Removing the newline and adding the NULL character
     line[linelen-1] = '\0';
     
    // Check that everything on the line is a digit
     j = 1;
    
     while (j< linelen -1)
      if (isdigit(line[j++])==0)
         exit(PARSING_ERROR_INVALID_FORMAT);
      
     
    //Compute the number of vertices
    speed_of_obstacle2 = strtoumax(line,endptr,0);
    
    //Check that number of vertices are >0
    if ( speed_of_obstacle2==0)
        exit(PARSING_ERROR_INVALID_FORMAT);
    graphInfunction[0].array[0].speed_of_obstacle2=speed_of_obstacle2;
    printf("SPEED OF OBSTACLE2 IS %d\n", speed_of_obstacle2);
  
    linelen=getline(&line, &nbytes, fp);
  
  if(linelen<7 || linelen>8)
  {
      exit(PARSING_ERROR_INVALID_FORMAT);
  }
  else
  {
       line[linelen-1]='\0';
      if(line[0]!='(')
      {exit(PARSING_ERROR_INVALID_FORMAT);}
      
   
    secondobstacledir1=strtoumax(&line[1],endptr,0);
          
         
      
      //printf("%d\n", firstobstacledir1);
      if (secondobstacledir1!=0 && secondobstacledir1!=+1 && secondobstacledir1!=-1)
      {
          exit(INTEGER_IS_NOT_A_VERTEX);
      }
      if(secondobstacledir1==0)
      {
          if(line[2]!=',')
          {exit(PARSING_ERROR_INVALID_FORMAT);}
          secondobstacledir2=strtoumax(&line[3],endptr,0);
          //printf("%d\n", firstobstacledir2);
      
      }
      else if(secondobstacledir1==1 || secondobstacledir1==-1)
      {
          if(line[3]!=',')
          {exit(PARSING_ERROR_INVALID_FORMAT);}
          secondobstacledir2=strtoumax(&line[4],endptr,0);
          //printf("%d\n", firstobstacledir2);
      }
    graphInfunction[0].array[0].secondobstacledir1=secondobstacledir1;
    graphInfunction[0].array[0].secondobstacledir2=secondobstacledir2;
    printf("direction of obstacle2 is :(%d,%d)\n",  secondobstacledir1, secondobstacledir2);
  }
  
    /*linelen=getline(&line, &nbytes, fp);
    if(linelen!=-1)
    {
        printf("what else u want to do!");
    }*/
  
     
     
    
}


void obs1Position_distance(ArrayForGraph_inf graphInfunction[ARRAYSIZE]) {
    int size=graphInfunction[0].array[0].ROOM_SIZE;
    if (graphInfunction[0].array[0].firstobstacledir2 == -1 && graphInfunction[0].array[0].firstobstacledir1 == -1) {

        if (graphInfunction[0].array[0].leftpositionofob1 <= graphInfunction[0].array[0].rightpositionofob1) {
            graphInfunction[0].array[0].distanceObs1 = graphInfunction[0].array[0].leftpositionofob1 - 1;
        } else {
            graphInfunction[0].array[0].distanceObs1 = graphInfunction[0].array[0].rightpositionofob1 - 1;
        }
    }//North-west 
    else if (graphInfunction[0].array[0].firstobstacledir2 == 1 && graphInfunction[0].array[0].firstobstacledir1 == 1) {
        if (graphInfunction[0].array[0].leftpositionofob1 <= graphInfunction[0].array[0].rightpositionofob1) {
            graphInfunction[0].array[0].distanceObs1=size-graphInfunction[0].array[0].rightpositionofob1;
        } else {
            graphInfunction[0].array[0].distanceObs1 = size-graphInfunction[0].array[0].leftpositionofob1;
        }
    }//South-east
    else if(graphInfunction[0].array[0].firstobstacledir2 ==1 && graphInfunction[0].array[0].firstobstacledir1 == -1){
        if (graphInfunction[0].array[0].leftpositionofob1-1 <= size-graphInfunction[0].array[0].rightpositionofob1) {
            graphInfunction[0].array[0].distanceObs1=graphInfunction[0].array[0].leftpositionofob1-1;
        }
        else{
           graphInfunction[0].array[0].distanceObs1=size-graphInfunction[0].array[0].rightpositionofob1;
        }
    }//North-east
    else if(graphInfunction[0].array[0].firstobstacledir2 == -1 && graphInfunction[0].array[0].firstobstacledir1 == 1){
        if ((size-graphInfunction[0].array[0].leftpositionofob1) <= graphInfunction[0].array[0].rightpositionofob1-1) {
            graphInfunction[0].array[0].distanceObs1=size-graphInfunction[0].array[0].leftpositionofob1;
        }
        else{
           graphInfunction[0].array[0].distanceObs1=graphInfunction[0].array[0].rightpositionofob1-1;
        }
    }//South-west
    else if(graphInfunction[0].array[0].firstobstacledir2 ==0 && graphInfunction[0].array[0].firstobstacledir1 == -1){
           graphInfunction[0].array[0].distanceObs1=graphInfunction[0].array[0].leftpositionofob1-1;
    }//north
    else if(graphInfunction[0].array[0].firstobstacledir2 ==0 && graphInfunction[0].array[0].firstobstacledir1 == 1){
           graphInfunction[0].array[0].distanceObs1=size-graphInfunction[0].array[0].leftpositionofob1;
    }//south
    else if(graphInfunction[0].array[0].firstobstacledir2 ==1 && graphInfunction[0].array[0].firstobstacledir1 == 0){
           graphInfunction[0].array[0].distanceObs1=size-graphInfunction[0].array[0].rightpositionofob1;
    }//east
    else if(graphInfunction[0].array[0].firstobstacledir2 ==-1 && graphInfunction[0].array[0].firstobstacledir1 == 0){
           graphInfunction[0].array[0].distanceObs1=graphInfunction[0].array[0].rightpositionofob1-1;
    }//west
    
}
void obs2Position_distance(ArrayForGraph_inf graphInfunction[ARRAYSIZE]) {
    int size=graphInfunction[0].array[0].ROOM_SIZE;
    if (graphInfunction[0].array[0].secondobstacledir2 == -1 && graphInfunction[0].array[0].secondobstacledir1 == -1) {

        if (graphInfunction[0].array[0].leftpositionofob2 <= graphInfunction[0].array[0].rightpositionofob2) {
            graphInfunction[0].array[0].distanceObs2 = graphInfunction[0].array[0].leftpositionofob2 - 1;
        } else {
            graphInfunction[0].array[0].distanceObs2 = graphInfunction[0].array[0].rightpositionofob2 - 1;
        }
    }//North-west 
    else if (graphInfunction[0].array[0].secondobstacledir2 == 1 && graphInfunction[0].array[0].secondobstacledir1 == 1) {
        if (graphInfunction[0].array[0].leftpositionofob2 <= graphInfunction[0].array[0].rightpositionofob2) 
        {
            graphInfunction[0].array[0].distanceObs2=size-graphInfunction[0].array[0].rightpositionofob2;
        } else {
            graphInfunction[0].array[0].distanceObs2 = size-graphInfunction[0].array[0].leftpositionofob2;
        }
    }//South-east
    else if(graphInfunction[0].array[0].secondobstacledir2 ==1 && graphInfunction[0].array[0].secondobstacledir1 == -1){
        if (graphInfunction[0].array[0].leftpositionofob2-1 <= size-graphInfunction[0].array[0].rightpositionofob2) {
            graphInfunction[0].array[0].distanceObs2=graphInfunction[0].array[0].leftpositionofob2-1;
        }
        else{
           graphInfunction[0].array[0].distanceObs2=size-graphInfunction[0].array[0].rightpositionofob2;
        }
    }//North-east
    else if(graphInfunction[0].array[0].secondobstacledir2 == -1 && graphInfunction[0].array[0].secondobstacledir1 == 1){
        if ((size-graphInfunction[0].array[0].leftpositionofob2) <= graphInfunction[0].array[0].rightpositionofob2-1) {
            graphInfunction[0].array[0].distanceObs2=size-graphInfunction[0].array[0].leftpositionofob2;
        }
        else{
           graphInfunction[0].array[0].distanceObs2=graphInfunction[0].array[0].rightpositionofob2-1;
        }
    }//South-west
    else if(graphInfunction[0].array[0].secondobstacledir2 ==0 && graphInfunction[0].array[0].secondobstacledir1 == -1){
           graphInfunction[0].array[0].distanceObs2=graphInfunction[0].array[0].leftpositionofob2-1;
    }//north
    else if(graphInfunction[0].array[0].secondobstacledir2 ==0 && graphInfunction[0].array[0].secondobstacledir1 == 1){
           graphInfunction[0].array[0].distanceObs2=size-graphInfunction[0].array[0].leftpositionofob2;
    }//south
    else if(graphInfunction[0].array[0].secondobstacledir2 ==1 && graphInfunction[0].array[0].secondobstacledir1 == 0){
           graphInfunction[0].array[0].distanceObs2=size-graphInfunction[0].array[0].rightpositionofob2;
    }//east
    else if(graphInfunction[0].array[0].secondobstacledir2 ==-1 && graphInfunction[0].array[0].secondobstacledir1 == 0){
           graphInfunction[0].array[0].distanceObs2=graphInfunction[0].array[0].rightpositionofob2-1;
    }//west
    
   // printf("OBS2 distance from wall:%d\n", graphInfunction[0].array[0].distanceObs2);
}
void obsPosition_direction(ArrayForGraph_inf graphInfunction[ARRAYSIZE]){
    int i=0;
    int distance=0;
    int obs1=graphInfunction[0].array[0].distanceObs1;
    int speed1=graphInfunction[0].array[0].speed_of_obstacle;
    int size=graphInfunction[0].array[0].ROOM_SIZE;
    
        while(i<=30) {
            if(obs1-distance<speed1){
                
               if (graphInfunction[0].array[0].firstobstacledir2 == -1 && graphInfunction[0].array[0].firstobstacledir1 == -1) {
                //i++;
                graphInfunction[i].array[0].leftpositionofob1=graphInfunction[i].array[0].leftpositionofob1-(obs1-distance);
                graphInfunction[i].array[0].rightpositionofob1=graphInfunction[i].array[0].rightpositionofob1-(obs1-distance);
                printf("\nHit wall:#%d:ob1:(%d,%d)\n",i,graphInfunction[i].array[0].leftpositionofob1, graphInfunction[i].array[0].rightpositionofob1);
                graphInfunction[0].array[0].firstobstacledir2 = 1;
                graphInfunction[0].array[0].firstobstacledir1 = 1;
                 if (graphInfunction[i].array[0].leftpositionofob1 <= graphInfunction[i].array[0].rightpositionofob1) {
                    graphInfunction[0].array[0].distanceObs1 = size - graphInfunction[i].array[0].rightpositionofob1;
                } else {
                    graphInfunction[0].array[0].distanceObs1 = size - graphInfunction[i].array[0].leftpositionofob1;
                }
                obs1=graphInfunction[0].array[0].distanceObs1;
            } 
            else if (graphInfunction[0].array[0].firstobstacledir2 == 1 && graphInfunction[0].array[0].firstobstacledir1 == 1) {
                //i++;
                graphInfunction[i].array[0].leftpositionofob1=graphInfunction[i].array[0].leftpositionofob1+(obs1-distance);
                graphInfunction[i].array[0].rightpositionofob1=graphInfunction[i].array[0].rightpositionofob1+(obs1-distance);
                printf("\nHit wall:#%d:ob1:(%d,%d)\n", i,graphInfunction[i].array[0].leftpositionofob1,graphInfunction[i].array[0].rightpositionofob1);
                graphInfunction[0].array[0].firstobstacledir2 = -1;
                graphInfunction[0].array[0].firstobstacledir1 = -1;
                if (graphInfunction[0].array[0].leftpositionofob1 <= graphInfunction[i].array[0].rightpositionofob1) {
                    graphInfunction[0].array[0].distanceObs1 = graphInfunction[i].array[0].leftpositionofob1 - 1;
                } else {
                    graphInfunction[0].array[0].distanceObs1 = graphInfunction[i].array[0].rightpositionofob1 - 1;
                }
                obs1=graphInfunction[0].array[0].distanceObs1;
            }
            else if (graphInfunction[0].array[0].firstobstacledir2 == 1 && graphInfunction[0].array[0].firstobstacledir1 == -1) {
                //i++;
                graphInfunction[i].array[0].leftpositionofob1=graphInfunction[i].array[0].leftpositionofob1-(obs1-distance);
                graphInfunction[i].array[0].rightpositionofob1=graphInfunction[i].array[0].rightpositionofob1+(obs1-distance);
                printf("\nHit wall:#%d:ob1:(%d,%d)\n",i,graphInfunction[i].array[0].leftpositionofob1, graphInfunction[i].array[0].rightpositionofob1);
                graphInfunction[0].array[0].firstobstacledir2 = -1;
                graphInfunction[0].array[0].firstobstacledir1 = 1;
                if ((size - graphInfunction[i].array[0].leftpositionofob1) <= graphInfunction[i].array[0].rightpositionofob1 - 1) {
                    graphInfunction[0].array[0].distanceObs1 = size - graphInfunction[i].array[0].leftpositionofob1;
                } else {
                    graphInfunction[0].array[0].distanceObs1 = graphInfunction[i].array[0].rightpositionofob1 - 1;
                }
                obs1=graphInfunction[0].array[0].distanceObs1;
            }
            else if (graphInfunction[0].array[0].firstobstacledir2 == -1 && graphInfunction[0].array[0].firstobstacledir1 == 1) {
                //i++;
                graphInfunction[i].array[0].leftpositionofob1=graphInfunction[i].array[0].leftpositionofob1+(obs1-distance);
                graphInfunction[i].array[0].rightpositionofob1=graphInfunction[i].array[0].rightpositionofob1-(obs1-distance);
                printf("\nHit wall:#%d:ob1:(%d,%d)\n", i,graphInfunction[i].array[0].leftpositionofob1, graphInfunction[i].array[0].rightpositionofob1);
                graphInfunction[0].array[0].firstobstacledir2 = 1;
                graphInfunction[0].array[0].firstobstacledir1 = -1;
                if (graphInfunction[i].array[0].leftpositionofob1 - 1 <= size - graphInfunction[i].array[0].rightpositionofob1) {
                    graphInfunction[0].array[0].distanceObs1 = graphInfunction[i].array[0].rightpositionofob1 - 1;
                } else {
                    graphInfunction[0].array[0].distanceObs1 = size - graphInfunction[i].array[0].leftpositionofob1;
                }
                obs1=graphInfunction[0].array[0].distanceObs1;
            }
            else if (graphInfunction[0].array[0].firstobstacledir2 == 1 && graphInfunction[0].array[0].firstobstacledir1 == 0) {
                //i++;
                graphInfunction[i].array[0].leftpositionofob1=graphInfunction[i].array[0].leftpositionofob1;
                graphInfunction[i].array[0].rightpositionofob1=graphInfunction[i].array[0].rightpositionofob1+(obs1-distance);
                printf("\nHit wall#:%d:ob1:(%d,%d)\n", i,graphInfunction[i].array[0].leftpositionofob1, graphInfunction[i].array[0].rightpositionofob1);
                graphInfunction[0].array[0].firstobstacledir2 = -1;
                obs1=size-1;
                
            }
            else if (graphInfunction[0].array[0].firstobstacledir2 == -1 && graphInfunction[0].array[0].firstobstacledir1 == 0) {
                //i++;
                
                graphInfunction[i].array[0].leftpositionofob1=graphInfunction[i].array[0].leftpositionofob1;
                graphInfunction[i].array[0].rightpositionofob1=graphInfunction[i].array[0].rightpositionofob1-(obs1-distance);
                printf("\nHit wall:#%d:ob1:(%d,%d)\n", i,graphInfunction[i].array[0].leftpositionofob1, graphInfunction[i].array[0].rightpositionofob1);
                graphInfunction[0].array[0].firstobstacledir2 = 1;
                obs1=size-1;
            }
            else if (graphInfunction[0].array[0].firstobstacledir2 == 0 && graphInfunction[0].array[0].firstobstacledir1 == 1) {
                //i++;
                graphInfunction[i].array[0].leftpositionofob1=graphInfunction[i].array[0].leftpositionofob1+(obs1-distance);
                graphInfunction[i].array[0].rightpositionofob1=graphInfunction[i].array[0].rightpositionofob1;
                printf("\nHit wall:#%d:ob1:(%d,%d)\n", i,graphInfunction[i].array[0].leftpositionofob1, graphInfunction[i].array[0].rightpositionofob1);
                graphInfunction[0].array[0].firstobstacledir1 = -1;
                obs1=size-1;
            }
            else if (graphInfunction[0].array[0].firstobstacledir2 == 0 && graphInfunction[0].array[0].firstobstacledir1 == -1) {
               // i++;
                graphInfunction[i].array[0].leftpositionofob1=graphInfunction[i].array[0].leftpositionofob1-(obs1-distance);
                graphInfunction[i].array[0].rightpositionofob1=graphInfunction[0].array[0].rightpositionofob1;
                printf("\nHit wall:#%d:ob1:(%d,%d)\n", i,graphInfunction[i].array[0].leftpositionofob1, graphInfunction[i].array[0].rightpositionofob1);
                graphInfunction[0].array[0].firstobstacledir1 = 1;
                obs1=size-1;
            }
               distance = 0;
               //new cycle begin.
            }
            else{
            if (graphInfunction[0].array[0].firstobstacledir2 == -1 && graphInfunction[0].array[0].firstobstacledir1 == -1) {
                i++;
                graphInfunction[i].array[0].leftpositionofob1=graphInfunction[i-1].array[0].leftpositionofob1-speed1;
                graphInfunction[i].array[0].rightpositionofob1=graphInfunction[i-1].array[0].rightpositionofob1-speed1;
                printf("#%d:ob1:(%d,%d)\n",i,graphInfunction[i].array[0].leftpositionofob1, graphInfunction[i].array[0].rightpositionofob1);
            } 
            else if (graphInfunction[0].array[0].firstobstacledir2 == 1 && graphInfunction[0].array[0].firstobstacledir1 == 1) {
                i++;
                graphInfunction[i].array[0].leftpositionofob1=graphInfunction[i-1].array[0].leftpositionofob1+speed1;
                graphInfunction[i].array[0].rightpositionofob1=graphInfunction[i-1].array[0].rightpositionofob1+speed1;
                printf("#%d:ob1:(%d,%d)\n", i,graphInfunction[i].array[0].leftpositionofob1, graphInfunction[i].array[0].rightpositionofob1);
            }
            else if (graphInfunction[0].array[0].firstobstacledir2 == 1 && graphInfunction[0].array[0].firstobstacledir1 == -1) {
                i++;
                graphInfunction[i].array[0].leftpositionofob1=graphInfunction[i-1].array[0].leftpositionofob1-speed1;
                graphInfunction[i].array[0].rightpositionofob1=graphInfunction[i].array[0].rightpositionofob1+speed1;
                printf("#%d:ob1:(%d,%d)\n",i,graphInfunction[i].array[0].leftpositionofob1, graphInfunction[i].array[0].rightpositionofob1);
            }
            else if (graphInfunction[0].array[0].firstobstacledir2 == -1 && graphInfunction[0].array[0].firstobstacledir1 == 1) {
                i++;
                graphInfunction[i].array[0].leftpositionofob1=graphInfunction[i-1].array[0].leftpositionofob1+speed1;
                graphInfunction[i].array[0].rightpositionofob1=graphInfunction[i-1].array[0].rightpositionofob1-speed1;
                printf("#%d:ob1:(%d,%d)\n", i,graphInfunction[i].array[0].leftpositionofob1, graphInfunction[i].array[0].rightpositionofob1);
            }
            else if (graphInfunction[0].array[0].firstobstacledir2 == 1 && graphInfunction[0].array[0].firstobstacledir1 == 0) {
                i++;
                graphInfunction[i].array[0].leftpositionofob1=graphInfunction[0].array[0].leftpositionofob1;
                graphInfunction[i].array[0].rightpositionofob1=graphInfunction[i-1].array[0].rightpositionofob1+speed1;
                printf("#%d:ob1:(%d,%d)\n", i,graphInfunction[i].array[0].leftpositionofob1, graphInfunction[i].array[0].rightpositionofob1);
            }
            else if (graphInfunction[0].array[0].firstobstacledir2 == -1 && graphInfunction[0].array[0].firstobstacledir1 == 0) {
                i++;
                graphInfunction[i].array[0].leftpositionofob1=graphInfunction[0].array[0].leftpositionofob1;
                graphInfunction[i].array[0].rightpositionofob1=graphInfunction[i-1].array[0].rightpositionofob1-speed1;
                printf("#%d:ob1:(%d,%d)\n", i,graphInfunction[i].array[0].leftpositionofob1, graphInfunction[i].array[0].rightpositionofob1);
                
            }
            else if (graphInfunction[0].array[0].firstobstacledir2 == 0 && graphInfunction[0].array[0].firstobstacledir1 == 1) {
                i++;
                graphInfunction[i].array[0].leftpositionofob1=graphInfunction[i-1].array[0].leftpositionofob1+speed1;
                graphInfunction[i].array[0].rightpositionofob1=graphInfunction[0].array[0].rightpositionofob1;
                printf("#%d:ob1:(%d,%d)\n", i,graphInfunction[i].array[0].leftpositionofob1, graphInfunction[i].array[0].rightpositionofob1);
            }
            else if (graphInfunction[0].array[0].firstobstacledir2 == 0 && graphInfunction[0].array[0].firstobstacledir1 == -1) {
                i++;
                graphInfunction[i].array[0].leftpositionofob1=graphInfunction[i-1].array[0].leftpositionofob1-speed1;
                graphInfunction[i].array[0].rightpositionofob1=graphInfunction[0].array[0].rightpositionofob1;
                printf("#%d:ob1:(%d,%d)\n", i,graphInfunction[i].array[0].leftpositionofob1, graphInfunction[i].array[0].rightpositionofob1);
            }
            /*else if (graphInfunction[0].array[0].firstobstacledir2 == 0 && graphInfunction[0].array[0].firstobstacledir1 == 0) {
                i++;
                graphInfunction[i].array[0].leftpositionofob1=graphInfunction[0].array[0].leftpositionofob1;
                graphInfunction[i].array[0].rightpositionofob1=graphInfunction[0].array[0].rightpositionofob1;
                printf("#%d:ob1:(%d,%d)\n", i,graphInfunction[i].array[0].leftpositionofob1, graphInfunction[i].array[0].rightpositionofob1);
            }*/
            distance+=speed1;
            }
            
        }
}
void obs2Position_direction(ArrayForGraph_inf graphInfunction[ARRAYSIZE]){
    int i=0;
    int distance=0;
    //int obs1=graphInfunction[0].array[0].distanceObs1;
    int obs2=graphInfunction[0].array[0].distanceObs2; 
    
   //int speed1=graphInfunction[0].array[0].speed_of_obstacle;
    int speed2=graphInfunction[0].array[0].speed_of_obstacle2;
    int size=graphInfunction[0].array[0].ROOM_SIZE;
    
        while(i<=30) {
            if(obs2-distance<speed2){
                
               if (graphInfunction[0].array[0].secondobstacledir2 == -1 && graphInfunction[0].array[0].secondobstacledir1 == -1) {
                //i++;
                graphInfunction[i].array[0].leftpositionofob2=graphInfunction[i].array[0].leftpositionofob2-(obs2-distance);
                graphInfunction[i].array[0].rightpositionofob2=graphInfunction[i].array[0].rightpositionofob2-(obs2-distance);
                printf("\nHit wall:#%d:ob2:(%d,%d)\n",i,graphInfunction[i].array[0].leftpositionofob2, graphInfunction[i].array[0].rightpositionofob2);
                 //printf("direction(%d,%d)\n",i,graphInfunction[i].array[0].leftpositionofob2, graphInfunction[i].array[0].rightpositionofob2);
                graphInfunction[0].array[0].secondobstacledir2 = 1;
                graphInfunction[0].array[0].secondobstacledir1 = 1;
                //printf("direction(%d,%d)\n",graphInfunction[0].array[0].secondobstacledir1, graphInfunction[0].array[0].secondobstacledir2);
                 if (graphInfunction[i].array[0].leftpositionofob2 <= graphInfunction[i].array[0].rightpositionofob2) {
                    graphInfunction[0].array[0].distanceObs2 = size - graphInfunction[i].array[0].rightpositionofob2;
                } 
                 else {
                    graphInfunction[0].array[0].distanceObs2 = size - graphInfunction[i].array[0].leftpositionofob2;
                }
                obs2=graphInfunction[0].array[0].distanceObs2;
            } 
               else if (graphInfunction[0].array[0].secondobstacledir2 == 1 && graphInfunction[0].array[0].secondobstacledir1 == 1) {
                //i++;
                graphInfunction[i].array[0].leftpositionofob2=graphInfunction[i].array[0].leftpositionofob2+(obs2-distance);
                graphInfunction[i].array[0].rightpositionofob2=graphInfunction[i].array[0].rightpositionofob2+(obs2-distance);
                printf("\nHit wall:#%d:ob2:(%d,%d)\n", i,graphInfunction[i].array[0].leftpositionofob2,graphInfunction[i].array[0].rightpositionofob2);
                graphInfunction[0].array[0].secondobstacledir2 = -1;
                graphInfunction[0].array[0].secondobstacledir1 = -1;
                //printf("direction(%d,%d)\n",graphInfunction[0].array[0].secondobstacledir1, graphInfunction[0].array[0].secondobstacledir2);
                if (graphInfunction[i].array[0].leftpositionofob2 <= graphInfunction[i].array[0].rightpositionofob2) {
                    graphInfunction[0].array[0].distanceObs2 = graphInfunction[i].array[0].leftpositionofob2 - 1;
                } else {
                    graphInfunction[0].array[0].distanceObs2 = graphInfunction[i].array[0].rightpositionofob2 - 1;
                }
                obs2=graphInfunction[0].array[0].distanceObs2;
            }
               else if (graphInfunction[0].array[0].secondobstacledir2 == 1 && graphInfunction[0].array[0].secondobstacledir1 == -1) {
                //i++;
                //printf("\ndistance:%d %d\n",distance,obs2);
               // printf("%d\n",graphInfunction[0].array[0].distanceObs2);
                graphInfunction[i].array[0].leftpositionofob2=graphInfunction[i].array[0].leftpositionofob2-(obs2-distance);
                graphInfunction[i].array[0].rightpositionofob2=graphInfunction[i].array[0].rightpositionofob2+(obs2-distance);
                printf("\nHit wall:#%d:ob2:(%d,%d)\n",i,graphInfunction[i].array[0].leftpositionofob2, graphInfunction[i].array[0].rightpositionofob2);
                graphInfunction[0].array[0].secondobstacledir2 = -1;
                graphInfunction[0].array[0].secondobstacledir1 = 1;
                //printf("@@@direction(%d,%d)\n",graphInfunction[0].array[0].secondobstacledir1, graphInfunction[0].array[0].secondobstacledir2);
                if ((size - graphInfunction[i].array[0].leftpositionofob2) <= graphInfunction[i].array[0].rightpositionofob2 - 1) {
                    
                    graphInfunction[0].array[0].distanceObs2 = size - graphInfunction[i].array[0].leftpositionofob2;
                    
                } else {
                  
                    graphInfunction[0].array[0].distanceObs2 = graphInfunction[i].array[0].rightpositionofob2 - 1;
      
                }
                obs2=graphInfunction[0].array[0].distanceObs2;
                //printf("\ndistance:%d\n",obs2);
            }
               else if (graphInfunction[0].array[0].secondobstacledir2 == -1 && graphInfunction[0].array[0].secondobstacledir1 == 1) {
                //i++;
                graphInfunction[i].array[0].leftpositionofob2=graphInfunction[i].array[0].leftpositionofob2+(obs2-distance);
                graphInfunction[i].array[0].rightpositionofob2=graphInfunction[i].array[0].rightpositionofob2-(obs2-distance);
                printf("\nHit wall:#%d:ob2:(%d,%d)\n", i,graphInfunction[i].array[0].leftpositionofob2, graphInfunction[i].array[0].rightpositionofob2);
                graphInfunction[0].array[0].secondobstacledir2 = 1;
                graphInfunction[0].array[0].secondobstacledir1 = -1;
                if (graphInfunction[i].array[0].leftpositionofob2 - 1 <= size - graphInfunction[i].array[0].rightpositionofob2) {
                    graphInfunction[0].array[0].distanceObs2 = graphInfunction[i].array[0].leftpositionofob2 - 1;
                } else {
                    graphInfunction[0].array[0].distanceObs2 = size - graphInfunction[i].array[0].rightpositionofob2;
                }
                obs2=graphInfunction[0].array[0].distanceObs2;
            }
               else if (graphInfunction[0].array[0].secondobstacledir2 == 1 && graphInfunction[0].array[0].secondobstacledir1 == 0) {
                //i++;
                graphInfunction[i].array[0].leftpositionofob2=graphInfunction[0].array[0].leftpositionofob2;
                graphInfunction[i].array[0].rightpositionofob2=graphInfunction[i].array[0].rightpositionofob2+(obs2-distance);
                printf("\nHit wall#:%d:ob2:(%d,%d)\n", i,graphInfunction[i].array[0].leftpositionofob2, graphInfunction[i].array[0].rightpositionofob2);
                graphInfunction[0].array[0].secondobstacledir2 = -1;
                obs2=size-1;
                
            }
               else if (graphInfunction[0].array[0].secondobstacledir2 == -1 && graphInfunction[0].array[0].secondobstacledir1 == 0) {
                //i++;
                graphInfunction[i].array[0].leftpositionofob2=graphInfunction[0].array[0].leftpositionofob2;
                graphInfunction[i].array[0].rightpositionofob2=graphInfunction[i].array[0].rightpositionofob2-(obs2-distance);
                printf("\nHit wall:#%d:ob2:(%d,%d)\n", i,graphInfunction[i].array[0].leftpositionofob2, graphInfunction[i].array[0].rightpositionofob2);
                graphInfunction[0].array[0].secondobstacledir2 = 1;
                obs2=size-1;
            }
               else if (graphInfunction[0].array[0].secondobstacledir2 == 0 && graphInfunction[0].array[0].secondobstacledir1 == 1) {
                //i++;
                graphInfunction[i].array[0].leftpositionofob2=graphInfunction[i].array[0].leftpositionofob2+(obs2-distance);
                graphInfunction[i].array[0].rightpositionofob2=graphInfunction[i].array[0].rightpositionofob2;
                printf("\nHit wall:#%d:ob2:(%d,%d)\n", i,graphInfunction[i].array[0].leftpositionofob2, graphInfunction[i].array[0].rightpositionofob2);
                graphInfunction[0].array[0].secondobstacledir1 = -1;
                obs2=size-1;
            }
               else if (graphInfunction[0].array[0].secondobstacledir2 == 0 && graphInfunction[0].array[0].secondobstacledir1 == -1) {
               // i++;
                graphInfunction[i].array[0].leftpositionofob2=graphInfunction[i].array[0].leftpositionofob2-(obs2-distance);
                graphInfunction[i].array[0].rightpositionofob2=graphInfunction[i].array[0].rightpositionofob2;
                printf("#%d:ob2:(%d,%d)\n", i,graphInfunction[i].array[0].leftpositionofob2, graphInfunction[i].array[0].rightpositionofob2);
                graphInfunction[0].array[0].secondobstacledir1 = 1;
                obs2=size-1;
            }
               distance = 0;
               //new cycle begin.
            }
            else{
            if (graphInfunction[0].array[0].secondobstacledir2 == -1 && graphInfunction[0].array[0].secondobstacledir1 == -1) {
                i++;
                graphInfunction[i].array[0].leftpositionofob2=graphInfunction[i-1].array[0].leftpositionofob2-speed2;
                graphInfunction[i].array[0].rightpositionofob2=graphInfunction[i-1].array[0].rightpositionofob2-speed2;
                printf("#%d:ob2:(%d,%d)\n",i,graphInfunction[i].array[0].leftpositionofob2, graphInfunction[i].array[0].rightpositionofob2);
            } 
            else if (graphInfunction[0].array[0].secondobstacledir2 == 1 && graphInfunction[0].array[0].secondobstacledir1 == 1) {
                i++;
                // printf("**(%d)\n", speed2);
                graphInfunction[i].array[0].leftpositionofob2=graphInfunction[i-1].array[0].leftpositionofob2+speed2;
                graphInfunction[i].array[0].rightpositionofob2=graphInfunction[i-1].array[0].rightpositionofob2+speed2;
                printf("#%d:ob2:(%d,%d)\n", i,graphInfunction[i].array[0].leftpositionofob2, graphInfunction[i].array[0].rightpositionofob2);
            }
            else if (graphInfunction[0].array[0].secondobstacledir2 == 1 && graphInfunction[0].array[0].secondobstacledir1 == -1) {
                i++;
                graphInfunction[i].array[0].leftpositionofob2=graphInfunction[i-1].array[0].leftpositionofob2-speed2;
                graphInfunction[i].array[0].rightpositionofob2=graphInfunction[i-1].array[0].rightpositionofob2+speed2;
                printf("#%d:ob2:(%d,%d)\n",i,graphInfunction[i].array[0].leftpositionofob2, graphInfunction[i].array[0].rightpositionofob2);
            }
            else if (graphInfunction[0].array[0].secondobstacledir2 == -1 && graphInfunction[0].array[0].secondobstacledir1 == 1) {
                i++;
                graphInfunction[i].array[0].leftpositionofob2=graphInfunction[i-1].array[0].leftpositionofob2+speed2;
                graphInfunction[i].array[0].rightpositionofob2=graphInfunction[i-1].array[0].rightpositionofob2-speed2;
                printf("#%d:ob2:(%d,%d)\n", i,graphInfunction[i].array[0].leftpositionofob2, graphInfunction[i].array[0].rightpositionofob2);
            }
            else if (graphInfunction[0].array[0].secondobstacledir2 == 1 && graphInfunction[0].array[0].secondobstacledir1 == 0) {
                i++;
                graphInfunction[i].array[0].leftpositionofob2=graphInfunction[0].array[0].leftpositionofob2;
                graphInfunction[i].array[0].rightpositionofob2=graphInfunction[i-1].array[0].rightpositionofob2+speed2;
                printf("#%d:ob2:(%d,%d)\n", i,graphInfunction[i].array[0].leftpositionofob2, graphInfunction[i].array[0].rightpositionofob2);
            }
            else if (graphInfunction[0].array[0].secondobstacledir2 == -1 && graphInfunction[0].array[0].secondobstacledir1 == 0) {
                i++;
                graphInfunction[i].array[0].leftpositionofob2=graphInfunction[0].array[0].leftpositionofob2;
                graphInfunction[i].array[0].rightpositionofob2=graphInfunction[i-1].array[0].rightpositionofob2-speed2;
                printf("#%d:ob2:(%d,%d)\n", i,graphInfunction[i].array[0].leftpositionofob2, graphInfunction[i].array[0].rightpositionofob2);
            }
            else if (graphInfunction[0].array[0].secondobstacledir2 == 0 && graphInfunction[0].array[0].secondobstacledir1 == 1) {
                i++;
                graphInfunction[i].array[0].leftpositionofob2=graphInfunction[i-1].array[0].leftpositionofob2+speed2;
                graphInfunction[i].array[0].rightpositionofob2=graphInfunction[0].array[0].rightpositionofob2;
                printf("#%d:ob2:(%d,%d)\n", i,graphInfunction[i].array[0].leftpositionofob2, graphInfunction[i].array[0].rightpositionofob2);
            }
            else if (graphInfunction[0].array[0].secondobstacledir2 == 0 && graphInfunction[0].array[0].secondobstacledir1 == -1) {
                i++;
                graphInfunction[i].array[0].leftpositionofob2=graphInfunction[i].array[0].leftpositionofob2-speed2;
                graphInfunction[i].array[0].rightpositionofob2=graphInfunction[0].array[0].rightpositionofob2;
                printf("#%d:ob2:(%d,%d)\n", i,graphInfunction[i].array[0].leftpositionofob2, graphInfunction[i].array[0].rightpositionofob2);
            }
            /*else if (graphInfunction[0].array[0].secondobstacledir2 == 0 && graphInfunction[0].array[0].secondobstacledir1 == 0) {
                i++;
                graphInfunction[i].array[0].leftpositionofob2=graphInfunction[0].array[0].leftpositionofob2;
                graphInfunction[i].array[0].rightpositionofob2=graphInfunction[0].array[0].rightpositionofob2;
                printf("#%d:ob2:(%d,%d)\n", i,graphInfunction[i].array[0].leftpositionofob2, graphInfunction[i].array[0].rightpositionofob2);
            }*/
            distance+=speed2;
            }
            
        }
}
void findnextstep(ArrayForGraph_inf graphInfunction[ARRAYSIZE]){
   
    //for(count=0;count<10;count++){
      // printf("(%d,%d)\n",graphInfunction[count].array[0].leftpositionofob2, graphInfunction[count].array[0].rightpositionofob2); 
    //}
    int xob1=graphInfunction[count].array[0].leftpositionofob1;
    int yob1=graphInfunction[count].array[0].rightpositionofob1;
    int xob2=graphInfunction[count].array[0].leftpositionofob2;
    int yob2=graphInfunction[count].array[0].rightpositionofob2;
    //int f_robt_x=graphInfunction[0].array[0].initialpositionofrobot1;
    //int f_robt_y=graphInfunction[0].array[0].initialpositionofrobot2;
    int l_robt_x=graphInfunction[0].array[0].finalpositionofrobot1;
    int l_robt_y=graphInfunction[0].array[0].finalpositionofrobot2;
    
 
    
    
   // printf("(%d)")
    x1=graphInfunction[0].array[0].x_changing-1; 
    y1=graphInfunction[0].array[0].y_changing-1;
    
   xl =l_robt_x;
    yl=l_robt_y;
    vx1=-abs(xl-x1);
  
    vy1=-abs(yl-y1);
  
    v1= vx1 + vy1;
    if (xob1==x1&&yob1==y1)
        v1=-9999;
     if (xob2==x1&&yob2==y1)
        v1=-9999;
      if(x1==1 || y1==1)
        v1=-9999;
    if(x1== graphInfunction[0].array[0].ROOM_SIZE|| y1== graphInfunction[0].array[0].ROOM_SIZE)
        v1=-9999;  
    
    
    
    
    
    x2=graphInfunction[0].array[0].x_changing-1; 
    y2=graphInfunction[0].array[0].y_changing;
    vx2=-abs(xl-x2);
      //printf("%d",vx2);
    vy2=-abs(yl-y2);
     // printf("%d",vy2);
    v2= vx2 + vy2;
      
     if (xob2==x2&&yob2==y2)
        v2=-9999;
 if (xob1==x2&&yob1==y2)
        v2=-9999;
       if(x2==1 || y2==1)
        v2=-9999;
    if(x2== graphInfunction[0].array[0].ROOM_SIZE|| y2== graphInfunction[0].array[0].ROOM_SIZE)
        v2=-9999; 
    
    
    x3=graphInfunction[0].array[0].x_changing-1; 
    y3=graphInfunction[0].array[0].y_changing+1;
    vx3=-abs(xl-x3);
    vy3=-abs(yl-y3);
    v3= vx3 + vy3;
      //printf("%d",v3);
 if (xob1==x3&&yob1==y3)
        v3=-9999;
 if (xob2==x3&&yob2==y3)
        v3=-9999;
    
        if(x3==1 || y3==1)
        v3=-9999;
    if(x3== graphInfunction[0].array[0].ROOM_SIZE|| y3== graphInfunction[0].array[0].ROOM_SIZE)
        v3=-9999;  
    
    x4=graphInfunction[0].array[0].x_changing; 
    y4=graphInfunction[0].array[0].y_changing-1;
    vx4=-abs(xl-x4);
    vy4=-abs(yl-y4);
    v4= vx4 + vy4;
     if (xob1==x4&&yob1==y4)
        v4=-9999;
     if (xob2==x4&&yob2==y4)
        v4=-9999;
  if(x4==1 || y4==1)
        v4=-9999;
    if(x4== graphInfunction[0].array[0].ROOM_SIZE|| y4== graphInfunction[0].array[0].ROOM_SIZE)
        v4=-9999;  
    

    x6=graphInfunction[0].array[0].x_changing; 
    y6=graphInfunction[0].array[0].y_changing+1;
    vx6=-abs(xl-x6);
    vy6=-abs(yl-y6);
    v6= vx6 + vy6;
      //printf("%d",v6);
 if (xob1==x6&&yob1==y6)
        v6=-9999;
 if (xob2==x6&&yob2==y6)
        v6=-9999;
   if(x6==1 || y6==1)
        v6=-9999;
    if(x6== graphInfunction[0].array[0].ROOM_SIZE|| y6== graphInfunction[0].array[0].ROOM_SIZE)
        v6=-9999;   
    
    
    x7=graphInfunction[0].array[0].x_changing+1; 
    y7=graphInfunction[0].array[0].y_changing-1;
    vx7=-abs(xl-x7);
    vy7=-abs(yl-y7);
    v7= vx7 + vy7;
 if (xob1==x7&&yob1==y7)
        v7=-9999;
 if (xob2==x7&&yob2==y7)
        v7=-9999;
      if(x7==1 || y7==1)
        v7=-9999;
    if(x7== graphInfunction[0].array[0].ROOM_SIZE|| y7== graphInfunction[0].array[0].ROOM_SIZE)
        v7=-9999;  
    
    
    
    x8=graphInfunction[0].array[0].x_changing+1; 
    y8=graphInfunction[0].array[0].y_changing;
    vx8=-abs(xl-x8);
    vy8=-abs(yl-y8);
    v8= vx8 + vy8;
 if (xob1==x8&&yob1==y8)
        v8=-9999;
     if (xob2==x8&&yob2==y8)
        v8=-9999;
    
      if(x8==1 || y8==1)
        v8=-9999;
    if(x8== graphInfunction[0].array[0].ROOM_SIZE|| y8== graphInfunction[0].array[0].ROOM_SIZE)
        v8=-9999;  

    x9=graphInfunction[0].array[0].x_changing+1; 
    y9=graphInfunction[0].array[0].y_changing+1;
    vx9=-abs(xl-x9);
    vy9=-abs(yl-y9);
    v9= vx9 + vy9;
     if (xob1==x9&&yob1==y9)
        v9=-9999;
     if (xob2==x9&&yob2==y9)
        v9=-9999;
      if(x9==1 || y9==1)
        v9=-9999;
    if(x9== graphInfunction[0].array[0].ROOM_SIZE|| y9== graphInfunction[0].array[0].ROOM_SIZE)
        v9=-9999;  
    int number[8];
    int i;
    number[0]=v1,number[1]=v2,number[2]=v3,number[3]=v4,number[4]=v6,number[5]=v7,number[6]=v8,number[7]=v9;
   //sort(number,number+7);
    int j,k=0;
    signed int temp;
    for(j=0;j<7;j++)
    {
        for(k=0; k<7;k++)
        {
            if(number[k]<number[k+1])
            {
                temp=number[k];
                number[k]=number[k+1];
                number[k+1]=temp;

            }
        }
    }
    vmax=number[0];
     // printf("%d%d%d%d%d%d%d%d",number[7],number[6],number[5],number[4],number[3],number[2],number[1],number[0]);
    if(vmax==v1) {
        graphInfunction[0].array[0].x_changing = x1;
        graphInfunction[0].array[0].y_changing = y1;

        printf("v1POSITION OF robot IS: (%d,%d),this is step %d \n", x1, y1, t);
        t = t + 1;
    }
    if (vmax == v2) {

        graphInfunction[0].array[0].x_changing = x2;
        graphInfunction[0].array[0].y_changing = y2;
        printf("v2POSITION OF robot IS: (%d,%d),this is step %d \n", x2, y2, t);
        t = t + 1;
    }
    if (vmax == v3) {
        graphInfunction[0].array[0].x_changing = x3;
        graphInfunction[0].array[0].y_changing = y3;
        printf("v3POSITION OF robot IS: (%d,%d),this is step %d \n", x3, y3, t);
        t = t + 1;
    }
    if (vmax == v4) {
       graphInfunction[0].array[0].x_changing = x4;
        graphInfunction[0].array[0].y_changing = y4;
        printf("v4POSITION OF robot IS: (%d,%d),this is step %d \n", x4, y4, t);
        t = t + 1;
    }
    // if(vmax==v5){
    //  x=x5;
    //   y=y5;
    //  printf("POSITION OF robot IS: (%d,%d),this is step %d \n",x5,y5,t);
    //  t=t+1;
    // }
    if (vmax == v6) {
        graphInfunction[0].array[0].x_changing = x6;
        graphInfunction[0].array[0].y_changing = y6;
        printf("v6POSITION OF robot IS: (%d,%d),this is step %d \n", x6, y6, t);
        t = t + 1;
    }
    if (vmax == v7) {
       graphInfunction[0].array[0].x_changing = x7;
        graphInfunction[0].array[0].y_changing = y7;
        printf("v7POSITION OF robot IS: (%d,%d),this is step %d \n", x7, y7, t);
        t = t + 1;
    }
    if (vmax == v8) {
       graphInfunction[0].array[0].x_changing = x8;
        graphInfunction[0].array[0].y_changing = y8;
        printf("v8POSITION OF robot IS: (%d,%d),this is step %d \n", x8, y8, t);
        t = t + 1;
    }
    if (vmax == v9) {
        graphInfunction[0].array[0].x_changing = x9;
        graphInfunction[0].array[0].y_changing = y9;
        printf("v9POSITION OF robot IS: (%d,%d),this is step %d \n", x9, y9, t);
        t = t + 1;
    }
}

