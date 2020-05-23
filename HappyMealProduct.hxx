//-----------------------------------------------------------------------------
// File:   Product.hxx
// Author: Enhope
// Date:   Jun 2, 2019
//-----------------------------------------------------------------------------
#ifndef HAPPYMEALPRODUCT_HXX_
#define HAPPYMEALPRODUCT_HXX_

#include <iostream>
//-----------------------------------------------------------------------------
// \brief Product class.
class HappyMealProduct
{
public:
    //! \brief Virtual destructor for subclasses.
    virtual ~HappyMealProduct();

    class Builder;

    //! Enum for main course.
    typedef enum
    {
        HAMBURGER,
        FISH_BURGER,
        CHICKEN_BURGER
    } MainCourse;

    //! Enum for appetizer.
    typedef enum
    {
        FRIES,
        SALADE
    } Appetizer;

    //! Enum for drinks.
    typedef enum
    {
        COLA,
        FANTA,
        SAP
    } Drinks;

    //! Enum for happy meal toy.
    typedef enum
    {
        HOTWHEELS,
        BARBIE
    } Toy;

//-----------------------------------------------------------------------------
    friend std::ostream& operator<< (std::ostream& os, MainCourse mc)
    {
        switch (mc)
        {
            case HAMBURGER : return os << "HAMBURGER" ;
            case FISH_BURGER : return os << "FISH_BURGER";
            case CHICKEN_BURGER : return os << "CHICKEN_BURGER";
            // omit default case to trigger compiler warning for missing cases
            default: break;
        };

        return os;
    }

//-----------------------------------------------------------------------------
    friend std::ostream& operator<< (std::ostream& os, Appetizer ap)
    {
        switch (ap)
        {
            case FRIES : return os << "FRIES" ;
            case SALADE : return os << "SALADE";
            // omit default case to trigger compiler warning for missing cases
            default: break;
        };

        return os;
    }

//-----------------------------------------------------------------------------
    friend std::ostream& operator<< (std::ostream& os, Drinks dr)
    {
        switch (dr)
        {
            case COLA : return os << "COLA" ;
            case FANTA : return os << "FANTA";
            case SAP : return os << "SAP";
            // omit default case to trigger compiler warning for missing cases
            default: break;
        };

        return os;
    }

//-----------------------------------------------------------------------------
    friend std::ostream& operator<< (std::ostream& os, Toy ty)
    {
        switch (ty)
        {
            case HOTWHEELS : return os << "HOTWHEELS" ;
            case BARBIE : return os << "BARBIE";
            // omit default case to trigger compiler warning for missing cases
            default: break;
        };

        return os;
    }

//-----------------------------------------------------------------------------
    friend std::ostream & operator << (std::ostream &out, const HappyMealProduct &c)
    {
        out << c.m_main_course << ", "
            << c.m_appetizer   << ", "
            << c.m_drinks      << ", "
            << c.m_toy         << ", ";

        return out;
    }

private:
    //! \brief Constructor.
    HappyMealProduct(MainCourse main_course,
                     Appetizer appetizer,
                     Drinks drinks,
                     Toy toy);

    //! Main course.
    const MainCourse m_main_course;

    //! Appetizer.
    const Appetizer m_appetizer;

    //! Drinks.
    const Drinks m_drinks;

    //! Happy meal toy!
    const Toy m_toy;

};

//-----------------------------------------------------------------------------
// \brief Builder class.
class HappyMealProduct::Builder
{
public:
    Builder();

    // sets custom values for Product creation
    // returns Builder for shorthand inline usage (same way as cout <<)
    Builder& setMainCourse( MainCourse mc ){ this->m_main_course = mc; return *this; }
    Builder& setAppetizer( Appetizer ap){ this->m_appetizer = ap; return *this; }
    Builder& setDrinks( Drinks d ){ this->m_drinks = d; return *this; }
    Builder& setToy( Toy toy ){ this->m_toy = toy; return *this; }

    //! \brief Build the product.
    //! \return The product done.
    HappyMealProduct build(){
        // Here, optionaly check variable consistency
        // and also if Product is buildable from given information
        return HappyMealProduct(m_main_course, m_appetizer, m_drinks, m_toy);
    }
private:
    //! Main course.
    MainCourse m_main_course;

    //! Appetizer.
    Appetizer m_appetizer;

    //! Drinks.
    Drinks m_drinks;

    //! Happy meal toy!
    Toy m_toy;
};

#endif /* HAPPYMEALPRODUCT_HXX_ */
