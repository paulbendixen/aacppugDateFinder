/* This is Free Software (C) Paul M. Bendixen licensed under the GPL v. 2.0, see the license file */
#include "date.h"	// The date library is Howard Hinnants
#include <iostream>	// Yes, we still print text to the terminal as if it were the dark ages

/**
 * Calculate the date of the next Århus C++ User Group meeting. Make it possible to extend using
 * argc/argv to input a month of interest*/
int main( int argc, char* argv[] )
{
	// Using namespace should not be done
	namespace d = date;
	// Get the current date so that we can calculate the date of the meeting
	auto today = d::year_month_day{ d::floor< d::days >( std::chrono::system_clock::now() ) };
	// Get the day of the first regular tuesday hack of OSAA
	auto hackDay = d::tue[ 3 ]/today.month()/today.year();
	// The day of the meeting will regularly be the day after that
	auto cppDay = d::year_month_day{ d::day_point( hackDay ) + d::days{ 1 } };

	// You english... What's wrong with just appending a .?
	std::string ending;
	switch( unsigned( cppDay.day() ) % 10 )
	{
		case 1:
			ending = "st";
			break;
		case 2:
			ending = "nd";
			break;
		case 3:
			ending = "rd";
			break;
		default:
			ending = "th";
	};
	// Finally print out the string of the next meeting
	std::cout << "The Aarhus Cpp user group should convene the " << cppDay.day() << ending << " of this month.\n";

}
