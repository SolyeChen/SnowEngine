#include "Delegate.h"

class CMultiDelegate
{
public:
    typedef std::list<IDelegate*> ListDelegate;
    typedef ListDelegate::iterator ListDelegateIterator;
    typedef ListDelegate::const_iterator ConstListDelegateIterator;

    CMultiDelegate() { }
    ~CMultiDelegate() { clear(); }

    bool empty() const
    {
        for (ConstListDelegateIterator iter = mListDelegates.begin(); iter != mListDelegates.end(); ++iter)
        {
            if (*iter) return false;
        }
        return true;
    }

    void clear()
    {
        for (ListDelegateIterator iter = mListDelegates.begin(); iter != mListDelegates.end(); ++iter)
        {
            if (*iter)
            {
                delete (*iter);
                (*iter) = 0;
            }
        }
    }

    CMultiDelegate& operator+=(IDelegate* _delegate)
    {
        for (ListDelegateIterator iter = mListDelegates.begin(); iter != mListDelegates.end(); ++iter)
        {
            if ((*iter) && (*iter)->compare(_delegate))
            {
                delete _delegate;
                return *this;
            }
        }
        mListDelegates.push_back(_delegate);
        return *this;
    }

    CMultiDelegate& operator-=(IDelegate* _delegate)
    {
        for (ListDelegateIterator iter = mListDelegates.begin(); iter != mListDelegates.end(); ++iter)
        {
            if ((*iter) && (*iter)->compare(_delegate))
            {
                if ((*iter) != _delegate) delete (*iter);
                (*iter) = 0;
                break;
            }
        }
        delete _delegate;
        return *this;
    }

    void operator()()
    {
        ListDelegateIterator iter = mListDelegates.begin();
        while (iter != mListDelegates.end())
        {
            if (0 == (*iter))
            {
                iter = mListDelegates.erase(iter);
            }
            else
            {
                (*iter)->invoke();
                ++iter;
            }
        }
    }

private:
    CMultiDelegate(const CMultiDelegate& _event);
    CMultiDelegate& operator=(const CMultiDelegate& _event);

private:
    ListDelegate mListDelegates;
};