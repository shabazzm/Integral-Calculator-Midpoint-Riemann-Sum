// Name Maryum Shabazz
// Date 4/17/2017
// Project # Final project
// Project Description: We will use this program to calculate
//area under a curve using midpoint and the fundamental theorem of calculus
#include <fstream>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
 double errorCalc(double,double);

int main()
{	//variables to be used in program
	double total=0, error=-1;
  	const double errorTolerance=0.001;
   	double width, secondVal,firstVal,functionVal,xVal, multiplier,upperLimit, lowerLimit;
   	int nSquares=2, terms, FUNCTION;
    int index, counter=0,counter2=0;
    vector <double> coefficient;
   	vector<double> fPower;
   	double absUpper, absLower;
   	double power,xmultiplier,multiplicandA,multiplicandB,dividB,dividA,fundArea,midpointArea;
   	double runningtotal=0, midTotal=0, termSumA=0,termSumB=0, totalA=0,totalB=0;
    double upperVal=0, lowerVal=0;
  	double midpoint, sumval, intervals;
  	
 	//instructions on how to use program
 	cout<<"This program will calculate the area of a midpoint Riemann Sum"<<endl;
 	cout<<"as well as the area using the fundamental theorem of calculus."<<endl;
 	cout<<"The error will be calculated which is the absolute value of the"<<endl;
 	cout<<"difference of the midpoint area and the actual area. If the error"<<endl;
 	cout<<"calculated is not equal to or less than 0.001 the user will be"<<endl;
 	cout<<"prompted to restart the program and use a larger number of sqaures."<<endl;
 	cout<<endl;
 	
 	//opening file to store data in.
 	ofstream outputFile;
 	outputFile.open("CalculusData.txt");
 	cout<<"Data will be written to file CalculusData.txt "<<endl;
 	cout<<endl;
 	
 	//asking user for number of terms in function
 	cout<<"How many terms does your function have, enter an interger number?"<<endl;
 	cin>>terms;
 	
 	// collects the upper and lower limits from user
	cout<<"What is the upper limit of intergration (upper endpoint)"<<endl;
  	cin>>upperLimit;
  	cout<<"what is the lower limit of intergration (lower endpoint)"<<endl;
  	cin>>lowerLimit;
  	
  	cout<<"Please enter the terms of the function from right to left following the prompts"<<endl;
	
	//using for loop to collect function from user and store in two separate vectors

  double tempPower, tempCoeff;
  for (int i=0; i<terms;i++)
  {
  	cout<<"What is the power for the term?"<<endl ;
  	cin>>tempPower;
  	fPower.push_back(tempPower);
  	cout<<"What is the coefficient for that term?"<<endl;
  	cin>> tempCoeff;
  	coefficient.push_back(tempCoeff); 
  	counter++;
  }
  index=0;
  cout<<"This is the function"<<endl;
  cout<<"f(x)=";
  //used while loop to display function.
  while(index<counter)
  { 
  	cout<<coefficient[index]<<"x^"<<fPower[index]<<"+";
  	index++;
  
  }
  cout<<"0"<<endl;
  cout<<endl;
  
 //entering fundamental theory of calculus calculation of area
 power=fPower[index];
 //for loop containing while loop and if loop used to intergrate each term of function separate 
 for (int index=0; index<terms;index++)

  { 
  	power=power+1;
  	
    if (power==0)
    	{
			cout<<endl;
            while (upperLimit==0)
            {
				cout<<"Division 1/x is not possible when x is zero"<<endl;
                cout<<"Please enter  a new upper limit"<<endl;
                cin>>upperLimit;}
    			absUpper=abs(upperLimit);
    			termSumB=coefficient[index]*(log(absUpper));
    			totalB=termSumB+totalB;
    			
    		while(lowerLimit==0)
    		{
				cout<<"Division by 1/x is not possible when x is zero"<<endl;
    			cout<<"Please enter a new lower limit"<<endl;
    			cin>>lowerLimit;}
    			absLower=abs (lowerLimit);
    			termSumA=coefficient[index]*(log(absLower));
    			totalA=termSumA+totalA;
    		}
    	
    		cout<<endl;
    		power=fPower[index];
    		power=power+1;
    if (power!=0)
    
    { 	
    	multiplicandB= pow(upperLimit,power);
    	dividB=multiplicandB*coefficient[index];
    	termSumB=dividB/power;
    	totalB=termSumB+totalB;
    	multiplicandA=pow(lowerLimit,power);
    	dividA=multiplicandA*coefficient[index];
    	termSumA=dividA/power;
    	totalA=termSumA+totalA;
    }
    
 }
	fundArea=(totalB-totalA);
    
 //midpoint function below
 cout<<"How many intervals would you like to use determine area using a Midpoint Riemann Sum"<<endl;
 cin>>nSquares;
   
  lowerVal=lowerLimit;
  do
  {
  width=((upperLimit-lowerLimit)/nSquares);
  
       while(counter2<nSquares)
       {								//code bewow used to determine midpoints
       		upperVal=lowerVal+width;
       		sumval=(lowerVal+upperVal);
       		midpoint=sumval/2;
       		lowerVal=width+lowerVal;
       		counter2++;
    								//sending midpoints through function
       for (index=0;index<=nSquares;index++)
       {
      		multiplier=pow(midpoint,fPower[index]);
           	total=multiplier*coefficient[index];
      		runningtotal=runningtotal+total;
      }
 	midpointArea=runningtotal*width; 
      }
       cout<<"The midpoint area is.  "<<midpointArea<<endl;
       error=errorCalc(fundArea,midpointArea); //function call to error calc function
       nSquares=nSquares+1;
	         
  } while (error==-1);
	//cout statements used to display data to user
  	cout<<endl;
  	cout<<"This is the error "<<error<<endl;
  	cout<<endl;
  	cout<<"This is the area based on the fundamental theory of calculus.  "<<fundArea<<endl; 
  	intervals=nSquares-1;
  	cout<<endl;
  	cout<<"The area was divided into  "<<intervals<<"  intervals."<<endl;
  	cout<<endl;
  	//writing data to file
  	outputFile<<"The midpoint area is.  "<<midpointArea<<endl;
  	outputFile<<endl;
  	outputFile<<"This is the error "<<error<<endl;
  	outputFile<<endl;
  	outputFile<<"This is the area based on the fundamental theory of calculus.  "<<fundArea<<endl; 
  	outputFile<<endl;
  	outputFile<<"The area was divided into  "<<intervals<<"  intervals."<<endl;
  	outputFile<<endl;
  
  //if/else if used to determine whether user is within error.
  if (error>errorTolerance)
  {
  cout<<"You will need to run the program and enter a higher number of intervals"<<endl;
  cout<<"The error is still more than 0.001"<<endl;
  outputFile<<"You will need to run the program and enter a higher number of intervals"<<endl;
  outputFile<<"The error is still more than 0.001"<<endl;
  }
  else if (error<=errorTolerance)
  {
  cout<<"The intervals you entered are enough that error in area is less than 0.001"<<endl;
  outputFile<<"The intervals you entered are enough that error in area is less than 0.001"<<endl;
  }
  cout<<endl;
  //closing file
  outputFile.close();
  cout<<"Data written to file CalculusData.txt "<<endl;
  cout<<endl;
  cout << "Please press [ENTER] to end. ";
  cin.get();
  cin.get();
  return 0; 
}

//error calc function, used to calculate area and return to function
//fundthe stands for fundamental theory and will receieve the argument fundArea
//midPo stands for midPoint and will recieve the parameter midpointArea
double errorCalc(double fundThe,double midPo)

{   double value;
       value=fundThe-midPo; //error is calcuated by subtraction
       value=abs(value); //absolute value is taken to ensure error is only positive
       return value;
   
}
