#include<stdio.h>
#include<string.h>
#define n 3
#define m 4
//we assume that our station numbers are 0,1,2
//days are from 0 to 3
#define DB_SIZE 3// DB_SIZE is number of stations
//#define STATUS_SIZE 
#define URBAN 1
#define RURAL 0
#define DIST_SIZE 100
#define DAYS 4

struct climate
{
	float skyviewfactor;
	float vegetationdensityratio;
	float populationdensity;
	float pervioussurfacefraction;
	float impervioussurfacefraction;
	int stationstatus;
	int distance[3];
	float airtemp[4];
	float relativehumidity[4];	
};
struct climate station[3];
//void initialize(struct climate station[],int size)
//{
//	int i,j,k;
//	for(i=0;i<size;i++)
//	{
//		station[i].skyviewfactor=0;
//		station[i].vegetationdensityratio=0;
//	    station[i].populationdensity=0;
//	    station[i].pervioussurfacefraction=0;
//	    station[i].impervioussurfacefraction=0;
//	    station[i].stationstatus=-1;
//	    for(j=0;j<100;j++)
//	    {
//	    	station[i].distance[j]=0;
//		}
//		for(k=0;k<30;k++)
//		{
//			station[i].airtemp[k]=0;
//			station[i].relativehumidity[k]=0;
//		}
//	} tempdiff=station[no].airtemp[k]-station[j].airtemp[k];
//}

float averagevalQ1(struct climate station[])//question 1 function start here
{
	float numerator=0,denominator,average;
	int i ,j;
 	for(i=0;i<DB_SIZE;i++)
	{
		for(j=0;j<DAYS;j++)
		{
			numerator=numerator+station[i].airtemp[j];
			
		}
	}
	denominator=DAYS*(DB_SIZE);
	average=numerator/denominator;	
	printf("old average is %f",average);
	return average;
}

void heatdegree(struct climate station[])
{
	float avg;
	int i,j,count=0,temp,loc,a1[DB_SIZE];
    int array[DB_SIZE];
	avg=averagevalQ1(station);
	printf("average value is %f",avg);
	for(i=0;i<DB_SIZE;i++)
	{
		a1[i]=i;
		//printf("\n%d",a1[i]);
	}
	
	for(i=0;i<DB_SIZE;i++)
	{
		count=0;
		for(j=0;j<DAYS;j++)
		{
			if(station[i].airtemp[j]>avg)
			{
				count++;
			}
		}
		array[i]=count;
		
	}
	for(i=0;i<DB_SIZE;i++)
	{
	   printf("\n%d",array[i]);
	}

	temp=array[0];
	loc=0;
	printf(" value initial in temp is %d",temp);
	for(i=0;i<DB_SIZE-1;i++)
	{
		if(array[i+1]>array[i])
		{
			temp=array[i+1];
			loc=i+1;
		}
	}
	printf("the station numbers with maximum heat degree days are ");
	
	for(i=0;i<DB_SIZE;i++)
	{
		if(array[i]==temp)
		{
			printf("%d \n",a1[i]);
		}
	}
}

