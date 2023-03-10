#include "catch2/catch.hpp"
#include "preferredItem.h"
#include "brick.h"
#include "item.h"
#include "masterData.h"
#include "serviceFunctions.h"
#include <iostream>

using namespace std;

//example pseudo code scenario to get you started
//you probably want to make more fine grained & specific test scenarios than this
//do not spend your time making a random data generator
//write test scenarios with simple hard coded data that ensures your algorithms function as designed
//write test scenarios to show us you have analysed and are aware of the complexity and edge cases 
//it is better to have a failing test than no test at all

/*********************************************************************************/
// First scenario: I am testing the correctness of basic functions
// that will be used in solving the problem.
SCENARIO("Basic functionalities check.") {

	GIVEN( "Some bricks..." ) {
		Brick brick1(1, {3, 2, 10});
		Brick brick2(1, {2, 3, 10});
		Brick brick3(4, {3, 2, 4, 90});
		Brick brick4(10, {1, 90});

		THEN( "I can check that two bricks are equal or not." ) {
			REQUIRE(!(brick1 == brick2));
			REQUIRE(!(brick1 == brick3));
		}

		GIVEN( "Some items that contain a different quantity of bricks..." ) {
			Item item1(1, {brick1});
			Item item2(2, {brick1, brick1});

			THEN( "I can check that their brick lists are not equal." ) {
				REQUIRE(!Brick::doBrickListsMatch(item1.getBricks(), item2.getBricks()));
			}
		}

		GIVEN( "Some items that contain the same brick, but in different quantities..." ) {
			Item item1(1, {brick1, brick2});
			Item item2(2, {brick1, brick1});

			THEN( "I can check that their brick lists are not equal." ) {
				REQUIRE(!Brick::doBrickListsMatch(item1.getBricks(), item2.getBricks()));
			}
		}

		GIVEN( "Some items that contain the same bricks in the same quantities, but not inserted in the same order..." ) {
			Item item1(1, {brick1, brick1, brick2});
			Item item2(2, {brick2, brick1, brick1});

			THEN( "I can check that their brick lists are equal." ) {
				REQUIRE(Brick::doBrickListsMatch(item1.getBricks(), item2.getBricks()));
			}
		}

		GIVEN( "Some items that contain the same number of bricks, but not the same bricks..." ) {
			Item item1(1, {brick1, brick2, brick3});
			Item item2(2, {brick4, brick4, brick4});

			THEN( "I can check that their brick lists are not equal." ) {
				REQUIRE(!Brick::doBrickListsMatch(item1.getBricks(), item2.getBricks()));
			}
		}

	}
}

// Second scenario: I am testing that the algorithm can find the preferred item
// that fully matches specific brick requirements.
SCENARIO("Finding the preferred item.") {

	GIVEN( "A list of items and a list of masterdata..." ) {
		list<Item> itemList = ServiceFunctions::ItemService();
		list<MasterData> mdList = ServiceFunctions::MasterDataService();

		GIVEN( "A request containing only one brick..." ) {
			list<Brick> request = {Brick(1, {30})};

			THEN( "I can find the preferred item." ) {
				REQUIRE(PreferredItemService(itemList, mdList, request).getItemID() == 2);
			}
		}

		GIVEN( "A request containing multiple copies of the same brick..." ) {
			list<Brick> request = {Brick(1, {30}), Brick(1, {30})};

			THEN( "I can find the preferred item." ) {
				REQUIRE(PreferredItemService(itemList, mdList, request).getItemID() == 7);
			}
		}

		GIVEN( "A request containing different bricks..." ) {
			list<Brick> request = {Brick(1, {30}), Brick(4, {30, 40}), Brick(1, {30})};

			THEN( "I can find the preferred item." ) {
				REQUIRE(PreferredItemService(itemList, mdList, request).getItemID() == 10);
			}
		}

		GIVEN( "A request for bricks that cannot be satisfied..." ) {
			list<Brick> request = {Brick(4, {40})};

			THEN( "I can detect the problem." ) {
				REQUIRE(PreferredItemService(itemList, mdList, request).getItemID() == -1);
			}
		}

	}
}