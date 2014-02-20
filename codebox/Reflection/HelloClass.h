#ifndef HelloClass_h
#define HelloClass_h


#include "BaseClass.hpp"

class HelloClass : public BaseClass
{
private:
    DECLARE_CLASS(HelloClass)
    
public:
    SYNTHESIZE(HelloClass, int*, m_pValue)//���Ӹı�*m_pValue ����
    
    HelloClass() ;
    virtual ~HelloClass() ;
    static void* createInstance() ;
    virtual void registProperty() ;
    virtual void display() ;
protected:
    int *m_pValue ;

} ;

#endif
