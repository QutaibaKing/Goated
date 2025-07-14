#ifndef Function_H
#define Function_H


 //summarization of all functions in the program
 double Sin_Deg(double x);
 double Cos_Deg(double x);
 double distance(Airport *Depature, Airport *Arrival); //calculate the distance between two airports
 double decimalDegree(double Degree, double minutes, double seconds); //calculate de decimaldegree from Coordinates
 Time calc_Duration(Time Depature, Time Arrival); //calculate the differenze in time firs lower time , second upper time
 void Generate_Time_Table(FMS *pFMS);
 void Generate_Duration_Table(FMS *pFMS);
 void Generate_Distance_Table(FMS *pFMS);
 Adresses load_FMS(); //load all Given Data in array and link them together
 void Free_FMS (Adresses save); //delete all saved data


#endif