float tempdiff(struct climate station[],int no,int j,int k)//question 2 functions begin here.
{
	
	float tempdiff;
	
		tempdiff=station[no].airtemp[k]-station[j].airtemp[k];
		return tempdiff;
	
}
void assign(struct climate station[],int j)
{
	int i;
	float distance[3];
	for(i=0;i<3;i++)
       {
       	distance[i]=station[j].distance[i];
	   }
	   
	   for(i=0;i<n;i++)
	   printf("%d",distance[i]);
}
void thermallycomfortabledays(int distance[],struct climate station[],int stationstatus,int noofstations,int stationno)
{
	int a1[n],i,j,k,loc,no,day[m],a2[m],flag=1,a[n],flag1=1;
	float min,temp,tempdi;
	//char str1[]="rural";
	//char str2[]="urban";
	day[0]=0;
	no=stationno;
	if(station[no].stationstatus==0) 
	{
		printf("put urban station only");
		flag=0;
	}
	if(flag==1)
	{
	
	for(i=0;i<n;i++) //TO MAINTAIN THE VALUE OF CORRESPONDING STATION NO.
	{
		a1[i]=i;
	
		a[i]=i;
		
	}
		
	for(i=0;i<m;i++)
	{
		
		a2[i]=i;
	
	}


	for(i=0;i<n;i++) //SORTING OF DISTANCE ARRAY USING SELECTION SORT
	{
	   		min=distance[i];
	        loc=i;
	        for(j=i+1;j<n;j++)
	        {
	        	if(distance[j]<min)
	        	{
	        		min=distance[j];
	        		loc=j;
	        		
	        		
				}
				
			}
			distance[loc]=distance[i];
			distance[i]=min;
			temp=a[loc];
			a[loc]=a[i];
			a[i]=temp;
			
	}
	
	i=1;
	while(i<n && flag1==1) //as i=0 will be distance from same station i.e 0
	{
		j=a[i];
		if(station[j].stationstatus==1)//urban
		{
			i++;
		}
		else if(station[j].stationstatus==0)//rural station found
		{
			printf("rural station number %d",j);
			flag1=0;
			for(k=0;k<DAYS;k++)
			{
			   tempdi=tempdiff(station,no,j,k);//day loop to be added	tempdiff(struct climate station[],int no,int j,int k)
			   if(tempdi>0)
			   {
			   	 day[k]=tempdi;
			   }
			   else
			   {
			   	  day[k]=-1*(tempdi);
			   }
			}
			
			//array by the name of day is ready 
}
}
	for(i=0;i<m;i++) //SORTING OF DAY ARRAY USING SELECTION SORT
	{
	   		min=day[i];
	        loc=i;
	        for(j=i+1;j<n;j++)
	        {
	        	if(day[j]<min)
	        	{
	        		min=day[j];
	        		loc=j;
	        	
	        		
				}
				
			}
			day[loc]=day[i];
			day[i]=min;
				temp=a2[loc];
			a2[loc]=a2[i];
			a2[i]=temp;
			
	}
	printf("thermally comfortable days are");
		i=0;
		printf("%d",a2[i]);
		while(day[i+1]==day[i])
		{
			printf("%d",a2[i+1]);
			i++;
		}
			


}

}
//question 3 functions begin here.
float averageval(int N,struct climate station[])
{
	float numerator=0,denominator,average;
	int i ,j;
 	for(i=0;i<N;i++)
	{
		for(j=0;j<4;j++)
		{
			numerator=numerator+station[i].airtemp[j];
			
		}
	}
	denominator=4*N;
	average=numerator/denominator;	
	return average;
}
void dates(struct climate station[],int array2[])
{
	int i,j,k;
    float avg;
    avg=averageval(3,station);
    for(k=0;k<DB_SIZE;k++)
    {
    	i=array2[k];
    	printf("station number %d",i);
        	printf("dates");
    
        for( j=0 ; j<DAYS ; j++)
        {
            if(station[i].airtemp[j]>avg)
            {
            
                printf(" %d ",j);
            }
        }
    }	
	
   
}

//to sort the vegetation density ratio in decreasing order
void part3(struct climate station[])
{
    int i,temp,sorted=0,arr[DB_SIZE+1],temp1,loc;
    int j,array2[DB_SIZE];
	float min,array1[DB_SIZE];
	for(i=0;i<DB_SIZE;i++)
	{
		arr[i]=0;
	}
	for(i=0;i<DB_SIZE;i++)
	{
		array1[i]=0;
		array2[i]=0;
	}
	for (i=0 ; i<DB_SIZE ; i++)
	{
		array1[i]=station[i].vegetationdensityratio;
		array2[i]=i;
	}
	for(i=0;i<DB_SIZE-1;i++)
	{
		min=array1[i];
		loc=i;
		for(j=i+1;j<DB_SIZE;j++)
		{
			if(array1[j]>min)
			{
				min=array1[j];
				loc=j;
			}
		}
		array1[loc]=array1[i];
		array1[i]=min;
		temp=array2[loc];
		array2[loc]=array2[i];
		array2[i]=temp;
	}
   
            
        
    
    dates(station,array2);
}

float max(struct climate station[] ,int i)//question 4 functions begin here.
 {
 	int j;
    float s=station[i].airtemp[0];
    for( j=1;j<4;j++)
    {
        if(station[i].airtemp[j]>m)
        {
            s=station[i].airtemp[j];
        }

    }
    return s;

 }
