#include <list>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;


/*****************************************************************
 * Compile:     g++ -o carRental carRental.cpp -std=c++11
 * Run:         ./carRental
 * **************************************************************/

/*****************************************************************
 * @brief       Base class of car
 *
 * @class       CCar
 * **************************************************************/
class CCar
{
public:
    CCar(string plate, string brand) : mPlate(plate), mBrand(brand) {}

    string getPlate()
    {
        return mPlate;
    }

    string getBrand()
    {
        return mBrand;
    }

    virtual int queryPassengerNumber() = 0;

private:
    string mPlate;
    string mBrand;
};


/*****************************************************************
 * @brief       SUV class, derived class of car
 *              add optional extension for the third row
 *
 * @class       CSUV
 * ***************************************************************/
class CSUV : public CCar
{
public:

    CSUV(string plate, string brand, bool rowExtension = false) : CCar(plate, brand), mRowExtenstion(rowExtension) {} 

    virtual int queryPassengerNumber()
    {
        return mRowExtenstion ? 7 : 4; // Assume that SUV without third row can carry 4 passengers
    }

private:
    bool mRowExtenstion;
};


/*****************************************************************
 * @brief       Sedan class, derived class of car
 *              add optional sportsPackage
 *
 * @class       CSedan
 * ***************************************************************/
class CSedan: public CCar
{
public:

    CSedan(string plate, string brand, bool sportsPackage = false) : CCar(plate, brand), mSportsPackage(sportsPackage) {} 

    virtual int queryPassengerNumber()
    {
        return 4; // Assume that Sedan can only carry 4 passengers
    }

    bool hasSportsPackage()
    {
        return mSportsPackage;
    }

private:
    bool mSportsPackage;
};


/*****************************************************************
 * @brief       CarRental class
 *              Two lists, mSUV and mSedan
 *              Two hash maps, mSUVDict and mSedanDict
 *              Implement O(1) for add, delete and query
 *              For delete, we can use either class or plate NO.
 *
 * @class       CCarRental
 * ***************************************************************/
class CCarRental
{
public:
    CCarRental(){}

    bool addCar(CSUV suv)
    {
        if(mSUVDict.find(suv.getPlate()) != mSUVDict.end()) return false;
        auto iter = mSUV.insert(mSUV.begin(), suv);
        mSUVDict[suv.getPlate()] = iter;
        return true;
    }

    bool addCar(CSedan sedan)
    {
        if(mSedanDict.find(sedan.getPlate()) != mSedanDict.end()) return false;
        auto iter = mSedan.insert(mSedan.begin(), sedan);
        mSedanDict[sedan.getPlate()] = iter;
        return true;
    }

    bool deleteCar(CSUV suv)
    {
        if(mSUVDict.empty()) return false;
        auto iter = mSUVDict.find(suv.getPlate());
        if(iter == mSUVDict.end()) return false;
        mSUV.erase(iter->second);
        mSUVDict.erase(iter);
        return true;
    }

    bool deleteCar(CSedan sedan)
    {
        if(mSedanDict.empty()) return false;
        auto iter = mSedanDict.find(sedan.getPlate());
        if(iter == mSedanDict.end()) return false;
        mSedan.erase(iter->second);
        mSedanDict.erase(iter);
        return true;
    }

    bool deleteCar(string plate)
    {
        if(!mSUVDict.empty())
        {
            auto iter = mSUVDict.find(plate);
            if(mSUVDict.end() != iter)
            {
                mSUV.erase(iter->second);
                mSUVDict.erase(iter);
                return true;
            }
        }

        if(!mSedanDict.empty())
        {
            auto iter = mSedanDict.find(plate);
            if(mSedanDict.end() != iter)
            {
                mSedan.erase(iter->second);
                mSedanDict.erase(iter);
                return true;
            }
        }

        return false;
    }

    CSUV* getSUV(string plate)
    {
        if(mSUV.empty()) return NULL;
        auto iter = mSUVDict.find(plate);
        if(iter == mSUVDict.end()) return NULL;
        return static_cast<CSUV*> (&(*(iter->second)));
    }

    CSedan* getSedan(string plate)
    {
        if(mSedan.empty()) return NULL;
        auto iter = mSedanDict.find(plate);
        if(iter == mSedanDict.end()) return NULL;
        return static_cast<CSedan*> (&(*(iter->second)));
    }

private:
    list<CSUV> mSUV;
    list<CSedan> mSedan;
    unordered_map<string, list<CSUV>::iterator> mSUVDict; // dict: plate -> SUV iterator
    unordered_map<string, list<CSedan>::iterator> mSedanDict; // dict: plate -> Sedan iterator
};



// Test 
int main()
{
    CSUV suv1("X22", "BMW", true);
    CSUV suv2("X23", "Ford");
    CSUV suv3("X24", "Ferrari");
    CSUV suv4("X25", "McLaren");

    CSedan sedan1("X32", "Benz", true);
    CSedan sedan2("X33", "Hydai");
    CSedan sedan3("X34", "Honda");
    CSedan sedan4("X35", "Toyota");

    CCarRental rental;
    
    // Test add
    rental.addCar(suv1);
    rental.addCar(suv2);
    rental.addCar(suv3);
    rental.addCar(suv4);

    rental.addCar(sedan1);
    rental.addCar(sedan2);
    rental.addCar(sedan3);
    rental.addCar(sedan4);

    // Test get
    auto suv = rental.getSUV("X22");
    if(NULL != suv)
    {
        cout << "Info of SUV X22" << endl;
        cout << suv->getPlate() << endl;
        cout << suv->getBrand() << endl;
        cout << suv->queryPassengerNumber() << endl;
    }

    auto sedan = rental.getSedan("X32");
    if(NULL != sedan)
    {
        cout << "Info of Sedan X32" << endl;
        cout << sedan->getPlate() << endl;
        cout << sedan->getBrand() << endl;
        cout << sedan->queryPassengerNumber() << endl;
        cout << sedan->hasSportsPackage() << endl;
    }

    // Test delete
    rental.deleteCar(suv1);
    suv = rental.getSUV("X22");
    string r = NULL == suv ? "successfully" : "failed";
    cout << "Delete X22 " + r << endl;

    rental.deleteCar("X32");
    sedan = rental.getSedan("X32");
    r = NULL == sedan ? "successfully" : "failed";
    cout << "Delete X32 " + r << endl;
    

    return 0;
}
