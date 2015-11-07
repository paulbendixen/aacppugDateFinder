#include "date.h"
#include <iostream>

int main( int argc, char* argv[] )
{
	namespace d = date;
	auto today = d::year_month_day{ d::floor< d::days >( std::chrono::system_clock::now() ) };
	auto hackDay = d::tue[ 3 ]/today.month()/today.year();
	auto cppDay = d::year_month_day{ d::day_point( hackDay ) + d::days{ 1 } };
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
	std::cout << "The Aarhus Cpp user group should convene the " << cppDay.day() << ending << " of this month.\n";

}