void question4(struct climate station[],int mo)
{
	int no=3;//number of stations taken as 3
	
	int i,loc,j,arr2[no-1],count=0,low,high,k,l,location;
	
	float min,arr1[no-1],temp,maxima,large;
	for (i=0;i<3;i++)
	{
		arr1[i]=station[i].populationdensity;
		arr2[i]=i;
	}
	for(i=0;i<2;i++)//i<no-1
	{
		min=arr1[i];
		loc=i;
		for(j=i+1;j<no;j++)
		{
			if(arr1[j]<min)
			{
				min=arr1[j];
				loc=j;
			}
		}
		arr1[loc]=arr1[i];
		arr1[i]=min;
		temp=arr2[loc];
		arr2[loc]=arr2[i];
		arr2[i]=temp;
	}
	printf("the station numbers are");
	i=0;
    while(count<mo)
	{
		 if(i==no-1 && count<mo)
	    {
	    	printf("%d",arr2[i]);
	    	break;
		}
		else if(arr1[i+1]!=arr1[i] && i<n-1)
		{
		
		   printf("%d",arr2[i]);
		   count++;
		   i++;
	    }
	    
        else if(arr1[i+1]==arr1[i])
    {
       low=i;
       while(arr1[i+1]==arr1[i]  && i<n)
       {
       	i++;
	   }
	   high=i;
	   for(k=low;k<high;k++)
	   {
	   	large=arr2[k];
	   	location=k;
	   	for(l=k+1;l<=high;l++)
	   	{
	   		if(max(station,l)>max(station,k))
	   		{
	   		 large=arr2[l];
	   		 location=l;
			}
	   	
	   	  
		   
	   }
	   arr2[location]=arr2[k];
	   arr2[k]=large;
	}
	i=low;
	while(count<mo && i<=high)
	{
		printf("%d",arr2[i]);
		i++;
		count++;
	}

}
}
	    
}

float avg_temp(struct climate station[], int stationnumber)//q5 functions start here.
{   float sum=0;
     int i;
	 printf("entered station number is %d \n",stationnumber) ;
	for(i=0; i<DAYS;i++)
	{ 
	  sum=sum+station[stationnumber].airtemp[i];
	  
	}
	printf("sum is %f\n", sum);
	return sum/DAYS;
}
void heat_island_intensity( struct climate station[])
{ 
    int pos,i,flag1=1,a1[DB_SIZE],a[DB_SIZE],a2[DB_SIZE],min,loc,j,temp,k,urban,rural;
    float intensity;
   // for(j=0;j<DB_SIZE;j++)
//
//	{
//		 for(i=0;i<DB_SIZE;i++)
  //      {
  //       	printf("the entered  distances of %d station from %d station is %d",j,i,station[j].distance[i]);
             
 //    	}
	
      	
  
	for(i=0; i<DB_SIZE; i++)//where i is indicating station number
	{
		if(station[i].stationstatus==0)
		{
			printf("%d station is rural hence checking next station",i);
			i++;
		}
		else if(station[i].stationstatus==1)//urban station found
		{  
		printf("urban station %d found",i);
		urban=i;
		  for(i=0;i<DB_SIZE;i++)
	{
		a1[i]=i;
	
		a[i]=i;
		
	}
		
	for(i=0;i<m;i++)
	{
		
		a2[i]=i;
	
	}
     i=urban;

	for(j=0;j<DB_SIZE;j++)
	{
	   		min=station[i].distance[j];
	        loc=j;
	        for(k=j+1;k<DB_SIZE;k++)
	        {
	        	if(station[i].distance[k]<min)
	        	{
	        		min=station[i].distance[k];
	        		loc=k;
	        		
	        		
				}
				
			}
			station[i].distance[loc]=station[i].distance[j];
			station[i].distance[j]=min;
			temp=a[loc];
			a[loc]=a[j];
			a[j]=temp;
			
	}
	j=1;
	while(j<DB_SIZE && flag1==1) //as j=0 will be distance from same station i.e 0
	{
	
		k=a[j];
		if(station[k].stationstatus==1)//urban
		{
			j++;
		}
		else if(station[k].stationstatus==0)//rural station found
		{
			printf("rural station number %d\n",k);
			
			rural=k;
			flag1=0;
    	}
		   
     }
		 
		  intensity=avg_temp(station, i)-avg_temp(station, rural);
		  printf("%f", intensity);
		   
		}
		
	}
}



