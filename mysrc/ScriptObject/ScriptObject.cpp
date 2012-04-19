
#include <sstream>
#include "ScriptObject.h"


ScriptObject::ScriptObject()
{
    m_type=ScriptObject::eValueType_Null;
}

ScriptObject::ScriptObject(int val)
{
    m_type=ScriptObject::eValueType_Int;
    m_int = val;
}
ScriptObject::ScriptObject(double val)
{
    m_type=ScriptObject::eValueType_Double;
    m_double=val;
}
ScriptObject::ScriptObject(std::string val)
{
    m_str = val;
    m_type=ScriptObject::eValueType_String;
}
ScriptObject::ScriptObject(void* val)
{
    m_pointer = val;
    m_type=ScriptObject::eValueType_Pointer;
}

int ScriptObject::toInt()
{
    return m_int;
}
double ScriptObject::toDouble()
{
    return m_double;
}
std::string ScriptObject::toString()
{
    switch(m_type){
        case ScriptObject::eValueType_String:
            return m_str;
        case ScriptObject::eValueType_Int:
            {
                std::ostringstream os;
                os<<"int:"<<m_int;
                return os.str();
            }
        case ScriptObject::eValueType_Double:
            {
                std::ostringstream os;
                os<<"double:"<<m_double;
                return os.str();
            }
        case ScriptObject::eValueType_Pointer:
            {
                std::ostringstream os;
                os<<"pointer:"<<(long)m_pointer;
                return os.str();
            }
        default:
            return std::string("unknown type");
    }
}

void* ScriptObject::toPointer()
{
    return m_pointer;
}
