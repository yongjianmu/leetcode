#include "../../second/include/header.h"

struct Employee
{
    string name;
    vector<Employee> manage;
    Employee(string s) : name(s) {}
};


Employee* solve(Employee* ceo, Employee* e1, Employee* e2)
{
    if(NULL == ceo) return NULL;
    //cout << ceo->name << ", " << e1->name << ", " << e2->name << endl;
    if(ceo->name == e1->name || ceo->name == e2->name) return ceo;
    set<Employee*> st;
    for(auto& e : ceo->manage)
    {
        Employee* temp = solve(&e, e1, e2);
        if(NULL != temp) 
        {
            st.insert(temp);
        }
    }
    if(st.size() >= 2) return ceo;
    else if(st.size() == 0) return NULL;
    else return solve(*st.begin(), e1, e2);
}

Employee findLeastCommon(Employee ceo, Employee e1, Employee e2)
{
    Employee* ret = solve(&ceo, &e1, &e2);
    if(NULL == ret) return Employee("error");
    return *ret;
}

int main()
{
    Employee ceo("ceo");
    Employee sub1("sub1"), sub2("sub2"), sub3("sub3"), sub4("sub4");
    Employee sub11("sub11"), sub12("sub12"), sub13("sub13"), sub14("sub14");
    Employee sub21("sub21"), sub22("sub22"), sub23("sub23"), sub24("sub24");
    Employee sub31("sub31"), sub32("sub32"), sub33("sub33"), sub34("sub34");
    Employee sub41("sub41"), sub42("sub42"), sub43("sub43"), sub44("sub44");

    sub1.manage.insert(sub1.manage.begin(), {sub11, sub12, sub13, sub14});
    sub2.manage.insert(sub2.manage.begin(), {sub21, sub22, sub23, sub24});
    sub3.manage.insert(sub3.manage.begin(), {sub31, sub32, sub33, sub34});
    sub4.manage.insert(sub4.manage.begin(), {sub41, sub42, sub43, sub44});
    ceo.manage.insert(ceo.manage.begin(), {sub1, sub2, sub3, sub4});

    Employee result = findLeastCommon(ceo, sub21, sub12);
    cout << result.name << endl;

    return 0;
}
