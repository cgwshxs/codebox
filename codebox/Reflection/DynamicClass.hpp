#ifndef DynamicClass_hpp
#define DynamicClass_hpp

#include"ClassFactory.hpp"

class DynamicClass
{
public:
    DynamicClass(string name, createClass method) 
	{
		ClassFactory::sharedClassFactory().registClass(name, method) ;//��̬����
	};
} ;

#define DECLARE_CLASS(className)\
string className##Name ;        \
static DynamicClass* m_className##dc ;
//�괦��������������
#define IMPLEMENT_CLASS(className)  \
DynamicClass* className::m_className##dc = \
new DynamicClass(#className, className::createInstance) ; 
 //ͨ��DynamicClassע����
#endif
//#�ǽ�className��Ϊ�ַ�������