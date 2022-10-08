#pragma once
#include <typeinfo>
#include <list>


class IDelegate
{
public:
    virtual ~IDelegate() { }
    virtual bool isType(const std::type_info& _type) = 0;
    virtual void invoke() = 0;
    virtual bool compare(IDelegate* _delegate) const = 0;
};



//注册普通函数的委托
class CStaticDelegate : public IDelegate
{
public:
    typedef void (*Func)();

    CStaticDelegate(Func _func) : mFunc(_func) { }

    virtual bool isType(const std::type_info& _type) { return typeid(CStaticDelegate) == _type; }

    virtual void invoke() { mFunc(); }

    virtual bool compare(IDelegate* _delegate) const
    {
        if (0 == _delegate || !_delegate->isType(typeid(CStaticDelegate))) return false;
        CStaticDelegate* cast = static_cast<CStaticDelegate*>(_delegate);
        return cast->mFunc == mFunc;
    }

private:
    Func mFunc;
};


//注册指向成员非静态函数的指针的委托template<class T>
template <class T>
class CMethodDelegate : public IDelegate
{
public:
    typedef void (T::* Method)();

    CMethodDelegate(T* _object, Method _method) : mObject(_object), mMethod(_method) { }

    virtual bool isType(const std::type_info& _type)
    { 
        return typeid(CMethodDelegate<T>) == _type;
    }

    virtual void invoke()
    {
        (mObject->*mMethod)();
    }

    virtual bool compare(IDelegate* _delegate) const
    {
        if (0 == _delegate || !_delegate->isType(typeid(CMethodDelegate<T>))) 
            return false;

        CMethodDelegate<T>* cast = static_cast<CMethodDelegate<T>*>(_delegate);
        
        return cast->mObject == mObject && cast->mMethod == mMethod;
    }

private:
    T* mObject;
    Method mMethod;
};



inline IDelegate* newDelegate(void (*_func)())
{
    return new CStaticDelegate(_func);
}

template<class T>
inline IDelegate* newDelegate(T* _object, void (T::* _method)())
{
    return new CMethodDelegate<T>(_object, _method);
}
