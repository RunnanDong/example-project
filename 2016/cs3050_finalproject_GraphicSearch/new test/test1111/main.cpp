#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <ctype.h>
#include <limits.h>


enum error {
    INCORRECT_NUMBER_OF_COMMAND_LINE_ARGUMENTS = 1,
    FILE_FAILED_TO_OPEN,
    FILE_FAILED_TO_CLOSE,
    PARSING_ERROR_INVALID_FORMAT,
    PARSING_ERROR_EMPTY_FILE,
    INTEGER_IS_NOT_A_VERTEX,
};


void parse_getlineforrobot(FILE* fp);


/*
 * 
 */

  int main(int argc, char** argv) {
    
    unsigned int answer;
   int count;
    if (argc != 2){
         exit(1);
    }
    FILE* fp = fopen(argv[1], "r");
    
    if (!fp)
    {
        printf("1,FILE_FAILED_TO_OPEN\n");
        exit(1);
    }
  
   
   parse_getlineforrobot(fp);
   

 }

  

void parse_getlineforrobot(FILE* fp)
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
    if (ROOM_SIZE==0)
        exit(PARSING_ERROR_INVALID_FORMAT);
    
    
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

       printf("final position of bots: (%d,%d)\n",  finalpositionofrobot1,  finalpositionofrobot2);
       
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

       printf("position of obstacle1 is: (%d,%d)\n",  leftpositionofob1,  rightpositionofob1);
       
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
    
    
    printf("SPEED OF OBSTACLE IS: %d\n",  speed_of_obstacle);
     

   
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
      if(firstobstacledir1==0 || firstobstacledir1==1)
      {
          if(line[2]!=',')
          {exit(PARSING_ERROR_INVALID_FORMAT);}
          firstobstacledir2=strtoumax(&line[3],endptr,0);
          //printf("%d\n", firstobstacledir2);
      
      }
      else
      {
          if(line[3]!=',')
          {exit(PARSING_ERROR_INVALID_FORMAT);}
          firstobstacledir2=strtoumax(&line[4],endptr,0);
          //printf("%d\n", firstobstacledir2);
      }
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
      if(secondobstacledir1==0 || secondobstacledir1==1)
      {
          if(line[2]!=',')
          {exit(PARSING_ERROR_INVALID_FORMAT);}
          firstobstacledir2=strtoumax(&line[3],endptr,0);
          //printf("%d\n", firstobstacledir2);
      
      }
      else
      {
          if(line[3]!=',')
          {exit(PARSING_ERROR_INVALID_FORMAT);}
          secondobstacledir2=strtoumax(&line[4],endptr,0);
          //printf("%d\n", firstobstacledir2);
      }
    printf("direction of obstacle2 is :(%d,%d)\n",  secondobstacledir1, secondobstacledir2);
      //if(isdigit)
      
      
      
      
    
  }
  
    linelen=getline(&line, &nbytes, fp);
    if(linelen!=-1)
    {
        printf("what else u want to do, u damn it destroy all of my work, go to the hell");
    }
  
     
     
    
}


