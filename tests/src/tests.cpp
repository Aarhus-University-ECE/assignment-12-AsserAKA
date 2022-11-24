#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

extern "C" {
    #include "duration.h"
}

// See Catch2's documentation: https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#scaling-up

// Add your test cases. Dont forget to include header file. 

TEST_CASE("Exercise d")
{
    
    Duration d0;
    REQUIRE(d0.getDuration() == 0);
    
    Duration d1(8);
    REQUIRE(d1.getDuration() == 8);
    
    Duration d2(121);
    REQUIRE(d2.getDuration() == 121);
}

TEST_CASE("Exercise e, f")
{
    Duration d0;
    d0.tick();
    REQUIRE(d0.getDuration() == 1);
   
    Duration d1;
    d1.tick(8);
    REQUIRE(d1.getDuration() == 8);
    
    Duration d2;
    d2.tick(121);
    REQUIRE(d2.getDuration() == 121);
}

TEST_CASE("Exercise g")
{
    Duration d0;
    d0.setAlarm(2);
    REQUIRE(d0.tick() == false);
   
    Duration d1;
    d1.setAlarm(2);
    REQUIRE(d1.tick(2) == false);
    
    Duration d2;
    d2.setAlarm(2);
    REQUIRE(d1.tick(3) == true);
}

TEST_CASE("Exercise h")
{
    Duration d0(3);
    d0.setAlarm(2);
    REQUIRE(d0.tick() == false);
   
    Duration d1(2);
    d1.setAlarm(2);
    REQUIRE(d1.tick() == false);
    
    Duration d2(5);
    d2.setAlarm(2);
    REQUIRE(d1.tick() == false);

    Duration d3;
    d3.setAlarm(2);
    REQUIRE(d3.tick(3) == true);
}

TEST_CASE("Exercise i")
{
    Duration d0(3);
    d0.setAlarm(2);
    REQUIRE(d0.checkAndUpdateAlarm() == false);
   
    Duration d1(2);
    d1.setAlarm(2);
    REQUIRE(d1.checkAndUpdateAlarm() == false);
    
    Duration d2(5);;
    REQUIRE(d1.checkAndUpdateAlarm() == false);

    Duration d3;
    d3.setAlarm(2);
    REQUIRE(d3.checkAndUpdateAlarm() == false);
}