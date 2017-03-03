#include <functional>

using namespace std;
template<typename V>
env<V> *addEnvironment(env<V> *p, string var, V value);
template<typename V>
env<V> *removeFirstEnvironmnet(env<V> *p);
template<typename V>
V getConstantFromEnvironment(env<V> *p, string var);
template<typename V>
V evalExpList(operators<V> ops, ExpList<V> *list, env<V> *p);


template<typename V>
env<V> *addEnvironment(env<V> *p, string var, V value)
{
    struct env<V>* newEnv = new struct env<V>;
    newEnv->var = var;
    newEnv->value = value;
    newEnv->next = p;
    return newEnv;
}

template<typename V>
env<V> *removeFirstEnvironmnet(env<V> *p)
{
    struct env<V>* temp = nullptr;
    if(p)
    {
        temp = p->next;
        delete p;
    }
    return temp;
}

template<typename V>
V getConstantFromEnvironment(env<V> *p, string var)
{
    struct env<V> *temp = p;
    while(temp)
    {
        if(temp->var == var) return temp->value;
        temp = temp->next;
    }
    //should never be reached
    return p->value;
}



template<typename V>
V Constant<V>::eval(env<V> *p)
{
    return c;
}


template<typename V>
V evalExpList(operators<V> ops, ExpList<V> *list, env<V> *p)
{
    if(list)
    {
        return ops.binop(list->head->eval(p), evalExpList(ops, list->tail, p));
    }
    return ops.unit;
}

template<typename V>
V OpApp<V>::eval(env<V> *p)
{
    return evalExpList(ops, args, p);
}


template<typename V>
V Var<V>::eval(env<V> *p)
{
    return getConstantFromEnvironment(p, name);
}



template<typename V>
V Let<V>::eval(env<V> *p)
{
    p = addEnvironment(p,bvar,bexp->eval(p));
    V result = body->eval(p);
    p = removeFirstEnvironmnet(p);
    return result;
}
