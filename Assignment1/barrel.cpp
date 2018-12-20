#include <cassert>      // Is this is for the assert functions in main.cpp?
#include "barrel.h"

#include <iostream>
using namespace std;



namespace data_structures_assignment_1 {
    // Add the barrel class implementation here.

//=============================================================================
    // Global Variables:
    // double Store_Water;

    // using Global Variables solve's 1 problem that is {scope limitation}, but introduces 100 more!
    // A lot of functions using the same named variable can lead to situations where the result is unknowingly modified by another function.
//=============================================================================


//=============================================================================
// CONSTRUCTORS for the barrel class:
    barrel::barrel() {

       height = 1;
       water_liters = 0;
       olive_oil_liters = 0;

    }

    barrel::barrel(double init_height, double init_water_liters, double init_olive_oil_liters)
    {

        // assert function???

        height = init_height;
        water_liters = init_water_liters;           // Default Volume is set at 0 liters.
        olive_oil_liters = init_olive_oil_liters;       // Default Volume is set at 0 liters.
        // TOTAL_CAPACITY = 100;       // The barrel can only hold 100 liters.
        assert (init_water_liters+init_olive_oil_liters <= init_height*100); // edit is made!

    }
//=============================================================================


//=============================================================================
// PUBLIC CONSTANT member functions for the barrel class:
    double barrel::get_olive_oil_liters() const
    {
        return olive_oil_liters;
    }

    double barrel::get_water_liters() const
    {
        return water_liters;
    }

    double barrel::get_height() const
    {
        return height;
    }

//=============================================================================


//=============================================================================
// PUBLIC MODIFICATION member functions for the barrel class:
    void barrel::add_olive_oil(double liters)
    {
        assert(liters >= 0);        // Liter's can not be negative.

        double total = get_water_liters() + get_olive_oil_liters();

        if (total + liters <= (100*height))
        {
            olive_oil_liters += liters;
            liters = 0;
        }

        double Total = get_water_liters() + get_olive_oil_liters(); // water + olive oil + liters inserted compared to height*100;

        if(Total + liters >= (100*height))
        {
            double Excess = total - (100*height);    // So the remaining fluid is removed. It can't be negative! ...

            if (Excess <= get_olive_oil_liters())
            {
                olive_oil_liters -= Excess;
            }

            if(Excess >= get_olive_oil_liters())
            {
                double Difference = Excess - get_olive_oil_liters();
                olive_oil_liters = 0;
                water_liters -= Difference;
            }
        }
    }


    void barrel::add_water(double liters)
    {
        assert(liters >= 0);                                            // Liter's can not be negative.

        double total = get_water_liters() + get_olive_oil_liters();     // Sum of Water and Oil;

        if (total + liters <= (100*height))
        {
            water_liters += liters;
        } else if (total + liters > 100*height)
        {
            // double Excess = total - (100*height);
            // So the remaining fluid is removed. It can't be negative! ...

            if (liters <= olive_oil_liters) {
                olive_oil_liters -= liters;             // 60 - 20 = 40;
                water_liters += liters;
                liters = 0;
            }

            if (liters > olive_oil_liters)
            {

                if ((liters + water_liters) < (100*height))
                {
                    water_liters += liters;
                    olive_oil_liters = (100*height) - water_liters;

                } else if((liters + water_liters) >= (100*height))
                {
                    olive_oil_liters = 0;
                    water_liters = (100 * height); // meaning the barrel only has water!
                }
            }
        }
    }


    void barrel::drain(double liters)
    {
        assert(liters > 0); // Liter's can not be negative.
        if (liters > get_olive_oil_liters()+get_water_liters())
        {
            olive_oil_liters = 0;
            water_liters = 0;               // Meaning that the barrel is empty!

        } else {
            double Capacity = get_olive_oil_liters() + get_water_liters() - get_total_capacity(); // 120 - 100 = 20;

            if (liters <= get_water_liters())
            {
                water_liters = get_water_liters() - liters;    // 60 - 35 = 25!
            } else if (liters == get_water_liters())
            {
                water_liters -= liters;             // meaning water liters would be 0!
            }else if (liters >= get_water_liters())
            {
               double Difference = Capacity - get_water_liters();
               olive_oil_liters -= Difference;
            }
        }
    }
//=============================================================================


//=============================================================================
// PRIVATE CONSTANT member functions for the barrel class:
    double data_structures_assignment_1::barrel::get_total_capacity() const
    {
        double TOTAL_CAPACITY = get_height()*100;   // for every 1 meter barrel we get 100 Liters.

        return TOTAL_CAPACITY;
    }

    double data_structures_assignment_1::barrel::get_empty_space() const
    {
        double total = get_total_capacity();                                 // 100;
        double Empty_Space = total - olive_oil_liters - water_liters;        // 100 - 40 - 25 = 35;

        return Empty_Space;
    }
//=============================================================================


//=============================================================================
// NON-MEMBER functions for the barrel class:
    data_structures_assignment_1::barrel operator+(const data_structures_assignment_1::barrel &s1, const data_structures_assignment_1::barrel &s2)
    {

        double x, y, z;
        x = s1.get_height()+ s2.get_height();                               // Height
        y = s1.get_water_liters() + s2.get_water_liters();                  // Water
        z = s1.get_olive_oil_liters() + s2.get_olive_oil_liters();          // Olive Oil
        barrel s3(x, y, z);                                                 // New Object

        return s3;
    }


    bool operator==(const data_structures_assignment_1::barrel &b1, const data_structures_assignment_1::barrel &b2)
    {
        return (b1.get_height() == b2.get_height()) && (b1.get_water_liters() == b2.get_water_liters()) && (b1.get_olive_oil_liters() == b2.get_olive_oil_liters());
    }
//=============================================================================

}