void main()
{
	int i,j,control_line;
	struct climate station[3];
	int distance[3];
	station[0].skyviewfactor=0.2;
	station[0].vegetationdensityratio=11;
	station[0].populationdensity=101;
	station[0].pervioussurfacefraction=1.5;
	station[0].impervioussurfacefraction=2.5;
	station[0].stationstatus=0;
	station[0].distance[0]=0;
	station[0].distance[1]=2;
    station[0].distance[2]=4;
    station[0].airtemp[0]=29;
    station[0].airtemp[1]=27;
    station[0].airtemp[2]=29;
    station[0].airtemp[3]=29;
    station[0].relativehumidity[0]=6;
    station[0].relativehumidity[1]=7;
    station[0].relativehumidity[2]=8;
    station[0].relativehumidity[3]=9;
	station[1].skyviewfactor=0.1;
	station[1].vegetationdensityratio=10;
	station[1].populationdensity=100;
	station[1].pervioussurfacefraction=1;
	station[1].impervioussurfacefraction=2;
	station[1].stationstatus=1;
	station[1].distance[0]=2;
	station[1].distance[1]=0;
    station[1].distance[2]=3;
    station[1].airtemp[0]=21;
    station[1].airtemp[1]=22;
    station[1].airtemp[2]=23;
    station[1].airtemp[3]=24;
    station[1].relativehumidity[0]=5;
    station[1].relativehumidity[1]=6;
    station[1].relativehumidity[2]=7;
    station[1].relativehumidity[3]=8;
    station[2].skyviewfactor=0.3;
	station[2].vegetationdensityratio=12;
	station[2].populationdensity=102;
	station[2].pervioussurfacefraction=2;
	station[2].impervioussurfacefraction=3;
	station[2].stationstatus=1;
	station[2].distance[0]=4;
	station[2].distance[1]=3;
    station[2].distance[2]=0;
    station[2].airtemp[0]=28;
    station[2].airtemp[1]=29;
    station[2].airtemp[2]=30;
    station[2].airtemp[3]=31;
    station[2].relativehumidity[0]=10;
    station[2].relativehumidity[1]=11;
    station[2].relativehumidity[2]=12;
    station[2].relativehumidity[3]=13;
       	
	//int delete_status1,delete_status2,delete_status3;
	
	control_line=1;
	
	
	while(control_line!=0)
	{
        printf("\n____________________\n");
        printf("0 -- exit terminal\n");
        printf("1 -- List of stations with heat degree days\n");
        printf("2 -- Thermally Comfortable days for a station\n");
        printf("3 -- List of dates for all stations with decreasing vegetation density ratio and for which the temperature was more than average city temperature.\n");
        printf("4 -- List of stations with minimum population density with highest maximum temperature.\n");
        printf("5 -- Heat island intensity for all urban stations\n");

        printf("\nEnter the number beside the function you want to execute : ");
		scanf("%d",&control_line);
		
		switch (control_line)
		{
			case 0: //Exit
			{
				printf("User Interface exited");
				break;
			}
				case 1: //Print
			{
			
			
				heatdegree(station);
//				printDB(spuriousflightRecord,DB_SIZE);
				break;
			}
			case 2: //thermally comfortable days
			 {
				 printf("enter station number");
                 scanf("%d",&j);
                 for(i=0;i<3;i++)
                {
                 	printf("enter distance of %d station from %d station",j,i);
                 	scanf("%d",&distance[i]);
      	
	             }
	              printf("enterd distances are distances");
	               for(i=0;i<3;i++)
	               printf("%d",distance[i]);
                  //assign(station,j);
       
       
       
                   thermallycomfortabledays( distance, station, 1, n, j)  ;
                   break;
			
			}
			
			case 3: //getNumFlights
			{
				part3(station);
				break;
			}
				case 4: //Check fullness
			{
                int k,flag=0;
				printf("enter k value");
                 scanf("%d",&k);
                if(3<k)
              {
             	printf("put k less than equal to n");
             	flag=1;
       	
	           }
	           if(flag==0)
	           {
	           	 question4( station, k);
			   }
              
               break;
			}
			case 5:
				{
						for(j=0;j<DB_SIZE;j++)
	                    {
	                    	 for(i=0;i<DB_SIZE;i++)
                            {
                            	printf("enter distance of %d station from %d station",j,i);
                                 scanf("%d",&station[j].distance[i]);
                         	}
                           for(i=0;i<DAYS;i++)
                           {
                              printf("enter temperature of %d station on %d day",j,i);
                             scanf("%f",&station[j].airtemp[i]);            
                             }
	
      	
                         }
	                     heat_island_intensity(station);  
	                     break;
               }
		
			default:
			{
				printf("Loop exited");
				control_line=0;
				break;
			}
		}
      
}
}