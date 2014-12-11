#include <iomanip>
#include <ios>
#include <sstream>

#include "diver.h"
//std::cout << d.difficulty << std::endl;
//Overload operator>> to read data for a diver d from stream in
//If errors were encountered while reading the data for a diver d
//then d.name is set to an empty string
//Return the stream in
istream& operator>>(istream& in, Diver& d)
{
    string s;
    int nr = 0;


    in >> ws;
    getline(in,d.name);
    in >> ws;
    in >> d.difficulty;

    if(!in.good()){
        d.name = ""; //fel --> ignorera
        in.clear(); //felet är fixat, vi tar bort den röda flagggan
    }

    getline(in, s);
    istringstream is(s);

    while((nr < NR_OF_REF) && (is >> d.points[nr])){
        nr++;
    }

    if(!(nr == NR_OF_REF)){
        d.name = ""; //ignorera
        in.clear(); //felet är fixat, vi tar bort den röda flagggan
    }

    return in;
}


//Calculate final score for diver d
//and store it in d.final_score
void calculate_final_score(Diver& d)
{
    double max = d.points[0], min = d.points[0], tot = 0;

    for(int i = 0; i < NR_OF_REF; i++){
        if( d.points[i] < min)
            min = d.points[i];

        if( d.points[i] > max)
            max = d.points[i];

        tot += d.points[i];
    }

    d.final_score = ((tot - min - max)/5) * 3 * d.difficulty;

    //cout << endl<< "tot" << tot << endl;
    return;
}


//Overload operator<< to write data for diver d
//to stream out: name and final score
ostream& operator<<(ostream& out, const Diver& d)
{
    out << setw(20) << left << d.name
    << setw(5) << fixed << setprecision(1) << d.final_score;

    return out;
}


//Overload comparison operator
//Return true if d1.final_score < d2.final_score
bool operator<(const Diver& d1, const Diver& d2)
{
    if( d1.final_score < d2.final_score)
        return true;

    return false;
}

