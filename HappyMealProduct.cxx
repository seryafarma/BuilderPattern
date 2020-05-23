//-----------------------------------------------------------------------------
// File:   Product.cxx
// Author: Enhope
// Date:   Jun 2, 2019
//-----------------------------------------------------------------------------
#include "HappyMealProduct.hxx"

#include <plog/Log.h>
//-----------------------------------------------------------------------------
HappyMealProduct::HappyMealProduct(MainCourse main_course,
                                   Appetizer appetizer,
                                   Drinks drinks,
                                   Toy toy)
:
    m_main_course(main_course),
    m_appetizer(appetizer),
    m_drinks(drinks),
    m_toy(toy)
{
    PLOGD;
}

//-----------------------------------------------------------------------------
HappyMealProduct::~HappyMealProduct()
{
    PLOGD;
}

//-----------------------------------------------------------------------------
HappyMealProduct::Builder::Builder()
:
    m_main_course(HAMBURGER),
    m_appetizer(FRIES),
    m_drinks(COLA),
    m_toy(HOTWHEELS)
{
}
