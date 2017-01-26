/******************************************************************************
   Copyright (C) 2017 Mathias C. Bellout <mathias.bellout@ntnu.no>

   This file and the WellIndexCalculator as a whole is part of the
   FieldOpt project. However, unlike the rest of FieldOpt, the
   WellIndexCalculator is provided under the GNU Lesser General Public
   License.

   WellIndexCalculator is free software: you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public License
   as published by the Free Software Foundation, either version 3 of
   the License, or (at your option) any later version.

   WellIndexCalculator is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with WellIndexCalculator.  If not, see
   <http://www.gnu.org/licenses/>.
******************************************************************************/

#include <gtest/gtest.h>
#include <boost/filesystem.hpp> /* exists */
#include <stdio.h>              /* printf */
#include <stdlib.h>             /* system, NULL, EXIT_FAILURE */

using namespace std;

namespace{

    class wicalcStandaloneTest : public ::testing::Test {
    protected:
        wicalcStandaloneTest(){};

        virtual ~wicalcStandaloneTest(){}

        virtual void SetUp(){}

        virtual void TearDown(){}

        string wicalc_path = "./wicalc";
        string grid_str = "--grid ../examples/ADGPRS/5spot/ECL_5SPOT.EGRID";
        string heel_str = "--heel 10 10 1712";
        string toe_str = "--toe 1000 1000 1712";
        string radius_str = "--radius 0.1905";
        string compdat_str = "--compdat";
        string wname_str = "--well-name PROD";

        bool check_wicalc_exists(){
            if ( !boost::filesystem::exists( wicalc_path ) ){
                printf ("Cannot find wicalc executable. Skipping test.\n");
                return false;
            }else{
                return true;
            }
        };
    };

    TEST_F(wicalcStandaloneTest, WellIndexValueWithQVector_test) {
        if (check_wicalc_exists()){
            string cmd_in = wicalc_path + " " +
                            grid_str + " " +
                            heel_str + " " +
                            toe_str + " " +
                            radius_str + " " +
                            compdat_str + " " +
                            wname_str;

            printf ("Executing: %s.\n", cmd_in.c_str());
            int i=system(cmd_in.c_str());
            printf ("The value returned was: %d.\n", i);
        }
    }
}