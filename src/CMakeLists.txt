include_directories( ../lib/date )
set( HEADER_FILES ../lib/date/date.h )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11" )
add_executable( aacppugDateFinder aacppugDateFinder.cpp )
