//-----------------------------------------------------------------------------
// File:   main.cxx
// Author: Enhope
// Date:   Jun 2, 2019
//-----------------------------------------------------------------------------
#include <iostream>

#include "HappyMealProduct.hxx"

#include "plog/Log.h"
#include "plog/Appenders/ColorConsoleAppender.h"

//-----------------------------------------------------------------------------
int main()
{
    static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;
    plog::init(plog::debug, &consoleAppender);

    PLOGI << "Begin the builder pattern";

    HappyMealProduct son_product =\
            HappyMealProduct::Builder()
            .setMainCourse(HappyMealProduct::HAMBURGER)
            .setAppetizer(HappyMealProduct::SALADE)
            .setDrinks(HappyMealProduct::SAP)
            .setToy(HappyMealProduct::HOTWHEELS)
            .build();

    PLOGI << son_product;

    HappyMealProduct daughter_product =\
            HappyMealProduct::Builder()
            .setMainCourse(HappyMealProduct::FISH_BURGER)
            .setAppetizer(HappyMealProduct::FRIES)
            .setDrinks(HappyMealProduct::COLA)
            .setToy(HappyMealProduct::BARBIE)
            .build();

    PLOGI << daughter_product;

    return 0;
}

