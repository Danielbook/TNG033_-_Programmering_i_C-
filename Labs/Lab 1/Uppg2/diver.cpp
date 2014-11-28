#include <iomanip>
#include <ios>
#include <sstream>
#include "diver.h"


//Test if scores line has correct format
//Accepted line format: difficulty, followed by 7 scores, and (possibly) some text
//The 7 scores should be stored in array scores and
//difficulty should be stored in dif
//If the line has correct format then return true
//stringstreams are used, see sec. 11.9 of course book
bool test_scores_line(string line, double scores[], double &dif)
{
    istringstream in_stream(line);

    if ( (in_stream >> dif >> scores[0] >> scores[1] >> scores[2] >> scores[3] >> scores[4] >> scores[5] >> scores[6] >> ws) || ( in_stream.eof() ))
    {
        return true;
    }

    else
    {
        return false;
    }
}

//Calculate final score for diver d
//and store it in d.final_score
void calculate_final_score(Diver& d)
{
    double sum = 0;
    
    const int TWO_CONST = 2;
    const int THREE_CONST = 3;

    double max = d.points[0], min = d.points[0];

    for (int i = 0; i < NR_OF_REF; i++) {
        if(max < d.points[i])
        {
            max = d.points[i];
        }

        else if (min > d.points[i])
        {
            min = d.points[i];
        }
    }

    for (int i = 0; i < NR_OF_REF; i++) {
        sum += d.points[i];
    }

    sum -= (max+min);

    sum /= (NR_OF_REF-TWO_CONST);

    sum *= THREE_CONST * d.difficulty;

    d.final_score = sum;
}

//Overload operator>> to read data for a diver d from stream in
//If errors were encountered while reading the data for a diver d
//then d.difficulty is set to a negative value
//Return the stream in
istream& operator>>(istream& in, Diver& d)
{
    string scoreLine;
    
    in >> ws;

    getline(in, d.name);
    
    in >> ws;

    getline(in, scoreLine);

    if( !test_scores_line(scoreLine, d.points, d.difficulty) )
    {
        d.difficulty = -1;
    }
    else
    {
        calculate_final_score(d);
    }

   return in;
}

//Overload operator<< to write data for diver d
//to stream out: name and final score
ostream& operator<<(ostream& out, const Diver& d)
{
    out << setw(20) << left << d.name << setw(20) << fixed << left
        << setprecision(1) << d.final_score << endl;

    return out;
}


//Overload comparison operator
//Return true if d1.final_score < d2.final_score
bool operator<(const Diver& d1, const Diver& d2)
{
    if(d1.final_score < d2.final_score)
        return true;
    
    return false;
}

