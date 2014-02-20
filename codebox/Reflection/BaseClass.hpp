#ifndef BaseClass_hpp
#define BaseClass_hpp

#include "DynamicClass.hpp" 

class BaseClass ;

typedef void (*setValue)(BaseClass *t, void* c) ;
class BaseClass
{
private:
    DECLARE_CLASS(BaseClass)
public:
	BaseClass(){};
	virtual ~BaseClass(){};
    static void* createInstance()
	{
		return new BaseClass() ;
	};
	virtual void registProperty(){};
	virtual void display(){};
    map<string, setValue> m_propertyMap ;
};


#define SYNTHESIZE(classType, varType, varName)    \
public:                                             \
inline static void set##varName(BaseClass*cp, void*value){ \
    classType* tp = (classType*)cp ;                        \
    tp->varName = (varType)value ;                      \
}                                                       \
inline varType get##varName(void) const {                \
	return varName ;                                      \
}
//���Ӹ��ı����ķ���
#endif
//##�����ӷ����������ַ�����������